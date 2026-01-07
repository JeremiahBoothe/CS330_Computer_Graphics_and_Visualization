/**
* The Purpose of this program is to demonstrate one of the objects for the project.
* @Author Jeremiah Boothe
* @Date 2/4/2024
*/

#include "DrawShapes.h"

int main(int argc, char* argv[])
{
    //Map to store ShapeObjects
    Shapes ShapeMap;

    //Initialize the program to pass arguments to the window
    if (!UInitialize(argc, argv, &window))
        return EXIT_FAILURE;

    // Create series of shapes to be rendered, and place them in the map for reference
    {
        UCreateShape("buttonArray", ShapeMap, buttonArrayVerts, buttonArrayIndices, colorShader1.vertShader, colorShader1.fragShader);

        UCreateShape("cubeObject", ShapeMap, cubeVertices, cubeIndices, colorShader1.vertShader, colorShader1.fragShader);

        UCreateShape("sliderObject", ShapeMap, cubeVertices, cubeIndices, colorShader1.vertShader, colorShader1.fragShader);

        UCreateShape("sliderBacking", ShapeMap, sliderBackerVertices, sliderBackerIndices, colorShader1.vertShader, colorShader1.fragShader);

        UCreateShape("tablePlane", ShapeMap, planeVertices, planeIndices, colorShader1.vertShader, colorShader1.fragShader);

        UCreateShape("cylinderObject", ShapeMap, cylinderVertices, cylinderIndices, colorShader1.vertShader, colorShader1.fragShader);
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        gDeltaTime = currentFrame - gLastFrame;
        gLastFrame = currentFrame;

        // Process User Input in window
        UProcessInput(window);

        // Render Shape Objects to window
        URenderShape(ShapeMap, window);

        glfwPollEvents();
    }
    
    //Cleans out the Shape Map of all objects and their buffers and shader programs.
    ShapeMap.clear();
    
    glfwTerminate();
     
    exit(0);
    return 0;
}


//Initializes window
bool UInitialize(int, char* [], GLFWwindow** window) {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // GLFW: window creation
     * window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (*window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(*window);
    glfwSetFramebufferSizeCallback(*window, UResizeWindow);
    glfwSetCursorPosCallback(*window, UMousePositionCallback);
    glfwSetScrollCallback(*window, UMouseScrollCallback);
    glfwSetMouseButtonCallback(*window, UMouseButtonCallback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // GLEW: initialize
    // Note: if using GLEW version 1.13 or earlier
    glewExperimental = GL_TRUE;
    GLenum GlewInitResult = glewInit();

    if (GLEW_OK != GlewInitResult)
    {
        std::cerr << glewGetErrorString(GlewInitResult) << std::endl;
        return false;
    }

    // Displays GPU OpenGL version
    cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl;
    return true;
}

void UResizeWindow(GLFWwindow* window, int width, int height) {

    glViewport(0, 0, width, height);

}

void UProcessInput(GLFWwindow * window) 
{
    static const float cameraSpeed = 3.5f;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, gDeltaTime);
}

void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}

void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    switch (button)
    {
    case GLFW_MOUSE_BUTTON_LEFT:
    {
        if (action == GLFW_PRESS)
            cout << "Left mouse button pressed" << endl;
        else
            cout << "Left mouse button released" << endl;
    }
    break;

    case GLFW_MOUSE_BUTTON_MIDDLE:
    {
        if (action == GLFW_PRESS)
            cout << "Middle mouse button pressed" << endl;
        else
            cout << "Middle mouse button released" << endl;
    }
    break;

    case GLFW_MOUSE_BUTTON_RIGHT:
    {
        if (action == GLFW_PRESS)
            cout << "Right mouse button pressed" << endl;
        else
            cout << "Right mouse button released" << endl;
    }
    break;

    default:
        cout << "Unhandled mouse button event" << endl;
        break;
    }
}

void UCreateShape(std::string name, Shapes& ShapeMap, vector<float> vertices, vector<unsigned int> indices, const char* vertShader, const char* fragShader) {

    // Creates objects and places them into the map as unique pointers.
    auto shape = std::make_unique<ShapeObject>(vertices, indices, vertShader, fragShader);
    ShapeMap.insert({ name ,std::move(shape) });

    const GLuint floatsPerVertex = 3;
    const GLuint floatsPerColor = 4;

    glGenVertexArrays(1, ShapeMap.at(name)->getVaoPtr()); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(ShapeMap.at(name)->getVao());

    // Create 2 buffers: first one for the vertex data; second one for the indices
    glGenBuffers(2, ShapeMap.at(name)->getVboPtr());
    glBindBuffer(GL_ARRAY_BUFFER, ShapeMap.at(name)->getVbo()); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getVertices().size(), ShapeMap.at(name)->getVertices().data(), GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    //mesh.nIndices = sizeof(indices) / sizeof(indices[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ShapeMap.at(name)->getIbo());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getIndices().size(), ShapeMap.at(name)->getIndices().data(), GL_STATIC_DRAW);

    // Strides between vertex coordinates is 6 (x, y, z, r, g, b, a). A tightly packed stride is 0.
    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerColor);// The number of floats before each

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, floatsPerColor, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(1);

    unsigned int shaderProgram = runShader::CreateShader(
        ShapeMap.at(name)->getVertexShader(),
        ShapeMap.at(name)->getFragmentShader());

    ShapeMap.at(name)->setShaderProgram(shaderProgram);
}

