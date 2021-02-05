#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    obj = Cubes(1);
    translatedObject = obj;
    pos = QPointF(0, 0);
}

MainWindow::~MainWindow(){
    delete ui;
}

QColor getRandomColor(){
    return QColor(rand() % 255, rand() % 255, rand() % 255);
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    drawObject(&painter);
}

void MainWindow::drawObject(QPainter * painter){
    QVector3D center = obj.getCenter();
    float scale = 35;
    QVector<QPolygonF> polygons;
    QPolygonF polygon;
    translatedObject = obj;
    QVector4D v;
    QMatrix4x4 M, M1, M_t;

    M1 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    M.translate(-center);
    M_t.scale(scale, -scale, scale);
    M = M.transposed() * M_t.transposed();
    M = M * rotationMatrix;
    M_t.setToIdentity();
    M = M * M_t.transposed();
    M_t.setToIdentity();
    M_t.translate(ui->br->geometry().center().x(), ui->br->geometry().center().y(), 0);
    M = M * M_t.transposed();

    for (int i = 0; i < translatedObject.obj.size(); i++)
        for(int j = 0; j < translatedObject.obj[i].getPolygon().size(); j++){
            v.setX(translatedObject.obj[i].getPolygon()[j].x());
            v.setY(translatedObject.obj[i].getPolygon()[j].y());
            v.setZ(translatedObject.obj[i].getPolygon()[j].z());
            v.setW(1);
            v = v * M;

            QVector3D tmpPolygon;
            tmpPolygon.setX(v.x() / v.w());
            tmpPolygon.setY(v.y() / v.w());
            tmpPolygon.setZ(v.z() / v.w());
            translatedObject.obj[i].setVector(tmpPolygon, j);
        }

    std::stable_sort(translatedObject.obj.begin(), translatedObject.obj.end(), polygonComp);

    M.setToIdentity();
    M.translate(-1 * ui->br->geometry().center().x(), -1 * ui->br->geometry().center().y(), 0);
    M = M.transposed() * M1.transposed();
    M_t.setToIdentity();
    M_t.translate(ui->br->geometry().center().x(), ui->br->geometry().center().y(), 0);
    M = M * M_t.transposed();

    for (int i = 0; i < translatedObject.obj.size(); i++){
        for(int j = 0; j < translatedObject.obj[i].getPolygon().size(); j++){
            v.setX(translatedObject.obj[i].getPolygon().at(j).x());
            v.setY(translatedObject.obj[i].getPolygon().at(j).y());
            v.setZ(translatedObject.obj[i].getPolygon().at(j).z());
            v.setW(1);
            v = v * M;
            polygon << QPointF(v.x()/v.w(), v.y()/v.w());
        }
        polygons << polygon;
        polygon.clear();
    }

    QColor red = getRandomColor();
    for (int i = polygons.size() - 1; i >= 0; i--){
        if (polygons[i].containsPoint(paintingPolygonPos, Qt::FillRule::OddEvenFill)
                && !translatedObject.getObject()[i].isColored()){
            qDebug() << "!!!" << i ;
            paintingPolygonPos = QPointF(0, 0);
            obj.obj[translatedObject.obj[i].getNumber()].setColor(red);
            qDebug() << translatedObject.obj[i].getNumber() << i ;
        }
    }


    for (int i = 0; i < translatedObject.obj.size(); i++){
        painter->setBrush(translatedObject.obj[i].getColor());
        painter->drawPolygon(polygons[i]);
    }
}

bool MainWindow::polygonComp(CustomPolygon a, CustomPolygon b){
    return a.getDepth() <= b.getDepth();
}

void MainWindow::mouseMoveEvent(QMouseEvent * event){
    double k = 5;
    QPointF dp = event->pos() - pos;
    pos = event->pos();
    rotationMatrix.rotate(- dp.x() / k, QVector3D(0, 1, 0));
    rotationMatrix.rotate(dp.y() / k, QVector3D(1, 0, 0));
    repaint();
}

