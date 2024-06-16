#include "ModelBase.h"
#include<QObject>
ModelBase::ModelBase(MODELTYPE _type, QString _name, QString _ID)
{
	type = _type;
	name = _name;
	initTypeStr();
	ID = _ID;
}

QString ModelBase::getName()
{
	return name;
}

void ModelBase::setName(QString _name)
{
	name = _name;
}

MODELTYPE ModelBase::getType()
{
	return type;
}

QString ModelBase::getTypeStr()
{
	return typeStr;
}

QString ModelBase::getID()
{
	return ID;
}


void ModelBase::initTypeStr()
{
	switch (type)
	{
	case triangle:
		typeStr = QObject::tr("triangle");
		break;
	case quadrangle:
		typeStr = QObject::tr("quadrangle");
		break;
	case circle:
		typeStr = QObject::tr("circle");
		break;
	case cube:
		typeStr = QObject::tr("cube");
		break;
	case ball:
		typeStr = QObject::tr("ball");
		break;
	case cylinder:
		typeStr = QObject::tr("cylinder");
		break;
	}

}
