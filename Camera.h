#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

protected:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 lookAtPoint;
	glm::vec3 upVec;

	float yaw; // rotation around the Y axis
	float pitch; // rotation around the X axis

	float rotationSpeed;

public:
	Camera(float x, float y, float z);
	glm::mat4 viewMatrix();
	void update();
};

#endif
