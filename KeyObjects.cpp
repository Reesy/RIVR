//
//  KeyObjects.cpp
//  RIVR
//
//  Created by James Rees on 23/03/2015.
//  Copyright (c) 2015 James Rees. All rights reserved.
//

#include "KeyObjects.h"
#include "TextureLoader.h"

KeyObjects::KeyObjects(){
    
}


void KeyObjects::generate(const char* filePath){
    this->collidable = true;
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,   -0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,    -1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,    -1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,    -1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,   -0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,   -0.0f, 0.0f,
        
        -0.5f, -0.5f,  0.5f,   0.0f, -0.0f,
        0.5f, -0.5f,  0.5f,    1.0f, -0.0f,
        0.5f,  0.5f,  0.5f,    1.0f, -1.0f,
        0.5f,  0.5f,  0.5f,    1.0f, -1.0f,
        -0.5f,  0.5f,  0.5f,   0.0f, -1.0f,
        -0.5f, -0.5f,  0.5f,   0.0f, -0.0f,
        
        -0.5f,  0.5f,  0.5f,  1.0f, -0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, -0.0f,
        
        0.5f,  0.5f,  0.5f,  1.0f, -0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, -1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, -0.0f,
        
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, -1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, -0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, -0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,- 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,
        
        -0.5f,  0.5f, -0.5f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, -1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, -0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, -0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, -0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, -1.0f
    };
    
    this->textureFilePath = filePath;
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
    
    image = SOIL_load_image(this->textureFilePath, &width, &height, 0, SOIL_LOAD_RGB);
    SOIL_free_image_data(image);
    this->keyTexture.Generate(width, height, image);

    

}

void KeyObjects::Draw(glm::mat4 view, glm::mat4 projection){
    
    keyTexture.Bind();
    
    glm::vec4 myTest(0, 0, 0, 1);
    
    glm::mat4 model;
    
    glm::mat4 mv;
    model = glm::translate(model, glm::vec3(this->getPosition().x, this->getPosition().y , this->getPosition().z));
  
  //  this->setTestPosition(model * myTest);
  
    
  //  model = glm::rotate(model, 20.f, glm::vec3(1, 0, 0));
    mv = model * view;
    model = glm::scale(model, glm::vec3(this->getScale().x, this->getScale().y, this->getScale().z));
    
    
    this->setTestPosition(mv * myTest);
    
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
    
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    
    
    

}

void KeyObjects::setShaderUniforms(Shader ourShader){
    modelLocation = glGetUniformLocation(ourShader.Program, "model");
    viewLocation = glGetUniformLocation(ourShader.Program, "view");
    projectionLocation = glGetUniformLocation(ourShader.Program, "projection");
    
}