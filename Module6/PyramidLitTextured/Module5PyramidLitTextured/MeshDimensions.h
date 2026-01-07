#pragma once
#include <vector>
#include <array>

struct Textures
{
	const char* pyramidTexture = "jbbricktexture.png";
} texturesStruct;


struct {

	vector<float> Vertices{
		// Vertex Positions		// Textures         // Normals
	//bottom side
	-1.0f, -1.0f, 1.0f,			0.0f, 1.0f,     0.0f, -1.0f, 0.0f,		//front bottom left
	-1.0f, -1.0f, -1.0f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,		//back bottom left
	0.5f, -0.5f, -0.5f,			1.0f, 0.0f,		0.0f, -1.0f, 0.0f,		//back bottom right	
	
	-1.0f, -1.0f, 1.0f,			0.0f, 1.0f,     0.0f, -1.0f, 0.0f,	//front bottom left
	-0.5f, -0.5f, 0.5f,			0.0f, 1.0f,		0.0f, -1.0f, 0.0f,			//front bottom left
	0.5f, -0.5f, 0.5f,			1.0f, 1.0f,		0.0f, -1.0f, 0.0f,			//front bottom right
	
	0.5f, -0.5f, -0.5f,			1.0f, 0.0f,		0.0f, -1.0f, 0.0f,			//back bottom right	
	-0.5f, -0.5f, 0.5f,			0.0f, 1.0f,		0.0f, -1.0f, 0.0f,			//front bottom left
	//back side
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		0.0f, 0.0f, -1.0f,	//top point	
	0.5f, -0.5f, -0.5f,			0.0f, 0.0f,		0.0f, 0.0f, -1.0f,	//back bottom right	
	-0.5f, -0.5f, -0.5f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f,	//back bottom left
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		0.0f, 0.0f, -1.0f,	//top point	
	//left side
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		-1.0f, 0.0f, 0.0f,	//top point	
	-0.5f, -0.5f, -0.5f,		0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	//back bottom left	
	-0.5f, -0.5f, 0.5f,			1.0f, 0.0f,		-1.0f, 0.0f, 0.0f,     //front bottom left
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		-1.0f, 0.0f, 0.0f,	//top point	
	//right side
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		1.0f, 0.0f, 0.0f,	//top point	
	0.5f, -0.5f, 0.5f,			0.0f, 0.0f,		1.0f, 0.0f, 0.0f,    //front bottom right
	0.5f, -0.5f, -0.5f,			1.0f, 0.0f,		1.0f, 0.0f, 0.0f,	//back bottom right	
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		1.0f, 0.0f, 0.0f,	//top point	
	//front side
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		0.0f, 0.0f, 1.0f,	//top point			
	-0.5f, -0.5f, 0.5f,			0.0f, 0.0f,		0.0f, 0.0f, 1.0f,    //front bottom left	
	0.5f, -0.5f, 0.5f,			1.0f, 0.0f,		0.0f, 0.0f, 1.0f,    //front bottom right
	0.0f, 0.5f, 0.0f,			0.5f, 1.0f,		0.0f, 0.0f, 1.0f,	//top point
	};

vector<float> vertices 
{
     // Vertex Positions (x,y,z)

	// front
	 0.0f,  1.0f, 0.0f,		// top point
	-1.0f, -1.0f, 1.0f,		// bottom left front
	 1.0f, -1.0f, 1.0f,		// bottom right front

	 // back
	 0.0f,  1.0f,  0.0f,	// top point
	-1.0f, -1.0f, -1.0f,	// bottom left rear
	 1.0f, -1.0f, -1.0f,	// bottom right rear

	 // left
	 0.0f,  1.0f,  0.0f,	//top point
	-1.0f, -1.0f, -1.0f,	//bottom left rear
	-1.0f, -1.0f,  1.0f,	//bottom left front
	
	// right
	 0.0f,  1.0f,  0.0f,	// top point
	 1.0f, -1.0f, -1.0f,	// bottom right rear
	 1.0f, -1.0f,  1.0f,	// bottom right front
	 
	 // bottom 
	 -1.0f, -1.0f, -1.0f,   // bottom left rear
	 1.0f, -1.0f, -1.0f,	// bottom right rear
	 -1.0f, -1.0f, 1.0f,	// bottom left front

	 1.0f, -1.0f, -1.0f,	// bottom right rear
	 -1.0f, -1.0f, 1.0f,	// bottom left front
	 1.0f, -1.0f, 1.0f,		// bottom right front

        
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

vector<float> normals {
	

0.57735f, 0.57735f, 0.57735f,
0.57735f, 0.57735f, 0.57735f,
0.57735f, 0.57735f, 0.57735f,

0.0f, 0.44721f, -0.89443f,
0.0f, 0.44721f, -0.89443f,
0.0f, 0.44721f, -0.89443f,

-0.89443f, 0.44721f, 0.0f,
-0.89443f, 0.44721f, 0.0f,
-0.89443f, 0.44721f, 0.0f,

0.89443f, 0.44721f, 0.0f,
0.89443f, 0.44721f, 0.0f,
0.89443f, 0.44721f, 0.0f,

0.0f, -1.0f, 0.0f,
0.0f, -1.0f, 0.0f,
0.0f, -1.0f, 0.0f,

0.0f, -1.0f, 0.0f,
0.0f, -1.0f, 0.0f,
0.0f, -1.0f, 0.0f,
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