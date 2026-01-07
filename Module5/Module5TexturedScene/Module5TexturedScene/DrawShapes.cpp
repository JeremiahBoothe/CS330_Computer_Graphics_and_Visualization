/**
* The Purpose of this program is to demonstrate texturing of the project, a little bit of lighting is also functioning.
* @Author Jeremiah Boothe
* @Date 2/11/2024
*/

#include "DrawShapes.h"

int main(int argc, char* argv[])
{
    //Map to store ShapeObjects
    Shapes ShapeMap;

    //Initialize the program to pass arguments to the window
    if (!UInitialize(argc, argv, &window))
        return EXIT_FAILURE;

    {       /* Creates all shapes in the scene */
        {   /* Skybox Scenery */
            UCreateSkybox("Skybox",
                ShapeMap,
                SkyBox.skyboxVertices,
                cubeObjectStruct.colors,
                cubeObjectStruct.indices,
                SkyBox.skyboxVertices,
                skyBoxShaderSource.skyboxShaderSource,
                skyBoxShaderSource.skyboxFragmentSource,
                texturesStruct.faces,
                TextureId);

            UCreateCubeMap("CubeMap",
                ShapeMap,
                SkyBox.cubeVertices,
                cubeObjectStruct.colors,
                cubeObjectStruct.indices,
                SkyBox.cubeVertices,
                cubeMapShaderShaderScript.cubeMapShaderSource,
                cubeMapShaderShaderScript.cubeMapFragmentSource,
                texturesStruct.faces,
                TextureId);
          
            UCreateShape("lighting",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colors,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                basicLighting.vertexShader,
                basicLighting.fragmentShader,
                texturesStruct.tableTexture,
                TextureId);
            
            UCreateShape("lightCube",
                ShapeMap,
                cubeObjectStruct.vertices,
                cubeObjectStruct.colors,
                cubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                basicLightCube.vertexShader,
                basicLightCube.fragmentShader,
                texturesStruct.tableTexture,
                TextureId);
        }

        {   // Desk tops, fake planes, really cubes ;O
            UCreateShape("tablePlane",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colors,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.tableTexture,
                TextureId);

            UCreateShape("tablePlane2",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colors,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.tableTexture2,
                TextureId);

            UCreateShape("keyboard",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colorsAlpha,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVerticesKeyboard,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.keyboard,
                TextureId);
        }

        { /* Presonus FaderPort */
            UCreateShape("buttonArray",
                ShapeMap,
                buttonArrayObjectStruct.vertices,
                buttonArrayObjectStruct.colors,
                buttonArrayObjectStruct.indices,
                buttonArrayObjectStruct.textureVertices,
                normals,
                textureShader.vertShader,
                textureShader.fragShader,
                texturesStruct.tableTexture2,
                TextureId);

            UCreateShape("cubeObject",
                ShapeMap,
                cubeObjectStruct.vertices,
                cubeObjectStruct.colors,
                cubeObjectStruct.indices,
                cubeObjectStruct.textureVertices,
                normals,
                colorShader.vertShader,
                colorShader.fragShader,
                texturesStruct.tableTexture,
                TextureId);

            UCreateShape("sliderObject",
                ShapeMap,
                sliderObjectStruct.vertices,
                sliderObjectStruct.colors,
                sliderObjectStruct.indices,
                sliderObjectStruct.textureVertices,
                normals,
                colorShader.vertShader,
                colorShader.fragShader,
                texturesStruct.tableTexture,
                TextureId);

            UCreateShape("sliderBacking",
                ShapeMap,
                sliderBackingObjectStruct.vertices,
                sliderBackingObjectStruct.colors,
                sliderBackingObjectStruct.indices,
                sliderBackingObjectStruct.textureVertices,
                normals,
                colorShader.vertShader,
                colorShader.fragShader,
                texturesStruct.tableTexture,
                TextureId);
            
            UCreateShape("presonusFace",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colorsAlpha,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.presonusFaceTexture,
                TextureId);
          
            UCreateShape("presonusKnob",
                ShapeMap,
                cylinderObjectStruct.vertices,
                cylinderObjectStruct.colors,
                cylinderObjectStruct.indices,
                cylinderObjectStruct.textureVertices,
                normals,
                colorShader.vertShader,
                colorShader.fragShader,
                texturesStruct.tableTexture,
                TextureId);
        }

        { /* Video Monitors */
            UCreateShape("monitor1",
                ShapeMap,
                planeObjectStruct.vertices,
                planeObjectStruct.colorsPink,
                planeObjectStruct.indices,
                planeObjectStruct.textureVertices,
                normals,
                textureShader.vertShader,
                textureShader.fragShader,
                texturesStruct.monitor1,
                TextureId);

            UCreateShape("monitor2",
                ShapeMap,
                planeObjectStruct.vertices,
                planeObjectStruct.colorsGreen,
                planeObjectStruct.indices,
                planeObjectStruct.textureVertices,
                normals,
                textureShader.vertShader,
                textureShader.fragShader,
                texturesStruct.monitor2,
                TextureId);

            UCreateShape("monitorStand",
                ShapeMap,
                cylinderObjectStruct.vertices,
                cylinderObjectStruct.colorsMatBlack,
                cylinderObjectStruct.indices,
                cylinderObjectStruct.textureVertices,
                normals,
                colorShader.vertShader,
                colorShader.fragShader,
                texturesStruct.tableTexture,
                TextureId);
        }

        { /* Speakers */
            UCreateShape("speakerRight",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colorsSteelBlack,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                colorShader.vertShader,
                colorShader.fragShader,
                texturesStruct.tableTexture,
                TextureId);

            UCreateShape("rightfrontspeakerface",
                ShapeMap,
                planeObjectStruct.vertices,
                planeObjectStruct.colorsGreen,
                planeObjectStruct.indices,
                planeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.rightfrontspeakertexture,
                TextureId);

            UCreateShape("speakerLeft",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colorsSteelBlack,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                colorShader.vertShader,
                colorShader.fragShader,
                texturesStruct.tableTexture,
                TextureId);


            UCreateShape("leftfrontspeakerface",
                ShapeMap,
                planeObjectStruct.vertices,
                planeObjectStruct.colorsGreen,
                planeObjectStruct.indices,
                planeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.rightfrontspeakertexture,
                TextureId);
        }


        { /* Focusrite Audio Interface */
            UCreateShape("focusRite",
                ShapeMap,
                basicCubeObjectStruct.focusriteVertices,
                basicCubeObjectStruct.colorsRed,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.focusriteMap,
                TextureId);


            UCreateShape("focusRiteKnobCollection",
                ShapeMap,
                cylinderObjectStruct.vertices,
                cylinderObjectStruct.colorsSilver,
                cylinderObjectStruct.indices,
                cylinderObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.chromeSwirl,
                TextureId);
        }
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
    vector<float> normals,
    const char* vertShader, 
    const char* fragShader,
    const char* filename,
    GLuint textureId) 
{
    

    if (name == "focusRite") {
        // Creates objects and places them into the map as unique pointers.
        auto shape = std::make_unique<ShapeObject>(vertices, indices, vertShader, fragShader);
        ShapeMap.insert({ name ,std::move(shape) });

    }
    if (name != "focusRite") {

        // converted these to methods that combine and then print to a text file, allowing finder control of vertices instead of relying on the round about indices to vertices which proves to be very difficult to get textures to align on.
        vector<float> tempVertices = buildCombinedVector(vertices, colors, indices, textures, normals);

        // writes output file of combined vectors in csv format with an f appended to each entry
        //outputToFile(tempVertices, name);

        // Creates objects and places them into the map as unique pointers.
        auto shape = std::make_unique<ShapeObject>(tempVertices, indices, vertShader, fragShader);
        ShapeMap.insert({ name ,std::move(shape) });
    };

    // Calculate Stride for (x,y,z,r,g,b,a,u,v,tan,bitan)
    const GLuint floatsPerVertex = 3;
    const GLuint floatsPerColor = 4;
    const GLuint floatsPerUV = 2;
    const GLuint floatsPerNormal = 2;

    // set to 0 for now to not break the work buildCombinedVector() does
    const GLuint floatsPerTangent = 0;
    const GLuint floatsPerBiTangent= 0;


    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV + floatsPerNormal + floatsPerTangent + floatsPerBiTangent);

    UCreateTexture(filename, textureId, ShapeMap, name);

    glGenVertexArrays(1, ShapeMap.at(name)->getVaoPtr()); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(ShapeMap.at(name)->getVao());

    // Create 2 buffers: first one for the vertex data; second one for the indices
    glGenBuffers(2, ShapeMap.at(name)->getVboPtr());

    glBindBuffer(GL_ARRAY_BUFFER, ShapeMap.at(name)->getVbo()); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getVertices().size(), ShapeMap.at(name)->getVertices().data(), GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ShapeMap.at(name)->getIbo());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getIndices().size(), ShapeMap.at(name)->getIndices().data(), GL_STATIC_DRAW);

    // Vertices - Attribute Pointer
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    // Color - Attribute Pointer
    glVertexAttribPointer(1, floatsPerColor, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(1);

    // Texture - Attribute Pointer
    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerColor)));
    glEnableVertexAttribArray(2);

    // Normals - Attribute Pointer
    glVertexAttribPointer(3, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV)));
    glEnableVertexAttribArray(3);

    // Tangent - Attribute Pointer - * Not fully Implemented *
    glVertexAttribPointer(4, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV + floatsPerTangent)));
    glEnableVertexAttribArray(4);

    // BiTangent - Attribute Pointer - * Not fully Implemented *
    glVertexAttribPointer(5, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV + floatsPerTangent + floatsPerBiTangent)));
    glEnableVertexAttribArray(5);

    unsigned int shaderProgram = runShader::CreateShader(
        ShapeMap.at(name)->getVertexShader(),
        ShapeMap.at(name)->getFragmentShader());

    ShapeMap.at(name)->setShaderProgram(shaderProgram);
}

