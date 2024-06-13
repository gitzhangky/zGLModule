
/*
*���Ʊ�����ɫ
*/
#include<QVector>
#include<qvector3d.h>
#include"ShaderBase.h"
class background : public ShaderBase
{
public:
	background();
	background(QVector<QVector3D> _colors);

	void setVectorColor(QVector<QVector3D> _colors);
	QVector<QVector3D> getVectorColor();

	bool initShaderProgram();
	void updateBackground();
private:

	QVector<QVector<double>> vectorsColor;       //����λ�ú���ɫ
	unsigned int VAO;
	unsigned int VBO;
	unsigned int ProgramID;
};