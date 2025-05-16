#define _USE_MATH_DEFINES

#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "globs.h"




float time;
float rValue, gValue, bValue;
int vertexColorLocation;


void changeColorOverTime()
{

	time = glfwGetTime();	
	rValue = ((sin(time + 1.57)) / 2) + 0.5;
	gValue = ((cos(time + 1.57)) / 2) + 0.5;
	bValue = (sin(time - (M_PI/4) / 2)) + 0.5;
	vertexColorLocation = glGetUniformLocation(shaderProgram, "color");

}

