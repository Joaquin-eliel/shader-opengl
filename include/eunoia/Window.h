#pragma once
#include "eunoia/Arch.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <vector>

class Window {
    private:
        GLFWwindow* window;
        std::vector<Arch*> objetos;
        static void set_framebuffer_callback(GLFWwindow* window, int width, int height);
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    public:
        Window(GLuint w, GLuint h, const char* t);
        void renderLoop();
        void addObj(Arch* obj);
};
