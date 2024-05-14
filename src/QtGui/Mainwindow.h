#include <qmainwindow.h>
#include <qboxlayout.h>
#include"OpenGLWidget.h"

namespace Ui
{
	class Mainwindow;
}


namespace widgets
{
	class Mainwindow :public QMainWindow
	{
	public:
		Mainwindow(QWidget* parent = nullptr);


	private:
		OpenGLWidget* openGLWidget;
		Ui::Mainwindow* _ui;
	};

}

