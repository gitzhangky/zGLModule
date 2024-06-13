#include "Render.h"

#include"glad/glad.h"




bool Render::initGlad()
{

	if (!gladLoadGL())              //GLAD����������OpenGL�ĺ���ָ��ģ������ڵ����κ�OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD��
	{      //��ʼ��glad
		return false;
	}

	return true;
}

bool Render::initShaderProgram()
{

	/******************
	������ɫ������
	������ɫ�������������ɫ��������
	��ɫ���������ɫ������(*.frag   *.vert)
	������ɫ����������ɫ����
	�ж������Ƿ�ɹ����ж��Ƿ����ɹ���
	ʹ����ɫ�����������ƬԪ
	*****************/

	shaderProgram = glCreateProgram();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


	/*
	*��ȡ��ɫ������
	*/
	std::string s_vertPath, s_fragPath;
	s_vertPath = getShaderPath("vertex", "001.vert");
	s_fragPath = getShaderPath("fragment", "001.frag");
	GLchar vertBuffer[512], fragBuffer[512];
	readeShaderSource(s_vertPath, vertBuffer);
	readeShaderSource(s_fragPath, fragBuffer);
	const char* vertSource = vertBuffer;
	const char* fragSource = fragBuffer;
	//������ɫ��
	glShaderSource(vertexShader, 1, &vertSource, nullptr);
	glCompileShader(vertexShader);
	if (!checkCompileErrors(vertexShader, "SHADER"))
	{
		return false;
	}
	//Ƭ����ɫ��
	glShaderSource(fragmentShader, 1, &fragSource, nullptr);
	glCompileShader(fragmentShader);

	if (!checkCompileErrors(fragmentShader, "SHADER"))
	{
		return false;
	}
	//������ɫ���������ɫ������
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	//����
	glLinkProgram(shaderProgram);
	if (!checkCompileErrors(shaderProgram, "PROGRAM"))
	{
		return false;
	}
	return true;
}

void Render::init_Vertext()
{
	/*******
	�������ͻ������
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

	// λ������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// ��ɫ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


}

void Render::paint()
{


	// render
	// ------
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);        //���������Ļ���õ���ɫ
	glClear(GL_COLOR_BUFFER_BIT);                 //�����Ļ����ɫ����

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);


}



Render::~Render()
{
}
