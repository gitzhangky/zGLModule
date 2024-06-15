#include<stdio.h>
#include"src/QtGui/Mainwindow.h"
#include<qapplication.h>
int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	widgets::Mainwindow* window = new widgets::Mainwindow;
	window->showMaximized();
	return app.exec();

}