#include "framework.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>





using namespace std;



class Shader
{
public:
	unsigned int program;

	Shader()
	{
		std::string vertSource, fragSource;
		std::stringstream vertStream, fragStream;
		unsigned int vertShader, fragShader;
		std::ifstream readFile;
		readFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		try
		{
			// opens, reads buffer to stream, streams into source
			//----------------------
			readFile.open("vertShader.glsl");
			vertStream << readFile.rdbuf();
			vertSource = vertStream.str();
			readFile.close();

			readFile.open("fragShader.glsl");
			fragStream << readFile.rdbuf();
			fragSource = fragStream.str();
			readFile.close();
		}
		catch (const std::ios_base::failure& e)
		{
			cerr << "Could not open " << readFile.get() << endl;
		}
		const char* vertShaderCode = vertSource.c_str();
		const char* fragShaderCode = fragSource.c_str();

		// vertex shader
		//--------------

		GLint success;
		vertShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertShader, 1, &vertShaderCode, NULL);
		glCompileShader(vertShader);
		glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
		if (!success)
			cerr << "Vertex shader failed to link" << endl;
		// fragment shader
		//--------------
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShader, 1, &fragShaderCode, NULL);
		glCompileShader(fragShader);
		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
		if (!success)
			cerr << "Fragment shader failed to link" << endl;
		// program linkage
		//---------------
		program = glCreateProgram();
		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			cout << "shader linkage error" << endl;
		}


	}

	void use()
	{
		glUseProgram(program);
	}

	// vector uniforms
	//----------------
	void send(const char* uniLocationName, glm::vec2 name)
	{
		glUniform2fv(glGetUniformLocation(program, uniLocationName), 1, glm::value_ptr(name));
	}
	void send(const char* uniLocationName, glm::vec3 name)
	{
		glUniform3fv(glGetUniformLocation(program, uniLocationName), 1, glm::value_ptr(name));
	}
	void send(const char* uniLocationName, glm::vec4 name)
	{
		glUniform4fv(glGetUniformLocation(program, uniLocationName), 1, glm::value_ptr(name));
	}
	void send(const char* uniLocationName, glm::vec1 name)
	{
		glUniform1fv(glGetUniformLocation(program, uniLocationName), 1, glm::value_ptr(name));
	}


	// matrix uniforms
	//----------------
	void send(const char* uniLocationName, glm::mat2 name)
	{
		glUniformMatrix2fv(glGetUniformLocation(program, uniLocationName), 1, GL_FALSE, glm::value_ptr(name));
	}
	void send(const char* uniLocationName, glm::mat3 name)
	{
		glUniformMatrix3fv(glGetUniformLocation(program, uniLocationName), 1, GL_FALSE, glm::value_ptr(name));
	}
	void send(const char* uniLocationName, glm::mat4 name)
	{
		glUniformMatrix4fv(glGetUniformLocation(program, uniLocationName), 1, GL_FALSE, glm::value_ptr(name));
	}
	void send(const char* uniLocationName, int x, int y)
	{
		glUniform2i(glGetUniformLocation(program, uniLocationName), x, y);
	}

	// int uniform
	//-------------
	void send(const char* uniLocationName, int x)
	{
		glUniform1i(glGetUniformLocation(program, uniLocationName), x);
	}
};







