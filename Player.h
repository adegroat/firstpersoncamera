#ifndef _PLAYER_H
#define _PLAYER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <stdio.h>

#include "Camera.h"
#include "Input.h"

class Player : public Camera {

public:
	Player(float x, float y, float z);

	void update(float dt);
	void printPos();

private:
	float moveSpeed;
	float rotationSpeed; // rotation speed when using arrow keys

	glm::vec3 velocity;
};

#endif