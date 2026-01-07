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
#include <learnopengl/camera.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <map>

// Variables for window width and height
const char* const WINDOW_TITLE = "Jeremiah Boothe";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Main GLFW window
GLFWwindow* window = nullptr;

// Camera Controls
Camera camera(glm::vec3(0.0f, 1.0f, 3.0f));
float lastX = WINDOW_WIDTH / 2.0f;
float lastY = WINDOW_HEIGHT / 2.0f;
bool firstMouse = true;

// Timing for movement controls
float gDeltaTime = 0.0f;
float gLastFrame = 0.0f;

int main(int argc, char* argv[]);

/**
* Map to hold shape objects, uses a unique_ptr to reference the object, and takes the name parameter to reference it by name.
*/
using Shapes = std::map<std::string, std::unique_ptr<ShapeObject>>;

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
void UResizeWindow(GLFWwindow* window, int width, int height);

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
void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos);

/**
* Mouse Scroll Callback reads scrolling of the mouse.
* @param GLFWwindow* - window
* @param double - x offset of scroll
* @param double - y offset of scroll
* @returns nothing
*/
void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

/**
* Mouse Button Callback reads clicks of mouse
* @param GLFWwindow* window - window
* @param int - button activated
* @param int - action that occured
* @param int - mods??
*/
void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

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
void UCreateShape(std::string name, Shapes& ShapeMap, vector<float> vertices, vector<unsigned int> indices, const char* vertShader, const char* fragShader);

/**
* Binds and renders shapes from the ShapeMap.
* @param Shapes - Aliased ShapeMap
* @param GLFWwindow* - points to the window the shapes are to be rendered in.
* @returns nothing
*/
void URenderShape(Shapes& ShapeMap, GLFWwindow* window);