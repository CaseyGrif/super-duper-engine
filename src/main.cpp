
// vertex shader source code


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

// glm includes
//---------------------
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "globs.h"
#include "shaders.h"



// initialize global variables

int height;
int width;
double cursorPosX;
double cursorPosY;
GLFWwindow* window;
Cursor cursor;
int transformLoc;


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
	int transformLoc = glGetUniformLocation(newShader.ID, "transform");




	gen_VBO_VAO();



	
	newShader.use();


	
	// main render loop
	while (!glfwWindowShouldClose(window))
	{	

		glClearColor(0.0f, 0.3f, 0.0f, 0.0f);	// sets default clear color
		glClear(GL_COLOR_BUFFER_BIT);			// clears color buffer with clear color


		// finding mouse position & resolution
		// -----------------------------------
		glfwGetCursorPos(window, &cursorPosX, &cursorPosY); // grab cursor pos
		glfwGetWindowSize(window, &width, &height); // grab resolution

		// normalizes into float between 0-1
		cursor.x = cursorPosX / width;
		cursor.y = cursorPosY / height;
		glUniform2f(resolution, (float)width, (float)height);
		glUniform2f(mouse, cursor.x, cursor.y); // uniforms normalized cursor pos


		// debug console outputs
		// -----------------------
		// std::cout << (float)cursor.x << ", " << (float)cursor.y << std::endl;
		// std::cout << width << ", " << height << std::endl;
		
		newShader.use();

		float scaleFactor = static_cast<float>(sin(glfwGetTime())); // casts sin function into float type
		float rotationSpeed = 45;

		glm::mat4 transMat = glm::mat4(1.0f);
		// first container
		// send uniform transformation info, then draw
		/*---------------------------*/
		 // init transformation matrix w/ identity matrix
		transMat = glm::translate(transMat, glm::vec3(-0.5f, 0.0f, 0.0f)); // translates 1 left
		transMat = glm::rotate(transMat, glm::radians(float(glfwGetTime()) * rotationSpeed), glm::vec3(1.0f, 1.0f, 1.0f)); // rotates around Z axis
		transMat = glm::scale(transMat, glm::vec3(0.3f, 0.3f, 0.3f)); // scales by 1/3

		
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transMat)); // changes uniform data before drawing

		glBindVertexArray(VAO[1]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// second container
		// resets transMat to reset transformation info
		/*----------------------------*/
		transMat = glm::mat4(1.0f); // resets transformation matrix back to identity matrix
		transMat = glm::translate(transMat, glm::vec3(0.5f, 0.0f, 0.0f)); // translates 1 right
		transMat = glm::scale(transMat, glm::vec3(0.3f, 0.3f, 0.0f)); // scales by 1/3
		transMat = glm::scale(transMat, glm::vec3(scaleFactor, scaleFactor, scaleFactor)); // scales with sin(time passed)

		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transMat)); // changes uniform data before drawing

		glBindVertexArray(VAO[1]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		std::cout << static_cast<float>(sin(glfwGetTime())) << std::endl;

	





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

