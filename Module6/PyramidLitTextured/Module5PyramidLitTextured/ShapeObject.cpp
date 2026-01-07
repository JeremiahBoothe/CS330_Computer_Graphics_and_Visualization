#include "Shapeobject.h"

ShapeObject::ShapeObject(
    vector<float> vertices,
    vector<unsigned int> indices,
    const char* vertexShader,
    const char* fragmentShader) :
    vao(),
    ibo(),
    vbo(),
    uvBuffer(),
    normalBuffer(),
    tangentBuffer(),
    bitangentBuffer(),
    elementBuffer(),
    vertexShader(vertexShader),
    fragmentShader(fragmentShader),
    shaderProgram(),
    indices(indices),
    vertices(vertices),
    TextureId()
{}

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

unsigned int ShapeObject::getTextureId()
{
    return TextureId;
}

unsigned int* ShapeObject::getTextureIdPtr()
{
    return &TextureId;
}
