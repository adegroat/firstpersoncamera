#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/gtc/matrix_transform.hpp>

class Camera {

private:
	glm::vec3 camPos;
	glm::vec3 lookAtPoint;
	glm::vec3 upVec;
	glm::vec3 direction;

	float yaw; // rotation around the Y axis
	float pitch; // rotation around the X axis
	float rotationSpeed;

public:
	Camera();
	glm::mat4 viewMatrix();
	void update();
};

#endif
