#include "Mesh.h"

Mesh::Mesh(std::shared_ptr<Material> material, std::shared_ptr<Geometry> geometry) 
	: m_material(material), m_geometry(geometry) {}

Mesh& Mesh::setPosition(vec3 position)
{
	m_position = position;

	return *this;
}

void Mesh::draw(std::shared_ptr<Camera> camera)
{
	m_material->bindProgram();

	// Add uniforms here
	mat4 M = TranslateMatrix(m_position);

	mat4 V;
	camera->getViewMatrix(V);
	mat4 P;
	camera->getProjMatrix(P);

	//mat4 MVP = M * V * P;

	//m_material->SetMatrix(MVP, "MVP");
	m_material->SetMatrix(M, "M");
	m_material->SetMatrix(V, "V");
	m_material->SetMatrix(P, "P");


	m_material->draw();
	m_geometry->draw();

	m_material->unbindProgram();
}
