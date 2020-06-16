#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <string>
using namespace std;

struct numberTrans
{
    unsigned int cod_region;//38 - Xz
    string country;//Rus
    string series;//серия C...AB
    unsigned int reg_number;//.065..
};

numberTrans scan_numberTrans(){
    numberTrans temp;
    cout << "Read country:";
    cin >> temp.country;
    cout << "Read region:";
    cin >> temp.reg_number;
    cout << "Read series:";
    cin >> temp.series;
    cout << "Read Reg. number:";
    cin >> temp.reg_number;
    return temp;
}

void print_numberTrans(numberTrans number){
    cout << "Series:" << number.series << "   Reg. number:" << number.reg_number << "   Country and region:" << number.country << number.cod_region << endl;
}

class Trans
{
protected:
    string marka;
    numberTrans number;
    long double speed;
    long double carrying;
public:
    Trans(string name,numberTrans arg_NT,long double arg_speed,long double arg_carrying):marka(name),number(arg_NT),speed(arg_speed),carrying(arg_carrying){}
    virtual void print_trans() = 0;
    virtual long double metod_carrying() = 0;
    virtual int getType() = 0;
    virtual bool getFlag() = 0;
    long double getCarrying(){
        return carrying;
    }
    long double getSpeed(){
        return speed;
    }
    string getMarka(){
        return marka;
    }
    numberTrans getNumberTrans(){
        return number;
    }
};

class Car: public Trans
{
private:
    virtual long double metod_carrying(){
        return carrying;
    }
    virtual bool getFlag(){
        return 0;
    }
public:
    Car(string name,numberTrans arg_NT,long double arg_speed,long double arg_carrying):Trans(name,arg_NT,arg_speed,arg_carrying){
        carrying = metod_carrying();
    }
    virtual void print_trans(){
        cout << "Marka:" << marka << endl;
        cout << "Speed:" << speed << endl;
        print_numberTrans(this->number);
        cout << "Carrying:" << carrying << endl;
    }
    virtual int getType(){
        return 0;
    }
};

class Motorcycle : public Trans
{
private:
    bool isFlag_pram;
    virtual long double metod_carrying(){
        if(isFlag_pram == false){
            return 0;
        }
        return carrying;
    }
public:
    Motorcycle(string name,numberTrans arg_NT,long double arg_speed,long double arg_carrying,bool flag):Trans(name,arg_NT,arg_speed,arg_carrying){
        isFlag_pram = flag;
        carrying = metod_carrying();
    }
    virtual void print_trans(){
        cout << "Marka:" << marka << endl;
        cout << "Speed:" << speed << endl;
        print_numberTrans(this->number);
        cout << "Pram:" << isFlag_pram << endl;
        cout << "Carrying:" << carrying << endl;
    }
    virtual int getType(){
        return 1;
    }
    virtual bool getFlag(){
        return isFlag_pram;
    }

};

class Truck : public Trans
{
private:
    bool isFlag_trailer;
    virtual long double metod_carrying(){
        if(isFlag_trailer == true){
            return carrying*2;
        }
        return carrying;
    }
public:
    Truck(string name,numberTrans arg_NT,long double arg_speed,long double arg_carrying,bool flag):Trans(name,arg_NT,arg_speed,arg_carrying){
        isFlag_trailer = flag;
        carrying = metod_carrying();
    }
    virtual void print_trans(){
        cout << "Marka:" << marka << endl;
        cout << "Speed:" << speed << endl;
        print_numberTrans(this->number);
        cout << "Trailer:" << isFlag_trailer << endl;
        cout << "Carrying:" << carrying << endl;
    }
    virtual int getType(){
        return 2;
    }
    virtual bool getFlag(){
        return isFlag_trailer;
    }
};

