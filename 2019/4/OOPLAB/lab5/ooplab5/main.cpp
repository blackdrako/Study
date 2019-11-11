#include <QCoreApplication>
#include <iostream>

using namespace std;

class Function
{
public:
    virtual void print() =0;
    virtual void write() =0;
    virtual double Calc (double x) = 0;
};

class Line: public Function
{
private:
    double a,b;
public:
    void print(){
        cout << "a:" << a << "   b:" << b;
    };
    void write(){
        cout << "Read a and b:";
        cin >> a;
        cin >> b;
    };
    double Calc(double x){
        return a*x+b;
    };
};

class Parabola: public Function
{
private:
    double a,b,c;
public:
    void print(){
        cout << "a:" << a << "   b:" << b << "   c:" << c;
    };
    void write(){
        cout << "Read a,b and c:";
        cin >> a;
        cin >> b;
        cin >> c;
    };
    double Calc(double x){
        return a*x*x+b*x+c;
    };
};

class Hyperbola: public Function
{
private:
    double a,b;
public:
    void print(){
        cout << "a:" << a << "   b:" << b;
    };
    void write(){
        cout << "Read a and b:";
        cin >> a;
        cin >> b;
    };
    double Calc(double x){
        return a/x+b;
    };
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Function **func;
    double x;
    cout << "Read X:";
    cin >> x;
    int n;
    cout << "Read count Function n:";
    cin >> n;
    func = new Function *[n];
    int control;
    double w = 2;
    for (int i =0;i<n;i++) {
        cout << "Read: 0 if Line,1 if Parabola or 2 Hyperbola - ";
        cin >> control;
        switch (control) {
        case 0:
            func[i] = new Line;
            func[i]->write();
            break;
        case 1:
            func[i] = new Parabola;
            func[i]->write();
            break;
        case 2:
            func[i] = new Hyperbola;
            func[i]->write();
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Func[" << i << "]:" << endl;
        func[i]->print();
        cout << endl;
        cout <<"y=f(" << x << "):   " << func[i]->Calc(x);
        cout << endl;
    }
    return app.exec();
}
