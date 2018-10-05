#ifndef _INPUT_H
#define _INPUT_H

#include <GLFW/glfw3.h>
#include <map>
#include <iostream>

class Input {
public:
	static std::map<int, bool> keys;
	static std::map<int, bool> keyToggles;

	static double mx, my, mdx, mdy; 	// Mouse x, y, dx, and dy
	static bool mouseLeft;

	static double mouseSensitivity;

	static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void mouseCallback(GLFWwindow* window, double x, double y);

	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};

#endif