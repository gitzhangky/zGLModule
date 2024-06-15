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
		bool isOk = render->initGlad();       //注意：gladLoadGL()必须写在initializeGL()函数中，否则会出错，避免踩坑！
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

