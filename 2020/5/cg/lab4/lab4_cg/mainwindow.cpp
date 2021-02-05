#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    timerId = startTimer(1000);
    range = 0;
    f = Cubes(range);
    globalScale = 1;
    view = 0;
    ui->central->setChecked(1);
    pos = QPointF(0, 0);

}

MainWindow::~MainWindow(){
    delete ui;
}

float maxSize(QVector3D& v){
    if (v.x() > v.y())
        if(v.x() > v.z()) return v.x();
        else return v.z();
    else if (v.y() > v.z()) return v.y();
        else return v.z();
}

void MainWindow::paintEvent(QPaintEvent * e){
    QPainter painter(this);
    drawLines(painter);
    drawProjections(painter, f);
    draw3D(painter, f, view);
}

void MainWindow::drawLines(QPainter &painter){
    painter.save();
    int ax = ui->tl->geometry().center().x();
    int ay = ui->tl->geometry().center().y();
    int bx = ui->tr->geometry().center().x();
    int by = ui->tr->geometry().center().y();
    int cx = ui->bl->geometry().center().x();
    int cy = ui->bl->geometry().center().y();

    painter.setPen(Qt::blue);
    painter.drawLine(QLine(QPoint(ax / 2, ay), QPoint(bx + ax / 2, by)));
    painter.drawLine(QLine(QPoint(ax, ay / 2), QPoint(cx, cy + ay / 2)));
    painter.restore();
}

void MainWindow::drawProjections(QPainter &painter, Object &obj){
    QVector3D center = obj.getCenter();
    QVector3D size = obj.getSize();

    float k = qMax(ui->br->width(), ui->br->height())/maxSize(size)/2*(1+(globalScale)/100.f);

    QVector <QPolygonF> polygons;
    QPolygonF polygon;
    const QVector<QVector<QVector3D>>currentObject = obj.getObject();
    QVector3D v;

    QMatrix4x4 M;
    //Вид спереди
    M.translate(ui->tl->geometry().center().x(), ui->tl->geometry().center().y());
    M.scale(k, -k, k);
    M.translate(-center);

    for (int i = 0; i < currentObject.size(); i++){
        for(int j = 0; j < currentObject.at(i).size(); j++){
            v.setX(currentObject.at(i).at(j).x());
            v.setY(currentObject.at(i).at(j).y());
            v.setZ(currentObject.at(i).at(j).z());
            v = M*v;
            polygon << QPointF(v.x(), v.y());
        }
        polygons << polygon;
        polygon.clear();
    }
    for (int i = 0; i < polygons.size(); i++)
        painter.drawPolygon(polygons.at(i));
    polygons.clear();

    M.setToIdentity();
    M.translate(ui->bl->geometry().center().x(), ui->bl->geometry().center().y());
    M.rotate(90, QVector3D(1, 0, 0));
    M.scale(k, -k, k);
    M.translate(-center);

    for (int i = 0; i < currentObject.size(); i++){
        for(int j = 0; j < currentObject.at(i).size(); j++){
            v.setX(currentObject.at(i).at(j).x());
            v.setY(currentObject.at(i).at(j).y());
            v.setZ(currentObject.at(i).at(j).z());
            v = M*v;
            polygon << QPointF(v.x(), v.y());
        }
        polygons << polygon;
        polygon.clear();
    }
    for (int i = 0; i < polygons.size(); i++)
        painter.drawPolygon(polygons.at(i));
    polygons.clear();

    //Вид сбоку
    M.setToIdentity();
    M.translate(ui->tr->geometry().center().x(), ui->tr->geometry().center().y());
     M.rotate(90, QVector3D(0, 1, 0));
    M.scale(k, -k, k);
    M.translate(-center);

    for (int i = 0; i < currentObject.size(); i++){
        for(int j = 0; j < currentObject.at(i).size(); j++){
            v.setX(currentObject.at(i).at(j).x());
            v.setY(currentObject.at(i).at(j).y());
            v.setZ(currentObject.at(i).at(j).z());
            v = M*v;
            polygon << QPointF(v.x(), v.y());
        }
        polygons << polygon;
        polygon.clear();
    }
    for (int i = 0; i < polygons.size(); i++)
        painter.drawPolygon(polygons.at(i));
    polygons.clear();
}

