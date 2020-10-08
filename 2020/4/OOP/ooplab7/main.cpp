#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <cstdio>
#include <iostream>
#include <exception>
#include <limits>
#include <cstdlib>
#include <string>
using namespace std;

class MyException : exception{
  public:
    virtual const char* what() const throw() override = 0;
};
class MyOverflowException : public MyException{
  private:
    long left;
    long right;
  public:
    MyOverflowException(long a, long b) : MyException(), left(a), right(b){}
    long get_left() const {return left;}
    long get_right() const {return right;}
};
class MySumOverflowException : MyOverflowException{
  public:
    MySumOverflowException(long a, long b) : MyOverflowException(a, b){}
    const char* what() const throw(){
      char* str = new char[80];
      sprintf(str, "Result of %li + %li Overflow\n", get_left(), get_right());
      return str;
    }
};
class MyMultOverflowException : MyOverflowException{
  public:
    MyMultOverflowException(long a, long b) : MyOverflowException(a, b){}
    const char* what() const throw(){
      char* str = new char[80];
      sprintf(str, "Result of %li * %li Overflow\n", get_left(), get_right());
      return str;
    }
};
class MyZeroDivisionException : MyException{
    public:
    const char* what() const throw(){
      return "MyZeroDivisionError";    }
};

class Fraction{
  private:
    int numerator;
    unsigned denumerator;
    void normalize();
    unsigned gcd(unsigned, unsigned);
    unsigned lcm(unsigned, unsigned);
    int safe_sum(int a, int b);
    int safe_mult(int a, int b);
    unsigned safe_mult(unsigned a, unsigned b);
  public:
    Fraction() : numerator(0), denumerator(1){}
    Fraction(int num, unsigned denum);
    Fraction(int int_part, int num, unsigned denum);
    Fraction operator+(const Fraction&);
    Fraction operator-(Fraction&);
    Fraction operator*(const Fraction&);
    Fraction operator/(const Fraction&);
    Fraction operator-();
    friend ostream& operator<< (std::ostream &out, const Fraction &f);
    friend istream& operator>> (std::istream &in, Fraction &f);
};

Fraction::Fraction(int num, unsigned denum) : numerator(num), denumerator(denum){
    if (denumerator == 0){
    throw (MyZeroDivisionException());
  }
}
Fraction::Fraction(int int_part, int num, unsigned denum) : numerator(int_part * denum + num), denumerator(denum){
    if (denumerator == 0){
        throw (MyZeroDivisionException());
    }
}

unsigned Fraction::gcd(unsigned a, unsigned b){
    while (a && b){
        if (a > b) a %= b;
        else       b %= a;
      }
      return a+b;
}

void Fraction::normalize(){
      if (this->denumerator == 0){
        throw MyZeroDivisionException();
      }
      int a = this->numerator;
      unsigned b = this->denumerator;
      unsigned d = this->gcd(abs(a), b);
      this->numerator = a/d;
      this->denumerator = b/d;
}

int Fraction::safe_sum(int a, int b){
      long result = a + b;
      if (result > numeric_limits<int>::max() ||
          result < numeric_limits<int>::min()){
            throw MySumOverflowException(a, b);
      }else{
        return result;
      }
}

int Fraction::safe_mult(int a, int b){
      long result = a * b;
      if (result > numeric_limits<int>::max() ||
          result < numeric_limits<int>::min()){
            throw MyMultOverflowException(a, b);
      }else{
        return result;
      }
}

unsigned Fraction::safe_mult(unsigned a, unsigned b){
      long unsigned result = a * b;
      if (result > numeric_limits<unsigned>::max() ||
          result < numeric_limits<unsigned>::min()){
            throw MyMultOverflowException(a, b);
      }else{
        return result;
      }
}

Fraction Fraction::operator-(){
      return Fraction(-this->numerator, this->denumerator);
}

Fraction Fraction::operator+(const Fraction& right){
      int a_num = this->numerator;
      int b_num = right.numerator;
      unsigned a_denum = this->denumerator;
      unsigned b_denum = right.denumerator;
      unsigned d = gcd(a_denum, b_denum);
      int new_num;
      unsigned new_denum;
      try{
        new_denum = this->safe_mult(a_denum, b_denum) / d;
        a_num *= new_denum / a_denum;
        b_num *= new_denum / b_denum;
        new_num = safe_sum(a_num, b_num);
      }
      catch(const MyOverflowException &e){
        std::cout << e.what();
      }
      Fraction result = Fraction(new_num, new_denum);
      result.normalize();
      return result;
}

Fraction Fraction::operator-(Fraction& right){
      return *this + (-right);
}

Fraction Fraction::operator*(const Fraction& right){
      int a_num = this->numerator;
      int b_num = right.numerator;
      unsigned a_denum = this->denumerator;
      unsigned b_denum = right.denumerator;
      int new_num;
      unsigned new_denum;
      try{
        new_num = safe_mult(a_num, b_num);
        new_denum = safe_mult(a_denum, b_denum);
      }
      catch(const MyOverflowException &e){
        cout << e.what();
      }
      Fraction result = Fraction(new_num, new_denum);
      result.normalize();
      return result;
}

Fraction Fraction::operator/(const Fraction& right){
      Fraction new_right = Fraction(right.denumerator, right.numerator);
      return *this * new_right;
}

std::ostream& operator<< (ostream &out, const Fraction &f){
      if (abs(f.numerator) >= f.denumerator){
        int int_part = f.numerator / (long)f.denumerator;
        int frac_part = abs(f.numerator) % (long)f.denumerator;
        out << int_part;
        if (frac_part != 0){
          out << ' ' <<  frac_part << '/' << f.denumerator;
        }
      }else{
        if (f.numerator % f.denumerator == 0){
          out << f.numerator / f.denumerator;
        }else{
          out << f.numerator << "/" << f.denumerator;
        }
      }
      return out;
}

istream& operator>> (std::istream &in, Fraction &f){
      in >> f.numerator;
      in >> f.denumerator;
      try{
        f.normalize();
      }
      catch(const MyZeroDivisionException&){
        cout << QString::fromUtf8("Знаменатель не может быть равен 0").toLocal8Bit().data() << std::endl;
      }
      return in;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    Fraction F1;
    Fraction F2(2,3);
    cin >> F1;
    cout << F1+F2;
    return a.exec();
}
