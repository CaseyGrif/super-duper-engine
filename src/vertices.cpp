#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "globs.h"
// declare vertex buffer object and vertex array object

unsigned int VAO[4];
unsigned int VBO[4];
unsigned int EBO;


float vertices[]{
	//// first triangle
	//// vertices			colors
	//-1.0f, 0.0f, 0.0f,  // left
	//-0.5f, 0.5f, 0.0f, // top
	//0.0f, 0.0f, 0.0f// right

	// first triangle
	// vertices			colors			tectures
	-1.0f, -1.0f, 0.0f, 1.0, 0.0, 0.0, 0.0, 0.0,// left
	0.0f, 1.0f, 0.0f, 0.0, 1.0, 0.0, 0.0, 0.0,// top
	1.0f, -1.0f, 0.0f, 0.0, 0.0, 1.0, 0.0, 0.0// right
};

float rectangle[]
{
	.5, 0.5, 0.0,// top right
	0.5, -0.5, 0.0,// top left
	-0.5, 0.5, 0.0,// bot right
	-0.5, -0.5, 0.0// bot left
};

float texCoords[]
{
	0.0, 0.0, // lower-left
	1.0, 0.0, // lower-right
	0.5, 1.0 // top-center
};



unsigned int indices[] =
{
	0, 1, 2,
	1, 2, 3
};


void gen_VBO_VAO(){

	// generates vertex array and buffers at corresponding memory addresses
	glGenVertexArrays(3, VAO);
	glGenBuffers(3, VBO);
	glGenBuffers(2, &EBO);


	// bind vertex array object first, then bind and set VBOs, then configure vertex attributes
	glBindVertexArray(VAO[0]);

	// bind array buffers to VBO.
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),  vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (8 * sizeof(float)), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (8 * sizeof(float)), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE(), 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// rectangle VAO/VBO
	//-----------------------------
	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);
	
	//// binds buffer to EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// second rectangle VAO/VBO
	//-----------------------------
	glBindVertexArray(VAO[2]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);

	// binds buffer to EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// how OpenGL will interpret vertex buffer objects
}








	