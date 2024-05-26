#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "scene.h"

#include "SatelliteBasicView.h"
#include "Program.h"
#include "Shader.h"
#include "CubeGeometry.h"

#define _USE_MATH_DEFINES
#include "math.h"

class GlobeScene : public Scene {
public:
	GlobeScene();

	void build() final;
};

