#include "Scene.h"

Scene::Scene() {
	camera = std::make_shared<Camera>();
}

void Scene::update(float dt) {
	camera->animate(dt);

	for (auto const& e : entities) {
		e->update(dt);
	}
}

void Scene::draw() {
	for (auto const& e : entities) {
		e->draw(camera);
	}
}

void Scene::mouseMotionFunc(double x, double y)
{
	camera->processMouseMove((int)x, (int)y);
}

void Scene::mouseButtonFunc(int button, int action)
{
	if (action == GLFW_PRESS) {
		camera->processMouseButton(KEYDOWN);
	}
	if (action == GLFW_RELEASE) {
		camera->processMouseButton(KEYUP);
	}
}

void Scene::keyEventFunc(int key, int action)
{
	if (action == GLFW_PRESS) {
		camera->processKey(key, KEYDOWN);
	}
	if (action == GLFW_RELEASE) {
		camera->processKey(key, KEYUP);
	}
}
