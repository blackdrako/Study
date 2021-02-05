#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::animate(){
    update();
}

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setMinimumSize(1200, 600);
    this->setMaximumSize(1200, 600);
    angle = 0;
    timer = new QTimer(this);
    timer->setInterval(1000/360);
    //timer->setInterval(1000/4);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start();

    radius = this->height() / 20;
    scaledCircleWidth = radius;
    center = Vector(this->width() / 4, this->height() / 2);
    tickSkip = 3;

    conv.push_back(QPoint(0,center.y()));
    conv.push_back(QPoint(0,center.y() - (radius * 2)));
    conv.push_back(QPoint(radius * 2,center.y() - (radius * 2)));
    conv.push_back(QPoint(radius * 2,center.y()));
    conv.push_back(QPoint(this->width() / 3,center.y()));
    conv.push_back(QPoint(this->width() / 3,center.y() + radius));
    conv.push_back(QPoint(0,center.y() + radius));


    ltr.push_back(QPoint(-50, -50));
    ltr.push_back(QPoint(-50, 50));
    ltr.push_back(QPoint(50, 50));

    stamp = Stamp(QPoint(this->width() / 3, center.y() + radius), QPoint(this->width()  / 3 + radius * 2, 0));

    lowerCircles[0] = QRect(this->width() / 4 - radius, center.y() + radius, radius, radius);
    QPoint tr = QPoint(lowerCircles[0].center().x() - radius / 8, lowerCircles[0].center().y() + radius / 8);
    QPoint bl = QPoint(tr.x() - 2 * radius, tr.y()  + 2 * radius);
    QPoint tl = QPoint(bl.x(), tr.y());
    QPoint br = QPoint(tr.x(), bl.y());
    lowerCircles[1] = QRect(tl, br);
    tl = QPoint(tl.x() -  1.5 * radius, tl.y() + 1.5 *radius);
    br = QPoint(br.x() -  1.5 *radius, br.y() +  1.5 *radius);
    lowerCircles[2] = QRect(tl, br);

    tl = QPoint(0, center.y());
    br = QPoint(radius * 2, center.y() - radius * 2);

    circleStartPos = QRect(tl, br);

    tl = QPoint(this->width() / 3 , center.y() -2 * radius);
    br = QPoint(tl.x() + 2 * radius , tl.y() + 2 * radius);

    circleReadyPos = QRect(tl, br);
    Circle * firstCircle = new Circle(circleStartPos);
    circles.push_back(firstCircle);
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.setBrush(Qt::black);
    drawStamp(&painter);
    drawLowerCircles(&painter);
    drawMainCircles(&painter);
    drawConv(&painter);

    painter.setBrush(Qt::black);
    painter.end();
}

void MainWindow::drawConv(QPainter * painter){
    painter->setPen(Qt::black);
    painter->drawPolygon(conv);
}

void MainWindow::drawLowerCircles(QPainter * painter){
    QBrush oldBrush = painter->brush();
    if (angle < 360) angle++; else angle = 0;
    int f = 1;
    for (int i = 0; i < 3; i++){
        f *= -1;
        painter->setBrush(Qt::red);
        painter->drawPie(lowerCircles[i], (0 + angle) * 16 * f, 90 * 16);
        painter->setBrush(Qt::blue);
        painter->drawPie(lowerCircles[i], (90 + angle) * 16 * f, 90 * 16);
        painter->setBrush(Qt::red);
        painter->drawPie(lowerCircles[i], (180 + angle) * 16 * f, 90 * 16);
        painter->setBrush(Qt::blue);
        painter->drawPie(lowerCircles[i], (270 + angle) * 16 * f, 90 * 16);
    }
    painter->setBrush(oldBrush);
}

void MainWindow::drawMainCircles(QPainter *painter){
    QBrush oldBrush = painter->brush();
    bool newCircleNeeded = false;
    for (int i = 0; i < circles.size(); i++){

        if ((circles[i]->getRect().bottomLeft().x() == circleReadyPos.bottomLeft().x()) && !circles[i]->isReady()){
            circles[i]->setDirection(0);
            circles[i]->setReadyPos(1);
        }
        circles[i]->move();

        //Определяем, нужно ли уменьшать шар
        if (circles[i]->isReady() && circles[i]->getWidth() != scaledCircleWidth){
            if (!tickSkip){
                circles[i]->scale();
                tickSkip = 10;
            }
            tickSkip--;

        }
        painter->setBrush(Qt::red);
        painter->drawEllipse(circles[i]->getRect());
    }

    if (circles[circles.size() - 1]->getRect().bottomLeft().y() == 335){
        Circle * tmpCircle = new Circle(circleStartPos);
        circles.push_back(tmpCircle);
        newCircleNeeded = false;
    }
    //Если очередной шар достиг нижней границы экрана - удалить
    if (circles[circles.size() - 1]->getRect().bottomRight().y() == 600) {
        delete circles[circles.size() - 1];
        circles.pop_front();
        circles.resize(circles.size() - 2);
    }

    painter->setBrush(oldBrush);
}

void MainWindow::drawStamp(QPainter * painter){
    QBrush oldBrush = painter->brush();
    painter->setBrush(Qt::black);
    //Сдивигаем штамп
    stamp.move();
    if (stamp.getLowerPos() == -240 || stamp.getLowerPos() == 0) stamp.changeDirection();

    painter->drawRect(stamp.getRect());
    painter->setBrush(oldBrush);
}
