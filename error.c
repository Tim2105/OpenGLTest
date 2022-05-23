#include "error.h"
#include <stdio.h>

void glfw_error_callback(int err, const char* desc)
{
    printf("GLFW Error(%d): %s\n", err, desc);
}
