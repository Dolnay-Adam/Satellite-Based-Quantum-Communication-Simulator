#include <iostream>
#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <chrono>

#include "stb_image.h"
#include "LinAlg.h"
#include "Shader.h"
#include "Program.h"
#include "Scene.h"

std::chrono::steady_clock::time_point timeAtLastFrame;

Scene scene = Scene();

void onInitialization() {
	scene.build();
	timeAtLastFrame = std::chrono::steady_clock::now();
}

void onIdle() {
	std::chrono::steady_clock::time_point timeAtThisFrame = std::chrono::steady_clock::now();
	float dt = std::chrono::duration<float, std::milli>(timeAtThisFrame - timeAtLastFrame).count() / 1000.0f;
	timeAtLastFrame = timeAtThisFrame;

	scene.update(dt);
	glutPostRedisplay();
}

void onDisplay1() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	scene.draw();

	glutSwapBuffers();
}

void onDisplay2() {
	glClearColor(1, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void onKeyboard(unsigned char key, int pX, int pY) {
}

void onKeyboardUp(unsigned char key, int pX, int pY) {
}

void onMouse(int button, int state, int pX, int pY) {
}

void onMouseMotion(int pX, int pY) {
}

int main(int argc, char * argv[]) {
	glutInit(&argc, argv);

	int majorVersion = 4;
	int minorVersion = 6;
	glutInitContextVersion(majorVersion, minorVersion);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	//glutInitWindowSize(600, 400);
	//glutInitWindowPosition(700, 500);
	//int w2 = glutCreateWindow("Globe");

	glutInitWindowSize(600, 400);
	glutInitWindowPosition(100, 100);
	int w1 = glutCreateWindow("Projection");

	glewExperimental = true;
	glewInit();

	glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &minorVersion);

	glViewport(0, 0, 600, 600);

	onInitialization(); //Ez is arra az ablakra vonatkozik, ami éppen aktív

	//glutSetWindow(w1);
	glutDisplayFunc(onDisplay1);
	glutIdleFunc(onIdle);


	//glutSetWindow(w2);
	//glutDisplayFunc(onDisplay2);
	glutMouseFunc(onMouse);
	glutIdleFunc(onIdle);
	glutKeyboardFunc(onKeyboard);
	glutKeyboardUpFunc(onKeyboardUp);
	glutMotionFunc(onMouseMotion);

	glutMainLoop();	

	return 0;
}