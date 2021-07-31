#pragma once
#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderUtils.h"

class ShaderProgram {
private:
	unsigned int ID;
public:
	ShaderProgram(std::string vertexPath, std::string fragPath);
	const unsigned int getID();
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, glm::mat4 value) const;
};

#endif SHADERPROGRAM_H
