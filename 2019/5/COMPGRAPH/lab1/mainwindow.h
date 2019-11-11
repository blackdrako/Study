#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <math.h>
#include <QPainter>
#include <QWheelEvent>
#include <QInputDialog>
#include <QLabel>
#include <QWidget>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    double a;
    int n;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ReadDate();

private:
    Ui::MainWindow *ui;

    int angle=0;

    QPolygonF dravPol(QPointF C,int count,double R);
    // Обработчик события перерисовки окна
    void paintEvent(QPaintEvent* event);

    void wheelEvent(QWheelEvent* );
};

#endif // MAINWINDOW_H
