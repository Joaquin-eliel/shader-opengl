#pragma once
#include "glad/glad.h"
#include "Shader.h"
class Arch : public Shader{
    private:
        GLuint VBO,VAO,EBO;
        float vertices[12] = {
            -1.0f, -1.0f, 0.0f, //0
             1.0f, -1.0f, 0.0f, //1
             1.0f,  1.0f, 0.0f, //2
            -1.0f,  1.0f, 0.0f, //3
        };
        int vindex[6] = {
            0,1,3,
            1,2,3
        };
    public:
        Arch();
        void deleteArch();
        virtual void render() = 0;
        virtual ~Arch() = default;
};
