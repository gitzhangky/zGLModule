#include "OpenGLWidget.h"
#include"Render.h"

#include<qmessagebox.h>
namespace widgets
{
	OpenGLWidget::OpenGLWidget(QWidget* parent) :QOpenGLWidget(parent)
	{

	}

	void OpenGLWidget::initializeGL()
	{
		render = new Render;
		bool isOk = render->initGlad();       //ע�⣺gladLoadGL()����д��initializeGL()�����У�������������ȿӣ�
		if (!isOk)
		{
			QMessageBox::warning(this, tr("error warning"), tr("Rendering library loading failed!"), QMessageBox::Ok);
		}
		render->initShaderProgram();
		render->init_Vertext();

	}

	void OpenGLWidget::paintGL()
	{
		render->paint();
	}


}

