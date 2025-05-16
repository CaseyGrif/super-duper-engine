#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globs.h"
// declare vertex buffer object and vertex array object

unsigned int VAO[2];
unsigned int VBO[2];
unsigned int EBO;


float vertices1[]{
	//// first triangle
	//// vertices			colors
	//-1.0f, 0.0f, 0.0f,  // left
	//-0.5f, 0.5f, 0.0f, // top
	//0.0f, 0.0f, 0.0f// right

	// first triangle
	// vertices			colors
	-1.0f, 0.0f, 0.0f, 1.0, 0.0, 0.0, // left
	-0.5f, 0.5f, 0.0f, 0.0, 1.0, 0.0, // top
	0.0f, 0.0f, 0.0f, 0.0, 0.0, 1.0 // right
};

float vertices2[]
{
	// second triangle

	1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // right
	0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // top
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f // left
};

float rectangle[]
{
	1.0, 1.0, 0.0,// top right
	1.0, -1.0, 0.0,// top left
	-1.0, 1.0, 0.0,// bot right
	-1.0, -1.0, 0.0// bot left
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1) + sizeof(vertices2), vertices1, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices1), vertices1);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices1), sizeof(vertices2), vertices2);
	
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (6 * sizeof(float)), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (6 * sizeof(float)), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);



	//// binds buffer to EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// how OpenGL will interpret vertex buffer objects
}








	