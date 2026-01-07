/**
* The Purpose of this program is to demonstrate Texturing and lighting of complex objects, the most complex object would be the focusrite which has a chrome texture on the knobs, and a different texture for the focusrite body.  The cubes are all wrapped so the coordintes were a bit tricky to figure out the first time.
* @Author Jeremiah Boothe
* @Date 2/18/2024
*/

#include "DrawShapes.h"

int main(int argc, char* argv[])
{
    //Map to store ShapeObjects
    Shapes ShapeMap;

    //Initialize the program to pass arguments to the window
    if (!UInitialize(argc, argv, &window))
        return EXIT_FAILURE;

    // new starting point, to minimize the main function clutter, all shapes are built from this function.
    BuildShapes(ShapeMap);

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
    
    // Destructor to clean up memory.

    glfwTerminate();
     
    exit(0);
    return 0;
}

void BuildShapes(Shapes& ShapeMap) {
    {       /* Creates all shapes in the scene */
        {   /* Skybox Scenery */
            UCreateSkybox("Skybox",
                ShapeMap,
                SkyBox.skyboxVertices,
                cubeObjectStruct.colors,
                cubeObjectStruct.indices,
                SkyBox.skyboxVertices,
                skyboxShaderSource.skyboxShaderSource,
                skyboxShaderSource.skyboxFragmentSource,
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

            // for the future light sources to have positions so the light isn't a magic source.
            /*
            UCreateShape("lighting",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colors,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lampShaders.lampVertexShaderSource,
                lampShaders.lampFragmentShaderSource,
                texturesStruct.tableTexture,
                TextureId);

            UCreateShape("lightCube",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                cubeObjectStruct.colors,
                cubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lampShaders.lampVertexShaderSource,
                lampShaders.lampFragmentShaderSource,
                texturesStruct.tableTexture,
                TextureId);*/
        }

        {   // Desk tops, fake planes, really cubes ;O
            UCreateShape("tablePlane",
                ShapeMap,
                basicCubeObjectStruct.basicCubeObjects,
                basicCubeObjectStruct.colorsAlpha,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.tableTexture3,
                TextureId);

            UCreateShape("tablePlane2",
                ShapeMap,
                basicCubeObjectStruct.basicCubeObjects,
                basicCubeObjectStruct.colorsAlpha,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.tableTexture4,
                TextureId);

            UCreateShape("mousePad",
                ShapeMap,
                basicCubeObjectStruct.basicCubeObjects,
                basicCubeObjectStruct.colorsAlpha,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.mousepad,
                TextureId);

            UCreateShape("keyboard",
                ShapeMap,
                basicCubeObjectStruct.basicCubeObjects,
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
            /*
            UCreateShape("buttonArray",
                ShapeMap,
                buttonArrayObjectStruct.vertices,
                buttonArrayObjectStruct.colors,
                buttonArrayObjectStruct.indices,
                buttonArrayObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.tableTexture2,
                TextureId);
                */
            UCreateShape("cubeObject",
                ShapeMap,
                cubeObjectStruct.faderport,
                cubeObjectStruct.colors,
                cubeObjectStruct.indices,
                cubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.faderportmap,
                TextureId);

            UCreateShape("presonusKnob",
                ShapeMap,
                cylinderObjectStruct.PresonusKnobComplete,
                cylinderObjectStruct.colors,
                cylinderObjectStruct.indices,
                cylinderObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.chromeSwirl,
                TextureId);

            UCreateShape("sliderObject",
                ShapeMap,
                basicCubeObjectStruct.focusriteVertices,
                sliderObjectStruct.colors,
                sliderObjectStruct.indices,
                sliderObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.chromeSwirl,
                TextureId);

            UCreateShape("sliderBacking",
                ShapeMap,
                basicCubeObjectStruct.basicCubeObjects,
                sliderBackingObjectStruct.colors,
                sliderBackingObjectStruct.indices,
                sliderBackingObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.chromeSwirl,
                TextureId);
        }



        { /* Video Monitors */
            UCreateShape("monitor1",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colorsAlpha,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.monitor1,
                TextureId);

            UCreateShape("monitor2",
                ShapeMap,
                basicCubeObjectStruct.vertices,
                basicCubeObjectStruct.colorsAlpha,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.monitor2,
                TextureId);

            UCreateShape("monitorStand",
                ShapeMap,
                cylinderObjectStruct.CylinderVerticesComplete,
                cylinderObjectStruct.colorsMatBlack,
                cylinderObjectStruct.indices,
                cylinderObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.tableTexture,
                TextureId);
        }

        { /* Speakers */
            UCreateShape("speakerRight",
                ShapeMap,
                basicCubeObjectStruct.focusriteVertices,
                basicCubeObjectStruct.colorsSteelBlack,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.rightspeakermap,
                TextureId);

            UCreateShape("speakerLeft",
                ShapeMap,
                basicCubeObjectStruct.focusriteVertices,
                basicCubeObjectStruct.colorsSteelBlack,
                basicCubeObjectStruct.indices,
                basicCubeObjectStruct.textureVertices,
                normals,
                lotsOfLightsShader.vertexShaderSource,
                lotsOfLightsShader.fragmentShaderSource,
                texturesStruct.leftspeakermap,
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
                cylinderObjectStruct.CylinderVerticesComplete,
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

    //sets up the starting point for the global lighting, and adds it to the globalLighting Singleton to manage

    Lighting* globalLighting = Lighting::getInstance();

    GLuint shaderProgram = ShapeMap.at("tablePlane")->getShaderProgram();

    globalLighting->setValues(shaderProgram);
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

    /* BufferSubData as a possible replacement to the buildCombinedVector, saves processing power by batching instead of interleaving
    float positions[] = { ... };
    float normals[] = { ... };
    float tex[] = { ... };
    // fill buffer
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(positions), &positions);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions), sizeof(normals), &normals);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions) + sizeof(normals), sizeof(tex), &tex);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(sizeof(positions)));
    glVertexAttribPointer(
    2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(sizeof(positions) + sizeof(normals)));

    void glCopyBufferSubData(GLenum readtarget, GLenum writetarget, GLintptr readoffset,
                         GLintptr writeoffset, GLsizeiptr size);
    */


    // set up to be able to transition from auto built to saved vertices, colors, normals, textures, etc...
    if (name == "focusRite" || name == "cubeObject" || name == "sliderObject" || name == "speakerRight" || name == "speakerLeft" || name == "monitorStand" || name == "focusRiteKnobCollection" || name == "presonusKnob" || name == "tablePlane" || name == "tablePlane2" || name == "mousePad" || name == "keyboard" || name == "sliderBacking") {
        // Creates objects and places them into the map as unique pointers.
        auto shape = std::make_unique<ShapeObject>(vertices, indices, vertShader, fragShader);
        ShapeMap.insert({ name ,std::move(shape) });

    } else {

        // converted these to methods that combine and then print to a text file, allowing finder control of vertices instead of relying on the round about indices to vertices which proves to be very difficult to get textures to align on.
        vector<float> tempVertices = buildCombinedVector(vertices, colors, indices, textures, normals);

        // writes output file of combined vectors in csv format with an f appended to each entry
        //outputToFile(tempVertices, name);

        // Creates objects and places them into the map as unique pointers.
        auto shape = std::make_unique<ShapeObject>(tempVertices, indices, vertShader, fragShader);
        ShapeMap.insert({ name ,std::move(shape) });
    };

    // Calculate Stride for (x,y,z,r,g,b,a,u,v,tan,bitan)
    const GLuint floatsPerVertex = 3U;
    const GLuint floatsPerColor = 4U;
    const GLuint floatsPerUV = 2U;
    const GLuint floatsPerNormal = 3U;

    // set to 0 for now to not break the work buildCombinedVector() does
    const GLuint floatsPerTangent = 0U;
    const GLuint floatsPerBiTangent= 0U;

    const unsigned int SHADOW_WIDTH = 1024;
    const unsigned int SHADOW_HEIGHT = 1024;

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
    glVertexAttribPointer(4, floatsPerTangent, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV + floatsPerTangent)));
    glEnableVertexAttribArray(4);

    // BiTangent - Attribute Pointer - * Not fully Implemented *
    glVertexAttribPointer(5, floatsPerBiTangent, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV + floatsPerTangent + floatsPerBiTangent)));
    glEnableVertexAttribArray(5);


    // Shadow casting setup, still implementing so not a final iteration by any stretchs.
    glGenFramebuffers(1, ShapeMap.at(name)->getFboPtr());

    glGenTextures(1, ShapeMap.at(name)->getDepthMapPtr());
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    unsigned int shaderProgram = runShader::CreateShader(
        ShapeMap.at(name)->getVertexShader(),
        ShapeMap.at(name)->getFragmentShader());

    ShapeMap.at(name)->setShaderProgram(shaderProgram);

    unsigned int shadowMappingProgram = runShader::CreateShader(
        Shadow_Mapping.shadowVertShader,
        Shadow_Mapping.shadowFragShader);

    ShapeMap.at(name)->setShadowMappingProgram(shadowMappingProgram);

    unsigned int shadowDepthProgram = runShader::CreateShader(
        ShadowDepth.depthVertShader,
        ShadowDepth.depthFragShader);

    ShapeMap.at(name)->setShadowDepthProgram(shadowDepthProgram);

    unsigned int emissionsProgram = runShader::CreateShader(
        Emissions.cubeVertLightingMap,
        Emissions.cubeFragLightingMap);

    ShapeMap.at(name)->setEmissionsProgram(emissionsProgram);

}

void URenderShape(Shapes& ShapeMap, GLFWwindow* window) 
{
    // moved some variables to global to be reassigned instead of creating duplicates for each object.
    GLint modelLoc;
    GLint viewLoc;
    GLint projLoc;
    GLint UVScaleLoc;
    glm::mat4 scale{};
    glm::mat4 rotation{};
    glm::vec3 location{};
    glm::mat4 translation{};
    glm::mat4 model{};
    glm::mat4 projection;

    // Initialize Global Lighting Singleton
    Lighting* globalLighting = Lighting::getInstance();

    // Values for button arrays
    const int nrows = 4;
    const int ncols = 1;
    const int nlevels = 4;
    const float xsize = 0.25f;
    const float ysize = 0.35f;
    const float zsize = 0.35f;

    // Enable z-depth
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_STENCIL_TEST);
    glEnable(GL_MULTISAMPLE);
    // Enable Blending
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
    glEnable(GL_BLEND);
    glEnable(GL_NORMALIZE);
    // Uncomment for polygon mode 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    // Clear the frame and z buffers
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // Set up for camra views
    if (camera.CameraProjectionMode == PERSPECTIVE)    
        projection = glm::perspective(glm::radians(camera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 1000.0f);
    else
        projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);

    glm::mat4 view = camera.GetViewMatrix();

    // prints current position to console
    //std::cout << camera.Position.x << ", " << camera.Position.y << ", " << camera.Position.z << std::endl;

    // sets up the first set of location variables and the shaderprogram, the goal is to move this process into a class that handles specific compilations of the shaders so it doesn't have to be recreated and tied to each object.
    glUseProgram(ShapeMap.at("tablePlane2")->getShaderProgram());

    modelLoc = glGetUniformLocation(ShapeMap.at("tablePlane2")->getShaderProgram(), "model");
    viewLoc = glGetUniformLocation(ShapeMap.at("tablePlane2")->getShaderProgram(), "view");
    projLoc = glGetUniformLocation(ShapeMap.at("tablePlane2")->getShaderProgram(), "projection");
    UVScaleLoc = glGetUniformLocation(ShapeMap.at("tablePlane2")->getShaderProgram(), "uvScale");

    // retrieves the lighting references from the lighting singleton class
    glUniform4f(globalLighting->getObjColLoc(), 0.0f, 0.0f, 0.0f, 1.0f);
    glUniform3f(globalLighting->getViewPosLoc(), camera.Position.x, camera.Position.y, camera.Position.z);
    glUniform1f(globalLighting->getAmbStrLoc(), 0.01f);
    //set ambient color
    glUniform3f(globalLighting->getAmbColLoc(), 1.0f, 1.0f, 1.0f);
    glUniform3f(globalLighting->getLight1ColLoc(), 0.1f, 0.8f, 0.3f);
    glUniform3f(globalLighting->getLight1PosLoc(), 0.0f, 4.45f, -8.0f);
    glUniform3f(globalLighting->getLight2ColLoc(), 0.8f, 0.3f, 0.1f);
    glUniform3f(globalLighting->getLight2PosLoc(), -3.0f, 6.0f, -4.0f);
    glUniform3f(globalLighting->getLight3ColLoc(), 0.89f, 0.914f, 1.0f);
    glUniform3f(globalLighting->getLight3PosLoc(), 3.0f, 4.5f, 6.0f);
    //set specular intensity
    glUniform1f(globalLighting->getSpecInt1Loc(), 0.9f);
    glUniform1f(globalLighting->getSpecInt2Loc(), 0.8f);
    glUniform1f(globalLighting->getSpecInt3Loc(), 0.7f);
    //set specular highlight size
    glUniform1f(globalLighting->getHighlghtSz1Loc(), 16.0f);
    glUniform1f(globalLighting->getHighlghtSz2Loc(), 16.0f);
    glUniform1f(globalLighting->getHighlghtSz3Loc(), 16.0f);
                
    /** Major cleanup of rendering section, less reinitialization, now it's just reassignments, to be moved to initial build to avoid having to constantly recalculate model, will be stored in and called from the shape */
    for (const auto& pair : ShapeMap)
    {
        const std::string& name = pair.first;
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        if (name == "tablePlane")
        {
            scale = glm::scale(glm::vec3(4.5f, 0.025f, 1.5f));
            rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(0.0f, 0.0f, -0.5f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "mousePad")
        {
            scale = glm::scale(glm::vec3(0.9f, 0.025f, 0.7f));
            rotation = glm::rotate(glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(3.5f, 0.06f, 0.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "tablePlane2")
        {
            scale = glm::scale(glm::vec3(5.0f, 0.025f, 5.0f));
            rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(0.0f, 2.0f, -5.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "keyboard")
        {
            scale = glm::scale(glm::vec3(2.25f, 0.025f, 0.65f));
            rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(0.0f, 0.06f, 0.26f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            // Retrieves and passes transform matrices to the Shader program
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());
            glActiveTexture(GL_TEXTURE0);

            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        // was an interesting idea, but I haven't yet worked out how to iterate across a texture and map the buttons individually to each object in the array.  I have an idea of how to make that happen with it rotating texture coordinates for each addition of a button, easier said than done though. So for now I'm just using a texture for the buttons on the Presonus Faderport.
        if (name == "buttonArray")
        {
            scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
            rotation = glm::rotate(glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            // Array 3x6
            for (int i = 0; i < nrows; ++i)
            {
                for (int j = 0; j < ncols; ++j)
                {
                    for (int k = 0; k < nlevels; ++k)
                    {
                        location = glm::vec3(i * xsize, j * ysize, k * (zsize - 0.05f));
                        translation = glm::translate(
                            glm::translate(
                                glm::rotate(
                                    glm::radians(6.4f),
                                    glm::vec3(1.0f, 0.0f, 0.0f)), location),
                            glm::vec3(-3.7f, 0.39f, -0.45f));
                        model = translation * rotation * scale;

                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
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
                    for (int k = 0; k < nlevels - 3; ++k)
                    {
                        location = glm::vec3(i * (xsize - .06f), j * ysize, k * zsize);
                        translation = glm::translate(
                            glm::translate(
                                glm::rotate(
                                    glm::radians(6.4f),
                                    glm::vec3(1.0f, 0.0f, 0.0f)),
                                location),
                            glm::vec3(-3.7f, 0.39f, 0.75f));
                        model = translation * rotation * scale;

                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                    }
                }
            };

            // Array 3x6
            for (int i = 0; i < nrows - 1; ++i)
            {
                for (int j = 0; j < ncols; ++j)
                {
                    for (int k = 0; k < nlevels - 3; ++k)
                    {
                        location = glm::vec3(i * xsize, j * ysize, k * zsize);
                        translation = glm::translate(glm::translate(glm::rotate(glm::radians(6.4f), glm::vec3(1.0f, 0.0f, 0.0f)), location), glm::vec3(-3.45f, 0.39f, -0.7f));
                        model = translation * rotation * scale;

                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

                        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                    }
                }
            };
            glBindVertexArray(0);
        };

        if (name == "cubeObject")
        {
            scale = glm::scale(glm::vec3(1.0f, 1.0f, .9f));
            rotation = glm::rotate(glm::radians(-90.0f), glm::vec3(1.0, 0.0f, 0.0f));
            location = glm::vec3(-3.5f, 0.25f, 0.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glBindVertexArray(ShapeMap.at(name)->getVao());
            glActiveTexture(GL_TEXTURE0);

            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "sliderObject")
        {
            scale = glm::scale(glm::vec3(0.05f, 0.05f, 0.11f));
            rotation = glm::rotate(glm::radians(6.4f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(-4.008f, 0.43f, 0.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());
            glActiveTexture(GL_TEXTURE0);

            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "sliderBacking")
        {
            scale = glm::scale(glm::vec3(0.020f, 0.75f, 0.05f));
            rotation = glm::rotate(glm::radians(95.8f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(-4.008f, 0.33f, 0.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());
            glActiveTexture(GL_TEXTURE0);

            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "speakerRight")
        {
            scale = glm::scale(glm::vec3(0.60f, 0.9f, 0.60f));
            rotation = glm::rotate(glm::radians(-50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(4.0f, 2.926f, -4.9f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());
            glActiveTexture(GL_TEXTURE0);

            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
        };

        if (name == "speakerLeft")
        {
            scale = glm::scale(glm::vec3(0.60f, 0.9f, 0.60f));
            rotation = glm::rotate(glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(-4.0f, 2.926f, -4.9f);
            translation = glm::translate(location);
            model = translation * rotation * scale;


            // Retrieves and passes transform matrices to the Shader program

            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at(name)->getVao());
            glActiveTexture(GL_TEXTURE0);

            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "focusRite")
        {
            scale = glm::scale(glm::vec3(1.1f, .25f, 0.75f));
            rotation = glm::rotate(glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            location = glm::vec3(-3.0f, 2.295f, -6.5f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        // Focusrite Knobs
        if (name == "focusRiteKnobCollection")
        {
            {
                scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.151f));
                rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                location = glm::vec3(-1.973f, 2.408, -6.58f);
                translation = glm::translate(location);
                model = translation * rotation * scale;

                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
                glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

                glBindVertexArray(ShapeMap.at(name)->getVao());

                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

                glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                glBindVertexArray(0);
            }

            {
                scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.149f));
                rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                location = glm::vec3(-1.844f, 2.408f, -6.729f);
                translation = glm::translate(location);
                model = translation * rotation * scale;

                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
                glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

                glBindVertexArray(ShapeMap.at(name)->getVao());

                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

                glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                glBindVertexArray(0);

            }
            {
                scale = glm::scale(glm::vec3(0.135f, 0.135f, 0.125f));
                rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                location = glm::vec3(-2.16f, 2.281f, -6.37f);
                translation = glm::translate(location);
                model = translation * rotation * scale;

                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
                glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

                glBindVertexArray(ShapeMap.at(name)->getVao());

                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

                glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                glBindVertexArray(0);
            }

            {
                scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.200f));
                rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                location = glm::vec3(-2.5f, 2.408f, -6.05f);
                translation = glm::translate(location);
                model = translation * rotation * scale;

                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
                glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

                glBindVertexArray(ShapeMap.at(name)->getVao());

                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

                glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                glBindVertexArray(0);
            }
            {
                scale = glm::scale(glm::vec3(0.065f, 0.065f, 0.200f));
                rotation = glm::rotate(glm::radians(-130.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                location = glm::vec3(-2.89f, 2.408f, -5.59f);
                translation = glm::translate(location);
                model = translation * rotation * scale;

                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
                glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

                glBindVertexArray(ShapeMap.at(name)->getVao());

                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

                glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
                glBindVertexArray(0);
            }

        };


        if (name == "presonusKnob")
        {
            scale = glm::scale(glm::vec3(.068f, 0.068f, 0.25f));
            rotation = glm::rotate(glm::radians(-83.6f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(-3.74f, 0.65f, -0.59f);
            translation = glm::translate(location);
            model = translation * rotation * scale;
   

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "monitorStand")
        {
            scale = glm::scale(glm::vec3(0.35f, 0.35f, 7.0f));
            rotation = glm::rotate(glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(0.0f, 2.05f, -8.8f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "monitor1")
        {
            glUniform1f(globalLighting->getAmbStrLoc(), 0.25f);

            scale = glm::scale(glm::vec3(3.4f, 0.0f, 2.0f));
            rotation = glm::rotate(glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(0.0f, 4.45f, -8.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));



            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glUniform1f(globalLighting->getAmbStrLoc(), 0.01f);
            glBindVertexArray(0);

        };

        if (name == "monitor2")
        {
            glUniform1f(globalLighting->getAmbStrLoc(), 0.25f);
            scale = glm::scale(glm::vec3(3.4f, 0.0f, 2.0f));
            rotation = glm::rotate(glm::radians(91.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(0.0f, 8.40f, -8.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));

            glUniform1f(globalLighting->getAmbStrLoc(), 0.01f);
            glBindVertexArray(0);
        };
    };

    for (const auto& pair : ShapeMap)
    {
        const std::string& name = pair.first;

        if (name == "lightCube")
        {   // Set the shader to be used
            // LearnOpenGL uses a format like shader.use();
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            scale = glm::scale(glm::vec3(0.5f, 0.5f, 0.5f));
            rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            //model = glm::rotate(model, (float)glfwGetTime() * -10.0f, glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
            location = glm::vec3(0.0f, 20.0f, 0.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            modelLoc = glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "model");
            projLoc = glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "projection");
            viewLoc = glGetUniformLocation(ShapeMap.at("lighting")->getShaderProgram(), "view");

            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glBindVertexArray(ShapeMap.at("lighting")->getVao());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at("lighting")->getVertices().size()));
            glBindVertexArray(0);
        };

        if (name == "CubeMap") 
        {
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            scale = glm::scale(glm::vec3(1000.0f, 1000.0f, 1000.0f));
            rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(0.0f, 0.0f, 0.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;
            
            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glDepthFunc(GL_LEQUAL);

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());
                
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glDepthFunc(GL_LESS); // set depth function back to default
            glBindVertexArray(0);
        };

        if (name == "SkyBox") 
        {
            glDepthFunc(GL_LEQUAL);
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            scale = glm::scale(glm::vec3(1000.0f, 1000.0f, 1000.0f));
            rotation = glm::rotate(glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            location = glm::vec3(0.0f, 0.0f, 0.0f);
            translation = glm::translate(location);
            model = translation * rotation * scale;

            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "viewstay");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));

            glBindVertexArray(ShapeMap.at(name)->getVao());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getVertices().size()));
            glDepthFunc(GL_LESS); // set depth function back to default
            glBindVertexArray(0);
        };

        if (name == "pyramidObject")
        {
            // Set the shader to be used
            glUseProgram(ShapeMap.at(name)->getShaderProgram());

            // Retrieves and passes transform matrices to the Shader program
            modelLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "model");
            viewLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "view");
            projLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "projection");
            UVScaleLoc = glGetUniformLocation(ShapeMap.at(name)->getShaderProgram(), "uvScale");

            glUniform2fv(UVScaleLoc, 1, glm::value_ptr(uvScale));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            // Activate the VBOs contained within the mesh's VAO
            glBindVertexArray(ShapeMap.at(name)->getVao());

            // 1. Scales the object by 2
            scale = glm::scale(glm::vec3(0.0727f, 0.0727f, 0.0727f));
            // 2. Rotates shape by 15 degrees in the x axis
            rotation = glm::rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            for (int i = 0; i < nrows; ++i)
            {
                for (int j = 0; j < ncols + 4; ++j)
                {
                    for (int k = 0; k < nlevels; ++k)
                    {
                        location = glm::vec3(i * xsize, j * ysize, k * zsize);
                        // 3. Place object at the origin
                        translation = glm::translate(location);
                        // Model matrix: transformations are applied right-to-left order
                        model = translation * rotation * scale;
                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                        glActiveTexture(GL_TEXTURE0);

                        glBindTexture(GL_TEXTURE_2D, ShapeMap.at(name)->getTextureId());
                        // Draws the triangles
                        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(ShapeMap.at(name)->getIndices().size()));
                        glBindVertexArray(0);                    }
                }
            };
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
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        
        if (channels == 1) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        }
        else if (channels == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        }
        else if (channels == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        }
        else {
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
    glfwWindowHint(GLFW_SAMPLES, 16);

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
    unsigned int vecnormSize = static_cast<unsigned int>(vecVerts.end() - vecVerts.begin());
    unsigned int totalSize = (vecvertSize + veccolorSize + vectextSize + vecnormSize);

    tempVertices.reserve(totalSize);

    unsigned int p1_index = 0U;
    unsigned int p2_index = 0U;
    unsigned int p3_index = 0U;
    unsigned int p4_index = 0U;

    for (unsigned int i = 0U; i < totalSize; i += 12U) 
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
        tempVertices.push_back(vecNormals[2]);

        p1_index += 3U;
        p2_index += 4U;
        p3_index += 2U;
        p4_index += 3U;
    }

    unsigned int tempDrawVertSize = static_cast<unsigned int>(indices.end() - indices.begin()) * 12U;

    drawVertices.reserve(tempDrawVertSize);

    for (unsigned int j = 0; j < (indices.end() - indices.begin()); j++) 
    {
        unsigned int index = indices[j]; // Assuming 'indices' is another vector containing indices

        drawVertices.push_back(tempVertices[index * 12]);
        drawVertices.push_back(tempVertices[(index * 12) + 1]);
        drawVertices.push_back(tempVertices[(index * 12) + 2]);
        drawVertices.push_back(tempVertices[(index * 12) + 3]);
        drawVertices.push_back(tempVertices[(index * 12) + 4]);
        drawVertices.push_back(tempVertices[(index * 12) + 5]);
        drawVertices.push_back(tempVertices[(index * 12) + 6]);
        drawVertices.push_back(tempVertices[(index * 12) + 7]);
        drawVertices.push_back(tempVertices[(index * 12) + 8]);
        drawVertices.push_back(tempVertices[(index * 12) + 9]);
        drawVertices.push_back(tempVertices[(index * 12) + 10]);
        drawVertices.push_back(tempVertices[(index * 12) + 11]);
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
        if (entryCount % 12 == 0 && i != tempVertices.size() - 1) {
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