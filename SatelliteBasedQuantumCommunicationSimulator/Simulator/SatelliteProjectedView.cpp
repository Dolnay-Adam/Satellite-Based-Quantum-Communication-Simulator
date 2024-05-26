#include "SatelliteProjectedView.h"

SatelliteProjectedView::SatelliteProjectedView(std::shared_ptr<Mesh> mesh) : Entity(mesh) {
	m_orbit = std::make_shared<Orbit>();
	t = 0.f;
}

void SatelliteProjectedView::update(float dt)
{
	t += dt * 540;
	float earthAngularVelocity = 7.29E-5f;
	float P = 2 * M_PI / earthAngularVelocity;
	if (t > P) {
		t -= P;
	}


	m_orbit->update(dt);
	
	auto coords = m_orbit->getCoordinates();

	float x = coords->getThetaECEF(t * earthAngularVelocity);
	float y = coords->getPhi();


	x = (x - M_PI) / M_PI;
	y = y / (M_PI / 2.0f);

	m_mesh->setPosition(vec3(x, y, 0.0f));
}