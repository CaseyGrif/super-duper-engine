#pragma once
#include "framework.h"

void frame_buffersize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
}


void keypress_callback(GLFWwindow* window, int key, int action, int scancode, int mods)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
