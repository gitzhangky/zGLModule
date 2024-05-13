#include "Mainwindow.h"

Mainwindow::Mainwindow(QWidget* parent) :QMainWindow(parent)
{
	openGLWidget = new OpenGLWidget(this);

	setCentralWidget(openGLWidget);
	this->resize(1200, 800);

}
