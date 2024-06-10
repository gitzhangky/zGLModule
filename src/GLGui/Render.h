
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
	* ��ʼ��
	*/
	bool initGlad();

	/*
	*������ɫ��
	*/
	void loadShader();

	/*
	*��ʼ������
	*/
	void init_Vertext();

	/*
	*��Ⱦͼ��
	*/
	void paint();

	/*
	*��ȡ��ɫ������
	*/
	void readeShaderSource(std::string sourcePath, char* shaderBuffer);

	/*
	*��ȡ��ɫ��·��
	*/
	std::string getShaderPath(std::string type, std::string fileName);

	/*
	*��������
	*/
	~Render();

	/*
	*�����ɫ���Ƿ���Ч
	*/
	void checkCompileErrors(unsigned int shader, std::string type);
private:
	unsigned int VBO, VAO;               //VAO�����������VBO���㻺�����


	unsigned int shaderProgram;
	std::string shaderPath;

};



#endif

