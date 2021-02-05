#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <object.h>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QtOpenGL/QGLShaderProgram>
#include <QtOpenGL/QGLBuffer>
#include <QtOpenGL/QGLContext>

class ViewWidget : public QOpenGLWidget{
    Q_OBJECT
public:
    ViewWidget(QWidget *parent = nullptr);
    ~ViewWidget(){}

    void initializeGL() override;
    void resizeGL(int w , int h) override;
    void paintGL() override;
    void initShaders();

    void initObject();

    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool loadObject(QString filename);
private:
    QMatrix4x4 projectionMatrix, viewMatrix, modelMatrix, modelViewMatrix;
    QOpenGLShaderProgram shaderProgram;
    Object obj;
    QOpenGLBuffer arrayBuffer;
    QOpenGLBuffer indexBuffer;
    QString filename;
    //QOpenGLTexture texture;

};

#endif // VIEWWIDGET_H
