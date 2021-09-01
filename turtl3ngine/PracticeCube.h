#pragma once
#include "VisualEntity.h"
#include "ShapeConstants.h"
#include "Object/ObjectStructs.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class PracticeCube : public VisualEntity {
private:
	unsigned int VAO;
	unsigned int VBO;
	glm::mat4 model = glm::mat4(1.0f);

public:
	PracticeCube(glm::vec3 position) : VisualEntity(position){
		glGenVertexArrays(1, &VAO);

		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CUBE_VERT_3D), CUBE_VERT_3D, GL_STATIC_DRAW);

		// Vertices
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// vertex normals
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

		// Texture Coords
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindVertexArray(VAO);

		this->texture = new Texture2D("./Binnie.png");

		this->model = glm::translate(this->model, this->getPosition());

		glBindTexture(GL_TEXTURE_2D, this->texture->getID());
		glBindVertexArray(VAO);
	}
	virtual void render(ShaderProgram& shader) {


		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		model = glm::mat4(1.0f);
		this->model = glm::translate(this->model, this->getPosition());
		//shader.use();
		shader.setMat4("model", this->model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
};

