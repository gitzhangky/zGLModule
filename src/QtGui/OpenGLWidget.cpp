#include "OpenGLWidget.h"
#include"Render.h"

#include<qmessagebox.h>

OpenGLWidget::OpenGLWidget(QWidget* parent) :QOpenGLWidget(parent)
{

}

void OpenGLWidget::initializeGL()
{
	render = new Render;
	bool isOk = render->initGlad();       //×¢Òâ£ºgladLoadGL()±ØÐëÐ´ÔÚinitializeGL()º¯ÊýÖÐ£¬·ñÔò»á³ö´í£¬±ÜÃâ²È¿Ó£¡
	if (!isOk)
	{
		QMessageBox::warning(this, "´íÎóÌáÐÑ", "äÖÈ¾¿â¼ÓÔØÊ§°Ü!", QMessageBox::Ok);
	}

	render->loadShader();

}

void OpenGLWidget::paintGL()
{
	render->paint();
}


