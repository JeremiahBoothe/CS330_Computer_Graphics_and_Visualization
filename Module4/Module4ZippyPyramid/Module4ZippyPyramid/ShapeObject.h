#pragma once
#include "ShaderCompiler.h"
#include <vector>
using namespace std;


/** Foundational class for all Shape Objects
* @param vector<float> vertices - the vertices of the object
* @param vector<unsigned int> indices - the indices of the vertices of the object
* @param const char* - vertex shader to be used with the object.
* @param const char* - fragment shader to be used with the object.
*/
class ShapeObject {
public:

    ShapeObject(vector<float> vertices,
        vector<unsigned int> indices,
        const char* vertexShader,
        const char* fragmentShader);

    GLuint* getVaoPtr();
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