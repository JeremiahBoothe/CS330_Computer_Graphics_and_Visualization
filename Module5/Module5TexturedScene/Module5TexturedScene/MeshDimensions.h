#pragma once
#include <vector>
#include <array>

/* List of textures used in project */
struct Textures
{
	const char* tableTexture = "textures/tables/texture.png";
	const char* tableTexture2 = "textures/tables/tableTexture2.png";
	const char* presonusFaceTexture = "textures/faderport/badTexture.png";
	const char* rightfrontspeakertexture = "textures/speakers/rightfrontspeakertexture.png";
	const char* monitor1 = "textures/monitors/monitor1.png";
	const char* monitor2 = "textures/monitors/monitor2.png";
	const char* keyboard = "textures/keyboard/keyboard.png";
	const char* speakerFaceNormal = "textures/speakers/rightfrontspeakertexture_NRM.png";
	const char* focusriteMap = "textures/focusrite/focusriteMap.png";
	const char* chromeSwirl = "textures/chromeSwirl.jpg";


	vector<const char*> focusriteTextures
	{	
		"textures/focusrite/top.png",		
		"textures/focusrite/left.png",
		"textures/focusrite/right.png",
		"textures/focusrite/front.png",
		"textures/focusrite/bottom.png",
		"textures/focusrite/back.png"
	};


	/* SkyBox Faces */
	vector<std::string> faces
	{
		"textures/skybox/left.jpg",
		"textures/skybox/right.jpg",
		"textures/skybox/bottom.jpg",
		"textures/skybox/top.jpg",
		"textures/skybox/front.jpg",
		"textures/skybox/back.jpg"
	};

} texturesStruct;

vector<float> normals{
	0.20f, 0.27f
};

struct 
{
	vector<float> cubeVertices 
	{
		// positions          // normals
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};

	vector<float> skyboxVertices 
	{
		// positions          
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,

		 1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,

		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		
		 1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f
	};
} SkyBox;

/** big ol mess of vertices & indices for different objects and purposes*/
struct 
{
	vector<float> vertices
	{
		-1.0f, -1.0f, -1.0f,    // 0 back bottom left
		-1.0f,  1.0f, -1.0f,    // 1 back top left
		 1.0f,  1.0f, -1.0f,	// 2 back top right
		 1.0f, -1.0f, -1.0f,	// 3 back bottom right

		-1.0f, -1.0f,  1.0f,    // 4 front bottom left
		-1.0f,  1.0f,  1.0f,	// 5 front top left
		 1.0f,  1.0f,  1.0f,    // 6 front top right
		 1.0f, -1.0f,  1.0f,	// 7 front bottom right
	};

	vector<float> colors
	{
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
		
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f
	};


	vector<float> colorsRed
	{
		0.49f, 0.01f, 0.13f, 1.0f,
		0.49f, 0.01f, 0.13f, 1.0f,
		0.49f, 0.01f, 0.13f, 1.0f,
		0.49f, 0.01f, 0.13f, 1.0f,
		
		0.49f, 0.01f, 0.13f, 1.0f,
		0.49f, 0.01f, 0.13f, 1.0f,
		0.49f, 0.01f, 0.13f, 1.0f,
		0.49f, 0.01f, 0.13f, 1.0f,
	};

	vector<float> colorsSteelBlack
	{
		0.34f, 0.41f, 0.48f, 1.0f,
		0.34f, 0.41f, 0.48f, 1.0f,
		0.34f, 0.41f, 0.48f, 1.0f,
		0.34f, 0.41f, 0.48f, 1.0f,
		0.34f, 0.41f, 0.48f, 1.0f,
		0.34f, 0.41f, 0.48f, 1.0f,
		0.34f, 0.41f, 0.48f, 1.0f,
		0.34f, 0.41f, 0.48f, 1.0f,
	};

	vector<float> colorsAlpha
	{
		/**Presonus device back*/
		0.27f, 0.31f, 0.33f, 0.0f,    // 0 back bottom left
		0.27f, 0.31f, 0.33f, 0.0f,    // 1 back upper left
		0.27f, 0.31f, 0.33f, 0.0f,    // 2 back upper right
		0.27f, 0.31f, 0.33f, 0.0f,    // 3 back bottom right

		0.54f, 0.55f, 0.54f, 0.0f,    // 4 front bottom left
		0.54f, 0.55f, 0.54f, 0.0f,    // 5 front upper left
		0.54f, 0.55f, 0.54f, 0.0f,    // 6 front upper right
		0.54f, 0.55f, 0.54f, 0.0f,    // 7 front bottom right
	};