Trans** search_trans(Trans **autopark,long double min,long double max,long int count_trans_in_autopark){
    long int *indexTrans = new long int[count_trans_in_autopark];//указатели на искомый транспорт
    long int countIndex = 0;//количество найденого транспорта
    for (long int index = 0; index > count_trans_in_autopark; index++) {
        if(autopark[index]->getCarrying() > min && autopark[index]->getCarrying() < max){
            indexTrans[countIndex] = index;
            countIndex++;
        }
    }
    Trans **tempAutopark = new Trans *[countIndex];
    cout << "debug";
    for (long int index = 0; index < countIndex; index++) {
        switch (autopark[indexTrans[index]]->getType()) {
        case 0:
            tempAutopark[index] = new Car(autopark[indexTrans[index]]->getMarka(),autopark[indexTrans[index]]->getNumberTrans(),autopark[indexTrans[index]]->getSpeed(),autopark[indexTrans[index]]->getCarrying());
            break;
        case 1:
            tempAutopark[index] = new Motorcycle(autopark[indexTrans[index]]->getMarka(),autopark[indexTrans[index]]->getNumberTrans(),autopark[indexTrans[index]]->getSpeed(),autopark[indexTrans[index]]->getCarrying(),autopark[indexTrans[index]]->getFlag());
            break;
        case 2:
            if(autopark[indexTrans[index]]->getFlag() == true){
                tempAutopark[index] = new Truck(autopark[indexTrans[index]]->getMarka(),autopark[indexTrans[index]]->getNumberTrans(),autopark[indexTrans[index]]->getSpeed(),autopark[indexTrans[index]]->getCarrying()/2,autopark[indexTrans[index]]->getFlag());
            } else {
                tempAutopark[index] = new Truck(autopark[indexTrans[index]]->getMarka(),autopark[indexTrans[index]]->getNumberTrans(),autopark[indexTrans[index]]->getSpeed(),autopark[indexTrans[index]]->getCarrying(),autopark[indexTrans[index]]->getFlag());
            }
        }
    }
    return tempAutopark;
}


int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    QCoreApplication app(argc, argv);
    Trans **autopark;
    Trans **sAutopark;
    string name;
    numberTrans arg_NT;
    long double arg_speed;
    long double arg_carrying;
    bool flag;
    long int count_trans_in_autopark;
    cout << "Read count trans:", cin >> count_trans_in_autopark, autopark = new Trans *[count_trans_in_autopark];
    long unsigned int control_flag;
    for (long unsigned int index = 0; index < count_trans_in_autopark; index++) {
        cout << "Read type trans 1-Car,2-Motocycle and 3-Truck", cin >> control_flag;
        switch (control_flag) {
        case 1:
            cout << "Name car:"; cin >> name;
            arg_NT = scan_numberTrans();
            cout << "Read speed car:"; cin >> arg_speed;
            cout << "Read carrying car:"; cin >> arg_carrying;
            autopark[index] = new Car(name,arg_NT,arg_speed,arg_carrying);
            autopark[index]->print_trans();
            break;
        case 2:
            cout << "Name motorcycle:"; cin >> name;
            arg_NT = scan_numberTrans();
            cout << "Read speed motorcycle:"; cin >> arg_speed;
            cout << "Read flag if extra slot:"; cin >> flag; cout << "Read carrying motorcycle:"; cin >> arg_carrying;
            autopark[index] = new Motorcycle(name,arg_NT,arg_speed,arg_carrying,flag);
            autopark[index]->print_trans();
            break;
        case 3:
            cout << "Name track:"; cin >> name;
            arg_NT = scan_numberTrans();
            cout << "Read speed truck:"; cin >> arg_speed;
            cout << "Read flag if extra slot:"; cin >> flag; cout << "Read carrying truck:"; cin >> arg_carrying;
            autopark[index] = new Truck(name,arg_NT,arg_speed,arg_carrying,flag);
            autopark[index]->print_trans();
            break;
        default:
            break;
        }
    }
    sAutopark = search_trans(autopark,80,120,count_trans_in_autopark);
    sAutopark[0]->print_trans();
    return app.exec();
}
