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
        /*
        UCreateShape("pyramidObject",
            ShapeMap,
            pyramidVertices,
            pyramidColors, 
            pyramidIndices, 
            colorShader1.vertShader,
            colorShader1.fragShader);
            */

        UCreateShape("buttonArray",
            ShapeMap, 
            buttonArrayObjectStruct.vertices, 
            buttonArrayObjectStruct.colors,
            buttonArrayObjectStruct.indices, 
            buttonArrayObjectStruct.textureVertices, 
            colorShader1.vertShader,
            colorShader1.fragShader);

        UCreateShape("cubeObject", 
            ShapeMap,
            cubeObjectStruct.vertices,
            cubeObjectStruct.colors,
            cubeObjectStruct.indices,            
            cubeObjectStruct.textureVertices,            
            colorShader1.vertShader,
            colorShader1.fragShader);

        UCreateShape("sliderObject", 
            ShapeMap, 
            sliderObjectStruct.vertices,
            sliderObjectStruct.colors,
            sliderObjectStruct.indices,   
            sliderObjectStruct.textureVertices,
            colorShader1.vertShader, 
            colorShader1.fragShader);

        UCreateShape("sliderBacking",
            ShapeMap, 
            sliderBackingObjectStruct.vertices,
            sliderBackingObjectStruct.colors,
            sliderBackingObjectStruct.indices, 
            sliderBackingObjectStruct.textureVertices,
            colorShader1.vertShader, 
            colorShader1.fragShader);

        UCreateShape("tablePlane", 
            ShapeMap, 
            basicCubeObjectStruct.vertices,
            basicCubeObjectStruct.colors,
            basicCubeObjectStruct.indices,
            basicCubeObjectStruct.textureVertices,
            textureShader.vertShader, 
            textureShader.fragShader);

        UCreateShape("monitor1",
            ShapeMap,
            planeObjectStruct.vertices,
            planeObjectStruct.colorsPink,
            planeObjectStruct.indices, 
            planeObjectStruct.textureVertices,
            colorShader1.vertShader,
            colorShader1.fragShader);

        UCreateShape("monitor2",
            ShapeMap,
            planeObjectStruct.vertices,
            planeObjectStruct.colorsGreen,
            planeObjectStruct.indices,
            planeObjectStruct.textureVertices,
            colorShader1.vertShader,
            colorShader1.fragShader);

        UCreateShape("tablePlane2",
            ShapeMap,
            basicCubeObjectStruct.vertices,
            basicCubeObjectStruct.colors,
            basicCubeObjectStruct.indices,
            basicCubeObjectStruct.textureVertices,
            textureShader.vertShader,
            textureShader.fragShader);

        UCreateShape("speakers",
            ShapeMap,
            basicCubeObjectStruct.vertices,
            basicCubeObjectStruct.colorsSteelBlack,
            basicCubeObjectStruct.indices,
            basicCubeObjectStruct.textureVertices,
            colorShader1.vertShader,
            colorShader1.fragShader);

        UCreateShape("cylinderObject", 
            ShapeMap, 
            cylinderObjectStruct.vertices, 
            cylinderObjectStruct.colors, 
            cylinderObjectStruct.indices, 
            cylinderObjectStruct.textureVertices, 
            colorShader1.vertShader, 
            colorShader1.fragShader);

        UCreateShape("cylinderObject2",
            ShapeMap,
            cylinderObjectStruct.vertices,
            cylinderObjectStruct.colors,
            cylinderObjectStruct.indices,
            cylinderObjectStruct.textureVertices,
            colorShader1.vertShader,
            colorShader1.fragShader);
    }

   
    const char* texFilename = "texture.jpg";
    if (!UCreateTexture(texFilename, TextureId))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
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
    // Check for P key to be pressed, wait until release before repeating
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
        if (!pKeyPressed) {
            camera.ToggleProjectionMode();
            pKeyPressed = true;  // Set the flag to indicate 'P' was pressed
        }
    }
    else {
        pKeyPressed = false; // Reset the flag when 'P' is released
    }
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

void UCreateShape(std::string name, 
    Shapes& ShapeMap, 
    vector<float> vertices, 
    vector<float> colors,
    vector<unsigned int> indices,
    vector<float> textures,
    const char* vertShader, 
    const char* fragShader) 
{

    vector<float> tempVertices = buildCombinedVector(vertices, colors, indices, textures);

    // Creates objects and places them into the map as unique pointers.
    auto shape = std::make_unique<ShapeObject>(tempVertices, indices, vertShader, fragShader);
    ShapeMap.insert({ name ,std::move(shape) });

    const GLuint floatsPerVertex = 3;
    const GLuint floatsPerColor = 4;
    const GLuint floatsPerUV = 2;

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
    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV);// The number of floats before each

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, floatsPerColor, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerColor)));
    glEnableVertexAttribArray(2);


    unsigned int shaderProgram = runShader::CreateShader(
        ShapeMap.at(name)->getVertexShader(),
        ShapeMap.at(name)->getFragmentShader());

    ShapeMap.at(name)->setShaderProgram(shaderProgram);

}

