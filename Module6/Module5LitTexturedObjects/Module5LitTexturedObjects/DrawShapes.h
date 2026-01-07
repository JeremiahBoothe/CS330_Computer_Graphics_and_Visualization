#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#define STB_IMAGE_IMPLEMENTATION

/* Internal Project .h files*/
#include "ShapeObject.h"
#include "MeshDimensions.h"
#include "ShaderCompiler.h"
#include "ShaderScripts.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Lighting.h"

/* External Project Libraries */
#include <cstdlib> // EXIT_FAILURE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <learnopengl/camera.h>
#include <stb_image.h>  
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstddef>

Lighting* Lighting::lightingPtr
= new Lighting();

// Variables for window width and height
const char* const WINDOW_TITLE = "Jeremiah Boothe";
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// Main GLFW window
GLFWwindow* window = nullptr;

// Camera Controls
Camera camera(glm::vec3(0.0f, 3.0f, 10.0f));
float lastX = WINDOW_WIDTH / 2.0f;
float lastY = WINDOW_HEIGHT / 2.0f;

// Mouse Controls
bool firstMouse = true;
bool pKeyPressed = false;

// Global TextureId and uvScale
GLuint TextureId;
glm::vec2 uvScale(1.0f, 1.0f);

// Timing for movement controls
float gDeltaTime = 0.0f;
float gLastFrame = 0.0f;
glm::vec3 lightPos(0.0f, 10.0f, 2.0f);


GLuint gCubeProgramId;
GLuint gLampProgramId;

// Subject position and scale
glm::vec3 gCubePosition(0.0f, 0.0f, 0.0f);
glm::vec3 gCubeScale(2.0f);

// Cube and light color
//m::vec3 gObjectColor(0.6f, 0.5f, 0.75f);
glm::vec3 gObjectColor(1.f, 0.2f, 0.0f);
glm::vec3 gLightColor(1.0f, 1.0f, 1.0f);

// Light position and scale
glm::vec3 gLightPosition(1.5f, 0.5f, 3.0f);
glm::vec3 gLightScale(0.3f);

/**
* Takes input arguments from keyboard and mouse.
*/
int main(int argc, char* argv[]);

/* Map to hold shape objects, uses a unique_ptr to reference the object, and takes the name parameter to reference it by name. */
using Shapes = std::map<std::string, std::unique_ptr<ShapeObject>>;

/** not yet implemented**/
void flipImageVertically(unsigned char* image, 
	int width, 
	int height, 
	int channels);

/**
* Generates the texture
* @param const char* - the path/name to the file
* @param GLuint& textureId - Id of texture
* @param Shapes& ShapeMap - map of created Shapes
* @returns bool
*/
bool UCreateTexture(const char* filename, 
	GLuint& textureId, 
	Shapes& ShapeMap, 
	std::string name);

/**
* Initializes Window.
* @param int -
* @param char* [] - 
* @param GLFWwindow** - window
* @returns bool - true if initialized
*/
bool UInitialize(int, char* [], GLFWwindow** window);

/**
* Resize window capabilities.
* @param GLFWwindow* - window pointer
* @param int width - pick your width
* @param int height - pick your height
* @returns nothing
*/
void UResizeWindow(GLFWwindow* window, 
	int width, 
	int height);

/**
* Processes user input to window
* @param GLFWwindow* - window
* @returns nothing
*/
void UProcessInput(GLFWwindow* window);

/**
* Mouse Position Callback to read the changes in mouse position
* @param GLFWwindow* - window
* @param double - x position of mouse 
* @param double - y position of mouse
* @returns nothing
*/
void UMousePositionCallback(GLFWwindow* window, 
	double xpos, 
	double ypos);

/**
* Mouse Scroll Callback reads scrolling of the mouse.
* @param GLFWwindow* - window
* @param double - x offset of scroll
* @param double - y offset of scroll
* @returns nothing
*/
void UMouseScrollCallback(GLFWwindow* window, 
	double xoffset, 
	double yoffset);

/**
* Mouse Button Callback reads clicks of mouse
* @param GLFWwindow* window - window
* @param int - button activated
* @param int - action that occured
* @param int - mods??
*/
void UMouseButtonCallback(GLFWwindow* window, 
	int button, 
	int action,
	int mods);

/**
* Creates unique pointers to shape objects and places them in the map.
* @param string - reference name of object being created.
* @param Shapes - Shape Map passed by reference.
* @param vector<float> - vectors of vertices of object.
* @param vector<unsigned int> - vector of indices for object.
* @param const char* - vertex shader to be used for object.
* @param const char* - fragment shader to be used for object.
* @param GLuint - Texture Id used for ShapeObject
* @returns nothing
*/
void UCreateShape(std::string name, 
	Shapes& ShapeMap, 
	vector<float> vertices, 
	vector<float> colors,
	vector<unsigned int> indices,
	vector<float> textures,
	vector<float> normals,
	const char* vertShader, 
	const char* fragShader,
	const char* filename,
	GLuint TextureId);