	vector<float> normals{
	0.20f, 0.27f
	};

	vector<float> textureVertices
	{
		0.0f, 1.0f,		// bottom left
		0.0f, 1.0f,		// top left
		1.0f, 1.0f,		// top right
		1.0f, 1.0f,     // bottom right

		0.0f, 0.0f,     // bottom left
		0.0f, 0.0f,		// top left
		1.0f, 0.0f,		// top right
		1.0f, 0.0f,		// bottom right
	};

	vector<float> focusriteVertices 
	{ /*** X **** Y **** Z ********** R **** G **** B **** A ******** U **** V *********  Normals */
		// Top
		-1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 1.000f,		0.20f, 0.27f,	// front top left corner
		-1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.666f,		0.20f, 0.27f,	// back top left corner
		 1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.666f,		0.20f, 0.27f,   // back top right corner
		-1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 1.000f,		0.20f, 0.27f,	// front top left corner
		 1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 1.000f,		0.20f, 0.27f,	// front top right corner
		 1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.666f,		0.20f, 0.27f,	// back top right corner

		 // left
		-1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.75f, 0.333f,		0.20f, 0.27f,	// front bottom left corner
		-1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.75f, 0.666f,		0.20f, 0.27f,	// front top left corner
	    -1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.666f,		0.20f, 0.27f,	// back top left corner
		-1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.75f, 0.333f,		0.20f, 0.27f,	// front bottom left
		-1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.666f,		0.20f, 0.27f,	// back top left corner
		-1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.333f,		0.20f, 0.27f,	// back bottom left corner
		
		// bottom
		-1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.000f,		0.20f, 0.27f,	// front bottom left
		-1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.333f,		0.20f, 0.27f,	// back bottom left
		 1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.333f,		0.20f, 0.27f,	// back bottom  right
		-1.00f,-1.00f, 1.00f,	    0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.000f,		0.20f, 0.27f,	// front bottom left
		 1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.000f,		0.20f, 0.27f,	// front bottom right
		 1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.333f,		0.20f, 0.27f,	// back bottom right

		 //back
		-1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.333f,		0.20f, 0.27f,	// back bottom left
		-1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.50f, 0.666f,		0.20f, 0.27f,	// back top left
		 1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.666f,		0.20f, 0.27f,	// back top right
		-1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,	    0.50f, 0.333f,		0.20f, 0.27f,	// back bottom left
		 1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,	    0.25f, 0.333f,		0.20f, 0.27f,	// back bottom right
		 1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.666f,		0.20f, 0.27f,	// back top right
		
		 // front
		-1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,	    0.75f, 0.333f,		0.20f, 0.27f,	// front bottom left
		-1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.75f, 0.666f,		0.20f, 0.27f,	// front top left
		 1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		1.00f, 0.666f,		0.20f, 0.27f,	// front top right
		-1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,	    0.75f, 0.333f,		0.20f, 0.27f,	// front bottom left
		 1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		1.00f, 0.666f,		0.20f, 0.27f,   // front top right
		 1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		1.00f, 0.333f,		0.20f, 0.27f,	// front bottom right

		 // right
		 1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.666f,		0.20f, 0.27f,	// back top right
		 1.00f,-1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,	    0.25f, 0.333f,		0.20f, 0.27f,   // back bottom right  
 		 1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.00f, 0.333f,		0.20f, 0.27f,	// front bottom right
		 1.00f, 1.00f,-1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.25f, 0.666f,		0.20f, 0.27f,	// back top right
		 1.00f, 1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.00f, 0.666f,		0.20f, 0.27f,   // front top right
		 1.00f,-1.00f, 1.00f,		0.49f, 0.01f, 0.13f, 1.00f,		0.00f, 0.333f,		0.20f, 0.27f	// front bottom right
	};

	vector<float> textureVerticesKeyboard
	{
		0.0f, 0.0f,		// bottom left
		0.0f, 1.0f,		// top left
		1.0f, 1.0f,		// top right
		0.0f, 0.0f,     // bottom right

		0.0f, 0.0f,     // bottom left
		0.0f, 0.0f,		// top left
		1.0f, 0.0f,		// top right
		0.0f, 0.0f,		// bottom right
	};

