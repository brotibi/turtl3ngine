#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include <GLFW/glfw3.h>
#include "Camera.h"

float global_deltaTime = 0.0f;
float global_lastFrame = 0.0f;

int setDeltaTime() {
	float currentFrame = glfwGetTime();
	global_deltaTime = currentFrame - global_lastFrame;
	global_lastFrame = currentFrame;
	return global_deltaTime;
}

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
bool firstMouse = true;
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

float yaw = YAW;
float pitch = PITCH;

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}




#endif
