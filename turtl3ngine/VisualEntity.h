#pragma once
#ifndef VISUALENTITY_H
#define VISUALENTITY_H
#include <iostream>
#include <vector>
#include "Texture2D.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderProgram.h"

class VisualEntity
{
private:
	glm::vec3 position;
	glm::vec3 direction;
	std::vector<VisualEntity>* attachedEntities;
	bool visible = true;
protected:
	Texture2D* texture;
public:
	bool isVisible() {
		return this->visible;
	}

	void setVisibility(bool isVisible) {
		this->visible = isVisible;
	}


	VisualEntity();


	VisualEntity(glm::vec3 position) {
		this->direction = glm::vec3(0.f);
		this->position = position;
	}
	//~VisualEntity();

	virtual void render(ShaderProgram& shader) = 0;

	void setPosition(glm::vec3 newPosition) {
		this->position = newPosition;
	}

	void translate(glm::vec3 translationVector) {
		this->position += translationVector;
	}

	glm::vec3 getPosition() {
		return this->position;
	}

	glm::vec3 getDirection() {
		return this->direction;
	}


	void setDirection(glm::vec3 newAngle) {
		this->direction = newAngle;
	}

	void addEntity(VisualEntity entity);

	void updateAll() {

	}

	void renderAll() {

	}
};
#endif
