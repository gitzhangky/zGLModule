#include "Mainwindow.h"
#include"ui_Mainwindow.h"

namespace widgets
{
	Mainwindow::Mainwindow(QWidget* parent) :QMainWindow(parent)
	{
		_ui = new Ui::Mainwindow;
		_ui->setupUi(this);


		openGLWidget = new OpenGLWidget(this);

		QHBoxLayout* hLayout = new QHBoxLayout(_ui->widget);
		hLayout->addWidget(openGLWidget);
		hLayout->setMargin(0);
		this->resize(1200, 800);

	}

}
