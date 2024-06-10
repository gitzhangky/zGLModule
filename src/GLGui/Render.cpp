#include "Render.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



bool Render::initGlad()
{

	if (!gladLoadGL())              //GLAD是用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化GLAD。
	{      //初始化glad
		return false;
	}

	return true;
}

void Render::loadShader()
{

	/******************
	创建着色器程序
	创建着色器对象关联到着色器程序中
	着色器对象绑定着色器代码(*.frag   *.vert)
	链接着色器（编译着色器）
	判断链接是否成功（判断是否编译成功）
	使用着色器来处理顶点和片元
	*****************/

	shaderProgram = glCreateProgram();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


	/*
	*获取着色器代码
	*/
	std::string s_vertPath, s_fragPath;
	s_vertPath = getShaderPath("vertex", "001.vert");
	s_fragPath = getShaderPath("fragment", "001.frag");
	GLchar vertBuffer[512], fragBuffer[512];
	readeShaderSource(s_vertPath, vertBuffer);
	readeShaderSource(s_fragPath, fragBuffer);
	const char* vertSource = vertBuffer;
	const char* fragSource = fragBuffer;
	//顶点着色器
	glShaderSource(vertexShader, 1, &vertSource, nullptr);
	glCompileShader(vertexShader);
	checkCompileErrors(vertexShader, "SHADER");

	//片段着色器
	glShaderSource(fragmentShader, 1, &fragSource, nullptr);
	glCompileShader(fragmentShader);
	checkCompileErrors(fragmentShader, "SHADER");

	//关联着色器程序和着色器对象
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	//链接
	glLinkProgram(shaderProgram);
	checkCompileErrors(shaderProgram, "PROGRAM");

}

void Render::init_Vertext()
{
	/*******
	顶点对象和缓冲对象
	*******/
	glCreateVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glCreateBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	float vertex[] = {
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	// 位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// 颜色属性
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


}

void Render::paint()
{


	// render
	// ------
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);        //设置清空屏幕所用的颜色
	glClear(GL_COLOR_BUFFER_BIT);                 //清空屏幕的颜色缓冲

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);


}

void Render::readeShaderSource(std::string sourcePath, char* shaderBuffer)
{
	std::string Code;
	std::ifstream ShaderFile;
	// ensure ifstream objects can throw exceptions:
	ShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		ShaderFile.open(sourcePath);
		std::stringstream ShaderStream;
		// read file's buffer contents into streams
		ShaderStream << ShaderFile.rdbuf();
		// close file handlers
		ShaderFile.close();

		// convert stream into string
		Code = ShaderStream.str();
		std::strcpy(shaderBuffer, Code.c_str());
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
	}

}

std::string Render::getShaderPath(std::string type, std::string fileName)
{

	char buff[100];
	getcwd(buff, 100);
	std::string path = buff;
	if (type == "fragment")
	{
		shaderPath = path + "\\..\\src\\GLSL\\Fragment\\" + fileName;
	}
	else if (type == "vertex")
	{
		shaderPath = path + "\\..\\src\\GLSL\\Vertex\\" + fileName;
	}
	return shaderPath;

}

void Render::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}

Render::~Render()
{
}
