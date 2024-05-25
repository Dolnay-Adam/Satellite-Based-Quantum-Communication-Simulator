#include "Camera.h"
#include <iostream>

Camera::Camera() {
	pos = vec3(0.0f, 0.0f, 6.0f);
	ahead = vec3(0.0f, 0.0f, -1.0f);
	vup = vec3(0.0f, 1.0f, 0.0f);
	yaw = 3.14f;
	pitch = 0.0f;

	asp = 1.0f;
	fov = 1.0f;
	farPlane = 1000.0f;
	nearPlane = 0.1f;

	wPressed = false;
	aPressed = false;
	sPressed = false;
	dPressed = false;
	ePressed = false;
	qPressed = false;
	speed = 5.0f;

	mouseClicked = false;
	lastMousePos = vec2(0, 0);
	mouseDelta = vec2(0, 0);
}

void Camera::getViewMatrix(mat4& view) {
	vec3 w = normalize(ahead);
	vec3 u = normalize(cross(vup, w));
	vec3 v = cross(w, u);

	view = mat4(u.x, v.x, w.x, 0.0f,
		u.y, v.y, w.y, 0.0f,
		u.z, v.z, w.z, 0.0f,
		-dot(pos, u), -dot(pos, v), -dot(pos, w), 1.0f);
}

void Camera::getProjMatrix(mat4& proj) {
	float Sy = 1 / tanf(fov * 0.5f);
	float Sx = Sy / asp;
	float zf = farPlane;
	float zn = nearPlane;

	proj = mat4(Sx, 0.0f, 0.0f, 0.0f,
		0.0f, Sy, 0.0f, 0.0f,
		0.0f, 0.0f, zf / (zf - zn), 1.0f,
		0.0f, 0.0f, -zn * zf / (zf - zn), 0.0f);
}

void Camera::animate(float dt) {
	vec3 right = normalize(cross(vup, ahead));
	vec3 up = vec3(0, 1, 0);

	if (wPressed)
		pos = pos + ahead * speed * dt;
	if (aPressed)
		pos = pos - right * speed * dt;
	if (sPressed)
		pos = pos - ahead * speed * dt;
	if (dPressed)
		pos = pos + right * speed * dt;
	if (qPressed)
		pos = pos - up * speed * dt;
	if (ePressed)
		pos = pos + up * speed * dt;

	yaw += mouseDelta.x * 0.01f;
	pitch += mouseDelta.y * 0.01f;

	if (pitch > 3.14f / 2.0f)
		pitch = 3.14f / 2.0f;
	if (pitch < -3.14f / 2.0f)
		pitch = -3.14f / 2.0f;

	mouseDelta = vec2(0, 0);
	ahead = vec3(sinf(yaw) * cosf(pitch), -sinf(pitch), cosf(yaw) * cosf(pitch));
}

void Camera::processKey(unsigned char key, KeyStatus status) {
	if (status == KEYDOWN) {
		if (key == 'W')
			wPressed = true;
		if (key == 'A')
			aPressed = true;
		if (key == 'S')
			sPressed = true;
		if (key == 'D')
			dPressed = true;
		if (key == 'E')
			ePressed = true;
		if (key == 'Q')
			qPressed = true;
	}
	if (status == KEYUP) {
		if (key == 'W')
			wPressed = false;
		if (key == 'A')
			aPressed = false;
		if (key == 'S')
			sPressed = false;
		if (key == 'D')
			dPressed = false;
		if (key == 'E')
			ePressed = false;
		if (key == 'Q')
			qPressed = false;
	}
}

void Camera::processMouseMove(int pX, int pY) {
	mousePos = vec2(pX, pY);
	if (mouseClicked) {
		mouseDelta = mousePos - lastMousePos;
		lastMousePos = mousePos;
	}
}

void Camera::processMouseButton(KeyStatus status) {
	if (status == KEYUP) {
		mouseClicked = false;
		mouseDelta = vec2(0, 0);
	}
	if (status == KEYDOWN) {
		mouseClicked = true;
		lastMousePos = mousePos;
	}
}
