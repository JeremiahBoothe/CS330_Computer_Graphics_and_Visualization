#pragma once
#include <iostream>

/** Shader program Macro - no more quoting every line with \n! */
#ifndef GLSL
#define GLSL(Version, Source) "#version " #Version " core \n" #Source

/** Script structs to feed into the ShapeObject class and make better reuse of it */
struct 
{
    /* Vertex Shader Source Code*/
    const GLchar* vertShader = GLSL(440,
        layout(location = 0) in vec3 position;
        layout(location = 1) in vec3 normal; // VAP position 1 for normals
        layout(location = 2) in vec2 textureCoordinate;

        out vec3 vertexNormal; // For outgoing normals to fragment shader
        out vec3 vertexFragmentPos; // For outgoing color / pixels to fragment shader
        out vec2 vertexTextureCoordinate;

        //Global variables for the transform matrices
        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(position, 1.0f); // transforms vertices to clip coordinates
            vertexFragmentPos = vec3(model * vec4(position, 1.0f)); // Gets fragment / pixel position in world space only (exclude view and projection)

            vertexNormal = mat3(transpose(inverse(model))) * normal; // get normal vectors in world space only and exclude normal translation properties
            vertexTextureCoordinate = textureCoordinate;
        }
    );

    /* Fragment Shader Source Code*/
    const GLchar* fragShader = GLSL(440,
        in vec3 vertexNormal; // For incoming normals
        in vec3 vertexFragmentPos; // For incoming fragment position
        in vec2 vertexTextureCoordinate;

        out vec4 fragmentColor;

        uniform vec3 objectColor;
        uniform vec3 lightColor;
        uniform vec3 lightPos;
        uniform vec3 viewPosition;
        uniform sampler2D uTexture;
        uniform vec2 uvScale;

        void main()
        {
            // ambient
            //float ambientStrength = 0.1;
            //vec3 ambient = ambientStrength * lightColor;

            // diffuse 
            //vec3 norm = normalize(Normal);
            //vec3 lightDir = normalize(lightPos - FragPos);
            //float diff = max(dot(norm, lightDir), 0.0);
            //vec3 diffuse = diff * lightColor;

            // specular
            //float specularStrength = 0.5;
            //vec3 viewDir = normalize(viewPos - FragPos);
            //vec3 reflectDir = reflect(-lightDir, norm);
            //float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
            //vec3 specular = specularStrength * spec * lightColor;

            //vec3 result = (ambient + diffuse + specular) * objectColor;
            //FragColor = vec4(result, 1.0);
            


            /*Phong lighting model calculations to generate ambient, diffuse, and specular components*/

            //Calculate Ambient lighting*/
            //float ambientStrength = 0.1f; // Set ambient or global lighting strength
            //vec3 ambient = ambientStrength * lightColor; // Generate ambient light color

            //Calculate Diffuse lighting*/
            //vec3 norm = normalize(vertexNormal); // Normalize vectors to 1 unit
            //vec3 lightDirection = normalize(lightPos - vertexFragmentPos); // Calculate distance (light direction) between light source and fragments/pixels on cube
            //float impact = max(dot(norm, lightDirection), 0.0);// Calculate diffuse impact by generating dot product of normal and light
            //vec3 diffuse = impact * lightColor; // Generate diffuse light color

            //Calculate Specular lighting*/
            //float specularIntensity = 0.8f; // Set specular light strength
            //float highlightSize = 16.0f; // Set specular highlight size
            //vec3 viewDir = normalize(viewPosition - vertexFragmentPos); // Calculate view direction
            //vec3 reflectDir = reflect(-lightDirection, norm);// Calculate reflection vector
            //Calculate specular component
            //float specularComponent = pow(max(dot(viewDir, reflectDir), 0.0), highlightSize);
            //vec3 specular = specularIntensity * specularComponent * lightColor;

            // Texture holds the color to be used for all three components
            //vec4 textureColor = texture(uTexture, vertexTextureCoordinate * uvScale);

            // Calculate phong result
            //vec3 phong = (ambient + diffuse + specular) * textureColor.xyz;

            //fragmentColor = vec4(phong, 1.0); // Send lighting results to GPU

            fragmentColor = texture(uTexture, vertexTextureCoordinate * uvScale);
        }
    );

} textureShader;

