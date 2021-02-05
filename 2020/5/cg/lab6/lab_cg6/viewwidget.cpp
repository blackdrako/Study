#include "viewwidget.h"
#include <QDebug>

ViewWidget::ViewWidget(QWidget *parent):
    QOpenGLWidget(parent), arrayBuffer(),
    indexBuffer(QOpenGLBuffer::IndexBuffer){
}

void ViewWidget::initializeGL(){
    qDebug() <<"initializeGL called!";
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    initShaders();
    initObject();
    qDebug() << "initializeGL done!";
}

void ViewWidget::initObject(){
    if (arrayBuffer.isCreated()) arrayBuffer.destroy();
    if (indexBuffer.isCreated()) indexBuffer.destroy();
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    obj.read("лампочка.obj");
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    QVector<Vertex> vertData = obj.getV();
    QVector<uint> indexes = obj.getIndicies();

    /*
    QVector<Vertex> vertData;
    QVector<uint> indexes;
    vertData.append (Vertex(QVector3D(0.5, 0.5, 0)));
    vertData.append (Vertex(QVector3D(-0.5, 0.5, 0)));
    vertData.append (Vertex(QVector3D(-0.5, -0.5, 0)));
    indexes.append(0);
    indexes.append(1);
    indexes.append(2);
    */

    arrayBuffer.create();
    arrayBuffer.bind();
    arrayBuffer.allocate(vertData.constData(), vertData.size()*sizeof(Vertex));
    arrayBuffer.release();

    indexBuffer.create();
    indexBuffer.bind();
    indexBuffer.allocate(indexes.constData(), indexes.size()*sizeof(uint));
    indexBuffer.release();

    projectionMatrix.setToIdentity();
    modelMatrix.setToIdentity();
    viewMatrix.setToIdentity();
}

void ViewWidget::resizeGL(int w, int h){
    float a = w/(float)h;
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45, a, 0.1f, 1000.0f);
}

void ViewWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //QMatrix4x4
    modelViewMatrix.setToIdentity();
    modelViewMatrix.scale(0.1f, 0.1f, 0.1f);
    modelViewMatrix.rotate(90, 1.0f, 0.0f, 0.0f);
    //modelViewMatrix.rotate(90, QVector3D(0.0f, 1.0f, 0.0f));

    shaderProgram.bind();
    shaderProgram.setUniformValue("qt_ModelViewProjectionMatrix", modelViewMatrix * projectionMatrix);
    shaderProgram.setUniformValue("qt_Texture0", 0);

    arrayBuffer.bind();

    int offset = 0;
    int vertLoc = shaderProgram.attributeLocation("qt_Vertex");
    shaderProgram.enableAttributeArray(vertLoc);
    shaderProgram.setAttributeBuffer(vertLoc, GL_FLOAT, offset, 3, sizeof(Vertex));


    indexBuffer.bind();

    glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);
    //arrayBuffer.release();
    //indexBuffer.release();

}
void ViewWidget::initShaders(){
    if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vshader.vert")){
        qDebug() << "ошибка добавления вершинного шейдера";
        close();
    }
    if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fshader.frag")){
        qDebug() << "ошибка добавления фрагментного шейдера";
        close();
    }
    if (!shaderProgram.link()){
        qDebug() << "ошибка линковки шейдеров";
        close();
    }
}

void ViewWidget::wheelEvent(QWheelEvent *event){


}

void ViewWidget::mousePressEvent(QMouseEvent *event){

}

void ViewWidget::mouseMoveEvent(QMouseEvent *event){


}

bool ViewWidget::loadObject(QString filename){
    bool result = obj.read(filename);
    if (result){
    }
    return result;
}
