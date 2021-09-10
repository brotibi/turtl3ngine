#pragma once
#include "Lighting.h"
#include <iostream>
#include <format>

void Lighting::render(ShaderProgram& shader) {
	shader.use();
	glBindTexture(GL_TEXTURE_2D, this->diffuse->getID());
	shader.setVec4("lightColor", this->color);
	model->render(shader, glm::rotate(glm::translate(glm::mat4(1.0f), this->getPosition()), 1.f,this->getDirection()));
}

void Lighting::addLighting(ShaderProgram& shader, int index) {
	std::string str = "lights[" + std::to_string(index);
	//std::string str = std::format("lights[{}!]", index);
	str = str + "].";
	std::cout << str << std::endl;
	shader.use();
	shader.setFloat(str+"ambientStrength", this->ambientStrength);
	shader.setVec4(str+"color", this->color);
	shader.setVec3(str+"position", this->getPosition());
}

Lighting::Lighting(glm::vec3 position) : VisualEntity(position) {
	this->ambientStrength = 0.2;
	this->color = glm::vec4(1.f,1.f, 1.f, 1.f);
	this->model = new Model("C:/Users/broti/OneDrive/Documents/3D Models/cube.obj");
	this->diffuse = new Texture2D("./Binnie.png");
}

Lighting::~Lighting(){
	delete this->model;
}

// PointLight

void PointLight::addLighting(ShaderProgram& shader, int index) {
	std::string str = "pointLights[" + std::to_string(index);
	//std::string str = std::format("lights[{}!]", index);
	str = str + "].";
	std::cout << str << std::endl;
	shader.use();
	shader.setFloat(str + "ambientStrength", this->ambientStrength);
	shader.setVec4(str + "color", this->color);
	shader.setVec3(str + "position", this->getPosition());

	shader.setFloat(str + "constant", this->constant);
	shader.setFloat(str + "linear", this->linear);
	shader.setFloat(str + "quadratic", this->quadratic);
}

PointLight::PointLight(glm::vec3 position) : Lighting(position)
{
	this->constant = 1.0f;
	this->linear = 0.09f;
	this->quadratic = 0.032f;
}

void DirectionalLight::addLighting(ShaderProgram& shader, int index) {
	std::string str = "directionalLights[" + std::to_string(index);
	//std::string str = std::format("lights[{}!]", index);
	str = str + "].";
	std::cout << str << std::endl;
	shader.use();
	shader.setFloat(str + "ambientStrength", this->ambientStrength);
	shader.setVec4(str + "color", this->color);
	shader.setVec3(str + "position", this->getPosition());
	shader.setVec3(str + "direction", this->getDirection());
}

DirectionalLight::DirectionalLight(glm::vec3 position) : Lighting(position)
{
}
