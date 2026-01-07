#include "ShapeObject.h"

ShapeObject::ShapeObject(
    std::array<float, VertSize>& vertices,
    std::array<unsigned int, IndSize>& indices,
    const char* vertexShader,
    const char* fragmentShader) :
    vao(0),
    ibo(0),
    vbo(),
    vertexShader(vertexShader),
    fragmentShader(fragmentShader),
    indices(indices),
    vertices(vertices),
    shaderProgram(0)
{
}

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

GLuint ShapeObject::getVbo1() const
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

array<float, VertSize>& ShapeObject::getVertices()
{
    return vertices;
}

array<unsigned int, IndSize>& ShapeObject::getIndices()
{
    return indices;
}

void ShapeObject::setShaderProgram(unsigned int shaderProgram)
{
    this->shaderProgram = shaderProgram;
}

unsigned int ShapeObject::getShaderProgram()
{
    return shaderProgram;
}
