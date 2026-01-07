#pragma once
#include <iostream>

/** Shader program Macro - no more quoting every line with \n! */
#ifndef GLSL
#define GLSL(Version, Source) "#version " #Version " core \n" #Source

/** Scripts structs to feed into the ShapeObject class and make better reuse of it */
struct {
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

} lampShaders;

struct {
    const GLchar* vertexShaderSource = GLSL(440,
        layout(location = 0) in vec3 vertexPosition;    // VAP position 0 for vertex position data
        layout(location = 3) in vec4 vertexColor;       // VAP position 1 for vertex color data
        layout(location = 2) in vec2 textureCoordinate; // VAP position 2 for texture coordinate data
        layout(location = 1) in vec3 vertexNormal;      // VAP position 3 for vertex normal data
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
        uniform samplerCube skybox;
        
      

        /**
        * Work in progress - partially functional, still needs calculations Tangent Space implemented
        */
        void main()
        {   
            vertexFragmentPos = vec3(model * vec4(vertexPosition, 1.0f)); // Gets fragment / pixel position in world space only (exclude view and projection)
            vertexTextureCoordinate = textureCoordinate;
            
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

            vertexFragmentNormal = mat3(transpose(inverse(model))) * vertexNormal; // get normal vectors in world space only and exclude normal translation properties

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
        uniform vec3 light3Color;
        uniform vec3 light3Position;
        uniform sampler2D uTexture;
        uniform vec2 uvScale;
        uniform sampler2D diffuseMap;
        uniform sampler2D normalMap;
        
        uniform samplerCube skybox;

        uniform bool ubHasTexture = true;               // Set to true only for transition to lighting textured objects, excluding non-textured objects
        uniform float ambientStrength = 0.0f;           // Set ambient or global lighting strength
        uniform float specularIntensity1 = 0.8f;        // Set specularIntensity1
        uniform float highlightSize1 = 16.0f;           // Set hightlightSize1
        uniform float specularIntensity2 = 0.8f;        // Set specularIntenxity2    
        uniform float highlightSize2 = 16.0f;           // Set highlightSize2
        uniform float specularIntensity3 = 0.8f;        // Set specularIntenxity3    
        uniform float highlightSize3 = 16.0f;           // Set highlightSize3

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
            
            vec3 light3Direction = normalize(light3Position - vertexFragmentPos);
            
            float impact3 = max(dot(norm, light3Direction), 1.0);
            vec3 diffuse3 = impact3 * light3Color; 
            
            
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
            
            
            vec3 reflectDir3 = reflect(-light3Direction, norm);
            float specularComponent3 = pow(max(dot(viewDir, reflectDir3), 0.0), highlightSize3);
            vec3 specular3 = specularIntensity3 * specularComponent3 * light3Color;

            //vec4 fragColor = vec4(texture(skybox, reflectDir3).rgb, 1.0);
            //**Calculate phong result**
            //Texture holds the color to be used for all three components
            vec4 textureColor = texture(uTexture, vertexTextureCoordinate); //fragColor;


            vec3 phong1;
            vec3 phong2;
            vec3 phong3;

            if (ubHasTexture == true)
            {
                phong1 = ((ambient) + (diffuse1) + (specular1)) * textureColor.xyz;
                phong2 = ((ambient) + (diffuse2) + (specular2)) * textureColor.xyz;
                //phong3 = (ambient + diffuse3 + specular3) * textureColor.xyz;
            }
            else
            {
                phong1 = (ambient + diffuse1 + specular1) * objectColor.xyz;
                phong2 = (ambient + diffuse2 + specular2) * objectColor.xyz;
                //phong3 = (ambient + diffuse3 + specular3) * objectColor.xyz;
            };

            if (textureColor.a < 0.1)
                discard;

            fragmentColor = vec4((phong1 + (phong2 * 0.40f)), 1.0); // Send lighting results to GPU
            //fragColor = vec4(texture(skybox, R).rgb, 1.0);
            //fragmentColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    );

} lotsOfLightsShader;

#endif