#pragma once

#include <memory>

#include "Material.h"
#include "Geometry.h"
#include "LinAlg.h"
#include "Camera.h"

class Mesh
{
public:

	Mesh(std::shared_ptr<Material> material, std::shared_ptr<Geometry> geometry);

	Mesh& setPosition(vec3 pos);

	void draw(std::shared_ptr<Camera> camera);

private:
	std::shared_ptr<Material> m_material;
	std::shared_ptr<Geometry> m_geometry;
	vec3 m_position;
};

