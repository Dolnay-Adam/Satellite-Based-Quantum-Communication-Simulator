#include "Coordinates.h"

Coordinates::Coordinates(float r, float phi, float theta) : m_r(r), m_phi(phi), m_theta(theta)
{}

float Coordinates::getR() const
{
	return m_r;
}

float Coordinates::getPhi() const
{
	return m_phi;
}

float Coordinates::getTheta() const
{
	return m_theta;
}

float Coordinates::getThetaECEF(float earthRotation) const
{
	float res = m_theta - earthRotation;
	if (res < 0.f) {
		res += 2 * M_PI;
	}
	return res;
}
