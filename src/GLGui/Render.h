
#ifndef RENDER_H__
#define RENDER_H__


#include"ShaderBase.h"

class background;
class Render :public ShaderBase
{
public:
	Render();
	/*
	* 初始化
	*/
	bool initGlad();

	/*
	*加载着色器
	*/
	bool initShaderProgram();

	/*
	*初始化顶点
	*/
	void init_Vertext();

	/*
	*渲染图像
	*/
	void paint();

	/*
	*析构函数
	*/
	~Render();

private:
	unsigned int VBO, VAO;               //VAO顶点数组对象，VBO顶点缓冲对象


	unsigned int shaderProgram;
	std::string shaderPath;
	background* _background;
};



#endif

