
/*
*���Ʊ�����ɫ
*/
#include<vector>
#include"ShaderBase.h"
#include"glm/glm.hpp"

struct backgroundVertex       //����ṹ�壬����λ�ú���ɫ��Ϣ
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

	backgroundVertex verctex[6];       //�������
	unsigned int VAO;
	unsigned int VBO;
	unsigned int ProgramID;
};