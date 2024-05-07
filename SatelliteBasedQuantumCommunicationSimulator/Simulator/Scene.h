#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
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

#define _USE_MATH_DEFINES
#include "math.h"

class Scene {
public:
	Scene();

	void build();
	void update(float dt);
	void draw();

	void onKeyboard(unsigned char key);
	void onKeyboardUp(unsigned char key);
	void onMouse(int button, int state, int pX, int pY);
	void onMouseMotion(int pX, int pY);

private:
	float t;
	std::vector<std::shared_ptr<Entity>> entities;
};

