#pragma once
#ifndef SHADERUTILS_H
#define SHADERUTILS_H
#include <iostream>
#include <fstream>

using namespace std;

unsigned int loadFragmentShaderFromFile(string filePath);

unsigned int loadVertexShaderFromFile(string filePath);

void printShaderStatus(unsigned int shaderID);

#endif
