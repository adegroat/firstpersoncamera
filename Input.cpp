#include "Input.h"

std::map<int, bool> Input::keys;
std::map<int, bool> Input::keyToggles;

double Input::mx;
double Input::my;

double Input::mdx;
double Input::mdy;

bool Input::mouseLeft;

void Input::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if(action == GLFW_PRESS) {
		keys[key] = true;

		keyToggles[key] = !keyToggles[key];
	}
	if(action == GLFW_RELEASE) {
		keys[key] = false;
	}
}

void Input::mouseCallback(GLFWwindow* window, double x, double y) {
	mdx = x - mx;
	mdy = y - my;

	mx = x;
	my = y;
}

void Input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if(action == GLFW_PRESS) {
		if(button == GLFW_MOUSE_BUTTON_LEFT) mouseLeft = true;
	}

	if(action == GLFW_RELEASE) {
		if(button == GLFW_MOUSE_BUTTON_LEFT) mouseLeft = false;
	}
}