struct
{
    const char* vertShader = GLSL(440,
        layout(location = 0) in vec3 position; // Vertex data from Vertex Attrib Pointer 0
        layout(location = 1) in vec4 color;  // Color data from Vertex Attrib Pointer 1

        out vec4 vertexColor; // variable to transfer color data to the fragment shader

        //Global variables for the  transform matrices
        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(position, 1.0f); // transforms vertices to clip coordinates
            vertexColor = color; // references incoming color data
        }
    );

    const char* fragShader = GLSL(440,
        in vec4 vertexColor; // Variable to hold incoming color data from vertex shader

        out vec4 fragmentColor;

        void main()
        {
            fragmentColor = vec4(vertexColor);
        }
    );

} colorShader;

struct {
    const GLchar* vertexShaderSource = GLSL(440,
        layout(location = 0) in vec3 vertexPosition;    // VAP position 0 for vertex position data
        layout(location = 1) in vec4 vertexColor;       // VAP position 1 for vertex color data
        layout(location = 2) in vec2 textureCoordinate; // VAP position 2 for texture coordinate data
        layout(location = 3) in vec3 vertexNormal;      // VAP position 3 for vertex normal data
        layout(location = 4) in vec3 aTangent;          // VAP position 4 for normal Tangent Data
        layout(location = 5) in vec3 aBitangent;        // VAP position 5 for normal BiTangent Data

        out vec3 vertexFragmentPos;                     // outgoing fragment positions -> fragment shader
        out vec4 vertexColor;                           // outgoing colors -> fragmentShader
        out vec2 vertexTextureCoordinate;               // outgoing texture coordinates -> fragment shader
        out vec3 vertexFragmentNormal;                  // outgoing fragment normals -> fragment shader
        out vec3 TangentLightPos;                       // outgoing tangent light position -> fragment shader
        out vec3 TangentViewPos;                        // outgoing tangent view position -> fragment shader
        out vec3 TangentFragPos;                        // outgoing tangent fragment position -> fragment shader

        // Uniform Global variables for the transform matrices
        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;
        uniform vec3 lightPos;
        uniform vec3 viewPos;

        /**
        * Work in progress - partially functional, still needs calculations Tangent Space implemented
        */
        void main()
        {
            mat3 normalMatrix = transpose(inverse(mat3(model)));
            vec3 T = normalize(normalMatrix * aTangent);
            vec3 N = normalize(normalMatrix * vertexNormal);
            T = normalize(T - dot(T, N) * N);
            vec3 B = cross(N, T);

            mat3 TBN = transpose(mat3(T, B, N));
            TangentLightPos = TBN * lightPos;
            TangentViewPos = TBN * viewPos;
            TangentFragPos = TBN * vertexFragmentPos;

            gl_Position = projection * view * model * vec4(vertexPosition, 1.0f); // Transforms vertices into clip coordinates

            vertexFragmentPos = vec3(model * vec4(vertexPosition, 1.0f)); // Gets fragment / pixel position in world space only (exclude view and projection)

            vertexFragmentNormal = mat3(transpose(inverse(model))) * vertexNormal; // get normal vectors in world space only and exclude normal translation properties
            vertexTextureCoordinate = textureCoordinate;
        }
    );

