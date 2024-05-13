#include "Render.h"

#include<iostream>
#include"glad/glad.h"
#include"GLFW/glfw3.h"


const char* vertexShaderSource = "#version 330 core\n"             //将顶点着色器语言用字符串保存
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"             //将片段着色器语言用字符串保存
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource1 = "#version 330 core\n"             //将片段着色器语言用字符串保存
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 0.5f, 0.0f, 1.0f);\n"
"}\n\0";



bool Render::initGlad()
{

	if (!gladLoadGL())              //GLAD是用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化GLAD。
	{      //初始化glad
		return false;
	}

	return true;
}

void Render::loadShader()
{

	// build and compile our shader program
// ------------------------------------
// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);                  //新建顶点着色器对象

	shaderProgram = glCreateProgram();       //新建着色器程序
	shaderProgram1 = glCreateProgram();     //第二个着色器程序


	/*****************************************************************************************************************
	//将顶点着色器语言绑定到顶点着色器上，第一个参数时着色器对象，第二个参数源码字符串数量，第三个参数是着色器源码
*********************************************************************************************************************/
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);          //编译顶点着色器
	// check for shader compile errors
	int success;                            //用于判断着色器是否编译成功的对象
	char infoLog[512];                       //如果编译着色器失败，infoLog缓冲对象保存错误信息
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);          //用于判断着色器编译是否成功的函数接口
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);              //获取错误信息，并保存到infoLog中
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;     //打印错误信息
	}
	// fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);        //创建片段着色器对象
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);        //创建片段着色器对象
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
	unsigned int shaderProgram = glCreateProgram();       //新建着色器程序
	glAttachShader(shaderProgram, vertexShader);           //将顶点着色器附加到着色器程序中
	glAttachShader(shaderProgram, fragmentShader);         //将片段着色器附加到着色器程序中
	glLinkProgram(shaderProgram);                           //将程序对象中的着色器链接在一起
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);      //获取链接状态，如果链接出错，打印错误信息。
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);                 //着色器程序已经链接着色器，剩下的着色器没有作用，可以删除
	glDeleteShader(fragmentShader);

	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader1);
	glLinkProgram(shaderProgram1);
	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);      //获取链接状态，如果链接出错，打印错误信息。
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

	glGenVertexArrays(1, &VAO);          //生成顶点数组对象名称
	glGenBuffers(1, &VBO);               //生成顶点缓冲对象名称
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);               //绑定VAO

	glBindBuffer(GL_ARRAY_BUFFER, VBO);       //绑定VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);         //将顶点数据复制到缓冲空间中，供OpenGL使用

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
	设置顶点属性指针，第一个参数是配置顶点属性，与着色器语言的layout (location = 0)对应，第二个属性，指定顶点属性的大小
	第三个参数，指定数据类型，第四个参数定义是否希望参数标准化，第五个参数是连续的顶点属性数据的间隔
	最后一个参数它表示位置数据在缓冲中起始位置的偏移量(Offset)。由于位置数据在数组的开头，所以这里是0
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
	//glBindBuffer(GL_ARRAY_BUFFER, 0);        //将顶点数据复制到缓冲空间中，供OpenGL使用后，再将VBO顶点缓冲对象进行解绑

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	//glBindVertexArray(0);              //将VBO顶点数组对象进行解绑

	// uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// render loop
	// -----------
}

void Render::paint()
{


	// render
	// ------
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);        //设置清空屏幕所用的颜色
	glClear(GL_COLOR_BUFFER_BIT);                 //清空屏幕的颜色缓冲

	// draw our first triangle
	glUseProgram(shaderProgram);             //激活着色器程序
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 6);          //画三角形
	// glBindVertexArray(0); // no need to unbind it every time 
	glBindVertexArray(VAO1);
	glDrawArrays(GL_TRIANGLES, 0, 3);          //画三角形

	glUseProgram(shaderProgram1);             //激活着色器程序
	glBindVertexArray(VAO2); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);          //画三角形


	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------


}

Render::~Render()
{
}
