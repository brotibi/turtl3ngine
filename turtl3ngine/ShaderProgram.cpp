#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertexPath, std::string fragPath) {
	this->ID = glCreateProgram();
	unsigned int vertShader = loadVertexShaderFromFile(vertexPath);
	printShaderStatus(vertShader);
	unsigned int fragShader = loadFragmentShaderFromFile(fragPath);
	printShaderStatus(fragShader);

	glAttachShader(this->getID(), vertShader);
	glAttachShader(this->getID(), fragShader);
	glLinkProgram(this->getID());


	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

const unsigned int ShaderProgram::getID() {
	return this->ID;
}

void ShaderProgram::use() {
	glUseProgram(this->getID());
}

// Uniform helper methods
void ShaderProgram::setBool(const std::string& name, bool value) const {
	int uniformLocation = glGetUniformLocation(this->ID, name.c_str());
	glUniform1f(uniformLocation, value);
}

void ShaderProgram::setInt(const std::string& name, int value) const {
	int uniformLocation = glGetUniformLocation(this->ID, name.c_str());
	glUniform1f(uniformLocation, value);
}

void ShaderProgram::setFloat(const std::string& name, float value) const {
	int uniformLocation = glGetUniformLocation(this->ID, name.c_str());
	glUniform1f(uniformLocation, value);
}

void ShaderProgram::setMat4(const std::string& name, glm::mat4 value) const {
	int uniformLocation = glGetUniformLocation(this->ID, name.c_str());
	glUniformMatrix4fv(uniformLocation, 1,GL_FALSE,&value[0][0]);
}