    /* Surface Fragment Shader Source Code*/
    const GLchar* fragmentShaderSource = GLSL(440,

        in vec3 vertexFragmentNormal;           // incoming normals
        in vec3 vertexFragmentPos;              // incoming fragment position
        in vec2 vertexTextureCoordinate;        // incoming texture coordinates
        in vec3 TangentLightPos;                // incoming tangent light position
        in vec3 TangentViewPos;                 // incoming tangent view position
        in vec3 TangentFragPos;                 // incoming tangent fragment position

        out vec4 fragmentColor;                 // outgoing cube color -> the GPU

        // Uniform Global variables for object color, light color, light position, diffuseMap, texture,  normalMap and camera/view position
        uniform vec4 objectColor;
        uniform vec3 ambientColor;
        uniform vec3 light1Color;
        uniform vec3 light1Position;
        uniform vec3 light2Color;
        uniform vec3 light2Position;
        uniform vec3 viewPosition;
        uniform sampler2D uTexture;
        uniform vec2 uvScale;
        uniform sampler2D diffuseMap;
        uniform sampler2D normalMap;
        
        uniform bool ubHasTexture = true;               // Set to true only for transition to lighting textured objects, excluding non-textured objects
        uniform float ambientStrength = 0.1f;           // Set ambient or global lighting strength
        uniform float specularIntensity1 = 0.8f;        // Set specularIntensity1
        uniform float highlightSize1 = 16.0f;           // Set hightlightSize1
        uniform float specularIntensity2 = 0.8f;        // Set specularIntenxity2    
        uniform float highlightSize2 = 16.0f;           // Set highlightSize2



        //uniform vec3 lightPos;
        //uniform vec3 viewPos;

        void main()
        {
            /*
            * 
            **************** SECTION FOR IMPORTED NORMAL, DIFFUSE, AND SPECULAR MAPS *************
            * 
            // obtain normal from normal map in range [0,1]
            vec3 normal = texture(normalMap,vertexTextureCoordinates).rgb;
            // transform normal vector to range [-1,1]
            normal = normalize(normal * 2.0 - 1.0);  // this normal is in tangent space

            // get diffuse color
            vec3 color = texture(diffuseMap, vertexTextureCoordinates).rgb;
            // ambient
            vec3 ambient = 0.1 * color;
            // diffuse
            vec3 lightDir = normalize(TangentLightPos - TangentFragPos);
            float diff = max(dot(lightDir, normal), 0.0);
            vec3 diffuse = diff * color;
            // specular
            vec3 viewDir = normalize(TangentViewPos - TangentFragPos);
            vec3 reflectDir = reflect(-lightDir, normal);
            vec3 halfwayDir = normalize(lightDir + viewDir);
            float spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);

            vec3 specular = vec3(0.2) * spec;
            // fragmentColor = vec4(ambient + diffuse + specular, 1.0);

            ****************** END IMPORTED MAPS SECTION*********************************/


            /*Phong lighting model calculations to generate ambient, diffuse, and specular components*/

            //Calculate Ambient lighting/
            vec3 ambient = ambientStrength * ambientColor; // Generate ambient light color

            //**Calculate Diffuse lighting**
            vec3 norm = normalize(vertexFragmentNormal); // Normalize vectors to 1 unit
            vec3 light1Direction = normalize(light1Position - vertexFragmentPos); // Calculate distance (light direction) between light source and fragments/pixels on cube
            float impact1 = max(dot(norm, light1Direction), 0.0);// Calculate diffuse impact by generating dot product of normal and light
            vec3 diffuse1 = impact1 * light1Color; // Generate diffuse light color
            vec3 light2Direction = normalize(light2Position - vertexFragmentPos); // Calculate distance (light direction) between light source and fragments/pixels on cube
            float impact2 = max(dot(norm, light2Direction), 0.0);// Calculate diffuse impact by generating dot product of normal and light
            vec3 diffuse2 = impact2 * light2Color; // Generate diffuse light color

            //**Calculate Specular lighting**
            vec3 viewDir = normalize(viewPosition - vertexFragmentPos); // Calculate view direction
            vec3 reflectDir1 = reflect(-light1Direction, norm);// Calculate reflection vector
            //Calculate specular component
            float specularComponent1 = pow(max(dot(viewDir, reflectDir1), 0.0), highlightSize1);
            vec3 specular1 = specularIntensity1 * specularComponent1 * light1Color;
            vec3 reflectDir2 = reflect(-light2Direction, norm);// Calculate reflection vector
            //Calculate specular component
            float specularComponent2 = pow(max(dot(viewDir, reflectDir2), 0.0), highlightSize2);
            vec3 specular2 = specularIntensity2 * specularComponent2 * light2Color;

            //**Calculate phong result**
            //Texture holds the color to be used for all three components
            vec4 textureColor = texture(uTexture, vertexTextureCoordinate * uvScale);
            vec3 phong1;
            vec3 phong2;

            if (ubHasTexture == true)
            {
                phong1 = (ambient + diffuse1 + specular1) * textureColor.xyz;
                phong2 = (ambient + diffuse2 + specular2) * textureColor.xyz;
            }
            else
            {
                phong1 = (ambient + diffuse1 + specular1) * objectColor.xyz;
                phong2 = (ambient + diffuse2 + specular2) * objectColor.xyz;
            }

            fragmentColor = vec4(phong1 + phong2, 1.0); // Send lighting results to GPU
            //fragmentColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    );

} lotsOfLightsShader;

struct 
{
    const GLchar* cubeMapShaderSource = GLSL(440,
        layout(location = 0) in vec3 aPos;
        layout(location = 1) in vec3 aNormal;

        out vec3 Normal;
        out vec3 Position;

        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            Normal = mat3(transpose(inverse(model))) * aNormal;
            Position = vec3(model * vec4(aPos, 1.0));
            gl_Position = projection * view * model * vec4(aPos, 1.0);
        }
    );

    const GLchar* cubeMapFragmentSource = GLSL(440,
        out vec4 FragColor;

        in vec3 Normal;
        in vec3 Position;

        uniform vec3 cameraPos;
        uniform samplerCube skybox;

        void main()
        {
            vec3 I = normalize(Position - cameraPos);
            vec3 R = reflect(I, normalize(Normal));
            FragColor = vec4(texture(skybox, R).rgb, 1.0);
        }
    );

} cubeMapShaderShaderScript;

struct 
{
    const GLchar* skyboxShaderSource = GLSL(440,
        layout(location = 0) in vec3 aPos;

        out vec3 TexCoords;

        uniform mat4 projection;
        uniform mat4 view;

        void main()
        {
            TexCoords = aPos;
            vec4 pos = projection * view * vec4(aPos, 1.0);
            gl_Position = pos.xyww;
        }
    );

