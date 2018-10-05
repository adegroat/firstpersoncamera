#include "Camera.h"

#include "Input.h"

Camera::Camera() {
	camPos.x = 0.0f;
	camPos.y = 20.0f;
	camPos.z = 50.0f;

	lookAtPoint.x = 0.0f;
	lookAtPoint.y = 0.0f;
	lookAtPoint.z = 0.0f;

	upVec.x = 0.0f;
	upVec.y = 1.0f;
	upVec.z = 0.0f;

	direction.x = 0.0f;
	direction.y = 0.0f;
	direction.z = -1.0f;

	yaw = 0.0f;
	pitch = 0.0f;

	rotationSpeed = 0.05f;
}

glm::mat4 Camera::viewMatrix() {
	direction.z = sin(yaw);
	direction.y = 0.0f;
	direction.x = cos(yaw);
	direction = glm::normalize(direction);

	return glm::lookAt(camPos, camPos + direction, upVec);
}

void Camera::update() {
	if(Input::keys[GLFW_KEY_W]) {
		camPos += direction;
	}

	if(Input::keys[GLFW_KEY_S]) {
		camPos -= direction;
	}

	if(Input::keys[GLFW_KEY_A]) {
		glm::vec3 strafeDir = glm::normalize(glm::cross(upVec, direction));
		camPos += strafeDir;
	}

	if(Input::keys[GLFW_KEY_D]) {
		glm::vec3 strafeDir = glm::normalize(glm::cross(upVec, direction));
		camPos -= strafeDir;	
	}

	// Look left and right
	if(Input::keys[GLFW_KEY_LEFT]) {
		yaw -= rotationSpeed;
	}

	if(Input::keys[GLFW_KEY_RIGHT]) {
		yaw += rotationSpeed;
	}
	if(abs(Input::mdx) > 1.0f) {
		yaw += Input::mdx * 0.01f;
		Input::mdx = 0.0f;
	}
}