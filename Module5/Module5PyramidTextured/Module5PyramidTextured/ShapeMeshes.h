#pragma once
#include "DrawShapes.h"
#include <iostream>


class ShapeMesh 
{
    public:
        virtual std::string name() = 0;

        virtual GLuint* getVaoPtr();
        GLuint getVao() const;
        GLuint getIbo() const;
        GLuint* getIboPtr();
        GLuint getVbo() const;
        GLuint* getVboPtr();
        const char* getVertexShader();
        const char* getFragmentShader();
        vector<float> getVertices();
        vector<unsigned int> getIndices();
        void setShaderProgram(unsigned int shaderProgram);
        unsigned int getShaderProgram();

    protected:
        const char* vertexShader;
        const char* fragmentShader;
        vector<float> vertices;
        vector<unsigned int> indices;
        unsigned int shaderProgram = {};
        GLuint vbo[2];
        GLuint vao;
        GLuint ibo;
};

class CubeMesh : public ShapeMesh 
{
    public:
        std::string name() override;

};