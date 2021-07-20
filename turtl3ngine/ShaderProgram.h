#pragma once
#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <glad/glad.h>
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
};

#endif SHADERPROGRAM_H
