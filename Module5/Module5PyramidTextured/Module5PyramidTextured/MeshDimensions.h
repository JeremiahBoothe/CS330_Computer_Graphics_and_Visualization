#pragma once
#include <vector>
#include <array>

struct Textures
{
	const char* pyramidTexture = "jbbricktexture.png";
} texturesStruct;


struct {
vector<float> vertices 
{
     // Vertex Positions (x,y,z)    // Colors (r,g,b,a)
	 0.0f,  1.0f, 0.0f,
	-1.0f, -1.0f, 1.0f,
	 1.0f, -1.0f, 1.0f,

	 0.0f,  1.0f,  0.0f,
	-1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,

	 0.0f,  1.0f,  0.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,

	 0.0f,  1.0f,  0.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f,  1.0f,

	 -1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 -1.0f, -1.0f, 1.0f,

	 1.0f, -1.0f, -1.0f,
	 -1.0f, -1.0f, 1.0f,
	 1.0f, -1.0f, 1.0f,

        
};

vector<float> colors 
{
	 0.109f, 0.0f,   0.698f, 1.0f,
	 0.389f, 0.964f, 0.922f, 1.0f,
	 0.968f, 0.0f,   0.988f, 1.0f,

	 0.984f, 0.964f, 0.207f, 1.0f,
	 0.684f, 0.690f, 0.694f, 1.0f,
	 0.984f, 0.964f, 0.207f, 1.0f,

	 0.109f, 0.0f,   0.698f, 1.0f,
	 0.389f, 0.964f, 0.922f, 1.0f,
	 0.968f, 0.0f,   0.988f, 1.0f,

	 0.984f, 0.964f, 0.207f, 1.0f,
	 0.684f, 0.690f, 0.694f, 1.0f,
	 0.984f, 0.964f, 0.207f, 1.0f,

	 0.109f, 0.0f,   0.698f, 1.0f,
	 0.389f, 0.964f, 0.922f, 1.0f,
	 0.968f, 0.0f,   0.988f, 1.0f,

	 0.984f, 0.964f, 0.207f, 1.0f,
	 0.684f, 0.690f, 0.694f, 1.0f,
	 0.984f, 0.964f, 0.207f, 1.0f,
};

vector<float> textureVertices{
		0.5f, 1.0f,		// bottom left
		0.0f, 0.0f,		// top left
		1.0f, 0.0f,		// top right

		0.5f, 1.0f,		// bottom left
		0.0f, 0.0f,		// top left
		1.0f, 0.0f,		// top right

		0.5f, 1.0f,		// bottom left
		0.0f, 0.0f,		// top left
		1.0f, 0.0f,		// top right
		
				
		0.5f, 1.0f,		// bottom left
		0.0f, 0.0f,		// top left
		1.0f, 0.0f,		// top right
		
		

		0.0f, 0.0f,		// top left
		1.0f, 0.0f,		// top right
        0.0f, 1.0f,		// bottom left


		1.0f, 0.0f,		// bottom left
		0.0f, 1.0f,		// top left
		1.0f, 1.0f,		// top right
};

vector<unsigned int> indices 
{
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,13, 14, 15, 16, 17,0
};


} pyramidObjectStruct;


/**************** For Experimental BuildCircle and Normalization functions ****/
std::vector<float> C1vertices;
std::vector<unsigned int> C1indices;
std::vector<unsigned int> Cindices;
std::vector<float> C2vertices;
std::vector<unsigned int> C2indices;
std::vector<unsigned int> C2ndices;