    const GLchar* skyboxFragmentSource = GLSL(440,
        out vec4 FragColor;

        in vec3 TexCoords;

        uniform samplerCube skybox;

        void main()
        {
            FragColor = texture(skybox, TexCoords);
    
        }
    );

} skyBoxShaderSource;

// Extras to pick through to figure out how to apply the properties
struct
{
    /* Cube Vertex Shader Source Code*/
    const GLchar* cubeVertexShaderSource = GLSL(440,

        layout(location = 0) in vec3 position; // VAP position 0 for vertex position data
    layout(location = 1) in vec3 normal; // VAP position 1 for normals
    layout(location = 2) in vec2 textureCoordinate;

    out vec3 vertexNormal; // For outgoing normals to fragment shader
    out vec3 vertexFragmentPos; // For outgoing color / pixels to fragment shader
    out vec2 vertexTextureCoordinate;

    //Uniform / Global variables for the  transform matrices
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    void main()
    {
        gl_Position = projection * view * model * vec4(position, 1.0f); // Transforms vertices into clip coordinates

        vertexFragmentPos = vec3(model * vec4(position, 1.0f)); // Gets fragment / pixel position in world space only (exclude view and projection)

        vertexNormal = mat3(transpose(inverse(model))) * normal; // get normal vectors in world space only and exclude normal translation properties
        vertexTextureCoordinate = textureCoordinate;
    }
    );

