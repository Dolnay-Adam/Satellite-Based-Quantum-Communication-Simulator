#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "Entity.h"

#define _USE_MATH_DEFINES
#include "math.h"

class Scene {
public:
	Scene();

	virtual void build() = 0;
	void update(float dt);
	void draw();

	virtual void mouseMotionFunc(double x, double y);
	virtual void mouseButtonFunc(int button, int action);
	virtual void keyEventFunc(int key, int action);

protected:
	std::vector<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Camera> camera;
};

