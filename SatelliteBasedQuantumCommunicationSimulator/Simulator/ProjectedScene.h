#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>


#include "scene.h"

#include "stb_image.h"
#include "LinAlg.h"

#include "Shader.h"
#include "Program.h"
#include "VAO.h"
#include "VBO.h"
#include "SatelliteProjectedView.h"
#include "Entity.h"
#include "PointGeometry.h"
#include "FullScreenQuadGeometry.h"
#include "FullScreenTexture.h"
#include "Camera.h"
#include "CubeGeometry.h"


#define _USE_MATH_DEFINES
#include "math.h"

class ProjectedScene : public Scene {
public:
	ProjectedScene();

	void build() final;
	
	void mouseMotionFunc(double x, double y) override;
	void mouseButtonFunc(int button, int action) override;
	void keyEventFunc(int key, int action) override;
};

