#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <chrono>
#include "ProjectedScene.h"
#include "GlobeScene.h"


std::chrono::steady_clock::time_point timeAtLastFrame;
auto scene = ProjectedScene();

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	scene.keyEventFunc(key, action);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	if (!io.WantCaptureMouse) {
		scene.mouseMotionFunc(xpos, ypos);
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	if (!io.WantCaptureMouse) {
		scene.mouseButtonFunc(button, action);
	}
}

void initialization(GLFWwindow* window) {
	scene.build();
	timeAtLastFrame = std::chrono::steady_clock::now();

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	initialization(window);

	// Set up ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");

	while (!glfwWindowShouldClose(window)) {
		// time calculations
		std::chrono::steady_clock::time_point timeAtThisFrame = std::chrono::steady_clock::now();
		float dt = std::chrono::duration<float, std::milli>(timeAtThisFrame - timeAtLastFrame).count() / 1000.0f;
		timeAtLastFrame = timeAtThisFrame;
		
		// input
		processInput(window);

		// simulation step
		scene.update(dt);
		
		// rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		scene.draw();

		ImGui::Begin("ImGui window");
		ImGui::Text("Hello there!");
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}