#pragma once

#include "Mesh.h"
#include <memory>
#include "Camera.h"

class Entity
{
public:
	explicit Entity(std::shared_ptr<Mesh> mesh);

	void draw(std::shared_ptr<Camera> camera);
	virtual void update(float dt);

protected:
	std::shared_ptr<Mesh> m_mesh;
};
