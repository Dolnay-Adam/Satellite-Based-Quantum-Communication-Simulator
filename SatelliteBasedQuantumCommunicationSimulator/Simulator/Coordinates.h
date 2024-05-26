#pragma once
#include "LinAlg.h"
#define _USE_MATH_DEFINES
#include "math.h"

class Coordinates
{
public:
	Coordinates(float r, float phi, float theta);

	float getR() const;
	float getPhi() const;
	float getTheta() const;
	// And so on...
	float getThetaECEF(float earthRotation) const;

private:
	float m_r;
	float m_phi;
	float m_theta;
};

