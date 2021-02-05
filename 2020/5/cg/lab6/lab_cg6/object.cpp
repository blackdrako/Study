#include "object.h"

Object::Object(){}

bool Object::read(QString filename){
    v.clear();
    indicies.clear();
    QFile f(filename);
    if (!f.exists()) {
        qDebug() << "Такого файла нет!";
        return false;
    }
    if (!f.open(QIODevice::ReadOnly)){
        qDebug() << "Не могу открыть файл!";
        return false;
    }
    QTextStream istream(&f);

    QVector<QVector3D> _v;
    QVector<QVector2D> _t;
    QVector<QVector3D> _n;
    QString tmp;
    QStringList list, indiciesList;

    while (!istream.atEnd()){
        tmp = istream.readLine();
        list = tmp.split(" ");
        if (list[0] == "v"){
            _v.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        if (list[0] == "vt"){
            _t.append(QVector2D(list[1].toFloat(), list[2].toFloat()));
            //qDebug() << list[1].toFloat() << list[2].toFloat();
            continue;
        }
        if (list[0] == "vn"){
            _n.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        if (list[0] == "f"){
            for (int i = 1; i <= 3; i++){
                indiciesList = list[i].split("/");
                if (indiciesList[1].size() == 0 && indiciesList[2].size() == 0)
                    v.append(Vertex(_v[indiciesList[0].toLong()-1]));

                if (indiciesList[1].size() == 0 && indiciesList[2].size() != 0)
                    v.append(Vertex(_v[indiciesList[0].toLong()-1], _n[indiciesList[2].toLong()-1]));

                if (indiciesList[1].size() != 0 && indiciesList[2].size() == 0)
                    v.append(Vertex(_v[indiciesList[0].toLong()-1], _t[indiciesList[1].toLong()-1]));

                if (indiciesList[1].size() != 0 && indiciesList[2].size() != 0)
                    v.append(Vertex(_v[indiciesList[0].toLong()-1], _t[indiciesList[1].toLong()-1], _n[indiciesList[2].toLong()-1]));

                indicies.append(indicies.size());
            }
        }
    }
    f.close();
    qDebug() << "reading done, size of v: " << v.size() << ", size of indicies: " << indicies.size();
    translate();
    return true;
}

void Object::translate(){
    center = getCenter();
    qDebug() << center;
    for (int i = 0; i < v.size(); i++){
        v[i].position.setX(v[i].position.x() - center.x());
        v[i].position.setY(v[i].position.y() - center.y());
        v[i].position.setZ(v[i].position.z() - center.z());
    }
}

QVector3D Object::getCenter(){
    QVector3D result(0, 0, 0);
    for (int i = 0; i < v.size(); i++){
        result.setX(result.x() + v[i].position.x());
        result.setY(result.y() + v[i].position.y());
        result.setZ(result.z() + v[i].position.z());
    }
    result.setX(result.x() / v.size());
    result.setY(result.y() / v.size());
    result.setZ(result.z() / v.size());
    return result;
}

Object::~Object(){

}