    /* Cube Fragment Shader Source Code*/
    const GLchar* cubeFragmentShaderSource = GLSL(440,

        in vec3 vertexNormal; // For incoming normals
    in vec3 vertexFragmentPos; // For incoming fragment position
    in vec2 vertexTextureCoordinate;

    out vec4 fragmentColor; // For outgoing cube color to the GPU

    // Uniform / Global variables for object color, light color, light position, and camera/view position
    uniform vec3 objectColor;
    uniform vec3 lightColor;
    uniform vec3 lightPos;
    uniform vec3 viewPosition;
    uniform sampler2D uTexture; // Useful when working with multiple textures
    uniform vec2 uvScale;

    void main()
    {
        /*Phong lighting model calculations to generate ambient, diffuse, and specular components*/

        //Calculate Ambient lighting*/
        float ambientStrength = 0.1f; // Set ambient or global lighting strength
        vec3 ambient = ambientStrength * lightColor; // Generate ambient light color

        //Calculate Diffuse lighting*/
        vec3 norm = normalize(vertexNormal); // Normalize vectors to 1 unit
        vec3 lightDirection = normalize(lightPos - vertexFragmentPos); // Calculate distance (light direction) between light source and fragments/pixels on cube
        float impact = max(dot(norm, lightDirection), 0.0);// Calculate diffuse impact by generating dot product of normal and light
        vec3 diffuse = impact * lightColor; // Generate diffuse light color

        //Calculate Specular lighting*/
        float specularIntensity = 0.8f; // Set specular light strength
        float highlightSize = 16.0f; // Set specular highlight size
        vec3 viewDir = normalize(viewPosition - vertexFragmentPos); // Calculate view direction
        vec3 reflectDir = reflect(-lightDirection, norm);// Calculate reflection vector
        //Calculate specular component
        float specularComponent = pow(max(dot(viewDir, reflectDir), 0.0), highlightSize);
        vec3 specular = specularIntensity * specularComponent * lightColor;

        // Texture holds the color to be used for all three components
        vec4 textureColor = texture(uTexture, vertexTextureCoordinate * uvScale);

        // Calculate phong result
        vec3 phong = (ambient + diffuse + specular) * textureColor.xyz;

        fragmentColor = vec4(phong, 1.0); // Send lighting results to GPU
    }
    );

    /* Lamp Shader Source Code*/
    const GLchar* lampVertexShaderSource = GLSL(440,

        layout(location = 0) in vec3 position; // VAP position 0 for vertex position data

    //Uniform / Global variables for the  transform matrices
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    void main()
    {
        gl_Position = projection * view * model * vec4(position, 1.0f); // Transforms vertices into clip coordinates
    }
    );

    /* Fragment Shader Source Code*/
    const GLchar* lampFragmentShaderSource = GLSL(440,

        out vec4 fragmentColor; // For outgoing lamp color (smaller cube) to the GPU

    void main()
    {
        fragmentColor = vec4(1.0f); // Set color to white (1.0f,1.0f,1.0f) with alpha 1.0
    }
    );

} NormalTextureShaderScript;
struct 
{
    /* Cube Vertex Shader Source Code*/
    const GLchar* cubeVertexShaderSource = GLSL(440,

        layout(location = 0) in vec3 position; // VAP position 0 for vertex position data
        layout(location = 1) in vec3 normal; // VAP position 1 for normals
        layout(location = 2) in vec2 textureCoordinate;

        out vec3 vertexNormal; // For outgoing normals to fragment shader
        out vec3 vertexFragmentPos; // For outgoing color / pixels to fragment shader
        out vec2 vertexTextureCoordinate;

        //Uniform / Global variables for the  transform matrices
        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(position, 1.0f); // Transforms vertices into clip coordinates

            vertexFragmentPos = vec3(model * vec4(position, 1.0f)); // Gets fragment / pixel position in world space only (exclude view and projection)

            vertexNormal = mat3(transpose(inverse(model))) * normal; // get normal vectors in world space only and exclude normal translation properties
            vertexTextureCoordinate = textureCoordinate;
        }
    );

