
#ifndef RENDER_H__
#define RENDER_H__


#include"ShaderBase.h"


class Render :public ShaderBase
{
public:

	/*
	* ��ʼ��
	*/
	bool initGlad();

	/*
	*������ɫ��
	*/
	bool initShaderProgram();

	/*
	*��ʼ������
	*/
	void init_Vertext();

	/*
	*��Ⱦͼ��
	*/
	void paint();

	/*
	*��������
	*/
	~Render();

private:
	unsigned int VBO, VAO;               //VAO�����������VBO���㻺�����


	unsigned int shaderProgram;
	std::string shaderPath;

};



#endif

