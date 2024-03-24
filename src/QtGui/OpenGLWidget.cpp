#include<qtimer.h>
#include"OpenGLWidget.h"
#include<QMatrix4x4>
#include<QOpenGLShaderProgram>
OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
    m_timer = new QTimer(this);
    QObject::connect(m_timer, &QTimer::timeout, [this]() {
        this->update();
        
        });
}

OpenGLWidget::~OpenGLWidget()
{
    m_timer->deleteLater();
}

void OpenGLWidget::StartAnimating()
{
    m_timer->start(10);
}

void OpenGLWidget::initializeGL()
{
    // 为当前环境初始化OpenGL函数
    initializeOpenGLFunctions();

    //新建着色器程序处理工具
    m_program = new QOpenGLShaderProgram(this);
    //加载顶点着色器程序
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    //加载片段着色器程序
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    //链接着色器程序
    m_program->link();
    //着色器程序位置属性
    m_posAttr = m_program->attributeLocation("posAttr");
    //断言是否成功
    Q_ASSERT(m_posAttr != -1);
    //着色器程序颜色属性
    m_colAttr = m_program->attributeLocation("colAttr");
    //断言是否成功
    Q_ASSERT(m_colAttr != -1);
    //返回统一值
    m_matrixUniform = m_program->uniformLocation("matrix");
    //断言是否成功
    Q_ASSERT(m_matrixUniform != -1);
}

void OpenGLWidget::paintGL()
{
    /*清空颜色缓存，深度缓存，模板缓存*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    //绑定着色器程序
    m_program->bind();

    QMatrix4x4 matrix;
    //设置透视矩阵
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    //沿着Z轴负方向平移-2
    matrix.translate(0, 0, -2);
    //绕Y轴旋转
    matrix.rotate(m_frame, 0, 1, 0);
    //为着色器程序传入当前变换
    m_program->setUniformValue(m_matrixUniform, matrix);
    //三角形三个顶点
    static const GLfloat vertices[] = {
         0.0f,  0.707f,
        -0.5f, -0.5f,
         0.5f, -0.5f
    };
    //三角形每个顶点对应的颜色值
    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };
    //为着色器设置顶点属性
    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    //为着色器设置颜色属性
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    //启用顶点着色器属性
    glEnableVertexAttribArray(m_posAttr);
    //启用颜色着色器属性
    glEnableVertexAttribArray(m_colAttr);
    //绘制三角形
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //关闭顶点着色器属性
    glDisableVertexAttribArray(m_colAttr);
    //关闭颜色着色器属性
    glDisableVertexAttribArray(m_posAttr);
    //解绑着色器
    m_program->release();
    ++m_frame;
}

void OpenGLWidget::resizeGL(int width, int height)
{
    /*获取设备像素比*/
    const qreal retinaScale = devicePixelRatio();
    //设置视口
    glViewport(0, 0, width * retinaScale, height * retinaScale);
}
