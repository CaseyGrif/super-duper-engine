#include "framework.h"
#include "globs.h"
#include "objects.h"
#include "callbacks.h"
#include "shaders.h"


using namespace std;

int width = 800;
int height = 600;


int main()
{
	
	// initialize glfw
	/*--------------------*/
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create window
	/*-------------------*/
	GLFWwindow* window = glfwCreateWindow(width, height, "My Second Renderer", NULL, NULL);

	if (window == NULL) // check if failed window init
	{
		std::cout << "Window failed to initialize" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwShowWindow(window);
	// initialize glad
	/*-------------------*/
	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
	{
		std::cout << "GLAD failed to initialize" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);
	// set gl defaults and glfw callbacks


	glfwSetFramebufferSizeCallback(window, frame_buffersize_callback);
	glfwSetKeyCallback(window, keypress_callback);

	Shader shader;

	Object cube;

	Camera camera;
	shader.use();
	shader.send("texture1", 0);
	shader.send("texture2", 1);

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);


	shader.send("projection", projection);


	// render loop

	while (!glfwWindowShouldClose(window))
	{

		float time = getTime();
		glClearColor(0.2, 0.3, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cube.activateTex();

		shader.use();

		camera.view = glm::mat4(1.0f);
		camera.camPos = glm::vec3(sin(getTime()) * 10.0f, 2.0f, cos(getTime()) * 10.0f);
		camera.update();
		shader.send("view", camera.view);

		glBindVertexArray(cube.VAO);
		for (int i = 0; i < 2; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cube.cubePositions[i]);
			model = glm::rotate(model, glm::radians(10.0f * i), glm::vec3(1.0f, 1.0f, 1.0f));
			shader.send("model", model);


			cube.draw();

		}
		
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	return 0;
}