	vector<unsigned int> indices
	{
		5, 1, 2,
		5, 6, 2,
		
		4, 5, 1,
		4, 1, 0,
		
		4, 0, 3,
		4, 7, 3,

		0, 1, 2,
		0, 3, 2,

		4, 5, 6,
		4, 6, 7,

		2, 3, 7,
		2, 6, 7,
	};
} basicCubeObjectStruct;

struct 
{
	vector<float> vertices
	{
		0.0f,   1.0f,   0.0f,			
		0.382f, 0.923f, 0.0f,			
		0.707f, 0.707f, 0.0f,			
		0.923f, 0.382f,  0.0f,			
      
		1.0f,    0.0f,   0.0f,			
		0.932f, -0.382f, 0.0f,			
		0.707f, -0.707f, 0.0f,			
		0.382f, -0.923f, 0.0f,			

		0.0f,   -1.0f,	  0.0f,			
		-0.382f, -0.923f, 0.0f,			
		-0.707f, -0.707f, 0.0f,			
		-0.932f, -0.382f, 0.0f,			

		-1.0f,   0.0f,   0.0f,		    
		-0.932f, 0.382f, 0.0f,			
		-0.707f, 0.707f, 0.0f,			
		-0.382f, 0.923f, 0.0f,			

		0.0f,    1.0f, -1.0f,			
		0.382f, 0.923f, -1.0f,			
		0.707f, 0.707f, -1.0f,			
		0.923f, 0.382f, -1.0f,			

		1.0f,    0.0f, -1.0f,		
		0.932f, -0.382f, -1.0f,		
		0.707f, -0.707f, -1.0f,		
		0.382f, -0.923f, -1.0f,		

		0.0f,   -1.0f,   -1.0f,		
		-0.382f, -0.923f, -1.0f,		
		-0.707f, -0.707f, -1.0f,		
		-0.932f, -0.382f, -1.0f,		

		-1.0f,     0.0f, -1.0f,		
		-0.932f, 0.382f, -1.0f,		
		-0.707f, 0.707f, -1.0f,		
		-0.382f, 0.923f, -1.0f,			 
	};

	vector<float> colorsMatBlack{
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,

		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,

		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,

		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,

		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,

		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
		0.16f, 0.16f, 0.17f, 1.0f,
	};

	vector<float> colorsSilver
	{
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,

		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,

		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,

		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,

		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,

		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,

		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,

		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
		0.753f, 0.753f, 0.753f, 1.0f,
	};

	vector<float> colors
	{
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,

		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,

		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,

		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,

		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,

		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,

		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,

		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
		0.20f, 0.23f, 0.63f, 1.0f,
	};

	vector<float> textureVertices
	{
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,

			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
			
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,

			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
			
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,

			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
			
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,

			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
	};

	vector<unsigned int> indices
	{
		// front circle
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,6,
		0,6,7,
		0,7,8,
		0,8,9,
		0,9,10,
		0,10,11,
		0,11,12,
		0,12,13,
		0,13,14,
		0,14,15,

		//back circle
		16, 17, 18,
		16, 18, 19,
		16, 19, 20,
		16, 20, 21,
		16, 21, 22,
		16, 22, 23,
		16, 23, 24,
		16, 24, 25,
		16, 25, 26,
		16, 26, 27,
		16, 27, 28,
		16, 28, 29,
		16, 29, 30,
		16, 30, 31,

		0, 16, 17,
		0, 1, 17,
		1, 17, 18,
		1, 2, 18,
		2, 18, 19, 
		2, 3, 19, 
		3, 19, 20, 
		3, 4,20, 
		4, 20,21, 
		4, 5,21, 
		5, 21,22, 
		5, 6,22, 
		6, 22, 23, 
		6, 7, 23, 
		7, 23, 24, 
		7,  8, 24, 
		8, 24, 25, 
		8, 9, 25, 
		9, 25, 26, 
		9, 10, 26, 
		10, 26, 27, 
		10, 11, 27, 
		11, 27, 28, 
		11, 12, 28, 
		12, 28, 29, 
		12, 13, 29, 
		13, 29, 30, 
		13, 14, 30, 
		14, 30, 31, 
		14, 15, 31, 
		15, 31, 0,
		0, 16, 31,
	};

} cylinderObjectStruct;

