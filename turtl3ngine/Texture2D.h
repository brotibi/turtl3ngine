#pragma once
#ifndef TEXTURE2D_H
#define TEXTURE2D_H
#include <iostream>
#include <glad/glad.h>


class Texture2D {
private:
	unsigned int ID;
	unsigned char* textureData;
	int width;
	int height;
	int nrChannels;
	std::string type;
public:
	Texture2D(std::string texturePath);
	Texture2D();
	const unsigned int getID();
	const unsigned char* getData();
	void setID(unsigned int ID);
	const int getWidth();
	const int getHeight();
	std::string getType();
	void setType(std::string const type);
};
#endif TEXTURE2D_H