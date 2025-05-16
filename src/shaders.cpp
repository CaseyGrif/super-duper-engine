#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globs.h"

const char* vertShaderResource = "#version 460 core\n"
// input variable created as vec3
// sets location of vec3 variable to 0
"layout (location = 0) in vec3 aPos;\n"

"void main()\n"
"{\n"
	"gl_Position = vec4(aPos, 1.0);\n"
"}\0";

const char* fragShaderResource =
"#version 460 core\n"
"out vec4 FragColor;\n"

"uniform vec4 color;\n"

//"in vec3 vertexColor;\n"


"void main()\n"
"{\n"
	"FragColor = color;\n"
"}\0";




unsigned int fragShader;
unsigned int vertShader;
unsigned int shaderProgram;

void compileFragShader()
{
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragShaderResource, NULL);
	glCompileShader(fragShader);

	int success;
	char infoLog[512];
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}




void compileVertShader()
{
	unsigned int vertShader = glCreateShader(GL_VERTEX_SHADER);	// creates vertex shader
	glShaderSource(vertShader, 1, &vertShaderResource, NULL);	// attaches vertex shader source code to vertexShader
	glCompileShader(vertShader);									// compiles shader

	int success;
	char infoLog[512];
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}


void linkShaders()
{
	// creates shader program object, attaches vertex and fragment shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);

	// links shaders attached to shaderProgram object
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINK_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}


void initShaders()
{
	// compiles and links shaders to shaderProgram
	compileVertShader();
	compileFragShader();

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	// deletes shaders after linking
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}