#pragma once
#ifndef LIGHTING_H
#define LIGHTING_H
#include "VisualEntity.h"
#include "ShaderProgram.h"
class Lighting : public VisualEntity {
private:
	float ambientStrength;
public:
	virtual void render(ShaderProgram& shader);
};
#endif