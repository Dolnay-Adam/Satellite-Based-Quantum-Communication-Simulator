#pragma once

#include <vector>
#include "VAO.h"
#include "Geometry.h"
#include "LinAlg.h"

class FullScreenQuadGeometry : public Geometry
{
public:
	explicit FullScreenQuadGeometry();
	void draw() override;

private:
	VAO vao;
};

