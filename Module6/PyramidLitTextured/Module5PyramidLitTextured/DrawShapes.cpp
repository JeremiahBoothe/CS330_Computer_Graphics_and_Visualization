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

    {  // pyramidObject
        UCreateShape("PyramidObject",
            ShapeMap,
            pyramidObjectStruct.vertices,
            pyramidObjectStruct.normals,
            pyramidObjectStruct.indices,
            pyramidObjectStruct.textureVertices,
            lotsOfLightsShader.vertexShaderSource,
            lotsOfLightsShader.fragmentShaderSource,
            texturesStruct.pyramidTexture,
            TextureId);
    }

    {  // pyramidObject
        UCreateShape("lightPyramid",
            ShapeMap,
            pyramidObjectStruct.vertices,
            pyramidObjectStruct.normals,
            pyramidObjectStruct.indices,
            pyramidObjectStruct.textureVertices,
            lampShaders.lampVertexShaderSource,
            lampShaders.lampFragmentShaderSource,
            texturesStruct.pyramidTexture,
            TextureId);
    }
    {  // pyramidObject
        UCreateShape("lightPyramid2",
            ShapeMap,
            pyramidObjectStruct.vertices,
            pyramidObjectStruct.normals,
            pyramidObjectStruct.indices,
            pyramidObjectStruct.textureVertices,
            lampShaders.lampVertexShaderSource,
            lampShaders.lampFragmentShaderSource,
            texturesStruct.pyramidTexture,
            TextureId);
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
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

void UCreateShape(std::string name, 
    Shapes& ShapeMap, 
    vector<float> vertices, 
    vector<float> colors,
    vector<unsigned int> indices,
    vector<float> textures,
    const char* vertShader, 
    const char* fragShader,
    const char* filename,
    GLuint textureId) 
{
    vector<float> tempVertices = buildCombinedVector(vertices, colors, indices, textures);

    // Creates objects and places them into the map as unique pointers.
    auto shape = std::make_unique<ShapeObject>(tempVertices, indices, vertShader, fragShader);
    ShapeMap.insert({ name ,std::move(shape) });

    // Calculate Stride for (x,y,z,r,g,b,a,u,v)
    const GLuint floatsPerVertex = 3;
    const GLuint floatsPerNormal = 3;
    const GLuint floatsPerUV = 2;
    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerUV + floatsPerNormal);

    UCreateTexture(filename, textureId, ShapeMap, name);

    glGenVertexArrays(1, ShapeMap.at(name)->getVaoPtr()); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(ShapeMap.at(name)->getVao());

    // Create 2 buffers: first one for the vertex data; second one for the indices
    glGenBuffers(2, ShapeMap.at(name)->getVboPtr());
    glBindBuffer(GL_ARRAY_BUFFER, ShapeMap.at(name)->getVbo()); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getVertices().size(), ShapeMap.at(name)->getVertices().data(), GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ShapeMap.at(name)->getIbo());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getIndices().size(), ShapeMap.at(name)->getIndices().data(), GL_STATIC_DRAW);

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
    glEnableVertexAttribArray(2);

    unsigned int shaderProgram = runShader::CreateShader(
        ShapeMap.at(name)->getVertexShader(),
        ShapeMap.at(name)->getFragmentShader());

    ShapeMap.at(name)->setShaderProgram(shaderProgram);
}

void URenderShape(Shapes& ShapeMap, GLFWwindow* window) 
{

    // Lamp orbits around the origin
    const float angularVelocity = glm::radians(45.0f);
    if (gIsLampOrbiting)
    {
        glm::vec4 newPosition = glm::rotate(angularVelocity * gDeltaTime, glm::vec3(0.0f, 0.125f, 0.0f)) * glm::vec4(gLightPosition, 1.0f);
        gLightPosition.x = newPosition.x;
        gLightPosition.y = newPosition.y;
        gLightPosition.z = newPosition.z;
    }
    // Values for button array
    const int nrows = 4;
    const int ncols = 1;
    const int nlevels = 4;

    const float xsize = 0.25f;
    const float ysize = 0.35f;
    const float zsize = 0.35f;
   
    // Enable z-depth
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // Uncomment for polygon mode 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear the frame and z buffers
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLint modelLoc{};
    GLint viewLoc{};
    GLint projLoc{};
    GLint UVScaleLoc{};
        
    glm::mat4 view = camera.GetViewMatrix();

    glm::mat4 projection;
    // camera/view transformation

    glm::mat4 model = glm::translate(gCubePosition) * glm::scale(gCubeScale);

    // Creates a perspective projection
    if (camera.CameraProjectionMode == PERSPECTIVE)    
        projection = glm::perspective(glm::radians(camera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 1000.0f);
    else
        projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);
    
    // iterates through the map, uses the object name as a pointer reference to retrieve value stored in the object. Allows for use of different shader programs for different objects.
    for (const auto& pair : ShapeMap) 
    {
        const std::string& name = pair.first;

        // Table Plane
        if (name == "PyramidObject") 
        {
            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());
            
            // Retrieves and passes transform matrices to the Shader program
            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            // Reference matrix uniforms from the Cube Shader program for the cub color, light color, light position, and camera position
            GLint objColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint viewPosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientCSTrength");
            GLint ambColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint light3ColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light3Color");
            GLint light3PosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light3Position");
            GLint specInt1Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");

            //glUniform4f(objColLoc, 0.0f, 0.0f, 0.0f, 1.0f);
            glUniform3f(objColLoc, gObjectColor.r, gObjectColor.g, gObjectColor.b);
            glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc, 0.05f);
            //set ambient color
            glUniform3f(light1ColLoc, 0.1f, 0.8f, 0.3f);
            glUniform3f(light1PosLoc, -25.0f, 5.0f, -20.0f);
            glUniform3f(light2ColLoc, 0.8f, 0.3f, 0.1f);
            glUniform3f(light2PosLoc, 25.0f, 5.0f, 20.0f);
            //set specular intensity
            glUniform1f(specInt1Loc, 1.0f);
            glUniform1f(specInt2Loc, 0.1f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc, 8.0f);
            glUniform1f(highlghtSz2Loc, 16.0f);
            //glUniform3f(light1ColLoc, gLightColor.r, gLightColor.g, gLightColor.b);
            //glUniform3f(light1PosLoc, gLightPosition.x, gLightPosition.y, gLightPosition.z);
            const glm::vec3 cameraPosition = camera.Position;
            glUniform3f(viewPosLoc, cameraPosition.x, cameraPosition.y, cameraPosition.z);

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
        };
        // Table Plane
        if (name == "lightPyramid")
        {
            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(0.1f, 0.1f, 0.1f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(25.0f, 2.5f, 20.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            model = translation * rotation * scale;

            // Reference matrix uniforms from the Lamp Shader program
            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            // Pass matrix data to the Lamp Shader program's matrix uniforms
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
        };

        if (name == "lightPyramid2")
        {
            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            // Pass matrix data to the Lamp Shader program's matrix uniforms
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            glm::mat4 scale = glm::scale(glm::vec3(0.1f, 0.1f, 0.1f));
            // 2. Rotates shape by 15 degrees in the x axis
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::vec3 location = glm::vec3(25.0f, 2.5f, 20.0f);
            // 3. Place object at the origin
            glm::mat4 translation = glm::translate(location);
            // Model matrix: transformations are applied right-to-left order
            model = translation * rotation * scale;
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            // Draws the triangles
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
        };
    };
    // Deactivate the Vertex Array Object
    glBindVertexArray(0);
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    glfwSwapBuffers(window);    // Flips the the back buffer with the front buffer every frame
}

