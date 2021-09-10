#pragma once
#ifndef MESH_H
#define MESH_H
#include <vector>
#include "../ShaderProgram.h"
#include "ObjectStructs.h"



class Mesh {
private:
	unsigned int VAO, VBO, EBO;
	void initMesh();
	//Mesh Data
	vector<Texture> textures;
	vector<Vertex> vertices;
	vector<unsigned int> indices;
public:
	void render(ShaderProgram& shader, glm::mat4 local);
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	vector<Texture> getTextures();
	vector<Vertex> getVertices();
	vector<unsigned int> getIndices();
};


#endif
