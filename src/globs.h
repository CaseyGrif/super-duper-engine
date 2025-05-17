#pragma once
// glm includes
//---------------------
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include "shaders.h"



extern unsigned int VBO[];
extern unsigned int VAO[];
extern unsigned int EBO;
extern float rectangle[];
extern 	int transformLoc;




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



