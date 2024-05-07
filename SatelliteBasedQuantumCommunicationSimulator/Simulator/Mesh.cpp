#include "Mesh.h"

Mesh::Mesh(std::shared_ptr<Material> material, std::shared_ptr<Geometry> geometry) 
	: m_material(material), m_geometry(geometry) {}

Mesh& Mesh::setPosition(vec3 position)
{
	m_position = position;

	return *this;
}

void Mesh::draw()
{
	m_material->bindProgram();

	// Add uniforms here
	mat4 M = TranslateMatrix(m_position);

	m_material->SetMatrix(M, "MVP");

	m_material->draw();
	m_geometry->draw();

	m_material->unbindProgram();
}
