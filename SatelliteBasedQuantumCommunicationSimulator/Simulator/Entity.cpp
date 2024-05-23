#include "Entity.h"

Entity::Entity(std::shared_ptr<Mesh> mesh) :
	m_mesh(mesh) {}

void Entity::draw(std::shared_ptr<Camera> camera)
{
	m_mesh->draw(camera);
}

void Entity::update(float dt)
{
}
