#include "Camera.h"

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition) : Camera( cameraPosition, targetPosition, glm::vec3(0.0f, 1.0f, 0.0f)){
	this->targetPosition = targetPosition;
}

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector) : VisualEntity(cameraPosition) {
	this->targetPosition = targetPosition;
	this->upVector = upVector;
	this->view = glm::lookAt(cameraPosition, targetPosition, upVector);
}

glm::mat4 Camera::getCameraView() {
	return this->view;
}

void Camera::setTargetPosition(glm::vec3 targetPosition) {
	this->targetPosition = targetPosition;
	this->view = glm::lookAt(this->getPosition(), targetPosition, this->upVector);
}

void Camera::setView(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector) {
	this->targetPosition = targetPosition;
	this->upVector = upVector;
	this->view = glm::lookAt(cameraPosition, targetPosition, upVector);
}