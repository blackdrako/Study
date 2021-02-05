#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "curveddata.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double x_min=0, x_max=1, y_min=0, y_max=1;
    QVector<CurveData*> curves;
    void calcYArea();
    void paintEvent(QPaintEvent *);

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
