#include "Player.h"

Player::Player(float x, float y, float z) : Camera(x, y, z) {
	rotationSpeed = 1.2f;
}

void Player::update(float dt) {
	// Movement forward, backward, left, right
	if(Input::keys[GLFW_KEY_W]) {
		velocity = forward * moveSpeed;
		position += velocity * dt; 
	}
	if(Input::keys[GLFW_KEY_S]) {
		velocity = -forward * moveSpeed;
		position += velocity * dt; 
	}
	if(Input::keys[GLFW_KEY_A]) {
		glm::vec3 strafeVec = glm::normalize(glm::cross(upVec, forward));
		velocity = strafeVec * moveSpeed;
		position += velocity * dt; 
	}
	if(Input::keys[GLFW_KEY_D]) {
		glm::vec3 strafeVec = glm::normalize(glm::cross(upVec, forward));
		velocity = strafeVec * moveSpeed;
		position -= velocity * dt;
	}

	// Look left, right, up, down with keys
	if(Input::keys[GLFW_KEY_LEFT]) {
		yaw -= rotationSpeed * dt;
	}

	if(Input::keys[GLFW_KEY_RIGHT]) {
		yaw += rotationSpeed * dt;
	}

	if(Input::keys[GLFW_KEY_UP]) {
		pitch += rotationSpeed * dt;
	}

	if(Input::keys[GLFW_KEY_DOWN]) {
		pitch -= rotationSpeed * dt;
	}

	// Mouse looking
	if(abs(Input::mdx) > 0.1f) {
		yaw += Input::mdx * Input::mouseSensitivity * dt;
		Input::mdx = 0.0f;
	}

	if(abs(Input::mdy) > 0.1f) {
		pitch -= Input::mdy * Input::mouseSensitivity * dt;
		Input::mdy = 0.0f;
	}

	// Sprint
	if(Input::keys[GLFW_KEY_LEFT_SHIFT]) {
		moveSpeed = 200.0f;
	} else {
		moveSpeed = 100.0f;
	}

}