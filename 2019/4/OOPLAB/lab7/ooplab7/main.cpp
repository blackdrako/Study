#include <QCoreApplication>

#include <QTextCodec>
//cout << QString::fromUtf8("").toLocal8Bit().data();
#include <iostream>

#include <iostream>
using namespace std;
#define MAX_STRING_SIZE 256
class _String{
protected:
    unsigned size;
    char* str;
public:
    _String(unsigned size):size(size){
        this->str=(char*)malloc(sizeof(char)*size);
    }
    ~_String(){
        free(str);
    }
};

class Exception:public exception{
public:
    virtual void show()=0;
};

class OutOfMemory:public Exception{
    unsigned size;
public:
    OutOfMemory(unsigned size):size(size){
        this->show();
    };
    void show(){
        cout<<"Exeption: out of memory. Current str size - "<<this->size<<endl;
    };
};

class EmptyStr:public Exception{
public:
    EmptyStr(){
        this->show();
    };
    void show(){
            cout<<"Exeption: empty str.\n";
    };
};

class OutOfRange:public Exception{
    unsigned called_char_index;
public:
    OutOfRange(unsigned called_str):called_char_index(called_str){
        this->show();
    };
    void show(){
        cout<<"Exeption: out of range. Called char - "<<this->called_char_index<<endl;
    };
};


class String:public _String{
    unsigned current_size;
    public:
    String(unsigned size);
    String(char* init_str);
    ~String();
    void print();
    char operator[](int i);
    String operator =(char* origin);
    void del_char(int index);
    void add_char(int index,char c);
};


    String::String(unsigned size):_String(size){
        this->current_size=0;
        this->str=(char*)malloc(sizeof(char)*size);
    }
    String::String(char* init_str):_String(MAX_STRING_SIZE){
        int i = 0;
        while(init_str[i]!='\0'){
            i++;
        }
        this->str=(char*)malloc(sizeof(char)*i+2);
        this->current_size=i+1;
        this->str[i+1]='\0';
        while(i!=0){
            this->str[i]=init_str[i];
            i--;
        }
    }
    String::~String(){
        free(str);
    }

    void String::print(){
        try{
            if(this->current_size==0) throw EmptyStr();
            cout<<this->str<<endl;
        }
        catch(EmptyStr){}
    }

    char String::operator[](int i){
        try{
            if(i>this->current_size) throw OutOfRange(i);
            if(this->current_size==0) throw EmptyStr();
            return this->str[i];
        }
        catch(OutOfRange){}
        catch(EmptyStr){}
    }

    String String::operator =(char* origin){
        try{
            int i=0,str_size;
            while(origin[i]!='\0') i++;
            str_size=i;
            i=0;
            if(str_size>MAX_STRING_SIZE) throw OutOfMemory(str_size);
            this->str=(char*)realloc(this->str,str_size+1);
            while(i<str_size){
                this->str[i]=origin[i];
                i++;
            }
            this->current_size=str_size+1;
        return *this;
        }
        catch(OutOfMemory){}
    }
    void String::del_char(int index){
        try{
            if(index>current_size) throw OutOfRange(index);
            if(current_size==0) throw EmptyStr();
            for(int i=index;i<current_size;i++){
                this->str[i]=str[i+1];
            }
            current_size=current_size-1;
            }
        catch(EmptyStr){}
        catch(OutOfRange){}
    };

    void String::add_char(int index,char c){
        try{
            if(index>current_size) throw OutOfRange(index);
            if(current_size+1>MAX_STRING_SIZE) throw OutOfMemory(current_size);
            int i=index+1;
            while(i<this->current_size+1){
                this->str[i]=this->str[i-1];
            }
            this->str[index]=c;
        }
        catch(OutOfRange){}
        catch(OutOfMemory){}
    };
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    char* temp_str;
    printf("Введите строку");
    scanf("%s",temp_str);
    String str(temp_str);
    str.print();
    return a.exec();
}
