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
    a = QInputDialog::getDouble(0, tr("Ввод стороны квадрата"),tr("a:"), 23.4, 100, 300, 10, &Ok1);
    if (!Ok1) {
    }
}

QPolygonF MainWindow::dravPol(QPointF C,int count,double R)
{
    QPolygonF Pol;
    QPointF T;
    for (int i =0; i < n; i++) {
        T = QPointF(C.x()+R*cos((2*M_PI*i)/n),C.y()+R*sin((2*M_PI*i)/n));
        Pol.append(T);
    }
    return Pol;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this); // Создаём объект-живописец
    painter.translate(width() / 2, height() / 2);
    if (width() < 50 || height() < 50)
     return;

    if (width() > height()) // Если ширина окна больше высоты
     a = (height() - 200) / 2; // Отступ от краёв - 10 пикселей
    else a = (width() - 200) / 2;

    QColor orangeRed(240, 100, 0);
    double d=(a*sqrt(2))/2;

    //Радиус описанной окружности четветины
    double r = (2*d-a)/2;
    double R = a/6;

    //Центры для многоугольников
    QPointF C_P1 = QPointF(-r,r);
    QPointF C_P2 = QPointF(r,r);
    QPointF C_P3 = QPointF(r,-r);
    QPointF C_P4 = QPointF(-r,-r);

    //Ромб
    QPolygonF square;
    QPointF A = QPointF(0,d);
    square.append(A);
    QPointF B = QPointF(d,0);
    square.append(B);
    QPointF C = QPointF(0,-d);
    square.append(C);
    QPointF D = QPointF(-d,0);
    square.append(D);
    painter.setBrush( orangeRed);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
    painter.drawPolygon(square);

    //Вписанные многоугольники
    painter.setBrush( Qt::blue);
    painter.setPen( Qt::blue );
    QPolygonF Pol1 = dravPol(C_P1,n,R);
    painter.drawPolygon(Pol1);
    QPolygonF Pol2 = dravPol(C_P2,n,R);
    painter.drawPolygon(Pol2);
    QPolygonF Pol3 = dravPol(C_P3,n,R);
    painter.drawPolygon(Pol3);
    QPolygonF Pol4 = dravPol(C_P4,n,R);
    painter.drawPolygon(Pol4);

    //Оси
    painter.setPen(QPen(Qt::black, 2, Qt::DotLine, Qt::FlatCap));
    painter.drawLine(0,0,A.x(),A.y());
    painter.drawLine(0,0,B.x(),B.y());
    painter.drawLine(0,0,C.x(),C.y());
    painter.drawLine(0,0,D.x(),D.y());

    //
    QPolygonF big_square;
    QPointF A_big = QPointF(0,d+a/2);
    big_square.append(A_big);
    QPointF B_big = QPointF(d+a/2,0);
    big_square.append(B_big);
    QPointF C_big = QPointF(0,-d-a/2);
    big_square.append(C_big);
    QPointF D_big = QPointF(-d-a/2,0);
    big_square.append(D_big);
    painter.setBrush( Qt::NoBrush);
    painter.setPen(QPen(Qt::black, 2, Qt::DotLine, Qt::FlatCap));
    painter.drawPolygon(big_square);

    QPointF start_1 = QPointF(B_big.x()-a/4-angle,-a/4+angle);
    QPointF start_2 = QPointF(-a/4-angle,A_big.y()-a/4-angle);
    QPointF start_3 = QPointF(D_big.x()-a/4+angle,-a/4-angle);
    QPointF start_4 = QPointF(-a/4+angle,C_big.y()-a/4+angle);
    if(start_1.x()-a/4 < -a/4){
        angle = 0;
    }
    painter.setBrush(Qt::red);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine, Qt::FlatCap));
    QSizeF R_s = QSizeF(a/2,a/2);
    QRectF s1 = QRectF(start_1,R_s);
    painter.drawEllipse(s1);
    QRectF s2 = QRectF(start_2,R_s);
    painter.drawEllipse(s2);
    QRectF s3 = QRectF(start_3,R_s);
    painter.drawEllipse(s3);
    QRectF s4 = QRectF(start_4,R_s);
    painter.drawEllipse(s4);
}

void MainWindow::wheelEvent(QWheelEvent* wheelevent)
{
    angle -= (wheelevent->delta()/20)*(-1);
    repaint(); // Обновляем окно
}
