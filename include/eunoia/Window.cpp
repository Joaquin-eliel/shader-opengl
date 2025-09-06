#include "Window.h"
#include "eunoia/Arch.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
Window::Window(GLuint w, GLuint h, const char* t) {
    try{
        if (!glfwInit()){
            throw -1;
        }

    }catch(int error){
        std::cerr << "ERROR INIT GLFW" << std::endl;
        std::cerr << "ERROR CODE: " << error << std::endl;
        glfwTerminate();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_ANGLE_PLATFORM_TYPE, GLFW_ANGLE_PLATFORM_TYPE_OPENGL);
    glfwWindowHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);

    int platform = glfwGetPlatform();
    glfwWindowHint(GLFW_PLATFORM, platform);

    if (platform == GLFW_PLATFORM_WAYLAND) {
        //                                    GLFW_WAYLAND_DISABLE_LIBDECOR
        glfwWindowHint(GLFW_WAYLAND_LIBDECOR, GLFW_WAYLAND_PREFER_LIBDECOR);

    } else if (platform == GLFW_PLATFORM_X11){
        glfwWindowHint(GLFW_X11_XCB_VULKAN_SURFACE, GLFW_FALSE);

    }else if (platform == GLFW_PLATFORM_COCOA){
        std::cout << "Se esta ejecutando en Ios.\n" << std::endl;
        glfwWindowHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_TRUE);
        glfwWindowHint(GLFW_COCOA_MENUBAR, GLFW_TRUE);
    }


    window = glfwCreateWindow(w,h,t,nullptr,nullptr);
    if(window == nullptr) {
        glfwDestroyWindow(window);
        glfwTerminate();
        std::cerr << "Error en crear ventana" << std::endl;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        std::cerr << "Error al Iniciar glad" << std::endl;
    }
    glViewport(0,0,w,h);
    std::cout << "setup callbacks" << std::endl;
    glfwSetFramebufferSizeCallback(window, set_framebuffer_callback);
    glfwSetKeyCallback(window, key_callback);


}

void Window::set_framebuffer_callback(GLFWwindow* window, int width, int height) {
    glViewport(0,0, width, height);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Window::addObj(Arch* obj) {objetos.push_back(obj);}

void Window::renderLoop() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        for (auto obj : objetos){obj->render();};

        glfwSwapBuffers(window);
    }
    std::cout << "apunto de salir del loop" << std::endl;
    for(auto obj : objetos){obj->remove();}
    glfwDestroyWindow(window);
    glfwTerminate();
}
