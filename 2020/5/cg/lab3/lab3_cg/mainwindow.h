#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "matrix.h"
#include "vector.h"
#include "circle.h"
#include "stamp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void drawStamp(QPainter * painter);
    void drawConv(QPainter * painter);
    void drawLowerCircles(QPainter * painter);
    void drawMainCircles(QPainter * painter);
private:
    Ui::MainWindow *ui;

    QTimer *timer;
    int tickSkip;
    int radius;
    int angle;
    int scaledCircleWidth;
    Vector center;
    QPolygon conv, ltr, trt;
    Stamp stamp;
    QVector <Circle *> circles;
    QRect lowerCircles[3], circleStartPos, circleReadyPos;
private slots:
    void animate();
};

#endif // MAINWINDOW_H
