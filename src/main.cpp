
// vertex shader source code


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globs.h"
#include "shaders.h"



// initialize global variables
int height;
int width;
double cursorPosX;
double cursorPosY;
GLFWwindow* window;
Cursor cursor;



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

	// compile and link shaders
	Shader newShader("shaders/vShader.txt", "shaders/fShader.txt");
	int mouse = glGetUniformLocation(newShader.ID, "u_mouse");
	int resolution = glGetUniformLocation(newShader.ID, "u_resolution");

	gen_VBO_VAO();

	newShader.use();


	
	// main render loop
	while (!glfwWindowShouldClose(window))
	{	

		glClearColor(0.2f, 0.3f, 0.3f, 0.0f);	// sets default clear color
		glClear(GL_COLOR_BUFFER_BIT);			// clears color buffer with clear color


		// finding mouse position & resolution
		// -----------------------------------
		glfwGetCursorPos(window, &cursorPosX, &cursorPosY); // grab cursor pos
		glfwGetWindowSize(window, &width, &height); // grab resolution

		// normalizes into float between 0-1
		cursor.x = cursorPosX / width;
		cursor.y = cursorPosY / height;
		glUniform2f(mouse, cursor.x, cursor.y); // uniforms normalized cursor pos


		std::cout << (float)cursor.x << std::endl;
		std::cout << (float)cursor.y << std::endl;

		//changeColorOverTime();
		// draws trianlge

		newShader.use();
		
		glBindVertexArray(VAO[1]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		//glDrawArrays(GL_TRIANGLES, 2, 3);

		

		// check for events
		// swaps buffers		
		glfwSwapBuffers(window);
		glfwPollEvents();	




	}
	// de-allocates resources
	glDeleteVertexArrays(1, &VAO[0]);
	glDeleteBuffers(1, &VBO[0]);
	

	glfwTerminate();
	return 0;
}

