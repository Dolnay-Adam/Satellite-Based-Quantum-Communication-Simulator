#pragma once
#include <vector>
#include "VAO.h"
#include "Geometry.h"
#include "LinAlg.h"


class PointGeometry : public Geometry
{
public:

	explicit PointGeometry();
	void draw() override;

private:
	VAO vao;
};

