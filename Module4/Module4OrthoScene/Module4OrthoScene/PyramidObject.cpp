#include "PyramidObject.h"

PyramidObject::PyramidObject(
    vector<float> vertices,
    vector<unsigned int> indices,
    const char* vertexShader,
    const char* fragmentShader) :
    ShapeObject(vertices,
        indices,
        vertexShader,
        fragmentShader){}