void URenderShape(Shapes& ShapeMap, GLFWwindow* window) 
{
    // Values for button arrays
    const int nrows = 4;
    const int ncols = 1;
    const int nlevels = 4;
    const float xsize = 0.25f;
    const float ysize = 0.35f;
    const float zsize = 0.35f;
    
    // Enable z-depth
    glEnable(GL_DEPTH_TEST);

    // Enable Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Uncomment for polygon mode 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear the frame and z buffers
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up for camra views
    glm::mat4 projection;

    if (camera.CameraProjectionMode == PERSPECTIVE)    
        projection = glm::perspective(glm::radians(camera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 1000.0f);
    else
        projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);

    glm::mat4 view = camera.GetViewMatrix();


    /** I went off the deep end and added all the lighting I could pack into the program without blowing up my video card, which whistles when it runs the program */
    for (const auto& pair : ShapeMap) 
    {
        const std::string& name = pair.first;
       
        if (name == "tablePlane") 
        {                


            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(4.5f, 0.025f, 1.5f));
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 0.0f, -0.5f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;
            
            GLint modelLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc0, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc0, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc0, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc0, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc, 1.0f, 1.0f, 1.0f, 1.0f);
            
            glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc, 0.4f);
            //set ambient color
            glUniform3f(ambColLoc, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc, 2.0f, 5.0f, 5.0f);
            glUniform3f(light2ColLoc, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc, -2.0f, 5.0f, 5.0f);
            //set specular intensity
            glUniform1f(specInt1Loc, .9f);
            glUniform1f(specInt2Loc, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc, 12.0f);
            glUniform1f(highlghtSz2Loc, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getIndices().size()));
            glBindVertexArray(0);
        };

        if (name == "tablePlane2")
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());
            
            glm::mat4 scale = glm::scale(glm::vec3(5.0f, 0.025f, 5.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 2.0f, -5.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;
            
            GLint modelLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc0 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc0, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc0, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc0, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc0, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc, 0.4f);
            //set ambient color
            glUniform3f(ambColLoc, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc, 2.0f, 5.0f, 5.0f);
            glUniform3f(light2ColLoc, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc, -2.0f, 5.0f, 5.0f);
            //set specular intensity
            glUniform1f(specInt1Loc, .9f);
            glUniform1f(specInt2Loc, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc, 12.0f);
            glUniform1f(highlghtSz2Loc, 12.0f);
            
            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "lightCube")
        {   // Set the shader to be used
            // LearnOpenGL uses a format like shader.use();
            glUseProgram(ShapeMap.at("lighting")->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(0.5f, 0.5f, 0.5f));
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 20.0f, 0.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            glUniform3f(glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "objectColor"), 1.00f, 0.65f, 0.34f);
            glUniform3f(glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "lightColor"), 1.00f, 0.65f, 0.34f);
            glUniform3f(glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "lightPos"), lightPos.x, lightPos.y, lightPos.z);
            glUniform3f(glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "viewPos"), camera.Position.x, camera.Position.y, camera.Position.z);

            GLint modelaLoc0 = glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "model");
            GLint projecLoc0 = glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "projection");
            GLint viewwLoc0 = glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "view");

            glUniformMatrix4fv(projecLoc0, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(viewwLoc0, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(modelaLoc0, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at("lighting")->getVao());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at("lighting")->getVertices().size()));

            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            model = ::glm::mat4(1.0f);
            model = glm::translate(model, lightPos);
            model = glm::scale(model, glm::vec3(0.2f));

            // Retrieves and passes transform matrices to the Shader program
            glUniformMatrix4fv(projecLoc0, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(viewwLoc0, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(modelaLoc0, 1, GL_FALSE, glm::value_ptr(model));

            // Expanded Representation of learnOpenGL functions that follow the format of lightingShader.setVec3("lightPos", lightPos);
            // glUniform3f(glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "lightPos"), 0.0f, 10.0f, 0.0f);

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "keyboard") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(2.25f, 0.025f, 0.65f));
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 0.06f, 0.26f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;
            
            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniform2fv(UVScaleLoc1, 1, glm::value_ptr(uvScale));
            glUniformMatrix4fv(viewLoc1, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc1, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc1, 1, GL_FALSE, glm::value_ptr(model));

            glUniform4f(objColLoc1, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc1, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc1, 0.4f);
            //set ambient color
            glUniform3f(ambColLoc1, 0.25f, 0.25f, 0.25f);
            glUniform3f(light1ColLoc1, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc1, 2.0f, 5.0f, 5.0f);
            glUniform3f(light2ColLoc1, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc1, -2.0f, 5.0f, 5.0f);
            //set specular intensity
            glUniform1f(specInt1Loc1, 0.774f);
            glUniform1f(specInt2Loc1, 0.774f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc1, 12.0f);
            glUniform1f(highlghtSz2Loc1, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());
            glActiveTexture(GL_TEXTURE0);
  
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "buttonArray") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            
            GLint modelLoc3 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc3 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc3 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint UVScaleLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniform2fv(UVScaleLoc1, 1, glm::value_ptr(uvScale));
            glUniformMatrix4fv(viewLoc3, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc3, 1, GL_FALSE, glm::value_ptr(projection));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            // Array 3x6
            for (int i = 0; i < nrows; ++i)
            {
                for (int j = 0; j < ncols; ++j)
                {
                    for (int k = 0; k < nlevels; ++k)
                    {
                        glm::vec3 location = glm::vec3(i * xsize, j * ysize, k * (zsize - 0.05f));
                        glm::mat4 translation = glm::translate(
                            glm::translate(
                                glm::rotate(
                                    glm::radians(6.4f), 
                                    glm::vec3(1.0f, 0.0f, 0.0f)), location), 
                                    glm::vec3(-3.7f, 0.39f,-0.45f));
                        glm::mat4 model = translation * rotation * scale;

                        glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(model));
                        glActiveTexture(GL_TEXTURE0);

                        glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());
                        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                        
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
                        glm::mat4 translation = glm::translate(
                            glm::translate(
                                glm::rotate(
                                    glm::radians(6.4f), 
                                    glm::vec3(1.0f, 0.0f, 0.0f)), 
                                location), 
                            glm::vec3(-3.7f, 0.39f, 0.75f));
                        glm::mat4 model = translation * rotation * scale;

                        glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(model));
                        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));

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
                        glm::mat4 translation = glm::translate(glm::translate(glm::rotate(glm::radians(6.4f), glm::vec3(1.0f, 0.0f, 0.0f)), location), glm::vec3(-3.45f, 0.39f, -0.7f));
                        glm::mat4 model = translation * rotation * scale;

                        glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(model));

                        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                    }
                }
            };
          glBindVertexArray(0);              
        };

        if (name == "cubeObject") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());
            
            glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(-90.0f), glm::vec3(1.0, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(-3.5f, 0.25f, 0.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc4, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc4, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc4, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };    

        if (name == "sliderObject") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(6.4f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(-4.0f, 0.46f, 0.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc5 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc5 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc5 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc5, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc5, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc5, 1, GL_FALSE, glm::value_ptr(model));
            
            glBindVertexArray(ShapeMap.at(name)->getVao());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "sliderBacking") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(0.05f, 1.7f, 0.2f));
            glm::mat4 rotation = glm::rotate(glm::radians(96.4f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(-4.0f, 0.29f, 0.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc6, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc6, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "speakerRight") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());
            glm::mat4 scale = glm::scale(glm::vec3(0.5f, 1.2f, 0.75f));
            glm::mat4 rotation = glm::rotate(glm::radians(40.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(3.8f, 3.225f, -4.5f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc7 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc7 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc7 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc7, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc7, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc7, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at(name)->getVao());
            
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
        };

        if (name == "rightfrontspeakerface") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());
            
            glm::mat4 scale = glm::scale(glm::vec3(0.75f, 1.22f, 1.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(-50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(3.415f, 3.2f, -4.175f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");
           
            glUniform4f(objColLoc6, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc6, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc6, 0.4f);
            //set ambient color
            glUniform3f(ambColLoc6, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc6, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc6, 2.0f, 5.0f, 5.0f);
            glUniform3f(light2ColLoc6, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc6, -2.0f, 5.0f, 5.0f);
            //set specular intensity
            glUniform1f(specInt1Loc6, .9f);
            glUniform1f(specInt2Loc6, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc6, 12.0f);
            glUniform1f(highlghtSz2Loc6, 12.0f);

            glUniformMatrix4fv(viewLoc6, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc6, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc6, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "speakerLeft") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(0.5f, 1.2f, 0.75f));
            glm::mat4 rotation = glm::rotate(glm::radians(-40.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(-3.8f, 3.225f, -4.5f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc9, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc9, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc9, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "leftfrontspeakerface") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(0.75f, 1.22f, 1.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(230.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(-3.415f, 3.2f, -4.175f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc10 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc10, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc10, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc10, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc10, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc10, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc10, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc10, 0.4f);
            //set ambient color
            glUniform3f(ambColLoc10, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc10, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc10, 2.0f, 5.0f, 5.0f);
            glUniform3f(light2ColLoc10, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc10, -2.0f, 5.0f, 5.0f);
            //set specular intensity
            glUniform1f(specInt1Loc10, .9f);
            glUniform1f(specInt2Loc10, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc10, 12.0f);
            glUniform1f(highlghtSz2Loc10, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "focusRite")
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(1.0f, .25f, 0.75f));
            glm::mat4 rotation = glm::rotate(glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(-3.0f, 2.295f, -6.5f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc9 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc9, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc9, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc9, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc9, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc9, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc9, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc9, 0.6f);
            //set ambient color
            glUniform3f(ambColLoc9, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc9, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc9, 3.0f, 6.0f, 6.0f);
            glUniform3f(light2ColLoc9, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc9, -3.0f, 6.0f, 6.0f);
            //set specular intensity
            glUniform1f(specInt1Loc9, .9f);
            glUniform1f(specInt2Loc9, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc9, 12.0f);
            glUniform1f(highlghtSz2Loc9, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        // Focusrite Knobs
        if (name == "focusRiteKnobCollection")
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.125f));
            glm::mat4 rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            glm::vec3 location = glm::vec3(-2.0f, 2.41, -6.50f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc14, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc14, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc14, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc14, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc14, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc14, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc14, .8f);
            //set ambient color
            glUniform3f(ambColLoc14, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc14, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc14, 2.0f, 5.0f, 10.0f);
            glUniform3f(light2ColLoc14, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc14, -2.0f, 5.0f, 10.0f);
            //set specular intensity
            glUniform1f(specInt1Loc14, .9f);
            glUniform1f(specInt2Loc14, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc14, 12.0f);
            glUniform1f(highlghtSz2Loc14, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.175f));
            rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(-1.92f, 2.41f, -6.68f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            GLint modelLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc15 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc15, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc15, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc15, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc15, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc15, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc15, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc15, .8f);
            //set ambient color
            glUniform3f(ambColLoc15, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc15, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc15, 2.0f, 5.0f, 10.0f);
            glUniform3f(light2ColLoc15, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc15, -2.0f, 5.0f, 10.0f);
            //set specular intensity
            glUniform1f(specInt1Loc15, .9f);
            glUniform1f(specInt2Loc15, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc15, 12.0f);
            glUniform1f(highlghtSz2Loc15, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));

            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            scale = glm::scale(glm::vec3(0.135f, 0.135f, 0.125f));
            rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(-2.2f, 2.280f, -6.35f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            GLint modelLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc1, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc1, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc1, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc1, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc1, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc1, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc1, .8f);
            //set ambient color
            glUniform3f(ambColLoc1, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc1, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc1, 2.0f, 5.0f, 10.0f);
            glUniform3f(light2ColLoc1, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc1, -2.0f, 5.0f, 10.0f);
            //set specular intensity
            glUniform1f(specInt1Loc1, .9f);
            glUniform1f(specInt2Loc1, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc1, 12.0f);
            glUniform1f(highlghtSz2Loc1, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());


            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));

            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.200f));
            rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(-2.5f, 2.4f, -6.05f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            GLint modelLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc4 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc4, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc4, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc4, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc4, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc4, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc4, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc4, .8f);
            //set ambient color
            glUniform3f(ambColLoc4, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc4, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc4, 2.0f, 5.0f, 10.0f);
            glUniform3f(light2ColLoc4, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc4, -2.0f, 5.0f, 10.0f);
            //set specular intensity
            glUniform1f(specInt1Loc4, .9f);
            glUniform1f(specInt2Loc4, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc4, 12.0f);
            glUniform1f(highlghtSz2Loc4, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));

            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.200f));
            rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(-2.86f, 2.4f, -5.64f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            GLint modelLoc116 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc116 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc116 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc116, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc116, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc116, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));

            glBindVertexArray(0);
        };

        if (name == "monitorStand") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(0.35f, 0.35f, 7.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 2.05f, -8.8f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc11 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc11 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc11 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc11, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc11, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc11, 1, GL_FALSE, glm::value_ptr(model));
            
            glBindVertexArray(ShapeMap.at(name)->getVao());
            
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "monitor1") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(3.4f, 2.0f, 0.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 4.4f, -8.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc12 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc12 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc12 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint UVScaleLoc12 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc12, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc12, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc12, 1, GL_FALSE, glm::value_ptr(model));

            glUniform2fv(UVScaleLoc12, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "monitor2") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(3.4f, 2.0f, 0.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 8.35f, -8.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc13 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc13 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc13 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint UVScaleLoc6 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc13, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc13, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc13, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc6, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "presonusFace") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(0.75f, 0.0f, 1.02f));
            glm::mat4 rotation = glm::rotate(glm::radians(6.4f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(-3.5f, 0.41f, 0.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc14, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc14, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc14, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc14, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc14, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc14, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc14, 1.5f);
            //set ambient color
            glUniform3f(ambColLoc14, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc14, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc14, 2.0f, 5.0f, 10.0f);
            glUniform3f(light2ColLoc14, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc14, -2.0f, 5.0f, 10.0f);
            //set specular intensity
            glUniform1f(specInt1Loc14, .9f);
            glUniform1f(specInt2Loc14, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc14, 12.0f);
            glUniform1f(highlghtSz2Loc14, 12.0f);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "presonusKnob") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(.068f, 0.068f, 0.25f));
            glm::mat4 rotation = glm::rotate(glm::radians(93.6f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(-3.74f, 0.37f, -0.68f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint viewPosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewPosition");
            GLint ambStrLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientStrength");
            GLint ambColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "ambientColor");
            GLint light1ColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Color");
            GLint light1PosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light1Position");
            GLint light2ColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Color");
            GLint light2PosLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "light2Position");
            GLint objColLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "objectColor");
            GLint specInt1Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity1");
            GLint highlghtSz1Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize1");
            GLint specInt2Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "specularIntensity2");
            GLint highlghtSz2Loc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "highlightSize2");
            GLint UVScaleLoc14 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc14, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc14, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc14, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc14, 1, glm::value_ptr(uvScale));

            glUniform4f(objColLoc14, 1.0f, 1.0f, 1.0f, 1.0f);

            glUniform3f(viewPosLoc14, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1f(ambStrLoc14, 1.5f);
            //set ambient color
            glUniform3f(ambColLoc14, 0.2f, 0.2f, 0.2f);
            glUniform3f(light1ColLoc14, 0.8f, 0.3f, 0.1f);
            glUniform3f(light1PosLoc14, 2.0f, 5.0f, 10.0f);
            glUniform3f(light2ColLoc14, 0.1f, 0.8f, 0.3f);
            glUniform3f(light2PosLoc14, -2.0f, 5.0f, 10.0f);
            //set specular intensity
            glUniform1f(specInt1Loc14, .9f);
            glUniform1f(specInt2Loc14, .9f);
            //set specular highlight size
            glUniform1f(highlghtSz1Loc14, 12.0f);
            glUniform1f(highlghtSz2Loc14, 12.0f);
            
            glBindVertexArray(ShapeMap.at(name)->getVao());
            
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "CubeMap") 
        {
            glDepthMask(GL_FALSE);
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(1000.0f, 1000.0f, 1000.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc16 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc16 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc16 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            
            glUniformMatrix4fv(viewLoc16, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc16, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc16, 1, GL_FALSE, glm::value_ptr(model));

            glDepthFunc(GL_LEQUAL);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());
                
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glDepthFunc(GL_LESS); // set depth function back to default
            glDepthMask(GL_TRUE);
            glBindVertexArray(0);
        };

        if (name == "SkyBox") 
        {
            glDepthMask(GL_FALSE);
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            glm::mat4 scale = glm::scale(glm::vec3(1000.0f, 1000.0f, 1000.0f));
            glm::mat4 rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec3 location = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::mat4 translation = glm::translate(location);
            glm::mat4 model = translation * rotation * scale;

            GLint modelLoc17 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc17 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc17 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");

            glUniformMatrix4fv(viewLoc17, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc17, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc17, 1, GL_FALSE, glm::value_ptr(model));

            glDepthFunc(GL_LEQUAL);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glDepthFunc(GL_LESS); // set depth function back to default
            glDepthMask(GL_TRUE);
            glBindVertexArray(0);
        };

        if (name == "pyramidObject")
        {
            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            GLint modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            GLint viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            GLint projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            GLint UVScaleLoc1 = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniform2fv(UVScaleLoc1, 1, glm::value_ptr(uvScale));
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
                        glm::vec3 location = glm::vec3(i * xsize, j * ysize, k * zsize);
                        // 3. Place object at the origin
                        glm::mat4 translation = glm::translate(location);
                        // Model matrix: transformations are applied right-to-left order
                        glm::mat4 model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                        glActiveTexture(GL_TEXTURE0);


                        glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());
                        // Draws the triangles
                        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getIndices().size()));
                        glBindVertexArray(0);                    }
                }
            };
        };
    }

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

