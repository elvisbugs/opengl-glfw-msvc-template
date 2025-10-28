#ifndef _MAIN_H_
#define _MAIN_H_

#include "glad/glad.h"
#include "glfw/glfw3.h"

#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

#endif // _MAIN_H_