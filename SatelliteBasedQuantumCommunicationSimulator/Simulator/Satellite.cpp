#include "Satellite.h"

Satellite::Satellite(std::shared_ptr<Mesh> mesh) : Entity(mesh) {
	m_orbit = std::make_shared<Orbit>();
}

void Satellite::update(float dt)
{
	m_orbit->update(dt);
	
	auto coords = m_orbit->getCoordinates();
	//Itt egy korrekt átváltás kéne, hogy történjen
	//m_mesh->setPosition(vec3(coords->getTheta(), coords->getPhi(), 0.9f));
	float r = coords->getR();
	r = 3.f;
	float phi = coords->getPhi();
	float theta = coords->getTheta();

	m_mesh->setPosition(vec3(r * cosf(phi) * cosf(theta), r * sinf(phi), r * cosf(phi) * sinf(theta)));
}