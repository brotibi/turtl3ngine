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
#include "Lighting.h"


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

	ShaderProgram phongShaderLight = ShaderProgram("./shaders/phongshader.vert", "./shaders/phongShaderLight.frag");

	//phongShader.use();
	

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

	//Model model = Model("./OBJfiles/demon/demon.oobj");
	//Model model =  Model("./OBJfiles/backpack/backpack.obj");
	Model model = Model("C:/Users/broti/OneDrive/Documents/3D Models/cube.obj");
	PointLight light = PointLight(glm::vec3(1.3f, -2.0f, -2.5f));
	DirectionalLight dLight = DirectionalLight(glm::vec3(-4.3f, 10.0f, 2.5f));
	dLight.setDirection(glm::vec3(0.5,1.0,0.1));


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
		//glm::mat4 trans = glm::mat4(1.0f);
		//trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
		trans = glm::rotate(trans, (float)glfwGetTime()/60, glm::vec3(0.0f, 0.01f, 0.0f));
		
		//dLight.setDirection(dLight.getDirection()*(float)glfwGetTime());

		camera.updateCameraDefMovement(global_deltaTime, window->getWindow(), cameraFront);
		//glm::mat4 view = camera.getCameraView();

		//glm::mat4 projection;
		//projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		//shaderProgram.setMat4("transform", trans);

		//glDrawArrays(GL_TRIANGLES, 0, 36);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		
		//camera.render(phongShaderLight);
		//phongShader.setFloat("ambientStrength", .1f);
		//phongShader.setVec4("lightColor", glm::vec4(0.7f, 0.7f, 0.7f, 1.0f));
		//phongShader.setVec3("lightPos", glm::vec3(1.2f, 1.0f, 2.0f));
		//phongShader.setVec3("lightPos", camera.getPosition());
		//phongShader.setVec3("viewPos", camera.getPosition());
		//phongShaderLight.setVec3("viewPos", camera.getPosition());

		light.addLighting(phongShader, 1);
		dLight.addLighting(phongShader, 0);


		light.render(phongShaderLight);
		dLight.render(phongShaderLight);


		for (unsigned int i = 8; i < 10; i++) {
			//cube.setPosition(cubePositions[i]);
			//cube.render(phongShader);
			//light2.setPosition(cubePositions[i]);
			//light2.addLighting(phongShader, i);
			//light2.render(phongShader);
		}


		model.render(phongShader);

		camera.render(phongShader);
		camera.render(phongShaderLight);
		//Slight.addLighting(phongShader);
		

		

		

		setDeltaTime();
		//processInput(window->getWindow());

		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
		
	}

	delete window;
	return 0;
}