struct  {
	vector<float> vertices
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f,  0.0f,
		-1.0f, 1.0f,  0.0f,
		1.0f,  1.0f,  0.0f,
	};

	vector<float> colors{
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
		0.44f, 0.34f, 0.04f, 1.0f,
	};

	vector<float> colorsGreen
	{
		0.18f, 0.40f, 0.20f, 1.0f,
		0.18f, 0.40f, 0.20f, 1.0f,
		0.18f, 0.40f, 0.20f, 1.0f,
		0.18f, 0.40f, 0.20f, 1.0f,
	};

	vector<float> textureVertices
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
	};

	vector<float> colorsPink
	{
		0.40f, 0.18f, 0.36f, 1.0f,
		0.40f, 0.18f, 0.36f, 1.0f,
		0.40f, 0.18f, 0.36f, 1.0f,
		0.40f, 0.18f, 0.36f, 1.0f,
	};

	vector<unsigned int> indices
	{
		0, 1, 2,
		1, 2, 3,
	};
} planeObjectStruct;

struct 
{
	vector<float> vertices
	{
		/**Presonus device back*/
		-0.75f, -1.0f, -0.25f,
		-0.75f,  1.0f, -0.25f,
		 0.75f,  1.0f, -0.25f,
		 0.75f, -1.0f, -0.25f,

		-0.75f,  -1.0f,  0.028f,
		-0.75f,   1.0f,  0.25f,
		 0.75f,   1.0f,  0.25f,
		 0.75f,  -1.0f,  0.028f,
	};

	vector<float> colors 
	{
		/**Presonus device back*/
		 0.27f, 0.31f, 0.33f, 1.0f,    // 0 back bottom left
		 0.27f, 0.31f, 0.33f, 1.0f,    // 1 back upper left
		 0.27f, 0.31f, 0.33f, 1.0f,    // 2 back upper right
		 0.27f, 0.31f, 0.33f, 1.0f,    // 3 back bottom right

		 0.54f, 0.55f, 0.54f, 1.0f,    // 4 front bottom left
		 0.54f, 0.55f, 0.54f, 1.0f,    // 5 front upper left
		 0.54f, 0.55f, 0.54f, 1.0f,    // 6 front upper right
		 0.54f, 0.55f, 0.54f, 1.0f,    // 7 front bottom right
	};

	vector<float> colorsAlpha
	{
		/**Presonus device back*/
		0.27f, 0.31f, 0.33f, 0.0f,    // 0 back bottom left
		0.27f, 0.31f, 0.33f, 0.0f,    // 1 back upper left
		0.27f, 0.31f, 0.33f, 0.0f,    // 2 back upper right
		0.27f, 0.31f, 0.33f, 0.0f,    // 3 back bottom right



		0.54f, 0.55f, 0.54f, 0.0f,    // 4 front bottom left
		0.54f, 0.55f, 0.54f, 0.0f,    // 5 front upper left
		0.54f, 0.55f, 0.54f, 0.0f,    // 6 front upper right
		0.54f, 0.55f, 0.54f, 0.0f,    // 7 front bottom right
	};

	vector<float> textureVertices 
	{
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
	};

	vector<unsigned int> indices 
	{
		//back
		0, 1, 2,
		0, 2, 3,

		//front
		4, 5, 6,
		4, 6, 7,

		// left
		0, 1, 4,
		1, 4, 5,

		// top
		1, 2, 6,
		1, 6, 5,

		// right
		2, 3, 6,
		6, 3, 7,

		// bottom
		0, 3, 4,
		3, 4, 7
	};
} cubeObjectStruct;

struct 
{
	vector<float> vertices
	{
		-0.06f,  -0.06f,-0.12f,
		-0.06f,  -0.06f, 0.12f,
		0.06f,  -0.06f, 0.12f,
		0.06f,  -0.06f, -0.12f,

		-0.06f, 0.06f, -0.12f,
		-0.06f, 0.06f,  0.12f,
		0.06f, 0.06f,  0.12f,
		0.06f, 0.06f, -0.12f,
	};

