#pragma once
#include <iostream>

/** Shader program Macro - no more quoting every line with \n! */
#ifndef GLSL
#define GLSL(Version, Source) "#version " #Version " core \n" #Source


/** Scripts structs to feed into the ShapeObject class and make better reuse of it */
struct {	
	const char* triVertShader = GLSL(440,
		layout(location = 0) in vec3 aPos;
	layout(location = 1) in vec4 colorFromVBO;
	out vec4 colorFromVS;
	void main()
	{
		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
		colorFromVS = colorFromVBO;
	}
	);

	const char* triFragShader = GLSL(440,
		in vec4 colorFromVS;
	out vec4 FragColor;
	void main()
	{
		FragColor = colorFromVS;
	}
	);
} TriangleShaderScripts;

struct {
	const char* pyrVertShader = GLSL(440,
		layout(location = 0) in vec3 position; // Vertex data from Vertex Attrib Pointer 0
	layout(location = 1) in vec4 color;  // Color data from Vertex Attrib Pointer 1

	out vec4 vertexColor; // variable to transfer color data to the fragment shader

	//Global variables for the  transform matrices
	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		gl_Position = projection * view * model * vec4(position, 1.0f); // transforms vertices to clip coordinates
		vertexColor = color; // references incoming color data
	}
	);

	const char* pyrFragShader = GLSL(440,
		in vec4 vertexColor; // Variable to hold incoming color data from vertex shader

	out vec4 fragmentColor;

	void main()
	{
		fragmentColor = vec4(vertexColor);
	}
	);

} PyramidShaderScripts;

#endif