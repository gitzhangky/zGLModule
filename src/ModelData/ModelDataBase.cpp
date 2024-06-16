#include "ModelDataBase.h"



ModelDataBase* ModelDataBase::_instance = nullptr;

ModelDataBase* ModelDataBase::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ModelDataBase;
	}

	return _instance;
}

QList<ModelBase*> ModelDataBase::getAllModel()
{
	return models;
}

ModelBase* ModelDataBase::getModel(QString ID)
{
	if (models.size() == 0)
		return nullptr;

	int i = 0;
	for (; i < models.size(); i++)
	{
		if (models[i]->getID() == ID)
		{
			return models[i];
		}
	}

	if (i == models.size())
	{
		return nullptr;
	}

}

QString ModelDataBase::getModelName(QString ID)
{
	QString name = "";

	if (models.size() == 0)
		return "";

	int i = 0;
	for (; i < models.size(); i++)
	{
		if (models[i]->getID() == ID)
		{
			return models[i]->getName();
		}
	}
	if (i == models.size())
	{
		return "";
	}

}

MODELTYPE ModelDataBase::getModeltype(QString ID)
{
	MODELTYPE type;

	if (models.size() == 0)
		return type;

	int i = 0;
	for (; i < models.size(); i++)
	{
		if (models[i]->getID() == ID)
		{
			return models[i]->getType();
		}
	}
	if (i == models.size())
	{
		return type;
	}


}

QStringList ModelDataBase::getAllModelName()
{
	QStringList nameList;
	for (ModelBase* model : models)
	{
		nameList << model->getName();
	}
	return nameList;
}


