#include "AppWindow.h"
#include <iostream>


using namespace std;

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

/*AppWindow::AppWindow(int width, int height, GLFWwindow* window) {
	this->window = window;
	this->width = width;
	this->height = height;
}*/

AppWindow::AppWindow(int width, int height) {
	GLFWwindow* window;
	this->width = width;
	this->height = height;
	
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		cout << "glfwInit failed" << endl;
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	this->window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);

	if (!this->window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(this->window, key_callback);

	glfwMakeContextCurrent(this->window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}
	glfwSwapInterval(1);

	glViewport(0, 0, this->width, this->height);

	glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
}

AppWindow::AppWindow() : AppWindow(640, 480){}

AppWindow::~AppWindow() {
	glfwTerminate();
}

GLFWwindow* AppWindow::getWindow() {
	return this->window;
}