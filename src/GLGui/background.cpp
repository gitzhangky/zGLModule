#include "background.h"
#include"glad/glad.h"
background::background()
{
	init();

}

background::background(std::vector<glm::vec3 > _colors)
{
	init();
	setVectorColor(_colors);
}

void background::init()
{
	verctex[0] = { {1.0,1.0,0.0},{0.67,0.76,1.0 } };
	verctex[1] = { {1.0,-1.0,0.0},{0.88,0.86,1.0 } };
	verctex[2] = { {-1.0,1.0,0.0},{0.91,0.88,1.0 } };
	verctex[3] = { {1.0,-1.0,0.0},{0.88,0.86,1.0 } };
	verctex[4] = { {-1.0,1.0,0.0},{0.91,0.88,1.0 } };
	verctex[5] = { {-1.0,-1.0,0.0},{1.0,1.0,1.0 } };


}

void background::setVectorColor(std::vector<glm::vec3 > _colors)
{
	for (int i = 0; i < 6; i++)
	{
		verctex[i].color = _colors[i];
	}


}

std::vector<glm::vec3 > background::getVectorColor()
{
	std::vector<glm::vec3 > _colors;
	for (int i = 0; i < _colors.size(); i++)
	{
		_colors[i] = verctex[i].color;
	}
	return _colors;
}

bool background::initShaderProgram()
{
	ProgramID = glCreateProgram();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


	/*
	*获取着色器代码
	*/
	std::string s_vertPath, s_fragPath;
	s_vertPath = getShaderPath("vertex", "001.vert");
	s_fragPath = getShaderPath("fragment", "001.frag");
	GLchar vertBuffer[512], fragBuffer[512];
	readeShaderSource(s_vertPath, vertBuffer);
	readeShaderSource(s_fragPath, fragBuffer);
	const char* vertSource = vertBuffer;
	const char* fragSource = fragBuffer;
	//顶点着色器
	glShaderSource(vertexShader, 1, &vertSource, nullptr);
	glCompileShader(vertexShader);
	if (!checkCompileErrors(vertexShader, "SHADER"))
	{
		return false;
	}
	//片段着色器
	glShaderSource(fragmentShader, 1, &fragSource, nullptr);
	glCompileShader(fragmentShader);

	if (!checkCompileErrors(fragmentShader, "SHADER"))
	{
		return false;
	}
	//关联着色器程序和着色器对象
	glAttachShader(ProgramID, vertexShader);
	glAttachShader(ProgramID, fragmentShader);
	//链接
	glLinkProgram(ProgramID);
	if (!checkCompileErrors(ProgramID, "PROGRAM"))
	{
		return false;
	}
	return true;
}

void background::init_Vertext()
{
	/*******
	顶点对象和缓冲对象
	*******/
	glCreateVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glCreateBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	int a = sizeof(verctex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verctex), &verctex, GL_STATIC_DRAW);

	// 位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(backgroundVertex), (void*)0);
	glEnableVertexAttribArray(0);
	// 颜色属性
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(backgroundVertex), (void*)(sizeof(glm::vec3)));
	glEnableVertexAttribArray(1);


}

void background::updateBackground()
{
	glUseProgram(ProgramID);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);


}
