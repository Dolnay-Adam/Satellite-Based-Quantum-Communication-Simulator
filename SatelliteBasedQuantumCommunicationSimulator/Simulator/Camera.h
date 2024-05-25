#pragma once

#include "LinAlg.h"


enum KeyStatus {
	KEYUP,
	KEYDOWN
};


class Camera {
	vec3 pos;
	vec3 ahead;
	vec3 vup;
	float yaw;
	float pitch;


	float fov;
	float asp;
	float nearPlane;
	float farPlane;

	bool wPressed;
	bool aPressed;
	bool sPressed;
	bool dPressed;
	bool ePressed;
	bool qPressed;
	float speed;

	bool mouseClicked;
	vec2 lastMousePos;
	vec2 mouseDelta;
	vec2 mousePos;


public:
	Camera();
	void getViewMatrix(mat4& view);
	void getProjMatrix(mat4& proj);

	void animate(float dt);

	void processKey(unsigned char key, KeyStatus status);
	void processMouseMove(int pX, int pY);
	void processMouseButton(KeyStatus status);
};

