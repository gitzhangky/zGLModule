#include "Render.h"

#include<iostream>
#include"glad/glad.h"
#include"GLFW/glfw3.h"


const char* vertexShaderSource = "#version 330 core\n"             //��������ɫ���������ַ�������
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"             //��Ƭ����ɫ���������ַ�������
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource1 = "#version 330 core\n"             //��Ƭ����ɫ���������ַ�������
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 0.5f, 0.0f, 1.0f);\n"
"}\n\0";



bool Render::initGlad()
{

	if (!gladLoadGL())              //GLAD����������OpenGL�ĺ���ָ��ģ������ڵ����κ�OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD��
	{      //��ʼ��glad
		return false;
	}

	return true;
}

void Render::loadShader()
{

	// build and compile our shader program
// ------------------------------------
// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);                  //�½�������ɫ������

	shaderProgram = glCreateProgram();       //�½���ɫ������
	shaderProgram1 = glCreateProgram();     //�ڶ�����ɫ������


	/*****************************************************************************************************************
	//��������ɫ�����԰󶨵�������ɫ���ϣ���һ������ʱ��ɫ�����󣬵ڶ�������Դ���ַ�����������������������ɫ��Դ��
*********************************************************************************************************************/
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);          //���붥����ɫ��
	// check for shader compile errors
	int success;                            //�����ж���ɫ���Ƿ����ɹ��Ķ���
	char infoLog[512];                       //���������ɫ��ʧ�ܣ�infoLog������󱣴������Ϣ
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);          //�����ж���ɫ�������Ƿ�ɹ��ĺ����ӿ�
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);              //��ȡ������Ϣ�������浽infoLog��
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;     //��ӡ������Ϣ
	}
	// fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);        //����Ƭ����ɫ������
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);        //����Ƭ����ɫ������
	glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader1);
	glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	// check for shader compile errors
	// link shaders
	unsigned int shaderProgram = glCreateProgram();       //�½���ɫ������
	glAttachShader(shaderProgram, vertexShader);           //��������ɫ�����ӵ���ɫ��������
	glAttachShader(shaderProgram, fragmentShader);         //��Ƭ����ɫ�����ӵ���ɫ��������
	glLinkProgram(shaderProgram);                           //����������е���ɫ��������һ��
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);      //��ȡ����״̬��������ӳ�����ӡ������Ϣ��
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);                 //��ɫ�������Ѿ�������ɫ����ʣ�µ���ɫ��û�����ã�����ɾ��
	glDeleteShader(fragmentShader);

	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader1);
	glLinkProgram(shaderProgram1);
	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);      //��ȡ����״̬��������ӳ�����ӡ������Ϣ��
	if (!success) {
		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}


	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f,  // top   
		 0.5f,  0.0f, 0.0f,
		 1.0f, -0.5f, 0.0f,
		 0.5f, -1.0f, 0.0f
	};

	float vertices1[] = {
		-0.5f,  0.5f,  0.0f,
		 0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.0f
	};

	float vertices2[] = {
		-0.5f,  1.0f, 0.0f,
		-1.0f,  0.5f, 0.0f,
		-0.5f,  0.0f, 0.0f
	};

	glGenVertexArrays(1, &VAO);          //���ɶ��������������
	glGenBuffers(1, &VBO);               //���ɶ��㻺���������
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);               //��VAO

	glBindBuffer(GL_ARRAY_BUFFER, VBO);       //��VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);         //���������ݸ��Ƶ�����ռ��У���OpenGLʹ��

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);



	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1);

	glBindVertexArray(VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	/********************************************************************************
	���ö�������ָ�룬��һ�����������ö������ԣ�����ɫ�����Ե�layout (location = 0)��Ӧ���ڶ������ԣ�ָ���������ԵĴ�С
	������������ָ���������ͣ����ĸ����������Ƿ�ϣ��������׼��������������������Ķ����������ݵļ��
	���һ����������ʾλ�������ڻ�������ʼλ�õ�ƫ����(Offset)������λ������������Ŀ�ͷ������������0
	*****************************************************************************/

	unsigned int VAO2, VBO2;
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);

	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);



	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	//glBindBuffer(GL_ARRAY_BUFFER, 0);        //���������ݸ��Ƶ�����ռ��У���OpenGLʹ�ú��ٽ�VBO���㻺�������н��

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	//glBindVertexArray(0);              //��VBO�������������н��

	// uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// render loop
	// -----------
}

void Render::paint()
{


	// render
	// ------
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);        //���������Ļ���õ���ɫ
	glClear(GL_COLOR_BUFFER_BIT);                 //�����Ļ����ɫ����

	// draw our first triangle
	glUseProgram(shaderProgram);             //������ɫ������
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 6);          //��������
	// glBindVertexArray(0); // no need to unbind it every time 
	glBindVertexArray(VAO1);
	glDrawArrays(GL_TRIANGLES, 0, 3);          //��������

	glUseProgram(shaderProgram1);             //������ɫ������
	glBindVertexArray(VAO2); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);          //��������


	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------


}

Render::~Render()
{
}
