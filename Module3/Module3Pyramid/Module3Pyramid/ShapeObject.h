#pragma once
#include "ShaderCompiler.h"
#include "Sizer.h"

/**
* The ShapeObject Class is the foundation for putting together the components of each shape to be rendered. Once constructed, it is a central reference point for other operations.
* @param array<float, size_t>& - Vertices Array
* @param array<unsigned int, size_t>& - Indices Array
* @param const char* - Vertex Shader Program
* @param const char* - Fragment Shader
* @Returns - ShapeObject
*/
class ShapeObject {
    public:
        ShapeObject(std::array<float, VertSize>& vertices, array<unsigned int, IndSize>& indices, const char* vertexShader, const char* fragmentShader);

        ShapeObject& getMyClass() {
            return *this;
        }
        
        GLuint* getVaoPtr();
        GLuint getVao() const;
        GLuint getVbo1() const;
        GLuint* getIboPtr();
        GLuint getVbo() const;
        GLuint* getVboPtr();
        const char* getVertexShader();
        const char* getFragmentShader();
        array<float, VertSize>& getVertices();
        array<unsigned int, IndSize>& getIndices();
        void setShaderProgram(unsigned int shaderPr); 
        unsigned int getShaderProgram();

private:    
    const char* vertexShader;
    const char* fragmentShader;
    unsigned int shaderProgram;
    array<float, VertSize>& vertices;
    array<unsigned int, IndSize>& indices;
    GLuint vbo[2];
    GLuint vao;
    GLuint ibo;
};