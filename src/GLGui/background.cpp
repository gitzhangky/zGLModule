#include "background.h"
background::background()
{
	vectorsColor =
	{
		{1.0,1.0,0.0,0.93,0.94,1.0},
		{1.0,-1.0,0.0,0.88,0.86,1.0},
		{-1.0,1.0,0.0,0.91,0.88,1.0},
		{-1.0,-1.0,0.0,0.91,0.93,1.0}
	};

}

background::background(QVector<QVector3D> _colors)
{
	vectorsColor =
	{
		{1.0,1.0,0.0,0.93,0.94,1.0},
		{1.0,-1.0,0.0,0.88,0.86,1.0},
		{-1.0,1.0,0.0,0.91,0.88,1.0},
		{-1.0,-1.0,0.0,0.91,0.93,1.0}
	};

	setVectorColor(_colors);
}

void background::setVectorColor(QVector<QVector3D> _colors)
{
	for (int i = 0; i < vectorsColor.size(); i++)
	{
		vectorsColor[i][3] = _colors[i][0];
		vectorsColor[i][4] = _colors[i][1];
		vectorsColor[i][5] = _colors[i][2];

	}


}

QVector<QVector3D> background::getVectorColor()
{
	QVector<QVector3D> _colors;
	for (int i = 0; i < vectorsColor.size(); i++)
	{
		_colors[i][0] = vectorsColor[i][3];
		_colors[i][1] = vectorsColor[i][4];
		_colors[i][2] = vectorsColor[i][5];
	}
	return _colors;
}

bool background::initShaderProgram()
{
	return false;
}

void background::updateBackground()
{
}
