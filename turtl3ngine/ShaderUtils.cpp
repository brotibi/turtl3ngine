#include "ShaderUtils.h"
#include <glad/glad.h>
#include <string>
#include <streambuf>

unsigned int loadFragmentShaderFromFile(string filePath) {
	ifstream shaderFile;
	shaderFile.open(filePath);
	string shaderData;
	shaderData.reserve(shaderFile.tellg());
	
	cout << "Reading Fragment Shader from file" << endl;
	//shaderFile >> shaderData;
	shaderData.assign((std::istreambuf_iterator<char>(shaderFile)),
		std::istreambuf_iterator<char>());

	unsigned int fragShader;
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	//cout << shaderData << endl;
	const char* shader = shaderData.c_str();
	glShaderSource(fragShader, 1, &shader, NULL);

	glCompileShader(fragShader);

	return fragShader;
}

unsigned int loadVertexShaderFromFile(string filePath) {
	ifstream shaderFile;
	shaderFile.open(filePath);
	string shaderData;
	shaderData.reserve(shaderFile.tellg());

	cout << "Reading Vertex Shader from file" << endl;
	//shaderFile >> shaderData;
	shaderData.assign((std::istreambuf_iterator<char>(shaderFile)),
		std::istreambuf_iterator<char>());

	unsigned int vertShader;
	vertShader = glCreateShader(GL_VERTEX_SHADER);
	const char* shader = shaderData.c_str();
	glShaderSource(vertShader, 1, &shader, NULL);

	glCompileShader(vertShader);

	return vertShader;
}

void printShaderStatus(unsigned int shaderID) {
	int  success;
	char infoLog[512];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	} else {
		cout << "SUCCESS\n" << endl;
	}
}