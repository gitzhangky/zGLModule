
#ifndef RENDER_H__
#define RENDER_H__




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
	*渲染图像
	*/
	void paint();


	/*
	*析构函数
	*/
	~Render();
private:
	unsigned int VBO, VAO;               //VAO顶点数组对象，VBO顶点缓冲对象

	unsigned int VAO1, VBO1;

	unsigned int VAO2, VBO2;

	unsigned int shaderProgram;       //新建着色器程序

	unsigned int shaderProgram1;     //第二个着色器程序

};



#endif

