#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include "object.h"
#include <QMatrix4x4>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent * event);
    void drawObject(QPainter * painter);
private:
    Ui::MainWindow *ui;

    bool debugFlag;
    Cubes obj;
    Cubes translatedObject;
    int range, view;
    double globalScale, centralViewPoint;
    QMatrix4x4 rotationMatrix, M1, M_t;
    QPointF pos, paintingPolygonPos;
    void mouseMoveEvent(QMouseEvent * event);
    static bool polygonComp(CustomPolygon a, CustomPolygon b);
};

#endif // MAINWINDOW_H