void URenderShape(Shapes& ShapeMap, GLFWwindow* window) {

    // Values for button array
    const int nrows = 4;
    const int ncols = 6;
    const int nlevels = 1;

    const float xsize = 0.25f;
    const float ysize = 0.35f;
    const float zsize = 0.0f;
    
    // Enable z-depth
    glEnable(GL_DEPTH_TEST);

    // Uncomment for polygon mode 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear the frame and z buffers
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // camera/view transformation
    glm::mat4 view = camera.GetViewMatrix();

    // Creates a perspective projection
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
    
    // iterates through the map, uses the object name as a pointer reference to retrieve value stored in the object. Allows for use of different shader programs for different objects.
    for (const auto& pair : ShapeMap) {
        const std::string& name = pair.first;
        // sets 2 arrays of buttons, one 3x6 and one 1x5 to make room for the knob
        if (name == "buttonArray") {

            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc2 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc2 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc2 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(0.0727f, 0.0727f, 0.0727f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            // Array 3x6
            for (int i = 1; i < nrows; i++)
            {
                for (int j = 0; j < ncols; ++j)
                {
                    for (int k = 0; k < nlevels; ++k)
                    {
                        glm::vec3 location = glm::vec3(i * xsize, j * ysize, (k * zsize) - 1.05f);
                        // 3. Place object at the origin
                        glm::mat4 translation = glm::translate(location);
                        // Model matrix: transformations are applied right-to-left order
                        glm::mat4 model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model));

                        // Draws the triangles
                        //glDrawArrays(GL_TRIANGLES, 0,  4 * sizeof(shape.getVertices().size()));

                        glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
                    }
                }
            };

            // array 1x5
            for (int i = 0; i < 1; i++)
            {
                for (int j = 0; j < (ncols-1); ++j)
                {
                    for (int k = 0; k < nlevels; ++k)
                    {
                        glm::vec3 location = glm::vec3(i * xsize, j * ysize, (k * zsize) - 1.05f);
                        // 3. Place object at the origin
                        glm::mat4 translation = glm::translate(location);
                        // Model matrix: transformations are applied right-to-left order
                        glm::mat4 model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model));

                        // Draws the triangles
                        //glDrawArrays(GL_TRIANGLES, 0,  4 * sizeof(shape.getVertices().size()));

                        glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
                    }
                }
            };
        };
        
        // Base CubeObject
        if (name == "cubeObject") {

            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc3 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc3 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc3 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc3, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc3, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object
            glm::mat4 scale = glm::scale(glm::vec3(2.3f, 2.3f, 1.5f));
            // 2. Rotates shape
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.1f, 0.90f,-1.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            //glDrawArrays(GL_TRIANGLES, 0,  4 * sizeof(shape.getVertices().size()));

            glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };    

        // Fader Slider Object
        if (name == "sliderObject") {
            
            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc4, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc4, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(0.1f, 0.2f, 0.2f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glm::vec3 location = glm::vec3(-0.45f, 1.0f, -0.88f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc4, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            //glDrawArrays(GL_TRIANGLES, 0,  4 * sizeof(shape.getVertices().size()));

            glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };

        if (name == "sliderBacking") {

            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc5 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc5 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc5 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc5, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc5, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(0.05f, 1.7f, 0.2f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glm::vec3 location = glm::vec3(-0.45f, 0.85f, -0.99f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc5, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            //glDrawArrays(GL_TRIANGLES, 0,  4 * sizeof(shape.getVertices().size()));

            glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };

        // Table Plane
        if (name == "tablePlane") {

            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc6, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc6, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(4.0f, 4.0f, 4.0f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.0f, 0.5f, 2.24f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            //glDrawArrays(GL_TRIANGLES, 0,  4 * sizeof(shape.getVertices().size()));

            glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };


        if (name == "cylinderObject") {

            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc7 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc7 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc7 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc7, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc7, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(0.05f, 0.05f, .19f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        
            glm::vec3 location = glm::vec3(0.0f, 1.75f, -.8f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc7, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            //glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getVertices().size());

            glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };
    }

    // Deactivate the Vertex Array Object
    glBindVertexArray(0);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    glfwSwapBuffers(window);    // Flips the the back buffer with the front buffer every frame
}