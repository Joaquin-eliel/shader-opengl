#pragma once
#include "glad/glad.h"
#include <string>
#include <sstream>
#include <fstream>
class Shader {
    private:
        int success;
        char infoLog[1024];
        GLuint vertexShader, fragmentShader, ID;
        void checkCompileErrors(GLuint shader, std::string type);
        std::string vertexCode, fragmentCode;
        const char* vShaderCode;
        const char* fShaderCode;
        std::stringstream vShaderStream, fShaderStream;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
    public:
        Shader(const char* veretxPath, const char* fragmentPath);
        void useShader();
        void shaderDelete();
};
