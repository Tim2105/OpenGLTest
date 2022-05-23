#include <stdio.h>
#include <stdlib.h>
#include "window.h"

cguiWindow** windows = NULL;
size_t length = 0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

cguiWindow* cguiCreateWindow(int width, int height, const char* msg)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(width, height, msg, NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSetKeyCallback(window, key_callback);

    cguiWindow* result = (cguiWindow*)malloc(sizeof(cguiWindow));
    result->window = window;
    result->pos = length;

    windows = (cguiWindow*)realloc(windows, sizeof(GLFWwindow*) * (length + 1));
    windows[length] = result;

    length++;

    return result;
}

void cguiDestroyWindow(cguiWindow* window)
{
    for(size_t i = window->pos; i < length - 1; i++)
        windows[i] = windows[i + 1];

    glfwDestroyWindow(window->window);

    free(window);

    windows = (cguiWindow*)realloc(windows, sizeof(GLFWwindow*) * (length - 1));

    length--;
}

void cguiLoop()
{
    while(length > 0)
    {
        for(size_t i = 0; i < length; i++)
        {
            GLFWwindow* window = windows[i]->window;

            glfwMakeContextCurrent(window);

            glfwSwapBuffers(window);

            if(glfwWindowShouldClose(window))
            {
                cguiDestroyWindow(windows[i]);
                i--;
            }
        }

        glfwPollEvents();
    }
}
