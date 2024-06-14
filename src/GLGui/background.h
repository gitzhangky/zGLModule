
/*
*绘制背景颜色
*/
#include<vector>
#include"ShaderBase.h"
#include"glm/glm.hpp"

struct backgroundVertex       //顶点结构体，包含位置和颜色信息
{
	glm::vec3 pos;
	glm::vec3 color;
};
class background : public ShaderBase
{
public:
	background();
	background(std::vector<glm::vec3 > _colors);
	void init();
	void setVectorColor(std::vector<glm::vec3> _colors);
	std::vector<glm::vec3> getVectorColor();

	bool initShaderProgram();
	void init_Vertext();
	void updateBackground();
private:

	backgroundVertex verctex[6];       //顶点对象
	unsigned int VAO;
	unsigned int VBO;
	unsigned int ProgramID;
};