
#ifndef MODELBASE
#define MODELBASE



#include<iostream>
#include<QString>
enum MODELTYPE       //类型枚举
{
	triangle,       //三角形
	quadrangle,      //四边形
	circle,          //圆形
	cube,            //立方体
	ball,            //球
	cylinder        //圆柱
};

class ModelBase
{
public:
	ModelBase(MODELTYPE _type, QString _name, QString _ID);
	~ModelBase() {};

	QString getName();   //获取名字

	void setName(QString _name);  //设置名字

	MODELTYPE getType();    //获取模型类型

	QString getTypeStr();

	QString getID();        //获取模型ID
private:
	void initTypeStr();

	QString typeStr;  //字符串形式的类型

	MODELTYPE type;   //类型

	QString name;     //名称

	QString ID;       //模型的唯一标识
};



#endif // !MODELBASE
