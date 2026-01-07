#pragma once
#include <array>
#include "Sizer.h" // List of size_t references to aid reuse of the ShapeObject class

/** Triangle Vertices Array, takes constexpr size_t to avoid hardcoding class constructors */
std::array<float, triVertSize> twoTrianglesVertices = {
      // Vertex Positions (x,y,z)    // Colors (r,g,b,a)
     -1.0f,  1.0f, 0.0f,             1.0f, 0.0f, 0.0f, 1.0f,
     -1.0f,  0.0f, 0.0f,             0.0f, 0.0f, 1.0f, 1.0f,
     -0.5f,  0.0f, 0.0f,             0.0f, 1.0f, 0.0f, 1.0f, 
      0.0f,  0.0f, 0.0f,             1.0f, 0.0f, 0.0f, 1.0f, 
      0.0f, -1.0f, 0.0f,             0.0f, 1.0f, 0.0f, 1.0f  

};

/** Index Reference of Triangles and colors duplicat numbers means the vertice is used twice */
std::array<unsigned int, triIndSize> twoTrianglesIndices = {
     0, 1, 2,
     3, 2, 4
};

/** Triangle Vertices Array, takes constexpr size_t to avoid hardcoding class constructors */
std::array<float, pyrVertSize> pyramidVertices = {
     // Vertex Positions (x,y,z)    // Colors (r,g,b,a)
     0.5f, -0.5f, -0.5f,            0.109f, 0.0f,   0.698f, 1.0f,  // 0 back right
    -0.5f, -0.5f, -0.5f,            0.389f, 0.964f, 0.922f, 1.0f,  // 1 Back Left
    -0.5f, -0.5f,  0.5f,            0.968f, 0.0f,   0.988f, 1.0f,  // 2 front left
     0.5f, -0.5f,  0.5f,            0.984f, 0.964f, 0.207f, 1.0f, // 3 front right
     0.0f,  0.5f,  0.0f,            0.684f, 0.690f, 0.694f, 1.0f, // 4 peak
};

/** Index Reference of Triangles and colors duplicat numbers means the vertice is used twice */
std::array<unsigned int, pyrIndSize> pyramidIndices {
     0, 1, 2,
     2, 3, 0,
     4, 0, 1,
     4, 3, 2,
     4, 2, 1,
     4, 3, 0
};