#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct cguiWindow
{
    GLFWwindow* window;
    size_t pos;
}cguiWindow;

cguiWindow* cguiCreateWindow(int, int, const char*);

void cguiDestroyWindow(cguiWindow*);

void cguiLoop();

#endif // WINDOW_H_INCLUDED
