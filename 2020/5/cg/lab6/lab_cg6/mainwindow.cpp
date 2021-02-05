#include "mainwindow.h"
#include <GL/glu.h>

ViewWidget::ViewWidget(QWidget *parent)
    : QGLWidget(parent){
    this->resize(600, 600);
    currentObject = Object();
}

void ViewWidget::initializeGL(){
    // Включение сортировки по глубине
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    float light0Ambient[]  = { 0.0, 0.0, 0.0, 1.0 };
    float light0DiffSpec[] = { 1.0, 1.0, 1.0, 1.0 };
    float light0Position[] = { 0.0, 0.0, -5.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0DiffSpec);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0DiffSpec);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void ViewWidget::resizeGL(int nWidth, int nHeight){
    glViewport(0, 0, nWidth, nHeight);
    resetProjection();
}

void ViewWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.2f, 0.2f, 0.2f);

    float color[] = {0.7, 0.0, 0.0};
    float specularColor[] = {0.1, 0.1, 0.1};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);

    drawObject();
}

void ViewWidget::drawObject(){
    Object o = Object();
    o.read("z.obj");
    QVector <Vertex> v = o.getV();
    glBegin(GL_TRIANGLES);
        for (int i = 0; i < v.size(); i++){
            glVertex3f(v[i].position.x(), v[i].position.y(), v[i].position.z());
            glNormal3f(v[i].normal.x(), v[i].normal.y(), v[i].normal.z());
        }
    glEnd();
}

void ViewWidget::resetProjection(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Инициализация перспективной проекции
    gluPerspective(30.0, (float)width() / height(), 0.1, 10);
    glTranslatef(0, 0, -zoffset);
    glRotatef(xAngle, 1.0, 0.0, 0.0);
    glRotatef(yAngle, 0.0, 1.0, 0.0);
}

void ViewWidget::mouseMoveEvent(QMouseEvent* event){
    QPoint mp = event->pos();
    yAngle += mp.x() - pos.x();
    xAngle += mp.y() - pos.y();
    pos = mp;
    resetProjection();
    updateGL(); // Перерисовать окно
}

void ViewWidget::wheelEvent(QWheelEvent* event){
    zoffset -= event->delta() / 500.0;
    resetProjection();
    updateGL(); // Перерисовать окно
}

void ViewWidget::mousePressEvent(QMouseEvent *event){
    pos = event->pos();
}

void ViewWidget::keyPressEvent(QKeyEvent* event){
    if (event->key() == Qt::Key_Escape){
        close();
    }
}