vector<float> buildCombinedVector(
    vector<float> vecVerts, 
    vector<float> vecColors, 
    vector<unsigned int> indices, 
    vector<float> vecTextures,
    vector<float> vecNormals) 
{
    vector<float> tempVertices;
    vector<float> drawVertices;

    unsigned int vecvertSize = static_cast<unsigned int>(vecVerts.end() - vecVerts.begin());
    unsigned int veccolorSize = static_cast<unsigned int>(vecColors.end() - vecColors.begin());
    unsigned int vectextSize = static_cast<unsigned int>(vecTextures.end() - vecTextures.begin());
    unsigned int vecnormSize = static_cast<unsigned int>(vecTextures.end() - vecTextures.begin());
    unsigned int totalSize = (vecvertSize + veccolorSize + vectextSize + vecnormSize);

    tempVertices.reserve(totalSize);

    unsigned int p1_index = 0U;
    unsigned int p2_index = 0U;
    unsigned int p3_index = 0U;
    unsigned int p4_index = 0U;

    for (unsigned int i = 0U; i < totalSize; i += 11U) 
    {
        tempVertices.push_back(vecVerts[p1_index]);
        tempVertices.push_back(vecVerts[p1_index + 1]);
        tempVertices.push_back(vecVerts[p1_index + 2]);
        tempVertices.push_back(vecColors[p2_index]);
        tempVertices.push_back(vecColors[p2_index + 1]);
        tempVertices.push_back(vecColors[p2_index + 2]);
        tempVertices.push_back(vecColors[p2_index + 3]);
        tempVertices.push_back(vecTextures[p3_index]);
        tempVertices.push_back(vecTextures[p3_index + 1]);
        tempVertices.push_back(vecNormals[0]);
        tempVertices.push_back(vecNormals[1]);

        p1_index += 3U;
        p2_index += 4U;
        p3_index += 2U;
        p4_index += 2U;
    }

    unsigned int tempDrawVertSize = static_cast<unsigned int>(indices.end() - indices.begin()) * 11U;

    drawVertices.reserve(tempDrawVertSize);

    for (unsigned int j = 0; j < (indices.end() - indices.begin()); j++) 
    {
        unsigned int index = indices[j]; // Assuming 'indices' is another vector containing indices

        drawVertices.push_back(tempVertices[index * 11]);
        drawVertices.push_back(tempVertices[(index * 11) + 1]);
        drawVertices.push_back(tempVertices[(index * 11) + 2]);
        drawVertices.push_back(tempVertices[(index * 11) + 3]);
        drawVertices.push_back(tempVertices[(index * 11) + 4]);
        drawVertices.push_back(tempVertices[(index * 11) + 5]);
        drawVertices.push_back(tempVertices[(index * 11) + 6]);
        drawVertices.push_back(tempVertices[(index * 11) + 7]);
        drawVertices.push_back(tempVertices[(index * 11) + 8]);
        drawVertices.push_back(tempVertices[(index * 11) + 9]);
        drawVertices.push_back(tempVertices[(index * 11) + 10]);
    };

    return drawVertices;
};





