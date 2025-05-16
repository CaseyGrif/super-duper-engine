
// vertex shader source code


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globs.h"


// initialize global variables
int height;
int width;
int key;
GLFWwindow* window;



int main()
{
	// initializes GLFW
	glfwInit();

	// glfwWindowHint configures GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create window object
	window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);

	// terminate GLFW if window failed to make
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// makes context of window the main context on current thread
	glfwMakeContextCurrent(window);

	// initializes GLAD with glfwGetProcAddress, which defines correct function
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);



			
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// callback created for resizing window
	glfwSetKeyCallback(window, key_pressed_callback);					// callback for key presses


	initShaders();

	gen_VBO_VAO();

	
	// main render loop
	while (!glfwWindowShouldClose(window))
	{	

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// sets default clear color
		glClear(GL_COLOR_BUFFER_BIT);			// clears color buffer with clear color

		changeColorOverTime();
		// draws trianlge
		glUseProgram(shaderProgram);
		glUniform4f(vertexColorLocation,  rValue, gValue, bValue, 1.0);
		glBindVertexArray(VAO[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);	
		
		glBindVertexArray(VAO[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(0);

		// check for events
		// swaps buffers		
		glfwSwapBuffers(window);
		glfwPollEvents();	


	}
	
	glfwTerminate();
	return 0;
}