void MainWindow::draw3D(QPainter &painter, Object &obj, int view){
    float c, k;

    QVector3D size = obj.getSize();
    float scale = qMax(ui->br->width(),
                       ui->br->height()) / maxSize(size) / 2 * (1 + (globalScale) / 100.f);

    QMatrix4x4 M, projectionMatrix;
    switch (view){
        case 0: c = 200 + ctrlMouseWheelCount;
                //Центральная проекция
                projectionMatrix = {1,   0,   0,   0,
                                    0,   1,   0,   0,
                                    0,   0,   0,   0,
                                    0,   0, -1/c,  1};
                break;
        case 1: k = qCos(M_PI_4)/2;
                //Косоугольная кабинетная проекция
                projectionMatrix = {1,   0,   k,   0,
                                    0,   1,   k,   0,
                                    0,   0,   0,   0,
                                    0,   0,   0,   1};
                break;
        case 2: k = qCos(M_PI_4);
                //Косоугольная свободная проекция
                projectionMatrix = {1,   0,   k,   0,
                                    0,   1,   k,   0,
                                    0,   0,   0,   0,
                                    0,   0,   0,   1};
                break;
        case 3:
                //Ортогональная проекция
                projectionMatrix = {1,   0,   0,   0,
                                    0,   1,   0,   0,
                                    0,   0,   0,   0,
                                    0,   0,   0,   1};
                break;
    }

    M.translate(ui->br->geometry().center().x(),
                ui->br->geometry().center().y(),
                0);

    QVector3D center = obj.getCenter();

    M = M * projectionMatrix;
    M = M * rotationMatrix.transposed();
    M.scale(scale, -scale, scale );
    M.translate(-center);

    QVector<QPolygonF> polygons;
    QPolygonF polygon;
    const QVector<QVector<QVector3D>> currentObject = obj.getObject();
    QVector4D v;

    for (int i = 0; i < currentObject.size(); i++){
        for(int j = 0; j < currentObject.at(i).size(); j++){
            v.setX(currentObject.at(i).at(j).x());
            v.setY(currentObject.at(i).at(j).y());
            v.setZ(currentObject.at(i).at(j).z());
            v.setW(1);
            v = M * v;
            polygon << QPointF(v.x()/v.w(), v.y()/v.w());
        }
        polygons << polygon;
        polygon.clear();
    }
    for (int i = 0; i < polygons.size(); i++)
        painter.drawPolygon(polygons.at(i));
}

void MainWindow::on_zoomInc_clicked(){
    globalScale += 10;
    this->repaint();
}

void MainWindow::on_zoomDec_clicked(){
    if (globalScale > 10)
        globalScale -= 10;
    this->repaint();
}

void MainWindow::on_central_clicked(){
    ui->central->setChecked(1);
    ui->cabinet->setChecked(0);
    ui->free->setChecked(0);
    ui->ortogonal->setChecked(0);
    view = 0;
    this->repaint();
}

void MainWindow::on_cabinet_clicked(){
    ui->central->setChecked(0);
    ui->cabinet->setChecked(1);
    ui->free->setChecked(0);
    ui->ortogonal->setChecked(0);
    view = 1;
    this->repaint();
}

void MainWindow::on_free_clicked(){
    ui->central->setChecked(0);
    ui->cabinet->setChecked(0);
    ui->free->setChecked(1);
    ui->ortogonal->setChecked(0);
    view = 2;
    this->repaint();
}

void MainWindow::on_ortogonal_clicked(){
    ui->central->setChecked(0);
    ui->cabinet->setChecked(0);
    ui->free->setChecked(0);
    ui->ortogonal->setChecked(1);
    view = 3;
    this->repaint();
}

void MainWindow::timerEventRotate(){

}

void MainWindow::timerEvent(QTimerEvent *event){
    double k = 5;
    QPointF dp(20.0,20.0);;

    rotationMatrix.rotate(- dp.x() / k, QVector3D(0, 1, 0));
    rotationMatrix.rotate(dp.y() / k, QVector3D(1, 0, 0));

    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event){
    double k = 5;
    QPointF dp = event->pos() - pos;
    pos = event->pos();

    rotationMatrix.rotate(- dp.x() / k, QVector3D(0, 1, 0));
    rotationMatrix.rotate(dp.y() / k, QVector3D(1, 0, 0));

    repaint();
}

void MainWindow::wheelEvent(QWheelEvent *event){
    if (event->delta() < 0){
        if (range > 0) range--;
    } else range++;
    f = Cubes(range);
    this->repaint();
}

void MainWindow::mousePressEvent(QMouseEvent * event){
    pos = event->pos();
}
