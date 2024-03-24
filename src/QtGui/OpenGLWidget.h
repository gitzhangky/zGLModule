#include<qopenglwidget.h>
#include <QOpenGLFunctions_3_3_Core>

static const char* vertexShaderSource =
"attribute highp vec4 posAttr;\n"
"attribute lowp vec4 colAttr;\n"
"varying lowp vec4 col;\n"
"uniform highp mat4 matrix;\n"
"void main() {\n"
"   col = colAttr;\n"
"   gl_Position = matrix * posAttr;\n"
"}\n";

static const char* fragmentShaderSource =
"varying lowp vec4 col;\n"
"void main() {\n"
"   gl_FragColor = col;\n"
"}\n";

class QOpenGLShaderProgram;

class OpenGLWidget :public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    /*Q_OBJECT*/

public:
    explicit OpenGLWidget(QWidget* parent = 0);
    ~OpenGLWidget();

public:
    void StartAnimating();
protected:
    /*初始化OpenGL资源和状态*/
    void initializeGL();
    /*渲染OpenGL场景*/
    void paintGL();
    /*设置OpenGL的视口、投影等。每次部件大小改变时都会调用该函数*/
    void resizeGL(int width, int height);

private:
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;

    QOpenGLShaderProgram* m_program = nullptr;

    int m_frame = 0;

    QTimer* m_timer;

};
