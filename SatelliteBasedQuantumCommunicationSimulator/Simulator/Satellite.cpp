#include "Satellite.h"

Satellite::Satellite(std::shared_ptr<Mesh> mesh) : Entity(mesh) {}

void Satellite::update(float dt)
{
	t += dt;
	m_mesh->setPosition(vec3(0.5f * cosf(2 * M_PI * t * 0.2f), 0.5f * sinf(2 * M_PI * t * 0.2f), 0.f));
}