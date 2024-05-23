#pragma once
#include "LinAlg.h"

class Coordinates
{
public:
	Coordinates(float r, float phi, float theta);

	float getR() const;
	float getPhi() const;
	float getTheta() const;
	// And so on...

private:
	float m_r;
	float m_phi;
	float m_theta;
};

