#pragma once

#include "Mesh.h"
#include <memory>

class Entity
{
public:
	explicit Entity(std::shared_ptr<Mesh> mesh);

	void draw();
	virtual void update(float dt);

protected:
	std::shared_ptr<Mesh> m_mesh;
};
