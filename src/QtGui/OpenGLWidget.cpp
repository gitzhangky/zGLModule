#include "OpenGLWidget.h"
#include"Render.h"

#include<qmessagebox.h>

OpenGLWidget::OpenGLWidget(QWidget* parent) :QOpenGLWidget(parent)
{

}

void OpenGLWidget::initializeGL()
{
	render = new Render;
	bool isOk = render->initGlad();       //ע�⣺gladLoadGL()����д��initializeGL()�����У�������������ȿӣ�
	if (!isOk)
	{
		QMessageBox::warning(this, "��������", "��Ⱦ�����ʧ��!", QMessageBox::Ok);
	}

	render->loadShader();

}

void OpenGLWidget::paintGL()
{
	render->paint();
}


