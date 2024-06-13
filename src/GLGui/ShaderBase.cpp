
#include"ShaderBase.h"
#include"glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
std::string ShaderBase::getShaderPath(std::string type, std::string fileName)
{
	std::string shaderPath;
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

void ShaderBase::readeShaderSource(std::string sourcePath, char* shaderBuffer)
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

bool ShaderBase::checkCompileErrors(unsigned int shader, std::string type)
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
			return false;
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
				return false;
			}
		}

		return true;
	}
}