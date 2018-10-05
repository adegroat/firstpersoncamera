#include "Camera.h"

#include "Input.h"

Camera::Camera(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;

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

	return glm::lookAt(position, position + direction, upVec);
}