void URenderShape(Shapes& ShapeMap, GLFWwindow* window) {

    // Values for button array
    const int nrows = 4;
    const int ncols = 1;
    const int nlevels = 4;

    const float xsize = 0.25f;
    const float ysize = 0.35f;
    const float zsize = 0.35f;
    
    // Enable z-depth
    glEnable(GL_DEPTH_TEST);

    // Uncomment for polygon mode 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear the frame and z buffers
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 view = camera.GetViewMatrix();

    glm::mat4 projection;
    // camera/view transformation

    // Creates a perspective projection
    if (camera.CameraProjectionMode == PERSPECTIVE)    
        projection = glm::perspective(glm::radians(camera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
    else
        projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);
    
    // iterates through the map, uses the object name as a pointer reference to retrieve value stored in the object. Allows for use of different shader programs for different objects.
    for (const auto& pair : ShapeMap) {
        const std::string& name = pair.first;
        if (name == "pyramidObject") {

            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(0.0727f, 0.0727f, 0.0727f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            for (int i = 0; i < nrows; ++i)
            {
                for (int j = 0; j < ncols + 4; ++j)
                {
                    for (int k = 0; k < nlevels; ++k)
                    {
                        glm::vec3 location = glm::vec3(i  * xsize, j * ysize, k * zsize);
                        // 3. Place object at the origin
                        glm::mat4 translation = glm::translate(location);
                        // Model matrix: transformations are applied right-to-left order
                        glm::mat4 model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

                        // Draws the triangles
                        glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

                        //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
                    }
                }
            };
        };

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
            glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));


            // Array 3x6
            for (int i = 0; i < nrows; ++i)
            {
                for (int j = 0; j < ncols; ++j)
                {
                    for (int k = 0; k < nlevels; ++k)
                    {
                        glm::vec3 location = glm::vec3(i * xsize, j * ysize, k * (zsize - 0.05f));
                        // 3. Place object at the origin
                        glm::mat4 translation = glm::translate(
                            glm::translate(
                                glm::rotate(
                                    glm::radians(6.4f), 
                                    glm::vec3(1.0f, 0.0f, 0.0f)), location), 
                                    glm::vec3(-0.2f, 0.39f,-0.45f));
                        // Model matrix: transformations are applied right-to-left order
                        glm::mat4 model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model));
                        // Draws the triangles
                        glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

                        //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
                    }

                }
            };
            // Array 3x6
            for (int i = 0; i < nrows + 1; ++i)
            {
                for (int j = 0; j < ncols; ++j)
                {
                    for (int k = 0; k < nlevels-3; ++k)
                    {
                        glm::vec3 location = glm::vec3(i * (xsize-.06f), j * ysize, k * zsize);
                        // 3. Place object at the origin
                        glm::mat4 translation = glm::translate(
                            glm::translate(
                                glm::rotate(
                                    glm::radians(6.4f), 
                                    glm::vec3(1.0f, 0.0f, 0.0f)), 
                                location), 
                            glm::vec3(-0.2f, 0.39f, 0.75f));

                        // Model matrix: transformations are applied right-to-left order
                        glm::mat4 model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model));
                        // Draws the triangles
                        glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

                        //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
                    }

                }
            };
            // Array 3x6
            for (int i = 0; i < nrows -1; ++i)
            {
                for (int j = 0; j < ncols; ++j)
                {
                    for (int k = 0; k < nlevels - 3; ++k)
                    {
                        glm::vec3 location = glm::vec3(i * xsize, j * ysize, k * zsize);
                        // 3. Place object at the origin
                        glm::mat4 translation = glm::translate(glm::translate(glm::rotate(glm::radians(6.4f), glm::vec3(1.0f, 0.0f, 0.0f)), location), glm::vec3(0.05f, 0.39f, -0.7f));
                        // Model matrix: transformations are applied right-to-left order
                        glm::mat4 model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model));
                        // Draws the triangles
                        glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

                        //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
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
            glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
            // 2. Rotates shape
            glm::mat4 rotation = glm::rotate(glm::radians(-90.0f), glm::vec3(1.0, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.0f, 0.25f, 0.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0,  ShapeMap.at(name)->getIndices().size());

            //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
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
            glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(6.4f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(-0.5f, 0.46f, 0.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc4, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

            //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
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
            glm::mat4 rotation = glm::rotate(glm::radians(96.4f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(-0.5f, 0.29f, 0.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc5, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

            //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };

        // Table Plane
        if (name == "speakers") {

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
            glm::mat4 scale = glm::scale(glm::vec3(0.5f, 1.2f, 0.75f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(40.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glm::vec3 location = glm::vec3(3.8f, 3.225f, -4.5f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

            //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };

        if (name == "cylinderObject2") {

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
            glm::mat4 scale = glm::scale(glm::vec3(0.35f, 0.35f, 7.0f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.0f, 2.05f, -8.8f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc7, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getVertices().size());

            //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };

        // Table Plane
        if (name == "monitor1") {

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
            glm::mat4 scale = glm::scale(glm::vec3(3.4f, 2.0f, 0.0f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.0f, 4.4f, -8.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

            //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
        };

        // Table Plane
        if (name == "monitor2") {

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

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureId);

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(3.4f, 2.0f, 0.0f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.0f, 8.35f, -8.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());

            //glDrawElements(GL_TRIANGLES, ShapeMap.at(name)->getIndices().size(), GL_UNSIGNED_INT, nullptr);
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

            GLint UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(gUVScale));


            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureId);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(4.5f, 0.025f, 1.5f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.0f, 0.0f, -0.5f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());
        };

        // Table Plane
        if (name == "tablePlane2") {

            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc6, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc6, 1, GL_FALSE, glm::value_ptr(projection));

            GLint UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(gUVScale));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureId);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            
            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(5.0f, 0.025f, 5.0f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glm::vec3 location = glm::vec3(0.0f, 2.0f, -5.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getIndices().size());
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
            glm::mat4 scale = glm::scale(glm::vec3(.05f, 0.05f, 0.25f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(93.6f), glm::vec3(1.0f, 0.0f, 0.0f));
        
            glm::vec3 location = glm::vec3(-0.2f, 0.39f, -0.7f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            glm::mat4 model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc7, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, ShapeMap.at(name)->getVertices().size());

        };
    }

    // Deactivate the Vertex Array Object
    glBindVertexArray(0);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    glfwSwapBuffers(window);    // Flips the the back buffer with the front buffer every frame
}


bool UCreateTexture(const char* filename, GLuint & textureId)
{
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    if (image)
    {
        flipImageVertically(image, width, height, channels);

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        if (channels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        else if (channels == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        else
        {
            cout << "Not implemented to handle image with " << channels << " channels" << endl;
            return false;
        }

        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(image);
        glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

        return true;
    }

    // Error loading the image
    return false;
}

// Images are loaded with Y axis going down, but OpenGL's Y axis goes up, so let's flip it
void flipImageVertically(unsigned char* image, int width, int height, int channels)
{
    for (int j = 0; j < height / 2; ++j)
    {
        int index1 = j * width * channels;
        int index2 = (height - 1 - j) * width * channels;

        for (int i = width * channels; i > 0; --i)
        {
            unsigned char tmp = image[index1];
            image[index1] = image[index2];
            image[index2] = tmp;
            ++index1;
            ++index2;
        }
    }
}


/*
void URenderShapew(ShapeObject& Shape, GLFWwindow* window)
{ 
    // Enable z-depth
    glEnable(GL_DEPTH_TEST);
    
    //POLYGON MODE ON OFF
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    // Render here
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 1. Scales the object by 2
    glm::mat4 scale = glm::scale(glm::vec3(2.6f, 3.6f, 2.6f));
    
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
    glDrawElements(GL_TRIANGLES, 4 * sizeof(Shape.getIndices().size()), GL_UNSIGNED_INT, nullptr);

    // Swap front and back buffers
    glfwSwapBuffers(window);


}*/



vector<float> buildCombinedVector(vector<float> vecVerts, vector<float> vecColors, vector<unsigned int> indices, vector<float> vecTextures) {

    vector<float> tempVertices;
    vector<float> drawVertices;

    unsigned int vecvertSize = vecVerts.end() - vecVerts.begin();
    unsigned int veccolorSize = vecColors.end() - vecColors.begin();
    unsigned int vectextSize = vecTextures.end() - vecTextures.begin();
    unsigned int totalSize = (vecvertSize + veccolorSize + vectextSize);

    tempVertices.reserve(totalSize);

    unsigned int p1_index = 0U;
    unsigned int p2_index = 0U;
    unsigned int p3_index = 0U;


    for (unsigned int i = 0U; i < totalSize; i += 9U) {
        tempVertices.push_back(vecVerts[p1_index]);
        tempVertices.push_back(vecVerts[p1_index + 1]);
        tempVertices.push_back(vecVerts[p1_index + 2]);
        tempVertices.push_back(vecColors[p2_index]);
        tempVertices.push_back(vecColors[p2_index + 1]);
        tempVertices.push_back(vecColors[p2_index + 2]);
        tempVertices.push_back(vecColors[p2_index + 3]);
        tempVertices.push_back(vecTextures[p3_index]);
        tempVertices.push_back(vecTextures[p3_index + 1]);

        p1_index += 3U;
        p2_index += 4U;
        p3_index += 2U;
    }

    unsigned int tempDrawVertSize = (indices.end() - indices.begin()) * 9;

    drawVertices.reserve(tempDrawVertSize);


    for (unsigned int j = 0; j < (indices.end() - indices.begin()); j++) {
        unsigned int index = indices[j]; // Assuming 'indices' is another vector containing indices

        drawVertices.push_back(tempVertices[index * 9]);
        drawVertices.push_back(tempVertices[(index * 9) + 1]);
        drawVertices.push_back(tempVertices[(index * 9) + 2]);
        drawVertices.push_back(tempVertices[(index * 9) + 3]);
        drawVertices.push_back(tempVertices[(index * 9) + 4]);
        drawVertices.push_back(tempVertices[(index * 9) + 5]);
        drawVertices.push_back(tempVertices[(index * 9) + 6]);
        drawVertices.push_back(tempVertices[(index * 9) + 7]);
        drawVertices.push_back(tempVertices[(index * 9) + 8]);

    };

    return drawVertices;

};


/********************* Experimental procedural generation and normalization of data ****************/
std::vector<float> normalizeData(const std::vector<float>& data) {
    // Find the minimum and maximum values in the data
    float minVal = *std::min_element(data.begin(), data.end());
    float maxVal = *std::max_element(data.begin(), data.end());

    // Calculate the range
    float range = maxVal - minVal;

    // Initialize the normalized data vector
    std::vector<float> normalizedData;

    // Normalize each element in the data
    for (float value : data) {
        float normalizedValue = 2.0 * ((value - minVal) / range) - 1.0;
        normalizedData.push_back(normalizedValue);
    }

    return normalizedData;
}

void vectorNormalize() {

    std::vector<float> inputData = { 6.8750f, 0.5f, 0.25f, 0.125f, 0.0416f, 0.0f };

    std::cout << "Original Data:" << std::endl;
    for (float value : C1vertices) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::vector<float> normalizedData = normalizeData(C1vertices);

    std::cout << "Normalized Data:" << std::endl;
    for (float value : normalizedData) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    //system("pause");
}

void buildCircle(float radius, int vCount)
{
    float angle = 360.0f / vCount;

    int triangleCount = vCount - 5  ;

    // positions
    for (int i = 0; i < vCount; i++)
    {
        float currentAngle = angle * i;
        float x = radius * cos(glm::radians(currentAngle));
        float y = radius * sin(glm::radians(currentAngle));
        float z = 0.0f;

        C1vertices.push_back(x);
        C1vertices.push_back(y);
        C1vertices.push_back(z);
        C1vertices.push_back(0.20f);
        C1vertices.push_back(0.23f);
        C1vertices.push_back(0.63f);
        C1vertices.push_back(1.0f);
        C1vertices.push_back(x);
        C1vertices.push_back(y);
        C1vertices.push_back(0.20f);
        C1vertices.push_back(0.23f);
        C1vertices.push_back(0.63f);
        C1vertices.push_back(1.0f);
    }

    // push indexes of each triangle points
    for (int i = 0; i < triangleCount; i++)
    {
        C1indices.push_back(i);
        C1indices.push_back(i + 1);
    }

};

void buildCircle2(float radius, int vCount){

    float angle = 360.0f / vCount;

    int triangleCount = vCount - 2;


    for (int i = 0; i < vCount; i++)
    {
        float currentAngle = angle * i;
        float x = radius * cos(glm::radians(currentAngle));
        float y = radius * sin(glm::radians(currentAngle));
        float z = 0.2f;

        C1vertices.push_back(x);
        C1vertices.push_back(y);
        C1vertices.push_back(z);
        C1vertices.push_back(0.20f);
        C1vertices.push_back(0.23f);
        C1vertices.push_back(0.63f);
        C1vertices.push_back(1.0f);
    }

    // push indexes of each triangle points
    for (int i = 0; i < triangleCount; i++)
    {
        C1indices.push_back(0);
        Cindices.push_back(i + 1);
        C1indices.push_back(i + 2);
    }
}

