#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMath>
#include <QPainter>
#include <QMatrix4x4>
#include <QMouseEvent>

#include "object.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

private:
    Cubes f;
    float globalScale, ctrlMouseWheelCount, altMouseWheel;
    int timerId;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent* e);
    void drawLines(QPainter & painter);
    void drawProjections(QPainter & painter, Object & obj);
    void draw3D(QPainter & painter, Object & obj, int view);

private slots:
    void on_zoomInc_clicked();
    void on_zoomDec_clicked();
    void on_central_clicked();
    void on_cabinet_clicked();
    void on_free_clicked();
    void on_ortogonal_clicked();
private:
    Ui::MainWindow *ui;
    QMatrix4x4 rotationMatrix;
    int view, range;
    QPointF pos;
    void mouseMoveEvent(QMouseEvent * event);
    void wheelEvent(QWheelEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void timerEvent(QTimerEvent * event);
    void timerEventRotate();
};

#endif // MAINWINDOW_H
