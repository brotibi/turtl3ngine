#pragma once
#include <iostream>
#include <stdio.h>
#include "AppWindow.h"
#include "ShaderUtils.h"
//#include "ShapeConstants.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Utility.h"
#include "PracticeCube.h"
#include "Object/Model.h"


using namespace std;

//void mouse_callback(GLFWwindow* window, double xpos, double ypos);

int main() {

	AppWindow* window = new AppWindow();

	glfwSetCursorPosCallback(window->getWindow(), mouse_callback);
	//glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);



	ShaderProgram shaderProgram = ShaderProgram("./shaders/example1.vert", "./shaders/example1.frag");

	ShaderProgram phongShader = ShaderProgram("./shaders/phongshader.vert", "./shaders/phongshader.frag");

	//shaderProgram.use();


	//Texture2D texture = Texture2D("./Binnie.png");

	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
	vec = trans * vec;
	std::cout << vec.x << vec.y << vec.z << std::endl;

	unsigned int transformLoc = glGetUniformLocation(shaderProgram.getID(), "transform");

	glEnable(GL_DEPTH_TEST);

	glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
	};
	PracticeCube cube = PracticeCube(cubePositions[0]);

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	Camera camera = Camera(cameraPos, cameraPos + cameraFront, cameraUp);

	//Model model = Model("./OBJfiles/demon/demon.obj");
	Model model = Model("./OBJfiles/Survival_BackPack_2/Survival_BackPack_2.fbx");


	while (!glfwWindowShouldClose(window->getWindow()))
	{

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// update the uniform color
		//float timeValue = glfwGetTime();
		//float greenValue = sin(timeValue) / 2.0f + 0.5f;
		//int vertexColorLocation = glGetUniformLocation(shaderProgram.getID(), "ourColor");
		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

		// Rotate the entity
		glm::mat4 trans = glm::mat4(1.0f);
		//trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

		camera.updateCameraDefMovement(global_deltaTime, window->getWindow(), cameraFront);
		//glm::mat4 view = camera.getCameraView();

		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		shaderProgram.setMat4("transform", trans);

		//glDrawArrays(GL_TRIANGLES, 0, 36);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		

		for (unsigned int i = 0; i < 10; i++) {
			cube.setPosition(cubePositions[i]);
			cube.render(phongShader);
		}

		model.render(phongShader);

		camera.render(phongShader);

		

		setDeltaTime();
		//processInput(window->getWindow());

		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
		
	}

	delete window;
	return 0;
}



