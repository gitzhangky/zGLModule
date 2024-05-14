#include<qopenglwidget.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
class Render;


namespace widgets
{
	class OpenGLWidget :public QOpenGLWidget
	{
	public:
		/*
		*构造函数
		*/
		OpenGLWidget(QWidget* parent = nullptr);

		/*
		*重写，初始化openGL
		*/
		void initializeGL()override;

		/*
		*重写，绘制图像
		*/
		void paintGL()override;


	private:

		Render* render;
	};

}
