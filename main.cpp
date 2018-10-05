#define GLM_ENABLE_EXPERIMENTAL 1 // for glm::to_string

#include <iostream>
#include <cmath>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Player.h"
#include "Input.h"

void errorCallback(int error, const char* msg) {
	std::cout << "Error: " << msg << std::endl;
}
void update(float dt);
void draw();

float fps = 60.0f;
const int WIDTH = 1280;
const int HEIGHT = 800;
const int WORLD_RADIUS = 50;

GLFWwindow* window;

Player* player;

void initialize() {
	player = new Player(0.0f, 20.0f, 0.0f);
}

int main() {
	glfwSetErrorCallback(errorCallback);

	if(!glfwInit()) {
		std::cout << "glfwInit() failed" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Setup", NULL, NULL);
	if(!window) {
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Mouse and keyboard callbacks
	glfwSetKeyCallback(window, Input::keyboardCallback);
	glfwSetCursorPosCallback(window, Input::mouseCallback);
	glfwSetMouseButtonCallback(window, Input::mouseButtonCallback);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	glEnable(GL_DEPTH_TEST);

	glClearColor( 92.0f / 255.0f, 188.0f / 255.0f, 219.0f / 255.0f, 1.0f );

	initialize();

	double startTime = glfwGetTime();

	while(!glfwWindowShouldClose(window)) {
		float dt = glfwGetTime() - startTime;
		if(dt >= 1.0f/fps) {
			dt = 1.0f/fps;
		}
		startTime = glfwGetTime();

		glDrawBuffer(GL_BACK);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glm::mat4 projMatrix = glm::perspective(45.0f, (float)WIDTH / (float)HEIGHT, 0.001f, 500.0f);
		glMultMatrixf(&projMatrix[0][0]);

		int fbWidth, fbHeight;
		glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
		glViewport(0, 0, fbWidth, fbHeight);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glm::mat4 viewMatrix = player->viewMatrix();
		glMultMatrixf(&viewMatrix[0][0]);

		update(dt);

		// draw stuff
		draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	delete player;

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void drawFloor() {
	float gridSize = 10.0f;

	glBegin(GL_TRIANGLES);
		for(int x = -WORLD_RADIUS; x < WORLD_RADIUS; x++) {
			for(int z = -WORLD_RADIUS; z < WORLD_RADIUS; z++) {
				if(x % 2 == 0 && z % 2 != 0) glColor3f(0.7f, 0.3f, 0.2f);
				else glColor3f(0.0f, 0.7f, 0.1f);

				glVertex3f((float)x * gridSize, 0.0f, (float)z * gridSize);
				glVertex3f((float)x * gridSize + gridSize, 0.0f, (float)z * gridSize);
				glVertex3f((float)x * gridSize + gridSize, 0.0f, (float)z * gridSize + gridSize);

				glVertex3f((float)x * gridSize + gridSize, 0.0f, (float)z * gridSize + gridSize);
				glVertex3f((float)x * gridSize, 0.0f, (float)z * gridSize + gridSize);
				glVertex3f((float)x * gridSize, 0.0f, (float)z * gridSize);
			}
		}
	glEnd();
}

void draw() {
	drawFloor();
}

void update(float dt) {
	if(Input::keys[GLFW_KEY_Q]) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	if(Input::keyToggles[GLFW_KEY_ESCAPE]) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	} else {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	player->update(dt);
}