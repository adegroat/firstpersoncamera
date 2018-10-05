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

	forward.x = 0.0f;
	forward.y = 0.0f;
	forward.z = -1.0f;

	yaw = 0.0f;
	pitch = 0.0f;

	rotationSpeed = 0.5f;
}

glm::mat4 Camera::viewMatrix() {
	forward.x = cos(yaw);
	forward.y = 0.0f;
	forward.z = sin(yaw);
	forward = glm::normalize(forward);

	lookAtPoint.x = 0.0f;
	lookAtPoint.z = 0.0f;
	lookAtPoint.y = sin(pitch);

	return glm::lookAt(position, position + forward + lookAtPoint, upVec);
}