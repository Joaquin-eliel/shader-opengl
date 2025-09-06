#pragma once
#include "eunoia/Renderable.h"
#include "glad/glad.h"
#include "Shader.h"
class Arch : public Shader, public Renderable{
    private:
        GLuint VBO,VAO,EBO;
        float vertices[24] = { //XYZ   RGB
            -1.0f, -1.0f, 0.0f,  0.5f,0.0f,0.5f, //0
             1.0f, -1.0f, 0.0f,  0.5f,0.0f,0.5f, //1
             1.0f,  1.0f, 0.0f,  0.5f,0.0f,0.5f, //2
             -1.0f,  1.0f, 0.0f, 0.5f,0.0f,0.5f  //3
        };
        int vindex[6] = {
            0,1,3,
            1,2,3
        };
    public:
        Arch();
        void remove() override;
        void render() override;

};
