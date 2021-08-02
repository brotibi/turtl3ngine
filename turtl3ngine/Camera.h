#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "VisualEntity.h"

class Camera : public VisualEntity {
private:
	glm::vec3 targetPosition;
	glm::vec3 upVector;
	glm::mat4 view;
public:
	Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition);
	Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector);
	glm::mat4 getCameraView();
	void setTargetPosition(glm::vec3 targetPosition);
	void setView(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector);
	void updateView();
};
#endif
