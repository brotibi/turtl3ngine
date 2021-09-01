#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "VisualEntity.h"
//#include "Utility.h"

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};



class Camera : public VisualEntity {
private:
	glm::vec3 targetPosition;
	glm::vec3 upVector;
	glm::vec3 rightVector;
	float yaw = -90.f;
	float pitch = 0.f;
	glm::mat4 view;
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
public:
	Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition);
	Camera(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector);
	glm::mat4 getCameraView();
	void setTargetPosition(glm::vec3 targetPosition);
	void setView(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 upVector);
	void updateView();
	void updateCameraDefMovement(float DeltaTime, GLFWwindow* window, glm::vec3 cameraFront);
	void setCaptureMouse(bool captureMouse, GLFWwindow* window);
	void render(ShaderProgram& shader);
};
#endif
