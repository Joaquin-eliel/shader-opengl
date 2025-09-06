#include "eunoia/Window.h"
#include "eunoia/Arch.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

int main(void) {

    auto window = std::make_unique<Window>(400,400,"Hola");
    Arch arc = Arch();
    window->addObj(&arc);
    window->renderLoop();
    std::cout << "chau" << std::endl;
   return 0;
}