bool UCreateTexture(const char* filename, GLuint& textureId, Shapes& ShapeMap, std::string name)
{
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    if (image)
    {
        flipImageVertically(image, width, height, channels);

        glGenTextures(1, ShapeMap.at(name)->getTextureIdPtr());
        glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

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

//Initializes window
bool UInitialize(int, char* [], GLFWwindow** window) 
{
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

void UResizeWindow(GLFWwindow* window, int width, int height) 
{

    glViewport(0, 0, width, height);
}

void UProcessInput(GLFWwindow* window)
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
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) 
    {
        if (!pKeyPressed) 
        {
            camera.ToggleProjectionMode();
            pKeyPressed = true;  // Set the flag to indicate 'P' was pressed
        }
    }
    else 
    {
        pKeyPressed = false; // Reset the flag when 'P' is released
    }
}

void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = static_cast<float>(xpos);
        lastY = static_cast<float>(ypos);
        firstMouse = false;
    }

    float xoffset = static_cast<float>(xpos) - lastX;
    float yoffset = lastY - static_cast<float>(ypos); // reversed since y-coordinates go from bottom to top

    lastX = static_cast<float>(xpos);
    lastY = static_cast<float>(ypos);

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
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

vector<float> buildCombinedVector(vector<float> vecVerts, 
    vector<float> vecColors, 
    vector<unsigned int> indices, 
    vector<float> vecTextures) 
{
    vector<float> tempVertices;
    vector<float> drawVertices;

    unsigned int vecvertSize = static_cast<unsigned int>(vecVerts.end() - vecVerts.begin());
    unsigned int veccolorSize = static_cast<unsigned int>(vecColors.end() - vecColors.begin());
    unsigned int vectextSize = static_cast<unsigned int>(vecTextures.end() - vecTextures.begin());
    unsigned int totalSize = (vecvertSize + veccolorSize + vectextSize);

    tempVertices.reserve(totalSize);

    unsigned int p1_index = 0U;
    unsigned int p2_index = 0U;
    unsigned int p3_index = 0U;

    for (unsigned int i = 0U; i < totalSize; i += 8U) 
    {
        tempVertices.push_back(vecVerts[p1_index]);
        tempVertices.push_back(vecVerts[p1_index + 1]);
        tempVertices.push_back(vecVerts[p1_index + 2]);
        tempVertices.push_back(vecColors[p2_index]);
        tempVertices.push_back(vecColors[p2_index + 1]);
        tempVertices.push_back(vecColors[p2_index + 2]);
        tempVertices.push_back(vecTextures[p3_index]);
        tempVertices.push_back(vecTextures[p3_index + 1]);

        p1_index += 3U;
        p2_index += 3U;
        p3_index += 2U;
    }

    unsigned int tempDrawVertSize = static_cast<unsigned int>(indices.end() - indices.begin()) * 8U;

    drawVertices.reserve(tempDrawVertSize);

    for (unsigned int j = 0; j < (indices.end() - indices.begin()); j++) 
    {
        unsigned int index = indices[j]; // Assuming 'indices' is another vector containing indices

        drawVertices.push_back(tempVertices[index * 8]);
        drawVertices.push_back(tempVertices[(index * 8) + 1]);
        drawVertices.push_back(tempVertices[(index * 8) + 2]);
        drawVertices.push_back(tempVertices[(index * 8) + 3]);
        drawVertices.push_back(tempVertices[(index * 8) + 4]);
        drawVertices.push_back(tempVertices[(index * 8) + 5]);
        drawVertices.push_back(tempVertices[(index * 8) + 6]);
        drawVertices.push_back(tempVertices[(index * 8) + 7]);

    };

    return drawVertices;
};