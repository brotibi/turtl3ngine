#pragma once
#ifndef MODEL_H
#define MODEL_H
#include "../stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../Texture2D.h"
#include "../ShaderProgram.h"
#include "Mesh.h"


class Model {
public:
    Model(std::string path)
    {
        loadModel(path);
    }
    void render(ShaderProgram& shader);
    void render(ShaderProgram& shader, glm::mat4 local);
private:
    // model data
    vector<Mesh> meshes;
    string directory;

    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
        string typeName);
};

#endif