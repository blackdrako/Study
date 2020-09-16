#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::ReadDate()
{
    bool Ok;
    n = QInputDialog::getInt(0, tr("Ввод количества сторон многоугольника"),tr("n:"), 5, 3, 30, 1, &Ok);
    if (!Ok) {
    }
    bool Ok1;
    a = QInputDialog::getDouble(0, tr("Ввод стороны квадрата"),tr("a:"), 100, 100, 300, 10, &Ok1);
    if (!Ok1) {
    }
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this); // Создаём объект-живописец
    painter.translate(width() / 2, height() / 2);
    if (width() < 50 || height() < 50)
     return;

    if (width() > height()) // Если ширина окна больше высоты
     a = (height() - sqrt(2)*a) / 2;
    else a = (width() - sqrt(2)*a) / 2;

    double a2=a/2;
    double a3=a/3;
    double a6=a/6;

    double s1 = sqrt(a*a+a2*a2);
    double s2 = sqrt(a*a+a*a);

    QRect rect = QRect(-a2, 0, a, a);
    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::FlatCap));
    painter.drawRect(rect);

    painter.drawLine(-a2,0,-a-a2,0);
    painter.drawLine(-a-a2,0,-a2,a);

    painter.drawLine(a2,0,a+a2,0);
    painter.drawLine(a+a2,0,a2,a);

    painter.drawLine(0,0,0,-a);
    painter.drawLine(0,-a,a2,0);

    painter.drawLine(0,-a+a3,-a3,-a+a3-a6);
    painter.drawLine(0,-a,-a3,-a+a3+a6);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_0){
        angle=angle+4;
    }
    repaint(); // Обновляем окно
}
