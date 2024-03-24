#include<stdio.h>
#include"src/QtGui/Mainwindow.h"
#include<qapplication.h>
int main(int argc ,char** argv)
{
	QApplication app(argc, argv);
	Mainwindow* window = new Mainwindow;
	window->show();
	return app.exec();

}