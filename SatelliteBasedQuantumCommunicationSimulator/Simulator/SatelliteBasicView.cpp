#include "SatelliteBasicView.h"

SatelliteBasicView::SatelliteBasicView(std::shared_ptr<Mesh> mesh) : Entity(mesh)
{
	m_orbit = std::make_shared<Orbit>();
}

void SatelliteBasicView::update(float dt)
{
	m_orbit->update(dt);

	auto coords = m_orbit->getCoordinates();

	float r = coords->getR() / 10E5f;
	float phi = coords->getPhi();
	float theta = coords->getTheta();
	m_mesh->setPosition(vec3(r * cosf(phi) * cosf(theta), r * sinf(phi), r * cosf(phi) * sinf(theta)));
}