	vector<float> colors
	{
		0.27f, 0.31f, 0.33f, 1.0f,    // 0 
		0.27f, 0.31f, 0.33f, 1.0f,    // 2 
		0.27f, 0.31f, 0.33f, 1.0f,   // 3
		0.27f, 0.31f, 0.33f, 1.0f,    // 1


		0.27f, 0.31f, 0.33f, 1.0f,    // 4
		0.27f, 0.31f, 0.33f, 1.0f,    // 6 
		0.27f, 0.31f, 0.33f, 1.0f,    // 7
		0.27f, 0.31f, 0.33f, 1.0f,    // 5
	};

	vector<float> textureVertices 
	{
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
	};

	vector<unsigned int> indices
	{
		0, 1, 2,
		0, 2, 3,

		4, 5, 6,
		4, 6, 7,

		0, 4, 5,
		0, 1, 5,

		1, 5, 6,
		1, 2, 6,

		2, 6, 7,
		2, 3, 7,

		0, 3, 7,
		0, 4, 7
	};
} sliderObjectStruct;

struct 
{
	vector<float> vertices
	{
		/**Presonus device back*/
		-0.366f, -0.5f, -0.5f,
		0.366f, -0.5f, -0.5f,
		-0.366f, 0.5f, -0.5f,
		0.366f, 0.5f, -0.5f,

		-0.366f, -0.5f, 0.0f,
		0.366f, -0.5f, 0.0f,
		-0.366f, 0.5f, 0.0f,
		0.366f, 0.5f, 0.0f,
	};

	vector<float> colors
	{
		/**Presonus device back*/
		0.08f, 0.09f, 0.09f, 1.0f, // 0 back lower left
		0.08f, 0.09f, 0.09f, 1.0f,    // 1 back lower right
		0.08f, 0.09f, 0.09f, 1.0f, // 2, back upper left
		0.08f, 0.09f, 0.09f, 1.0f,      //3 back upper right

		0.08f, 0.09f, 0.09f, 1.0f, // 4 front lower left
		0.08f, 0.09f, 0.09f, 1.0f,   // 5 front lower right
		0.08f, 0.09f, 0.09f, 1.0f, // 6, front upper left
		0.08f, 0.09f, 0.09f, 1.0f      //7 front upper right
	};

	vector<float> textureVertices 
	{
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
	};

	vector<unsigned int> indices = {
	/** flat front indices*/
	0, 1, 2,
	3, 2, 1,

	/** flat back indices */
	4, 5, 6,
	7, 6, 5,

	/** left side*/
	0, 4, 2,
	2, 6, 4,

	/** top side*/
	2, 3, 6,
	7, 3, 6,

	/** bottom */
	0, 1, 4,
	5, 4, 1,
	/** right side */
	1, 5, 3,
	3, 7, 5
	};
} sliderBackingObjectStruct;

struct 
{
	vector<float> vertices
	{
		 0.0f,  0.02f,   0.01f,
		 0.0f, -0.02f,   0.01f,

		-0.07f,  0.02f,   0.0f,
		-0.07f, -0.02f,   0.0f,

		 0.07f,  0.02f,   0.0f,
		 0.07f, -0.02f,   0.0f,

		-0.07f,  0.02f,   0.0f,
		-0.07f, -0.02f,   0.0,

		 0.07f,  0.02f,   0.0f,
		 0.07f, -0.02f,   0.0f,
	};

	vector<float> colors
	{
		 0.78f, 0.82f, 0.82f, 1.0f, // 0 center top front
		 0.78f, 0.82f, 0.82f, 1.0f, // 1 center bottom front 

		 0.78f, 0.82f, 0.82f, 1.0f, // 2 top left
		 0.78f, 0.82f, 0.82f, 1.0f, // 3 bottom left

		 0.78f, 0.82f, 0.82f, 1.0f, // 4 top right
		 0.78f, 0.82f, 0.82f, 1.0f, // 5 bottom right

		 0.78f, 0.82f, 0.82f, 1.0f, // 6 left top back
		 0.78f, 0.82f, 0.82f, 1.0f, // 7 left bottom back

		 0.78f, 0.82f, 0.82f, 1.0f, // 8 right top back
		 0.78f, 0.82f, 0.82f, 1.0f, // 9 right bottom back
	};

	vector<float> textureVertices 
	{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 1.0f,
	};

