#pragma once
#ifndef VISUALENTITY_H
#define VISUALENTITY_H
#include <iostream>
#include <vector>
#include "Texture2D.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class VisualEntity
{
private:
	glm::vec3 position;
	glm::vec3 angle;
	Texture2D* texture;
	std::vector<VisualEntity>* attachedEntities;
public:
	//VisualEntity();


	VisualEntity(glm::vec3 position) {
		this->position = position;
	}

	//~VisualEntity();

	//virtual void render();

	void setPosition(glm::vec3 newPosition) {
		this->position = newPosition;
	}

	glm::vec3 getPosition() {
		return this->position;
	}


	void setAngle(glm::vec3 newAngle) {
		this->angle = newAngle;
	}

	void addEntity(VisualEntity entity) {
		if(attachedEntities != nullptr) {
			
		}
		else {
			attachedEntities = new std::vector<VisualEntity>();

			attachedEntities->push_back(entity);
		}
	}

	void updateAll() {

	}

	void renderAll() {

	}
};
#endif
