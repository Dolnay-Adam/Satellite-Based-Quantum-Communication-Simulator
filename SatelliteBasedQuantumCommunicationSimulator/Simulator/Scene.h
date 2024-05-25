#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "stb_image.h"
#include "LinAlg.h"

#include "Shader.h"
#include "Program.h"
#include "VAO.h"
#include "VBO.h"
#include "Satellite.h"
#include "Entity.h"
#include "PointGeometry.h"
#include "FullScreenQuadGeometry.h"
#include "FullScreenTexture.h"
#include "Camera.h"
#include "CubeGeometry.h"

#define _USE_MATH_DEFINES
#include "math.h"

class Scene {
public:
	Scene();

	void build();
	void update(float dt);
	void draw();
	
	void mouseMotionFunc(double x, double y);
	void mouseButtonFunc(int button, int action);
	void keyEventFunc(int key, int action);

private:
	float t;
	std::vector<std::shared_ptr<Entity>> entities;

	std::shared_ptr<Camera> camera;
};

