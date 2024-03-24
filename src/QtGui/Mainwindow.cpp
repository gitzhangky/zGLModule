#include "Mainwindow.h"

Mainwindow::Mainwindow(QWidget* parent):QMainWindow(parent)
{
    QSurfaceFormat format;
    //����ÿ��ÿ�����ز����������������ڿ����
    format.setSamples(16);

	resize(1200, 800);
	setWindowTitle("zGLModule");
	openglWidget = new OpenGLWidget;
    openglWidget->setFormat(format);
    openglWidget->resize(640, 480);
    openglWidget->StartAnimating();
	setCentralWidget(openglWidget);


}
