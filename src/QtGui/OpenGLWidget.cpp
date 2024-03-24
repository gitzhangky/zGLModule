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
    // Ϊ��ǰ������ʼ��OpenGL����
    initializeOpenGLFunctions();

    //�½���ɫ����������
    m_program = new QOpenGLShaderProgram(this);
    //���ض�����ɫ������
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    //����Ƭ����ɫ������
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    //������ɫ������
    m_program->link();
    //��ɫ������λ������
    m_posAttr = m_program->attributeLocation("posAttr");
    //�����Ƿ�ɹ�
    Q_ASSERT(m_posAttr != -1);
    //��ɫ��������ɫ����
    m_colAttr = m_program->attributeLocation("colAttr");
    //�����Ƿ�ɹ�
    Q_ASSERT(m_colAttr != -1);
    //����ͳһֵ
    m_matrixUniform = m_program->uniformLocation("matrix");
    //�����Ƿ�ɹ�
    Q_ASSERT(m_matrixUniform != -1);
}

void OpenGLWidget::paintGL()
{
    /*�����ɫ���棬��Ȼ��棬ģ�建��*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    //����ɫ������
    m_program->bind();

    QMatrix4x4 matrix;
    //����͸�Ӿ���
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    //����Z�Ḻ����ƽ��-2
    matrix.translate(0, 0, -2);
    //��Y����ת
    matrix.rotate(m_frame, 0, 1, 0);
    //Ϊ��ɫ�������뵱ǰ�任
    m_program->setUniformValue(m_matrixUniform, matrix);
    //��������������
    static const GLfloat vertices[] = {
         0.0f,  0.707f,
        -0.5f, -0.5f,
         0.5f, -0.5f
    };
    //������ÿ�������Ӧ����ɫֵ
    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };
    //Ϊ��ɫ�����ö�������
    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    //Ϊ��ɫ��������ɫ����
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    //���ö�����ɫ������
    glEnableVertexAttribArray(m_posAttr);
    //������ɫ��ɫ������
    glEnableVertexAttribArray(m_colAttr);
    //����������
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //�رն�����ɫ������
    glDisableVertexAttribArray(m_colAttr);
    //�ر���ɫ��ɫ������
    glDisableVertexAttribArray(m_posAttr);
    //�����ɫ��
    m_program->release();
    ++m_frame;
}

void OpenGLWidget::resizeGL(int width, int height)
{
    /*��ȡ�豸���ر�*/
    const qreal retinaScale = devicePixelRatio();
    //�����ӿ�
    glViewport(0, 0, width * retinaScale, height * retinaScale);
}
