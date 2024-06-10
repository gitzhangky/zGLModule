
#ifndef RENDER_H__
#define RENDER_H__

#include<iostream>
#include <filesystem>

#include  <direct.h>  
#include  <stdio.h> 



class Render
{
public:

	/*
	* 初始化
	*/
	bool initGlad();

	/*
	*加载着色器
	*/
	void loadShader();

	/*
	*初始化顶点
	*/
	void init_Vertext();

	/*
	*渲染图像
	*/
	void paint();

	/*
	*读取着色器代码
	*/
	void readeShaderSource(std::string sourcePath, char* shaderBuffer);

	/*
	*获取着色器路径
	*/
	std::string getShaderPath(std::string type, std::string fileName);

	/*
	*析构函数
	*/
	~Render();

	/*
	*检查着色器是否有效
	*/
	void checkCompileErrors(unsigned int shader, std::string type);
private:
	unsigned int VBO, VAO;               //VAO顶点数组对象，VBO顶点缓冲对象


	unsigned int shaderProgram;
	std::string shaderPath;

};



#endif

