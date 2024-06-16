
#ifndef MODELBASE
#define MODELBASE



#include<iostream>
#include<QString>
enum MODELTYPE       //����ö��
{
	triangle,       //������
	quadrangle,      //�ı���
	circle,          //Բ��
	cube,            //������
	ball,            //��
	cylinder        //Բ��
};

class ModelBase
{
public:
	ModelBase(MODELTYPE _type, QString _name, QString _ID);
	~ModelBase() {};

	QString getName();   //��ȡ����

	void setName(QString _name);  //��������

	MODELTYPE getType();    //��ȡģ������

	QString getTypeStr();

	QString getID();        //��ȡģ��ID
private:
	void initTypeStr();

	QString typeStr;  //�ַ�����ʽ������

	MODELTYPE type;   //����

	QString name;     //����

	QString ID;       //ģ�͵�Ψһ��ʶ
};



#endif // !MODELBASE