void UCreateSkybox(std::string name,
    Shapes& ShapeMap,
    vector<float> vertices,
    vector<float> colors,
    vector<unsigned int> indices,
    vector<float> textures,
    const char* vertShader,
    const char* fragShader,
    vector<std::string> filenames,
    GLuint textureId)
{
    // Creates objects and places them into the map as unique pointers.
    auto shape = std::make_unique<ShapeObject>(
        vertices, 
        indices, 
        vertShader, 
        fragShader);

    ShapeMap.insert({ name, std::move(shape) });

    loadCubemap(filenames, textureId, ShapeMap, name);

    // skybox VAO
    glGenVertexArrays(1, ShapeMap.at(name)->getVaoPtr());
    glGenBuffers(1, ShapeMap.at(name)->getVboPtr());
    glBindVertexArray(ShapeMap.at(name)->getVao());
    glBindBuffer(GL_ARRAY_BUFFER, ShapeMap.at(name)->getVbo());
    glBufferData(GL_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getVertices().size(), ShapeMap.at(name)->getVertices().data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()), (void*)0);

    unsigned int shaderProgram = runShader::CreateShader(
        ShapeMap.at(name)->getVertexShader(),
        ShapeMap.at(name)->getFragmentShader());

    ShapeMap.at(name)->setShaderProgram(shaderProgram);
}

