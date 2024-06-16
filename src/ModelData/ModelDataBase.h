
#include<QList>
#include"ModelBase.h"

class ModelDataBase
{
private:
	ModelDataBase();

public:
	~ModelDataBase() {};

	static ModelDataBase* getInstance();

	QList<ModelBase*> getAllModel();

	ModelBase* getModel(QString ID);

	QString getModelName(QString ID);

	MODELTYPE getModeltype(QString ID);

	QStringList getAllModelName();
private:

	static ModelDataBase* _instance;


	QList<ModelBase*> models;



};

