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
public:
	Texture2D(std::string texturePath);
	const unsigned int getID();
	const unsigned char* getData();
	const int getWidth();
	const int getHeight();
};
#endif TEXTURE2D_H