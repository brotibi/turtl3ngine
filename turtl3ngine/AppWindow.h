#pragma once
#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class AppWindow {
private:
	int width;
	int height;
	GLFWwindow* window;
	bool firstMouse = true;
	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX;
	float lastY;
	float fov;
public:
	~AppWindow();
	AppWindow();
	AppWindow(int width, int height);
	//AppWindow(int width, int height, GLFWwindow*);
	void setWindowDimensions(int width, int height);
	GLFWwindow* getWindow();
};
#endif