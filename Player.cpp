#include "Player.h"

Player::Player(float x, float y, float z) : Camera(x, y, z) {

}

void Player::update() {
	// Movement forward, backward, left, right
	if(Input::keys[GLFW_KEY_W]) {
		position.y = 20.0f + sin(glfwGetTime() * 6.0f);

		position += direction * moveSpeed;
	}

	if(Input::keys[GLFW_KEY_S]) {
		position -= direction * moveSpeed;
	}

	if(Input::keys[GLFW_KEY_A]) {
		glm::vec3 strafeDir = glm::normalize(glm::cross(upVec, direction));
		position += strafeDir * moveSpeed;
	}

	if(Input::keys[GLFW_KEY_D]) {
		glm::vec3 strafeDir = glm::normalize(glm::cross(upVec, direction));
		position -= strafeDir * moveSpeed;	
	}

	// Look left and right
	if(Input::keys[GLFW_KEY_LEFT]) {
		yaw -= rotationSpeed;
	}

	if(Input::keys[GLFW_KEY_RIGHT]) {
		yaw += rotationSpeed;
	}

	if(abs(Input::mdx) > 0.1f) {
		yaw += Input::mdx * 0.01f;
		Input::mdx = 0.0f;
	}

	// Sprint
	if(Input::keys[GLFW_KEY_LEFT_SHIFT]) {
		moveSpeed = 2.5f;
	} else {
		moveSpeed = 1.0f;
	}

}