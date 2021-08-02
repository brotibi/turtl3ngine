#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include <GLFW/glfw3.h>
#include "Camera.h"

float global_deltaTime = 0.0f;
float global_lastFrame = 0.0f;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
Camera camera = Camera(cameraPos, cameraPos + cameraFront, cameraUp);


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
