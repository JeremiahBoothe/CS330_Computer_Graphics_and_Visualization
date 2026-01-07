#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include "ShapeObject.h"
#include "MeshDimensions.h"
#include "ShaderCompiler.h"
#include "ShaderScripts.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

int main(void);

/**
* This function references the object, window, and shader program and executes rendering
* @param ShapeObject - Render Object
* @param GLFWwindow* - Pointer to relevant window for rendering.
* @returns - nothing
*/
void URenderShape(ShapeObject shape, GLFWwindow* window);


/**
* Generates the Shader Program, end goal to be able to attach different shaders to different objects.
* @param ShapeObject - passes a shape object for reference to generate and attach a shader program.
* @return ShapeObject - with attached shaderProgram to reference during execution.
*/
ShapeObject& UCreateShaderProgram(ShapeObject &shape);


/** Capture escape key presses to avoid forced exit 
* @param GLFWwindow* - the relevant window to process user input
* @returns - nothing, handles input operations in window context.
*/
void UProcessInput(GLFWwindow* window);