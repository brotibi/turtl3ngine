#pragma once
#ifndef LIGHTING_H
#define LIGHTING_H
#include "VisualEntity.h"
#include "ShaderProgram.h"
#include "Object/Model.h"
class Lighting : public VisualEntity {
protected:
	float ambientStrength;
	glm::vec4 color;
	Texture2D* diffuse;
	Model* model;

public:
	virtual void render(ShaderProgram& shader);
	virtual void addLighting(ShaderProgram& shader, int index);
	Lighting(glm::vec3 position);
	~Lighting();
};


class DirectionalLight : public Lighting {
public:
	virtual void addLighting(ShaderProgram& shader, int index);
	DirectionalLight(glm::vec3 position);
};

class PointLight : public Lighting {
private:
	float constant;
	float linear;
	float quadratic;
public:
	virtual void addLighting(ShaderProgram& shader, int index);
	PointLight(glm::vec3 position);
};

class SpotLight : public Lighting {
public:
	virtual void addLighting(ShaderProgram& shader, int index);
};
#endif