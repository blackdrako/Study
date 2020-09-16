#include <QCoreApplication>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
using namespace std;

class String
{
private:
    char *str;
    int n;

    int isUpper(char c){//Возв True если A...Z false a...z
        return (c >= 'A' && c <= 'Z');
    }
    int isPunctuation(char c){//Проверка на знаки препинания
        // Знаками препинания считаем символы ASCII с 65 по 79 и с 90 по 96
        return ((c >= 65 && c <= 79) || (c >= 90 && c <= 96));
    }
    char toLower(char c){//Возв строчного символа алфавита
        return c - ('a' - 'A');
    }
    //Увеличения или уменьшения строки
    void resizeString(int length){
        char* newStr = new char [length];
        for (int i = 0; i<length; i++){
                    newStr[i] = str[i];
                }
                n = length;
                delete[] str;
                str = newStr;
    }
    /* Оператор деления возвращает часть строки, находящуюся до первого вхождения s2.
        Если s2 не входит в s1, то результат - вся строка s1 */
    friend const String operator /(const String& s1, const String& s2){
        int i = 0, occurence = 0;
        int n1 = s1.n;
        int n2 = s2.n;
        char *str1 = s1.str;
        char *str2 = s2.str;

        // За границей n1-n2 не может быть вхождения строки s2, имеющей длину n2
        while (i <= n1-n2 && !occurence){
                // Для каждого символа строки s1 пытаемся определить, является ли
        //подстрока s1[i..i+n2-1] строкой s2
            int j = 0;
            while (j < n2 && str1[i+j] == str2[j]){
                j++;
            }
            if (j == n2){
                occurence = 1;
            }
            i++;
        }
        int new_len;
        if (occurence){
            new_len = i-1;
        }else{
            new_len = n1;
        }
        String s3(str1, new_len);
        return s3;
    }

    friend const String operator >>(const String& s1, const int& count){
        /* Оператор возвращает строку, дополненную count пробелами слева */
        int new_len = s1.n + count;
        char *new_str = new char[new_len];
        for (int i = 0; i<count; i++){
            new_str[i] = ' ';
        }
        for (int j = 0; j<s1.n; j++){
            new_str[j+count] = s1.str[j];
        }
        String s3(new_str, new_len);
        return s3;
    }
public:
    String(char *chars,int count) {
        str = new char[count];
        n = count;
        for (long int index = 0; index < count; index++) {
            str[index] = chars[index];
        }
    }
    void showString(){
        for (long int i = 0; i < n; i++) {
            cout << str[i];
        }
        cout << endl;
    }
    int getN(){
        return n;
    }
    char* getString(){
        return str;
    }
    long int countSpace(){//Счет пробелов
        long int count = 0;
        for (long int i = 0; i < n; i++) {
            if(str[i] == ' ')
                count++;
        }
        return count;
    }
    //Преоброзования прописных в строчные
    void lower(){
            for (int i = 0; i<n; i++){
                if (isUpper(str[i])){
                    str[i] = toLower(str[i]);
                }
            }
        }
    void removePunctuationsToSring(){
            int last = 0;
            for (int i = 0; i<n; i++){
                if (!isPunctuation(str[i])){
                    if (i != last){
                        str[last] = str[i];
                    }
                    last++;
                }
            }
            resizeString(last);
        }
};

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    QCoreApplication app(argc, argv);
    String a = String("",0);
    String b = String("str2",4);
    String c = String("str3",4);
    a = b/c;
    a.showString();
    return app.exec();
}
