#pragma once
#include "shaders.h"



extern unsigned int VBO[];
extern unsigned int VAO[];
extern unsigned int EBO;


extern int vertexColorLocation;

// global functions

extern void key_pressed_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
extern void gen_VBO_VAO();
extern void changeColorOverTime();

class Cursor
{
public:
	float x;
	float y;
};