void UCreateCubeMap(std::string name,
    Shapes& ShapeMap,
    vector<float> vertices,
    vector<float> colors,
    vector<unsigned int> indices,
    vector<float> textures,
    const char* vertShader,
    const char* fragShader,
    vector<std::string> filenames,
    GLuint textureId)
{
    // Creates objects and places them into the map as unique pointers.
    auto shape = std::make_unique<ShapeObject>(vertices, 
        indices, 
        vertShader,
        fragShader);
    ShapeMap.insert({ name ,std::move(shape) });

    loadCubemap(filenames, textureId, ShapeMap, name);

    glGenVertexArrays(1, ShapeMap.at(name)->getVaoPtr());
    glGenBuffers(1, ShapeMap.at(name)->getVboPtr());
    glBindVertexArray(ShapeMap.at(name)->getVao());
    glBindBuffer(GL_ARRAY_BUFFER, ShapeMap.at(name)->getVbo());
    glBufferData(GL_ARRAY_BUFFER, 4 * ShapeMap.at(name)->getVertices().size(), ShapeMap.at(name)->getVertices().data(), GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    unsigned int shaderProgram = runShader::CreateShader(
        ShapeMap.at(name)->getVertexShader(),
        ShapeMap.at(name)->getFragmentShader());

    ShapeMap.at(name)->setShaderProgram(shaderProgram);
}

bool loadCubemap(vector<std::string> faces, 
    GLuint TextureID, 
    Shapes& ShapeMap, 
    std::string name)
{
    glGenTextures(1, ShapeMap.at(name)->getTextureIdPtr());
    glBindTexture(GL_TEXTURE_CUBE_MAP, ShapeMap.at(name)->getTextureId());;

    int width, height, nrComponents;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return true;
}

bool outputToFile(vector<float> tempVertices, std::string& name)
{
    std::string filename = generateNewFilename(name);
    // Output folder
    std::string folder = "outputfiles/";
    // Filename
    filename = folder + filename + ".txt";

    // Check if the file already exists
    std::ifstream fileExists(filename);
    if (fileExists.is_open()) {
        fileExists.close();
        // Generate a new filename
        filename = generateNewFilename(filename);
    }

    // Open the file for writing
    std::ofstream outFile(filename);

    // Check if the file is opened successfully
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return false;
    }

    // Set precision for float output
    outFile << std::fixed << std::setprecision(2);

    // Counter for number of entries written
    int entryCount = 0;

    // Iterate over the vector and print each float followed by an 'f'
    for (size_t i = 0; i < tempVertices.size(); ++i) {
        if (tempVertices[i] == static_cast<int>(tempVertices[i])) {
            outFile << std::setprecision(2) << std::setw(2) << std::setfill('0') << tempVertices[i] << "f";
        }
        else {
            outFile << tempVertices[i] << "f";
        }

        // Increment entry count
        entryCount++;

        // Add comma and new line every 11 entries
        if (entryCount % 11 == 0 && i != tempVertices.size() - 1) {
            outFile << ",\n";
        }
        else if (i != tempVertices.size() - 1) {
            outFile << ",";
        }
    }


    // Close the file
    outFile.close();

    std::cout << "File has been written successfully." << std::endl;
};

