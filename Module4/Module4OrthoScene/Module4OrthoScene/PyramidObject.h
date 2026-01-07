#pragma once
#include "ShaderCompiler.h"
#include "ShapeObject.h"
using namespace std;

/**
* The PyramidObject Class is the foundation for putting together the components of each shape to be rendered. Once constructed, it is a central reference point for other operations.
*/
class PyramidObject : public ShapeObject {
    using ShapeObject::ShapeObject;
public:
    PyramidObject(vector<float> vertices,
        vector<unsigned int> indices,
        const char* vertexShader,
        const char* fragmentShader);

};