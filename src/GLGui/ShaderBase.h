
#ifndef SHADERBASE_H__
#define SHADERBASE_H__


#include<string>
#include<iostream>
#include <filesystem>

#include  <direct.h>  
#include  <stdio.h> 
class ShaderBase
{
public:
	/*
	*获取着色器路径
	*/
	std::string getShaderPath(std::string type, std::string fileName);


	/*
	*读取着色器代码
	*/
	void readeShaderSource(std::string sourcePath, char* shaderBuffer);

	/*
	*检查着色器是否有效
	*/
	bool checkCompileErrors(unsigned int shader, std::string type);

	/*
	*初始化着色器程序，成功：ture，失败：false
	*/
	virtual bool initShaderProgram() = 0;
};




#endif // !SHADERBASE_H__