    /* Cube Fragment Shader Source Code*/
    const GLchar* cubeFragmentShaderSource = GLSL(440,

        in vec3 vertexNormal; // For incoming normals
        in vec3 vertexFragmentPos; // For incoming fragment position
        in vec2 vertexTextureCoordinate;

        out vec4 fragmentColor; // For outgoing cube color to the GPU

        // Uniform / Global variables for object color, light color, light position, and camera/view position
        uniform vec3 objectColor;
        uniform vec3 lightColor;
        uniform vec3 lightPos;
        uniform vec3 viewPosition;
        uniform sampler2D uTexture; // Useful when working with multiple textures
        uniform vec2 uvScale;

        void main()
        {
            /*Phong lighting model calculations to generate ambient, diffuse, and specular components*/

            //Calculate Ambient lighting*/
            float ambientStrength = 0.1f; // Set ambient or global lighting strength
            vec3 ambient = ambientStrength * lightColor; // Generate ambient light color

            //Calculate Diffuse lighting*/
            vec3 norm = normalize(vertexNormal); // Normalize vectors to 1 unit
            vec3 lightDirection = normalize(lightPos - vertexFragmentPos); // Calculate distance (light direction) between light source and fragments/pixels on cube
            float impact = max(dot(norm, lightDirection), 0.0);// Calculate diffuse impact by generating dot product of normal and light
            vec3 diffuse = impact * lightColor; // Generate diffuse light color

            //Calculate Specular lighting*/
            float specularIntensity = 0.8f; // Set specular light strength
            float highlightSize = 16.0f; // Set specular highlight size
            vec3 viewDir = normalize(viewPosition - vertexFragmentPos); // Calculate view direction
            vec3 reflectDir = reflect(-lightDirection, norm);// Calculate reflection vector
            //Calculate specular component
            float specularComponent = pow(max(dot(viewDir, reflectDir), 0.0), highlightSize);
            vec3 specular = specularIntensity * specularComponent * lightColor;

            // Texture holds the color to be used for all three components
            vec4 textureColor = texture(uTexture, vertexTextureCoordinate * uvScale);

            // Calculate phong result
            vec3 phong = (ambient + diffuse + specular) * textureColor.xyz;

            fragmentColor = vec4(phong, 1.0); // Send lighting results to GPU
        }
    );

    /* Lamp Shader Source Code*/
    const GLchar* lampVertexShaderSource = GLSL(440,

        layout(location = 0) in vec3 position; // VAP position 0 for vertex position data

        //Uniform / Global variables for the  transform matrices
        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(position, 1.0f); // Transforms vertices into clip coordinates
        }
    );

    /* Fragment Shader Source Code*/
    const GLchar* lampFragmentShaderSource = GLSL(440,

        out vec4 fragmentColor; // For outgoing lamp color (smaller cube) to the GPU

        void main()
        {
            fragmentColor = vec4(1.0f); // Set color to white (1.0f,1.0f,1.0f) with alpha 1.0
        }
    );
} lightingFragment;
struct {
    const GLchar* vertexShader = GLSL(440,

        layout(location = 0) in vec3 aPos;
        layout(location = 1) in vec3 aNormal;

        out vec3 FragPos;
        out vec3 Normal;

        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            FragPos = vec3(model * vec4(aPos, 1.0));
            Normal = mat3(transpose(inverse(model))) * aNormal;

            gl_Position = projection * view * vec4(FragPos, 1.0);
        }

    );

    const GLchar* fragmentShader = GLSL(440,
        out vec4 FragColor;

        in vec3 Normal;
        in vec3 FragPos;

        uniform vec3 lightPos;
        uniform vec3 viewPos;
        uniform vec3 lightColor;
        uniform vec3 objectColor;

        void main()
        {
            // ambient
            float ambientStrength = 0.1;
            vec3 ambient = ambientStrength * lightColor;

            // diffuse 
            vec3 norm = normalize(Normal);
            vec3 lightDir = normalize(lightPos - FragPos);
            float diff = max(dot(norm, lightDir), 0.0);
            vec3 diffuse = diff * lightColor;

            // specular
            float specularStrength = 0.5;
            vec3 viewDir = normalize(viewPos - FragPos);
            vec3 reflectDir = reflect(-lightDir, norm);
            float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
            vec3 specular = specularStrength * spec * lightColor;

            vec3 result = (ambient + diffuse + specular) * objectColor;
            FragColor = vec4(result, 1.0);
        }
    );

} basicLighting;
struct {

