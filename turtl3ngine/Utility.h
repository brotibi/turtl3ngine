#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include <GLFW/glfw3.h>
#include "Camera.h"

float global_deltaTime = 0.0f;
float global_lastFrame = 0.0f;

//float lastX = 400, lastY = 300;

bool firstMouse = true;
float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
Camera camera = Camera(cameraPos, cameraPos + cameraFront, cameraUp);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void setDeltaTime() {
	float currentFrame = glfwGetTime();
	global_deltaTime = currentFrame - global_lastFrame;
	global_lastFrame = currentFrame;
}


// For now we'll handle input here
void processInput(GLFWwindow *window) {
    float cameraSpeed = 2.5f * global_deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.translate(cameraSpeed * cameraFront);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.translate(-cameraSpeed * cameraFront);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.translate(glm::normalize(glm::cross(cameraFront, cameraUp)) * -cameraSpeed);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.translate(glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed);
}

#endif
