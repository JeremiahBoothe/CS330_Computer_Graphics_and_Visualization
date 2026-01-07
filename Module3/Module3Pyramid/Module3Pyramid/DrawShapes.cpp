/**
* The purpose of this program is to display cube perspective(also with polygon mode). It is also representative of the work put in to move toward a reusable object class and to minimize how much change over there is from one shape to another. It is still a work in progress, and a bit messy but also a little more organized for my sanity, as the one page of code is a bit tiresome to scroll through over and over again to find a singe line.
* @author Jeremiah Boothe
* @date 1/29/2024
*/

#include "DrawShapes.h"
#include "MeshDimensions.h"

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


    //&&&&&&&&&&&&&&&& Begin Two Triangles &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//
    //const char* triVertShaden = TriangleShaderScripts.triVertShader;
    //const char* triFragShaden = TriangleShaderScripts.triFragShader;        
    //ShapeObject shape = ShapeObject(twoTrianglesVertices, twoTrianglesIndices, triVertShaden, triFragShaden);
    //&&&&&&&&&&&&&&&& End Two Triangles &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//


    //%%%%%%%%%%%%%%%% Begin Pyramid ShapeObject %%%%%%%%%%%%%%%%%%%%%%%%%//
    const char* pyrVertShaden = PyramidShaderScripts.pyrVertShader;
    const char* pyrFragShaden = PyramidShaderScripts.pyrFragShader;

    ShapeObject pyramidObject = ShapeObject(pyramidVertices, pyramidIndices, pyrVertShaden, pyrFragShaden);
    //%%%%%%%%%%%%%%%% End Pyramid ShapeObject %%%%%%%%%%%%%%%%%%%%%%%%%%%//

    ShapeObject& shape = UCreateShaderProgram(pyramidObject);


    //####################################################################//
    //################## End Shape Create Bind ###########################//
    //####################################################################//
  


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* To capture the escape exit instead of manually closing */
        UProcessInput(window);

        /* Render Shape in window */
        URenderShape(shape, window);
    
        /* Poll for and process events and wait for the cows to come home */
        glfwPollEvents();
    }

    glfwTerminate();

    exit(0);
    return 0;
}

void URenderShape(ShapeObject Shape, GLFWwindow* window)
{

    // Enable z-depth
    glEnable(GL_DEPTH_TEST);

    /**POLYGON MODE ON OFF*/
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    /* Render here */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 1. Scales the object by 2
    glm::mat4 scale = glm::scale(glm::vec3(2.62f, 3.5f, 2.3f));

    // 2. Rotates shape by 15 degrees in the x axis - I fixed this, the original function was all over the place rotation-wise. Now I can control each axis
    glm::mat4 rotation = glm::rotate(glm::radians(25.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    // 3. Place object at the origin
    glm::mat4 translation = glm::translate(glm::vec3(0.0f, 0.0f, 0.0f));

    // Model matrix: transformations are applied right-to-left order
    glm::mat4 model = translation * rotation * scale;

    // Transforms the camera: move the camera back (z axis)
    glm::mat4 view = glm::translate(glm::vec3(0.0f, 0.0f, -8.0f));

    // Creates a orthographic projection
    glm::mat4 projection = glm::perspective(1.0f, 1.0f, 1.0f, 100.0f);

    // Set the shader to be used
    glUseProgram(Shape.getShaderProgram());

    // Retrieves and passes transform matrices to the Shader program
    GLint modelLoc = glGetUniformLocation(Shape.getShaderProgram(), "model");
    GLint viewLoc = glGetUniformLocation(Shape.getShaderProgram(), "view");
    GLint projLoc = glGetUniformLocation(Shape.getShaderProgram(), "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activates the VBOs contained within the Shape Object.
    glBindVertexArray(Shape.getVao());

    //glDrawArrays(GL_TRIANGLES, 0, 16);
    glDrawElements(GL_TRIANGLES, sizeof(Shape.getIndices()), GL_UNSIGNED_INT, nullptr);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

}

ShapeObject& UCreateShaderProgram(ShapeObject &shape)
{
    const GLuint floatsPerVertex = 3;
    const GLuint floatsPerColor = 4;

    glGenVertexArrays(1, shape.getVaoPtr()); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(shape.getVao());

    // Create 2 buffers: first one for the vertex data; second one for the indices
    glGenBuffers(2, shape.getVboPtr());
    glBindBuffer(GL_ARRAY_BUFFER, shape.getVbo()); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(shape.getVertices()), &shape.getVertices(), GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    //mesh.nIndices = sizeof(indices) / sizeof(indices[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shape.getVbo1());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(shape.getIndices()), &shape.getIndices(), GL_STATIC_DRAW);

    // Strides between vertex coordinates is 6 (x, y, z, r, g, b, a). A tightly packed stride is 0.
    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerColor);// The number of floats before each

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, floatsPerColor, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(1);

    unsigned int shaderProgram = runShader::CreateShader(
        shape.getVertexShader(),
        shape.getFragmentShader());

    shape.setShaderProgram(shaderProgram);

    return shape;
}

void UProcessInput(GLFWwindow* window)
{
    static const float cameraSpeed = 2.5f;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}