std::string generateNewFilename(const std::string& filename) {
    std::stringstream newFilename;
    size_t dotPos = filename.find_last_of('.');
    if (dotPos != std::string::npos) {
        newFilename << filename.substr(0, dotPos) << "_new" << filename.substr(dotPos);
    }
    else {
        newFilename << filename << "_new";
    }
    return newFilename.str();
}

/********************* Experimental procedural generation and normalization of data ****************/
std::vector<float> normalizeData(const std::vector<float>& data) 
{
    // Find the minimum and maximum values in the data
    float minVal = *std::min_element(data.begin(), data.end());
    float maxVal = *std::max_element(data.begin(), data.end());

    // Calculate the range
    float range = maxVal - minVal;

    // Initialize the normalized data vector
    std::vector<float> normalizedData;

    // Normalize each element in the data
    for (float value : data) {
        float normalizedValue = 2.0f * ((value - minVal) / range) - 1.0f;
        normalizedData.push_back(normalizedValue);
    }
    return normalizedData;
}
void vectorNormalize() 
{
    std::vector<float> inputData = { 6.8750f, 0.5f, 0.25f, 0.125f, 0.0416f, 0.0f };

    std::cout << "Original Data:" << std::endl;
    for (float value : C1vertices) 
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::vector<float> normalizedData = normalizeData(C1vertices);

    std::cout << "Normalized Data:" << std::endl;
    for (float value : normalizedData)
    {
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

    // push indexes of each triangle point
    for (int i = 0; i < triangleCount; i++)
    {
        C1indices.push_back(i);
        C1indices.push_back(i + 1);
    }
};
void buildCircle2(float radius, int vCount)
{
    float angle = 360.0f / vCount;

    int triangleCount = vCount - 2;

    for (int i = 0; i < vCount; i++)
    {
        float currentAngle = angle * i;
        float x = radius * cos(glm::radians(currentAngle));
        float y = radius * sin(glm::radians(currentAngle));
        float z = 0.2f;

        C2vertices.push_back(x);
        C2vertices.push_back(y);
        C2vertices.push_back(z);
        C2vertices.push_back(0.20f);
        C2vertices.push_back(0.23f);
        C2vertices.push_back(0.63f);
        C2vertices.push_back(1.0f);
    }

    // push indexes of each triangle point
    for (int i = 0; i < triangleCount; i++)
    {
        C2indices.push_back(0);
        C2indices.push_back(i + 1);
        C2indices.push_back(i + 2);
    }
}