    const char* vertexShader = GLSL(440,
        layout(location = 0) in vec3 aPos;

        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(aPos, 1.0);
        }
    );


    const char* fragmentShader = GLSL(440,
        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0); // set all 4 vector values to 1.0
        }
        
    );

} basicLightCube;
struct {
    const GLchar* normalVertShader = GLSL(440,
        layout(location = 0) in vec3 aPos;
        layout(location = 1) in vec3 aNormal;
        layout(location = 2) in vec2 aTexCoords;
        layout(location = 3) in vec3 aTangent;
        layout(location = 4) in vec3 aBitangent;

        out VS_OUT{
            vec3 FragPos;
            vec2 TexCoords;
            vec3 TangentLightPos;
            vec3 TangentViewPos;
            vec3 TangentFragPos;
        } vs_out;

        uniform mat4 projection;
        uniform mat4 view;
        uniform mat4 model;

        uniform vec3 lightPos;
        uniform vec3 viewPos;

        void main()
        {
            vs_out.FragPos = vec3(model * vec4(aPos, 1.0));
            vs_out.TexCoords = aTexCoords;

            mat3 normalMatrix = transpose(inverse(mat3(model)));
            vec3 T = normalize(normalMatrix * aTangent);
            vec3 N = normalize(normalMatrix * aNormal);
            T = normalize(T - dot(T, N) * N);
            vec3 B = cross(N, T);

            mat3 TBN = transpose(mat3(T, B, N));
            vs_out.TangentLightPos = TBN * lightPos;
            vs_out.TangentViewPos = TBN * viewPos;
            vs_out.TangentFragPos = TBN * vs_out.FragPos;

            gl_Position = projection * view * model * vec4(aPos, 1.0);
        }     
    );

    const GLchar* normalFragShader = GLSL(440, 
        out vec4 FragColor;

        in VS_OUT{
            vec3 FragPos;
            vec2 TexCoords;
            vec3 TangentLightPos;
            vec3 TangentViewPos;
            vec3 TangentFragPos;
        } fs_in;

        uniform sampler2D diffuseMap;
        uniform sampler2D normalMap;

        uniform vec3 lightPos;
        uniform vec3 viewPos;

        void main()
        {
            // obtain normal from normal map in range [0,1]
            vec3 normal = texture(normalMap, fs_in.TexCoords).rgb;
            // transform normal vector to range [-1,1]
            normal = normalize(normal * 2.0 - 1.0);  // this normal is in tangent space

            // get diffuse color
            vec3 color = texture(diffuseMap, fs_in.TexCoords).rgb;
            // ambient
            vec3 ambient = 0.1 * color;
            // diffuse
            vec3 lightDir = normalize(fs_in.TangentLightPos - fs_in.TangentFragPos);
            float diff = max(dot(lightDir, normal), 0.0);
            vec3 diffuse = diff * color;
            // specular
            vec3 viewDir = normalize(fs_in.TangentViewPos - fs_in.TangentFragPos);
            vec3 reflectDir = reflect(-lightDir, normal);
            vec3 halfwayDir = normalize(lightDir + viewDir);
            float spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);

            vec3 specular = vec3(0.2) * spec;
            FragColor = vec4(ambient + diffuse + specular, 1.0);
        }
    );
} moreAdvancedLighting;

#endif