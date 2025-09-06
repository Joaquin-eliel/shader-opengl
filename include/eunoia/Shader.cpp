#include "Shader.h"
#include "glad/glad.h"
#include <fstream>
#include <iostream>
Shader::Shader(const char* veretxPath, const char* fragmentPath) {
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        vShaderFile.open(veretxPath);
        fShaderFile.open(fragmentPath);
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }catch(std::ifstream::failure e){
        std::cerr << "ERROR: EN LEER SHADERS" << std::endl;
    };
    vShaderCode = vertexCode.c_str();
    fShaderCode = fragmentCode.c_str();

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::useShader() {
    glUseProgram(ID);
}
void Shader::shaderDelete() {
    glDeleteProgram(ID);
}

void Shader::checkCompileErrors(GLuint shader, std::string type) {
    if(type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR:EN_COMPILACION_DE_SHADER de tipo: " << type << infoLog << "------------------------------" << std::endl;
        }else {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if(!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR:EN_LINKEANDO_PROGRAMA de tipo: " << type << infoLog << "------------------------------" << std::endl;
            }
        }
    }
}
