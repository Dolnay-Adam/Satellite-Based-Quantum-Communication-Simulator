#pragma once
#include "Entity.h"
#include "LinAlg.h"

#define _USE_MATH_DEFINES
#include "math.h"

#include "Orbit.h"
#include "Coordinates.h"


class SatelliteProjectedView : public Entity
{
public:
	explicit SatelliteProjectedView(std::shared_ptr<Mesh> mesh);
	
	void update(float dt) override;
	
private:
	std::shared_ptr<Orbit> m_orbit;
	float t;
};

