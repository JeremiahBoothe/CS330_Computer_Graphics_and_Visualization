#pragma once

/** Some size_t values for shapes. The type of Array I'm using requires a value, and that's tedious and could require a lot of hardcoding across too many files, so this is a central source for anywhere it's relevant, and any changes in value to a specific meshes dimensions can be done here.
*/

/*Triangles*/
constexpr int triVertSize = 35;
constexpr int triIndSize = 6;

/*Pyramid*/
constexpr int pyrVertSize = 35;
constexpr int pyrIndSize = 18;

/*Class Reference*/
constexpr int VertSize = pyrVertSize;
constexpr int IndSize = pyrIndSize;