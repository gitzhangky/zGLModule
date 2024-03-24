#include <qmainwindow.h>
#include <qboxlayout.h>
#include"OpenGLWidget.h"

class Mainwindow :public QMainWindow
{
public:
	Mainwindow(QWidget* parent = nullptr);






private:
	QVBoxLayout* mainLayout;
	OpenGLWidget* openglWidget;
};
