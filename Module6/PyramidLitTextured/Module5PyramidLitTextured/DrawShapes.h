#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <cstdlib>          // EXIT_FAILURE
#include "ShapeObject.h"
#include "MeshDimensions.h"
#include "ShaderCompiler.h"
#include "ShaderScripts.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>  

#include <learnopengl/camera.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <map>

// Variables for window width and height
const char* const WINDOW_TITLE = "Jeremiah Boothe";
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// Main GLFW window
GLFWwindow* window = nullptr;

// Camera Controls
Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));
float lastX = WINDOW_WIDTH / 2.0f;
float lastY = WINDOW_HEIGHT / 2.0f;
bool firstMouse = true;
bool pKeyPressed = false;

GLuint TextureId;
glm::vec2 uvScale(1.0f, 1.0f);

// Shader programs
GLuint gCubeProgramId;
GLuint gLampProgramId;
// Timing for movement controls
float gDeltaTime = 0.0f;
float gLastFrame = 0.0f;

// Subject position and scale
glm::vec3 gCubePosition(0.0f, 0.0f, 0.0f);
glm::vec3 gCubeScale(2.0f);

// Cube and light color
//m::vec3 gObjectColor(0.6f, 0.5f, 0.75f);
glm::vec3 gObjectColor(0.8f, 0.3f, 0.1f);
glm::vec3 gLightColor(0.1f, 0.1f, 0.1f);

// Light position and scale
glm::vec3 gLightPosition(1.5f, 0.5f, 25.0f);
glm::vec3 gLightScale(0.1f);

// Lamp animation
bool gIsLampOrbiting = true;
/**
* Takes input arguments from keyboard and mouse.
*/
int main(int argc, char* argv[]);

/**
* Map to hold shape objects, uses a unique_ptr to reference the object, and takes the name parameter to reference it by name.
*/
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
* @returns nothing
*/
void UCreateShape(std::string name, 
	Shapes& ShapeMap, 
	vector<float> vertices, 
	vector<float> colors,
	vector<unsigned int> indices,
	vector<float> textures,
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
* @returns vector<float> - newly generated vector with combined vertices, colors, indices, textures, as needed.
*/
vector<float> buildCombinedVector(vector<float> vecVerts, 
	vector<float> vecColors, 
	vector<unsigned int> indices, 
	vector<float> vecTextures);