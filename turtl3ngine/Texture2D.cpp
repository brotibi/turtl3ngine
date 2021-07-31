#include "Texture2D.h"
#include "stb_image.h"

Texture2D::Texture2D(std::string texturePath) {
	glGenTextures(1, &(this->ID));
	glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
	glBindTexture(GL_TEXTURE_2D, this->getID());

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//stbi_set_flip_vertically_on_load(true);
	this->textureData = stbi_load(texturePath.c_str(), &(this->width), &(this->height), &(this->nrChannels), 0);

	if (this->textureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->textureData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(this->textureData);
}

const unsigned int Texture2D::getID() {
	return this->ID;
}

const unsigned char* Texture2D::getData() {
	return this->textureData;
}

const int Texture2D::getWidth() {
	return this->width;
}

const int Texture2D::getHeight() {
	return this->height;
}