#include <iostream>
#include <stdio.h>
#include "AppWindow.h"
#include "ShaderUtils.h"


using namespace std;

int main() {

	AppWindow* window = new AppWindow();

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int vertShader = loadVertexShaderFromFile("./shaders/example1.vert");
	unsigned int fragShader = loadFragmentShaderFromFile("./shaders/example1.frag");

	printShaderStatus(vertShader);
	printShaderStatus(fragShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	while (!glfwWindowShouldClose(window->getWindow()))
	{

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
	}

	delete window;
	return 0;
}
