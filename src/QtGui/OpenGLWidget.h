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
		*���캯��
		*/
		OpenGLWidget(QWidget* parent = nullptr);

		/*
		*��д����ʼ��openGL
		*/
		void initializeGL()override;

		/*
		*��д������ͼ��
		*/
		void paintGL()override;


	private:

		Render* render;
	};

}
