#pragma once

#include <memory>

#include "Vao.h"
#include "LinAlg.h"

#include "Geometry.h"

class CubeGeometry : public Geometry {

public:
	explicit CubeGeometry();
	void draw() override;

private:
	VAO vao;
};

