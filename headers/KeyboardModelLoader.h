//
//  KeyboardModelLoader.h
//  RIVR
//
//  Created by James Rees on 13/03/2015.
//  Copyright (c) 2015 James Rees. All rights reserved.
//

#ifndef RIVR_KeyboardModelLoader_h
#define RIVR_KeyboardModelLoader_h
#include "Shader.h"
#include <SOIL.h>

struct keys{
    int ID;
    TextureLoader letter;
    std::string Output;
    int x, y;
    
};


class KeyBoardModelLoader{
private:
    GLuint VAO, VBO;
    GLint modelLocation;
    GLint viewLocation;
    GLint projectionLocation;
   // glm::mat4 model;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
 
    
    TextureLoader letterA;
    TextureLoader letterB;
    TextureLoader letterC;
    TextureLoader letterD;
    TextureLoader letterE;
    TextureLoader letterF;
    TextureLoader letterG;
    TextureLoader letterH;
    TextureLoader letterI;
    TextureLoader letterJ;
    
    TextureLoader letterX;
    
    void generate_buffers()
    {
        GLfloat vertices1[] = {
            -0.5f, -0.5f, -0.5f,   0.0f, -0.0f,
             0.5f, -0.5f, -0.5f,   1.0f, -0.0f,
             0.5f,  0.5f, -0.5f,   1.0f, -1.0f,
             0.5f,  0.5f, -0.5f,   1.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,   0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,   0.0f, -0.0f,
            
      
        };
        
        GLfloat vertices[] = {
            -0.5f, -0.5f, -0.5f,   0.0f, -0.0f,
            0.5f, -0.5f, -0.5f,    1.0f, -0.0f,
            0.5f,  0.5f, -0.5f,    1.0f, -1.0f,
            0.5f,  0.5f, -0.5f,    1.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,   0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,   0.0f, -0.0f,
            
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
            
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        };
        // Create buffers/arrays
        glGenVertexArrays(1, &this->VAO);
        glGenBuffers(1, &this->VBO);
        
        
        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        // TexCoord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);
        
        glBindVertexArray(0); // Unbind VAO
        
        
        int width, height;
        unsigned char* image;
        
        
        //Textues are loaded here.
        
        image = SOIL_load_image("Resources/Textures/lettera.png", &width, &height, 0, SOIL_LOAD_RGB);
        SOIL_free_image_data(image);
        letterA.Generate(width, height, image);
       
        image = SOIL_load_image("Resources/Textures/letterb.png", &width, &height, 0, SOIL_LOAD_RGB);
        SOIL_free_image_data(image);
        letterB.Generate(width, height, image);
        
        image = SOIL_load_image("Resources/Textures/letterx.png", &width, &height, 0, SOIL_LOAD_RGB);
        SOIL_free_image_data(image);
        letterX.Generate(width, height, image);
        
        
        
        
    }
    void handle_shaders(Shader ourShader){
        
        //Define camera uniforms for shader.
        modelLocation = glGetUniformLocation(ourShader.Program, "model");
        viewLocation = glGetUniformLocation(ourShader.Program, "view");
        projectionLocation = glGetUniformLocation(ourShader.Program, "projection");
    }
public:
    KeyBoardModelLoader(GLfloat vertices[], Shader myShader){
       
        this->generate_buffers();
        this->handle_shaders(myShader);
        
        projection = glm::perspective(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);
    }
    
    void Draw(){
        
        
        std::string filePath;
        std::string currentLetter;
        
   /*
        for(int i = 97; i < 123; i++){
     
            currentLetter = "letter";
            currentLetter.push_back((char)i);
          
        }
    
    */
        letterA.Bind();
        
        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0, 0, -6));
        model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
        
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(this->VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
        
        
        
        
        letterB.Bind();
        
    
        model = glm::translate(model, glm::vec3(1, 0, 0));
       
        
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
        
        glBindVertexArray(this->VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        
        
        
        
    }
 
    
};


#endif
