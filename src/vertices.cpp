#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globs.h"
// declare vertex buffer object and vertex array object

unsigned int VAO[2];
unsigned int VBO[2];
unsigned int EBO;

// left triangle
float vertices1[]{
	-1.0f, 0.0f, 0.0f, // top right
	-0.5f, 0.5f, 0.0f, // bottom right
	0.0f, 0.0f, 0.0f, // top left
};

// right triangle
float vertices2[]{
	// second triangle
	1.0f, 0.0f, 0.0f, // bottom right
	0.5f, 0.5f, 0.0f, // bottom left
	0.0f, 0.0f, 0.0f // top left
};

unsigned int indices[] =
{
	0, 1, 2,
	1, 2, 3
};


void gen_VBO_VAO(){

	// generates vertex array and buffers at corresponding memory addresses
	glGenVertexArrays(2, VAO);
	glGenBuffers(2, VBO);
	glGenBuffers(1, &EBO);


	// bind vertex array object first, then bind and set VBOs, then configure vertex attributes
	glBindVertexArray(VAO[0]);

	// bind array buffers to VBO.
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// second triangle setup
	glBindVertexArray(VAO[1]);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//// binds buffer to EBO
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// how OpenGL will interpret vertex buffer objects
}








	