/**
* Binds and renders shapes from the ShapeMap.
* @param Shapes - Aliased ShapeMap
* @param GLFWwindow* - points to the window the shapes are to be rendered in.
* @returns nothing
*/
void URenderShape(Shapes& ShapeMap, GLFWwindow* window);

/**
* For speedier iteration and experimetation during shape creation, with this I can define the vertex points, the colors, texture, etc, separately, combine them, and then use indexing as  a means to redraw the whole vector into a new vector combined with colors fully iterating the shape as vertices for use in drawArray.
* @param vector<float> vecVerts - vertices for shape
* @param vector<float> vecColors - color Coordinates
* @param vector<unsigned int> indices - orderd to draw new vertices
* @param vector<float> vecTextures - texture Coordinates
* @param vector<float vecNormals - normals for appearance of depth
* @returns vector<float> - newly generated vector with combined vertices, colors, indices, textures, as needed.
*/
vector<float> buildCombinedVector(vector<float> vecVerts, 
	vector<float> vecColors, 
	vector<unsigned int> indices, 
	vector<float> vecTextures,
	vector<float> vecNormals);

/**
* These next two functions work together to output the combined vector to a text base file in csv format with an f appended to each value. I've used it once for the focusrite interface, to collect the verticies put together in the vectors, and manually make some adjustments as needed.
* @param vector<float> tempVertices - the combined set of x,y,z, r, g, b, a, u, v, and normals.
* @param std::string& name - the name reference for each object (ie, presonus, focusrite, monitors, etc...)
* @returns bool - true for successful
*/
bool outputToFile(vector<float> tempVertices, std::string& name);

/**
* This changes the file name if one exists, currently only works up to two different file names, and then just overwrites the 2nd again and again 
* @param const std::string& - filename to build off of for streaming the CSV values to a text file.
* @returns std::string - the file name based on the object being output to a text file
*/
std::string generateNewFilename(const std::string& filename);

/**
* Creates unique pointers to shape objects and places them in the map.
* @param string - reference name of object being created.
* @param Shapes - Shape Map passed by reference.
* @param vector<float> -vectors of vertices of object.
* @param vector<unsigned int> -vector of indices for object.
* @param const char* -vertex shader to be used for object.
* @param const char* -fragment shader to be used for object.
* @param GLuint - Texture Id used for ShapeObject
* @returns nothing
*/
void UCreateSkybox(std::string name, 
	Shapes& ShapeMap, 
	vector<float> vertices, 
	vector<float> colors, 
	vector<unsigned int> indices, 
	vector<float> textures, 
	const char* vertShader, 
	const char* fragShader, 
	vector<std::string> faces, 
	GLuint textureId);

/**
* Creates unique pointers to shape objects and places them in the map.
* @param string - reference name of object being created.
* @param Shapes - Shape Map passed by reference.
* @param vector<float> -vectors of vertices of object.
* @param vector<unsigned int> -vector of indices for object.
* @param const char* -vertex shader to be used for object.
* @param const char* -fragment shader to be used for object.
* @param GLuint - Texture Id used for ShapeObject
* @returns nothing
*/
void UCreateCubeMap(std::string name, 
	Shapes& ShapeMap, 
	vector<float> vertices, 
	vector<float> colors, 
	vector<unsigned int> indices, 
	vector<float> textures, 
	const char* vertShader,
	const char* fragShader,
	vector<std::string> faces,
	GLuint textureId);

/**
* Generates the textures for the CubeMap
* @param vector<std::string> - the string vector of faces to load 
* @param GLuint& - TextureId for the textures
* @param Shapes& - ShapeMap
* @param std::string - name of CubeMap
* @returns bool
*/
bool loadCubemap(vector<std::string> faces,
	GLuint TextureID,
	Shapes& ShapeMap,
	std::string name);

void BuildShapes(Shapes& ShapeMap);

/**
* Attempts to procedurally generate a circle.
* @param float radius - radius of circle to generate
* @param float int - points on the circle
* @returns nothing
*/
void buildCircle(float radius, int vCount);
void buildCircle2(float radius, int vCount);

/**
* Attempt to create a function that normalizes data within a range, to allow real world measurments to be scaled between -1 and 1.
* @param - const std::vector<float>& data - vector of data to normalize 
* @returns std::vector<float> - normalized vertice data
*/
std::vector<float> normalizeData(const std::vector<float>& data);
void vectorNormalize();