#pragma once

#include <memory>

#include "LinAlg.h"
#include "Coordinates.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <iostream>

class Orbit
{
public:
	Orbit(float semiMajorAxis = 6.571E6f, float eccentricity = 0.4f, float inclination = M_PI/4, float longitudeOfAscendingNode = 0.f, float argumentOfPerigee = 0.f, float trueAnomaly = 0.f);
	void update(float dt);
	std::shared_ptr<Coordinates> getCoordinates() const;

private:
	float semiMajorAxis = 0.f;
	float eccentricity = 0.f;
	float inclination = 0.f;
	float longitudeOfAscendingNode = 0.f;
	float argumentOfPerigee = 0.f;
	float trueAnomaly = 0.f;

	//Calculated values
	float Period = 0.f;
	float a = 0.f;
	float b = 0.f;
	float c = 0.f;
};