	vector<unsigned int> indices
	{
		// front face *Check
		0, 2, 3,
		0, 3, 1,
		0, 4, 5,
		0, 5, 1,

		// back face * check
		6, 7, 8,
		7, 8, 9,

		//fill space
		3, 5, 1,
		2, 4, 0,

		// top face *check
		2, 4, 8,
		2, 6, 8,

		// bottom face * check
		3, 5, 7,
		5, 9, 7,

		//left face
		2, 3, 6,
		3, 7, 6,

		//right face
		4, 5, 8,
		8, 5, 9
	};

} buttonArrayObjectStruct;

struct {


} speakerObjectStruct;

struct {


} keyboardObjectStruct;

struct {


} focusriteObjectStruct;

struct {/** Triangle Vertices Array, takes constexpr size_t to avoid hardcoding class constructors */
vector<float> vertices 
{
     // Vertex Positions (x,y,z)    // Colors (r,g,b,a)
     0.5f, -0.5f, -0.5f,           
    -0.5f, -0.5f, -0.5f,            
    -0.5f, -0.5f,  0.5f,            
     0.5f, -0.5f,  0.5f,           
     0.0f,  0.5f,  0.0f,           
};

vector<float> colors 
{
	0.109f, 0.0f,   0.698f, 1.0f,
	 0.389f, 0.964f, 0.922f, 1.0f,
	 0.968f, 0.0f,   0.988f, 1.0f,
	 0.984f, 0.964f, 0.207f, 1.0f,
	  0.684f, 0.690f, 0.694f, 1.0f,
};

vector<float> textureVertices{

};

vector<unsigned int> indices 
{
     0, 1, 2,
     2, 3, 0,
     4, 0, 1,
     4, 3, 2,
     4, 2, 1,
     4, 3, 0
};


} pyramidObjectStruct;

