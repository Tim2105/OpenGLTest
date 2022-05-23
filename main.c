#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "error.h"
#include "window.h"

int main()
{
    glfwSetErrorCallback(glfw_error_callback);

    if(!glfwInit())
    {
        printf("GLFW initialization failed\n");
        return -1;
    }

    printf("GLFW initialized\n");

    cguiCreateWindow(1200, 800, "Test");

    cguiCreateWindow(800, 600, "Test2");

    cguiLoop();

    glfwTerminate();

    return 0;
}
