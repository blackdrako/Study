#include "object.h"

QVector<QVector<QVector3D>> Object::getObject(){
    return obj;
}

QVector3D Object::getCenter(){
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1;
    float n1, n = obj.size();
    for (int i = 0; i < obj.size(); i++){
        x1 = 0;
        y1 = 0;
        z1 = 0;
        n1 = obj.at(i).size();
        for (int j = 0; j < obj.at(i).size(); j++){
            x1 += obj.at(i).at(j).x();
            y1 += obj.at(i).at(j).y();
            z1 += obj.at(i).at(j).z();
        }
        x0 += x1/n1;
        y0 += y1/n1;
        z0 += z1/n1;
    }
    return QVector3D(x0/n, y0/n, z0/n);
}

QVector3D Object::getSize(){
    float min_x = obj.at(0).at(0).x(),
          max_x = min_x,
          min_y = obj.at(0).at(0).y(),
          max_y = min_y,
          min_z = obj.at(0).at(0).z(),
          max_z = min_z;
    for (int i = 0; i < obj.size(); i++){
        for (int j = 0; j < obj.at(i).size(); j++){
            if (obj.at(i).at(j).x() < min_x) min_x = obj.at(i).at(j).x();
            if (obj.at(i).at(j).x() > max_x) max_x = obj.at(i).at(j).x();
            if (obj.at(i).at(j).y() < min_y) min_y = obj.at(i).at(j).y();
            if (obj.at(i).at(j).y() > max_y) max_y = obj.at(i).at(j).y();
            if (obj.at(i).at(j).z() < min_z) min_z = obj.at(i).at(j).z();
            if (obj.at(i).at(j).z() > max_z) max_z = obj.at(i).at(j).z();
        }
    }
    return QVector3D(max_x - min_x, max_y - min_y, max_z - min_z);
}

Cubes::Cubes(){
    Cubes(1);
}

Cubes::Cubes(int range){
    QVector3D   A (0,0,0),  B (4,0,0), C (4,4,0), D (0,4,0),
                A1(0,0,4),  B1(4,0,4), C1(4,4,4), D1(0,4,4);
    QVector<QVector3D> tmp;
    tmp << A << B << C << D;        obj << tmp; tmp.clear();
    tmp << B << C << C1 << B1;      obj << tmp; tmp.clear();
    tmp << B1 << C1 << D1 << A1;    obj << tmp; tmp.clear();
    tmp << A1 << D1 << D << A;      obj << tmp; tmp.clear();
    tmp << A << A1 << B1 << B;      obj << tmp; tmp.clear();
    tmp << D << D1 << C1 << C;      obj << tmp; tmp.clear();

    A = QVector3D(4, 3, 3); B = QVector3D(4, 3, 1);
    C = QVector3D(5 + range, 3, 1); D = QVector3D(5 + range, 3, 3);
    A1 = QVector3D(4, 1, 3); B1 = QVector3D(4, 1, 1);
    C1 = QVector3D(5 + range, 1, 1); D1 = QVector3D(5 + range, 1, 3);
    tmp << A << B << C << D;        obj << tmp; tmp.clear();
    tmp << B << C << C1 << B1;      obj << tmp; tmp.clear();
    tmp << B1 << C1 << D1 << A1;    obj << tmp; tmp.clear();
    tmp << A1 << D1 << D << A;      obj << tmp; tmp.clear();
    tmp << A << A1 << B1 << B;      obj << tmp; tmp.clear();
    tmp << D << D1 << C1 << C;      obj << tmp; tmp.clear();

    A = QVector3D(5 + range, -1, -1); B = QVector3D(9 + range, -1, -1);
    C = QVector3D(9 + range, 5, -1); D = QVector3D(5 + range, 5, -1);
    A1 = QVector3D(5 + range, -1, 5); B1 = QVector3D(9 + range, -1, 5);
    C1 = QVector3D(9 + range, 5, 5); D1 = QVector3D(5 + range, 5, 5);
    tmp << A << B << C << D;        obj << tmp; tmp.clear();
    tmp << B << C << C1 << B1;      obj << tmp; tmp.clear();
    tmp << B1 << C1 << D1 << A1;    obj << tmp; tmp.clear();
    tmp << A1 << D1 << D << A;      obj << tmp; tmp.clear();
    tmp << A << A1 << B1 << B;      obj << tmp; tmp.clear();
    tmp << D << D1 << C1 << C;      obj << tmp; tmp.clear();

    A = QVector3D(9 + range, 3, 3); B = QVector3D(9 + range, 3, 1);
    C = QVector3D(10 + range * 2, 3, 1); D = QVector3D(10 + range * 2, 3, 3);
    A1 = QVector3D(9 + range, 1, 3); B1 = QVector3D(9 + range, 1, 1);
    C1 = QVector3D(10 + range * 2, 1, 1); D1 = QVector3D(10 + range * 2, 1, 3);
    tmp << A << B << C << D;        obj << tmp; tmp.clear();
    tmp << B << C << C1 << B1;      obj << tmp; tmp.clear();
    tmp << B1 << C1 << D1 << A1;    obj << tmp; tmp.clear();
    tmp << A1 << D1 << D << A;      obj << tmp; tmp.clear();
    tmp << A << A1 << B1 << B;      obj << tmp; tmp.clear();
    tmp << D << D1 << C1 << C;      obj << tmp; tmp.clear();

    A = QVector3D(10 + range * 2, 0, 0); B = QVector3D(14 + range * 2, 0, 0);
    C = QVector3D(14 + range * 2, 4, 0); D = QVector3D(10 + range * 2, 4, 0);
    A1 = QVector3D(10 + range * 2, 0, 4); B1 = QVector3D(14 + range * 2, 0, 4);
    C1 = QVector3D(14 + range * 2, 4, 4); D1 = QVector3D(10 + range * 2, 4, 4);
    tmp << A << B << C << D;        obj << tmp; tmp.clear();
    tmp << B << C << C1 << B1;      obj << tmp; tmp.clear();
    tmp << B1 << C1 << D1 << A1;    obj << tmp; tmp.clear();
    tmp << A1 << D1 << D << A;      obj << tmp; tmp.clear();
    tmp << A << A1 << B1 << B;      obj << tmp; tmp.clear();
    tmp << D << D1 << C1 << C;      obj << tmp; tmp.clear();
}
