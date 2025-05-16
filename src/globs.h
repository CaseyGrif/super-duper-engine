#pragma once

extern unsigned int VBO[];
extern unsigned int VAO[];
extern unsigned int EBO;

extern unsigned int shaderProgram;
extern unsigned int shaderProgram2;
extern int vertexColorLocation;

// global functions
extern void initShaders();
extern void key_pressed_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
extern void gen_VBO_VAO();
extern void changeColorOverTime();

// global colors to use
extern float rValue, gValue, bValue;