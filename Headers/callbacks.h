#pragma once
#include "framework.h"

void frame_buffersize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
}

