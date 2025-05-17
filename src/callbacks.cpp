#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globs.h"

// key press callback, given to glfwSetKeyCallback parameters
void key_pressed_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	switch (key)
	{

	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, true);
		break;
	default:
		std::cout << glfwGetKeyName(key, scancode) << std::endl;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
}