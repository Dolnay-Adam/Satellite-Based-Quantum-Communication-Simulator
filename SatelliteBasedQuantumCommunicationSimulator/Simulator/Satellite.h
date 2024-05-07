#pragma once
#include "Entity.h"
#include "LinAlg.h"

#define _USE_MATH_DEFINES
#include "math.h"


class Satellite : public Entity
{
public:
	Satellite(std::shared_ptr<Mesh> mesh);
	
	void update(float dt) override;
	
private:
	float t = 0;
};

