#include "Mainwindow.h"

Mainwindow::Mainwindow(QWidget* parent):QMainWindow(parent)
{
    QSurfaceFormat format;
    //设置每个每个像素采样样本个数，用于抗锯齿
    format.setSamples(16);

	resize(1200, 800);
	setWindowTitle("zGLModule");
	openglWidget = new OpenGLWidget;
    openglWidget->setFormat(format);
    openglWidget->resize(640, 480);
    openglWidget->StartAnimating();
	setCentralWidget(openglWidget);


}
