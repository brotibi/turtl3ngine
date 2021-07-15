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
public:
	~AppWindow();
	AppWindow();
	AppWindow(int width, int height);
	//AppWindow(int width, int height, GLFWwindow*);
	void setWindowDimensions(int width, int height);
	GLFWwindow* getWindow();
};
#endif