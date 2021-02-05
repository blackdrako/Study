#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL/QtOpenGL>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGL>
#include <object.h>
#include <QMatrix4x4>

class ViewWidget : public QGLWidget{
    // Глубина объекта
    float zoffset = 3;
    float xAngle = 90, yAngle = 0;
    QPoint pos;
    void drawObject();
    QString filename;
    Object currentObject;
public:
    ViewWidget(QWidget *);
    void resetProjection();
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent * event);
};

#endif // MAINWINDOW_H
