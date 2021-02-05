#include "circle.h"
#include "QDebug"

Circle::Circle(){
    rect = QRect();
    direction = 1;
    inc = 1;
    reachedReadyPos = 0;
}

Circle::Circle(QRect r){
    rect = r;
    direction = 1;
    inc = 1;
    reachedReadyPos = 0;
}

QRect Circle::getRect(){
    return rect;
}

void Circle::move(){
    QPoint tl, br;
    if (direction){
        tl = QPoint(rect.topLeft().x() + 1 * inc, rect.topLeft().y());
        br = QPoint(rect.bottomRight().x() + 1 * inc, rect.bottomRight().y());
        rect = QRect(tl, br);
    } else {
        tl = QPoint(rect.topLeft().x(), rect.topLeft().y() + 1 * inc);
        br = QPoint(rect.bottomRight().x(), rect.bottomRight().y() + 1 * inc);
        rect = QRect(tl, br);
    }
}

void Circle::draw(QPainter *painter){
    QBrush prevBrush = painter->brush();
    painter->setBrush(Qt::red);
    painter->drawEllipse(rect);
    painter->setBrush(prevBrush);
}

void Circle::scale(){
    Vector tl, br;
    QPoint center = rect.center();

    tl = Matrix::scalingMatrix(0.9, 0.9) * Vector(rect.topLeft().x(), rect.topLeft().y());
    br = Matrix::scalingMatrix(0.9, 0.9) * Vector(rect.bottomRight().x(), rect.bottomRight().y());

    rect = QRect(tl.getPoint(), br.getPoint());

    int rx, ry;
    rx = center.x() - rect.center().x();
    ry = center.y() - rect.center().y();

    tl = Matrix::translationMatrix(rx, ry) * tl;
    br = Matrix::translationMatrix(rx, ry) * br;

    rect = QRect(tl.getPoint(), br.getPoint());
}

int Circle::getDirection(){
    return direction;
}

void Circle::setDirection(int newDirection){
    direction = newDirection;
}

int Circle::getInc(){
    return inc;
}

int Circle::getWidth(){
    return rect.bottomRight().x() - rect.bottomLeft().x();
}

void Circle::setInc(int newInc){
    inc = newInc;
}

void Circle::setReadyPos(bool f){
    reachedReadyPos = f;
}

bool Circle::isReady(){
    return reachedReadyPos;
}

bool Circle::isScalingNeeded(){
    return scalingNeeded;
}
