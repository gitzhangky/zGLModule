
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
	*��ȡ��ɫ��·��
	*/
	std::string getShaderPath(std::string type, std::string fileName);


	/*
	*��ȡ��ɫ������
	*/
	void readeShaderSource(std::string sourcePath, char* shaderBuffer);

	/*
	*�����ɫ���Ƿ���Ч
	*/
	bool checkCompileErrors(unsigned int shader, std::string type);

	/*
	*��ʼ����ɫ�����򣬳ɹ���ture��ʧ�ܣ�false
	*/
	virtual bool initShaderProgram() = 0;
};




#endif // !SHADERBASE_H__

