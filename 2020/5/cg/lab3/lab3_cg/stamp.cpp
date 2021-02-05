#include "stamp.h"
#include <QDebug>
Stamp::Stamp(){
    direction = -1;
    translation = -1;

}

Stamp::Stamp(QPoint tl, QPoint br){
    s = QRect(tl, br);
    direction = -1;
    translation = -1;
}

void Stamp::move(){
    Vector tmp, tmp1;
    tmp = Matrix::translationMatrix(0, translation) * Vector(s.topLeft().x(), s.topLeft().y());
    tmp1= Matrix::translationMatrix(0, translation) * Vector(s.bottomRight().x(), s.bottomRight().y());
    s = QRect(tmp.getPoint(), tmp1.getPoint());
}

int Stamp::getLowerPos(){
    return s.bottomLeft().y();
}

QRect Stamp::getRect(){
    return s;
}

void Stamp::changeDirection(){
   direction *= -1;
   translation *= -1;
}

void Stamp::setDirection(int newDirection){
    direction = newDirection;
}

int Stamp::getTranslation(){
    return translation;
}