std::vector<float> Cverticesmeh
{
	// cylinder bottom		// normals			// texture coords
	1.0f, 0.0f, 0.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 0.0f, -0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 0.0f, -0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 0.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 0.0f, -0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 0.0f, -0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 0.0f, -0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 0.0f, -0.94f,		0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 0.0f, -0.98f,		0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 0.0f, -1.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 0.0f, -0.98f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 0.0f, -0.94f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 0.0f, -0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 0.0f, -0.77f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 0.0f, -0.64f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 0.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 0.0f, -0.34f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 0.0f, -0.17f,	0.20f, 0.27f, 0.52f, 1.0f,
	-1.0f, 0.0f, 0.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 0.0f, 0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 0.0f, 0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 0.0f, 0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 0.0f, 0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 0.0f, 0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 0.0f, 0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 0.0f, 0.94f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 0.0f, 0.98f,		0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 0.0f, 1.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 0.0f, 0.98f,		0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 0.0f, 0.94f,		0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 0.0f, 0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 0.0f, 0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 0.0f, 0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 0.0f, 0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 0.0f, 0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 0.0f, 0.17f,		0.20f, 0.27f, 0.52f, 1.0f,

	// cylinder top			// normals			// texture coords
	1.0f, 1.0f, 0.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 1.0f, -0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 1.0f, -0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 1.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 1.0f, -0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 1.0f, -0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 1.0f, -0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 1.0f, -0.94f,		0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 1.0f, -0.98f,		0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 1.0f, -1.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 1.0f, -0.98f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 1.0f, -0.94f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 1.0f, -0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 1.0f, -0.77f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 1.0f, -0.64f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 1.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 1.0f, -0.34f,	0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 1.0f, -0.17f,	0.20f, 0.27f, 0.52f, 1.0f,
	-1.0f, 1.0f, 0.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 1.0f, 0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 1.0f, 0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 1.0f, 0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 1.0f, 0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 1.0f, 0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 1.0f, 0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 1.0f, 0.94f,		0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 1.0f, 0.98f,		0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 1.0f, 1.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 1.0f, 0.98f,		0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 1.0f, 0.94f,		0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 1.0f, 0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 1.0f, 0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 1.0f, 0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 1.0f, 0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 1.0f, 0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 1.0f, 0.17f,		0.20f, 0.27f, 0.52f, 1.0f,

	// cylinder body		// normals				// texture coords
	1.0f, 1.0f, 0.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	1.0f, 0.0f, 0.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 0.0f, -0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	1.0f, 1.0f, 0.0f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 1.0f, -0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 0.0f, -0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 0.0f, -0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 1.0f, -0.17f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 1.0f, -0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 0.0f, -0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 0.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 1.0f, -0.34f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 1.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 0.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 0.0f, -0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 1.0f, -0.5f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 1.0f, -0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 0.0f, -0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 0.0f, -0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 1.0f, -0.64f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 1.0f, -0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 0.0f, -0.77f,		0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 0.0f, -0.87f,		0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 1.0f, -0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 1.0f, -0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 0.0f, -0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 0.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 1.0f, -0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 1.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 0.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 0.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 1.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 1.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 0.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 0.0f, -1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 1.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 1.0f, -1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 0.0f, -1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 0.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 1.0f, -1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 1.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 0.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 0.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 1.0f, -0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 1.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 0.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 0.0f, -0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 1.0f, -0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 1.0f, -0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 0.0f, -0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 0.0f, -0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 1.0f, -0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 1.0f, -0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 0.0f, -0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 0.0f, -0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 1.0f, -0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 1.0f, -0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 0.0f, -0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 0.0f, -0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 1.0f, -0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 1.0f, -0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 0.0f, -0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 0.0f, -0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 1.0f, -0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 1.0f, -0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 0.0f, -0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 0.0f, -0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 1.0f, -0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 1.0f, -0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 0.0f, -0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-1.0f, 0.0f, 0.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 1.0f, -0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-1.0f, 1.0f, 0.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	-1.0f, 0.0f, 0.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 0.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-1.0f, 1.0f, 0.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 1.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 0.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 0.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.98f, 1.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 1.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 0.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 0.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.94f, 1.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 1.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 0.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 0.0f, 0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.87f, 1.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 1.0f, 0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 0.0f, 0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 0.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.77f, 1.0f, 0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 1.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 0.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 0.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.64f, 1.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 1.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 0.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 0.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.5f, 1.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 1.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 0.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 0.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.34f, 1.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 1.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 0.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 0.0f, 1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	-.17f, 1.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 1.0f, 1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 0.0f, 1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 0.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	0.0f, 1.0f, 1.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 1.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 0.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 0.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.17f, 1.0f, 0.98f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 1.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 0.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 0.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	.34f, 1.0f, 0.94f, 0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 1.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 0.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 0.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	.5f, 1.0f, 0.87f, 0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 1.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 0.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 0.0f, 0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	.64f, 1.0f, 0.77f, 0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 0.0f, 0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 0.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	.77f, 1.0f, 0.64f, 0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 1.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 0.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 0.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	.87f, 1.0f, 0.5f, 0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 1.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 0.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 0.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	.94f, 1.0f, 0.34f, 0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 1.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 0.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	.98f, 1.0f, 0.17f, 0.20f, 0.27f, 0.52f, 1.0f,
	1.0f, 1.0f, 0.0f, 0.20f, 0.27f, 0.52f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.20f, 0.27f, 0.52f, 1.0f,
};

std::vector<unsigned int> Cindicesmeh
{
	0, 1, 2,
	1, 2, 3,
	2, 3, 4,
	3, 4, 5
};

/** Triangle Vertices Array, takes constexpr size_t to avoid hardcoding class constructors */
vector<float> twoTrianglesVertices 
{
	// Vertex Positions (x,y,z)    // Colors (r,g,b,a)
   -1.0f,  1.0f, 0.0f,             1.0f, 0.0f, 0.0f, 1.0f,
   -1.0f,  0.0f, 0.0f,             0.0f, 0.0f, 1.0f, 1.0f,
   -0.5f,  0.0f, 0.0f,             0.0f, 1.0f, 0.0f, 1.0f,
	0.0f,  0.0f, 0.0f,             1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, -1.0f, 0.0f,             0.0f, 1.0f, 0.0f, 1.0f
};

/** Index Reference of Triangles and colors duplicat numbers means the vertice is used twice */
vector<unsigned int> twoTrianglesIndices
{
	 0, 1, 2,
	 3, 2, 4
};

/**************** For Experimental BuildCircle and Normalization functions ****/
std::vector<float> C1vertices;
std::vector<unsigned int> C1indices;
std::vector<unsigned int> Cindices;
std::vector<float> C2vertices;
std::vector<unsigned int> C2indices;
std::vector<unsigned int> C2ndices;