#include "Shapeobject.h"

ShapeObject::ShapeObject(
    vector<float> vertices,
    vector<unsigned int> indices,
    const char* vertexShader,
    const char* fragmentShader) :
    vao(0),
    ibo(0),
    vbo(),
    vertexShader(vertexShader),
    fragmentShader(fragmentShader),
    shaderProgram(0),
    indices(indices),
    vertices(vertices){}

GLuint* ShapeObject::getVaoPtr()
{
    return &vao;
}

GLuint ShapeObject::getVao() const
{
    return vao;
}

GLuint* ShapeObject::getIboPtr()
{
    return &vbo[0];
}

GLuint ShapeObject::getIbo() const
{
    return vbo[1];
}

GLuint* ShapeObject::getVboPtr()
{
    return &vbo[0];
}

GLuint ShapeObject::getVbo() const
{
    return vbo[0];
}

const char* ShapeObject::getVertexShader()
{
    return this->vertexShader;
}

const char* ShapeObject::getFragmentShader()
{
    return this->fragmentShader;
}

vector<float> ShapeObject::getVertices()
{
    return vertices;
}

vector<unsigned int> ShapeObject::getIndices()
{

    return indices;
}

void ShapeObject::setShaderProgram(unsigned int shaderProgram)
{
    this->shaderProgram = shaderProgram;
}

unsigned int ShapeObject::getShaderProgram()
{
    return this->shaderProgram;
}