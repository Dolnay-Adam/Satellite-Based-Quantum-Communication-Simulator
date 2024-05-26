#include "Orbit.h"



Orbit::Orbit(float semiMajorAxis, 
	float eccentricity, 
	float inclination, 
	float longitudeOfAscendingNode, 
	float argumentOfPerigee, 
	float trueAnomaly) :
	semiMajorAxis(semiMajorAxis),
	eccentricity(eccentricity),
	inclination(inclination),
	longitudeOfAscendingNode(longitudeOfAscendingNode),
	argumentOfPerigee(argumentOfPerigee),
	trueAnomaly(trueAnomaly)
{
	float G = 6.67E-11f;
	float M = 5.972E24f;
	Period = sqrtf((4 * powf(M_PI, 2) * powf(semiMajorAxis, 3)) / (G * M));
	std::cout << Period << std::endl;
	a = semiMajorAxis;
	b = a * sqrtf(1 - powf(eccentricity, 2));
	c = a * eccentricity;
}

void Orbit::update(float dt)
{
	dt *= 540;
	float r = (powf(a, 2) - powf(c, 2))/(c * cosf(trueAnomaly) + a);
	float w = (2 * M_PI * a * b) / (Period * powf(r, 2));
	trueAnomaly += w * dt;
	if (trueAnomaly > 2 * M_PI) {
		trueAnomaly -= 2 * M_PI;
	}
}

std::shared_ptr<Coordinates> Orbit::getCoordinates() const 
{
	float r = (powf(a, 2) - powf(c, 2)) / (c * cosf(trueAnomaly) + a);
	float phi = asinf(cosf(trueAnomaly) * sinf(inclination));
	float theta = atanf(sinf(trueAnomaly) / (cosf(trueAnomaly) * cosf(inclination)));
	if (trueAnomaly > M_PI / 2 && trueAnomaly < 3 * M_PI / 2) {
		theta += M_PI;
	}
	if (trueAnomaly > 3 * M_PI / 2)
		theta += 2 * M_PI;
	auto coords = std::make_shared<Coordinates>(r, phi, theta);
	return coords;
}
