
#ifndef RENDER_H__
#define RENDER_H__




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
	*��Ⱦͼ��
	*/
	void paint();


	/*
	*��������
	*/
	~Render();
private:
	unsigned int VBO, VAO;               //VAO�����������VBO���㻺�����

	unsigned int VAO1, VBO1;

	unsigned int VAO2, VBO2;

	unsigned int shaderProgram;       //�½���ɫ������

	unsigned int shaderProgram1;     //�ڶ�����ɫ������

};



#endif

