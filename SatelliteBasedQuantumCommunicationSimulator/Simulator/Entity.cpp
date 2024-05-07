#include "Entity.h"

Entity::Entity(std::shared_ptr<Mesh> mesh) :
	m_mesh(mesh) {}

void Entity::draw()
{
	m_mesh->draw();
}

void Entity::update(float dt)
{
}
