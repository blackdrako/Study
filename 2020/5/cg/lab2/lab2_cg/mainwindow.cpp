#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worldtoscreenconverter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcYArea(){
  double h = (x_max - x_min) / width();
  double x = x_min;

  y_min = curves[0]->F(x);
  y_max = y_min;

  QVector<CurveData*>::iterator it;
  for(it = curves.begin(); it != curves.end(); it++){
      x = x_min;
      for (; x <= x_max; x+=h){
        double y = (*it)->F(x);
        if (y_min > y)
          y_min = y;
        if (y_max < y)
          y_max = y;
      }
  }
}

void MainWindow::paintEvent(QPaintEvent *){
  QPainter paint(this);
  paint.setRenderHint(QPainter::HighQualityAntialiasing, true);
  QPoint minScreen(70, 60);
  QPoint maxScreen(width() - 30, height() - 60);
  WorldToScreenConverter converter(minScreen, maxScreen, x_min, y_min, x_max, y_max);

  int h = 70;
  double h_w = (x_max - x_min) / converter.get_w();
  double x = x_min;

  QVector<CurveData*>::iterator it;
  for(it = curves.begin(); it != curves.end(); it++) {
      paint.setPen((*it)->curvePen);
      x = x_min;
      QPoint p1 = converter.convert(x, (*it)->F(x));
      for (x = x + h_w; x < x_max; x += h_w){
        QPoint p2 = converter.convert(x, (*it)->F(x));
        paint.drawLine(p1, p2);
        p1 = p2;
      }
  }
  OrdAxis oy = OrdAxis();
  oy.draw(&paint, h, converter);
  AbscAxis ox = AbscAxis();
  ox.draw(&paint, h, converter);
}

void MainWindow::on_lineEdit_editingFinished()
{
    x_min = ui->lineEdit->text().toDouble();
    calcYArea();
    if (x_min < x_max)
        repaint();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    x_max = ui->lineEdit_2->text().toDouble();
    calcYArea();
    if (x_min < x_max)
        repaint();
}
