/** 
* This program takes an array of vertices representing spacial points and color values, and
* renders them into two right angle triangles with an aesthetic color pattern.
* @author - Jeremiah Boothe
* @date - 1/20/24
*/

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

/**
* Compiler function for the shaders, handles both vertex and fragment shader.
* @param unsigned int - determines type of shader 
* @param const std::string& - the source data of the shader
*/
static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type); // creates fragment and vertex type shaders
    const char* src = source.c_str(); // points to the beginning of the data
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;

    /** Some error handling to help track down errors that might otherwise not show up */

    glGetShaderiv(id, GL_COMPILE_STATUS, &result); // query the shader id for status

    if (result == GL_FALSE) // shader did not compile successfully
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length); // query for length of log 
        char* message = (char*)alloca(length * sizeof(char)); // a bit of C level control over the stack to handle log size
        glGetShaderInfoLog(id, length, &length, message); // to read log
        std::cout 
            << "Failed to compile Shader" 
            << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") // customize error to type
            << " shader!" << std::endl;
        std::cout 
            << message 
            << std::endl;

        glDeleteShader(id); // delete shaders if there was an error
        return 0;
    }


    return id; // returns shader id
}

/**
* creates the shader from the defined vertexShader and fragmentShader scripts.
* @param const std::string& - vertexShader script passed by reference
* @param const std::string& - fragmentShader script passed by reference
* @returns unsigned int - the shader program to run with glUseProgram().
*/
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vShader = CompileShader(GL_VERTEX_SHADER, vertexShader); // Tells openGL where the vertex points should be. Passes attributes to other attributes like fragmentShader.
    unsigned int fShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader); // The pixel shader that colors in the pixels within the vertexShader constraints. 

    /** Attach shaders, link program and validate program */
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);
    glValidateProgram(program);

    /** Cleanup delete values no longer needed for compilation */
    glDeleteShader(vShader); 
    glDeleteShader(fShader);

    return program; // shader program
};

//#include <GL/glut.h>
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Jeremiah Boothe", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /** call and initialize the GLEW extension entrypoints*/
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    /** Verticies of triangles, and color mappings */
    float vertices[] = {

        /** Index 0 */
       /* Strides 3s & 4s */
       /*|------3s-------|*/
        -1.0f, 1.0f, 0.0f,       
         1.0f, 0.0f, 0.0f, 1.0f,   // red
       /*|----------4s---------|*/

         /** Index 1 */
        -1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 1.0f, 1.0f,  // blue


         /** Index 2 */
        -0.5f, 0.0f, 0.0f, 
         0.0f, 1.0f, 0.0f, 1.0f,  // green

         /** Index 3 */
         0.0f, 0.0f, 0.0f,
         1.0f, 0.0f, 0.0f, 1.0f, // red

         /** Index 4 */
         0.0f, -1.0f, 0.0f,
         0.0f, 1.0f, 0.0f, 1.0f  // green

    };

    /** Index Reference of Triangles and colors duplicat numbers means the vertice is used twice */
    unsigned int indices[] = {
        0, 1, 2,
        3, 2, 4
    };
        
    /** Generates buffers and ID's */
    unsigned int vbo, vao;
    glGenBuffers(1, &vao);
    glGenBuffers(2, &vbo);
    glGenVertexArrays(1, &vao); 
    glBindVertexArray(vao);
    
    /** Binding Buffers */
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vao);

    /** Provide data to the buffers sized and populated with indices and vertices */
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    /** Calculates stride to distinguish spacial and color vertex entries */
    const unsigned int floatsPerVertex = 3;
    const unsigned int floatsPerColor = 4;
    int stride = sizeof(float) * (floatsPerVertex + floatsPerColor);

    /** Points at attributes in the buffer object, 0 are spacial segments, 1 is the vertex segments */
    glVertexAttribPointer(0,floatsPerVertex, GL_FLOAT, GL_FALSE, stride, (void*)0);

    /** Points at attributes in the buffer object, 0 are spacial segments, 1 is the vertex segments */
    glVertexAttribPointer(1, floatsPerColor, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));

    /** Enables array attributes */
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    /** vertex shader script defining the layout of the attributes */
    std::string vertexShader =
        "#version 440 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec4 colorFromVBO;\n"
        "out vec4 colorFromVS;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   colorFromVS = colorFromVBO;\n"
        "}\n\0";

    /** fragment Shader script defining the fragment color attributes */
    std::string fragmentShader =
        "#version 440 core\n"
        "in vec4 colorFromVS;\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = colorFromVS;\n"
        "}\n\0";

    /** Initializes shader to use with openGL to finally see the triangles! */
    unsigned int shaderProgram = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shaderProgram);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
           
        /* Draw Elements pulls from index buffer and renders */
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    /** Cleanup Delete Program */
    glDeleteProgram(shaderProgram);
    
    /** Terminates glfw*/
    glfwTerminate();
 
    /** Exit Gracefully*/
    exit(0);
    return 0;
}
