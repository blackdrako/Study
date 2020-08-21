#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <string>
#include <bitset>
#include <limits>
#include "LogMatr.cpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

using namespace std;

int EOF_FLAG = 0;

void write_vector(const vector<short>& v)//вывод вектора бит
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

void read_vector(vector<short>& V, int m, FILE *f)// считываение вектора бит
{
	for (int i = 0; i < m; i++)
	{
		int c;
		c = fgetc(f);
		if (c == EOF){
			EOF_FLAG = 1;
			return;
		}
		V.push_back(c - '0');// приведение к int
	}
}

int invert_rand_bit(vector<short>& v)// инвертирование случайного бита
{
	srand(time(NULL));
	int k = rand() % v.size();
	v[k] = (v[k] + 1) % 2;
	return k;
}

int invert_k_bit(vector<short>& v, int k)//инвертирование к-ого бита
{
	v[k] = (v[k] + 1) % 2;
	return k;
}

int bin_to_dec(vector<short>& v)
{
	int i;
	int res = 0;
	for (i = 0; i < v.size() - 1; i++)
	{
		res |= (v[i] - '0') & 1;
		res <<= 1;
	}
	res |= (v[i] - '0') & 1;
	return res;
}

bool check_syndrome(const vector<short>& synd)// проверка синдрома
{
	for (int i = 0; i < synd.size(); i++)
		if (synd[i] == 1)
			return false;
	return true;
}

int check_for_errors(vector<short>& synd)//нахождение значения синдрома
{
	if (check_syndrome(synd))
		return -1;
	else
	{
		int error_num = bin_to_dec(synd);
		return error_num;
	}
}

vector<short> get_infoword(vector<short>& codeword)//получение информационного слова из кодового
{
	vector<short> infoword;
	int k = 1;
	for (int i = 0; i < codeword.size(); i++)
		if (i + 1 == k)
			k *= 2;
		else
			infoword.push_back(codeword[i]);
	return infoword;
}

int main()
{
    setlocale(LC_ALL, "Rus");
	int end_flag = 1;
	while (end_flag)
	{
		int m, n, k = 0;
		cout << "Введите количество проверочных бит r = ";
		cin >> k;
		n = pow(2, k) - 1;
		m = n - k;
		cout << "Количество проверочных бит r = " << k << "\nдлина кодового слова n = " << n << "\nдлина информационного слова k = " << m << endl << endl;
		CheckMatr chmatr(k, n);//проверочная матрица H
		chmatr.createCheckMatr();//Генерация проверочной матрицы H
		cout << "Сгенерирована проверочная матрица H" << k << "x" << n << endl;
		cout << chmatr << endl;;// вывод проверочной матрицы H
		GeneratorMatr genmatr(m, n);//порождающая матрица
		genmatr.createGeneratorMatr();//создание порождающей матрицы
		cout << "Сгенерирована порождающая матрица G" << m << "x" << n << endl;
		cout << genmatr << endl;;//вывод порождающей матрицы

		vector<short> infoword;//информационное слово
		int count = 0;
		FILE *f = fopen("file.txt", "r");
		char s[1000],s2[1000];
		fscanf(f, "%s", s);//считывание информационного слова из файла
		cout << "В файле хранится сообщение\n" << s << endl;//вывод информационного слова на экран
		int len = strlen(s);//размер информационного слова
		int t = len / m;//кол во блоков информацинного слова
		cout << "Длина сообщения " << len << endl;
		cout << "Разобьем сообщения на блоки: " << endl;
		int count1 = 0;
		for (int i = 0; i < len; i++) {
			cout << s[i];
			s2[i]=s[i];
			count1++;
			if (count1 == m) {
				count1 = 0;
				cout << endl;
			}
		}
		s2[len]='\0';

		cout << endl;
		if (len % m){
			cout << "Длина сообщения не кратна длине информационного слова. Дополняем сообщение до " << (t + 1)*m << " символов." << endl;
			for (int i = 0; i < t; i++){
				s[len + i] = '0';
			}
			s[len + (len % m)] = '\0';
		}
		t = m - (len % m);
		int tr=t;
		//cout << "В начало выходного файла дописываем количество добавленных символов (" << t << ")" << endl;
		char tmp[20],itog[256];
		for (int i = m-1; i >= 0; i--){
			tmp[i] = t % 2 + '0';
			t /= 2;
		}
       for (int i = 0; i <m; i++)
            itog[i]=tmp[i];
       int counter=0;
       for (int i = m; i <m+len; i++){
                itog[i]=s[counter];
                counter++;
       }
       for (int i = m+len; i <m+len+tr; i++)
            itog[i]='0';
       itog[m+len+tr]='\0';
      // cout << itog<<endl;
		//for (int i = m; i< (m+len-); i++)

		tmp[m] = '\0';
		//cout << tmp << endl;
		cout << "Кодируем поблочно содержимое файла." << endl;
		fclose(f);
		f = fopen("file_dop.txt", "w");
		//fprintf(f, "%s", tmp);
		fprintf(f, "%s", s);
		fclose(f);
		f = fopen("file_dop.txt", "r");
		cout << endl;
		while (!EOF_FLAG){// пока не конец файла
			count ++;
			cout << "Читаем блок номер "<< count << "\n";
			infoword.clear();
			read_vector(infoword, m, f);
			if (infoword.size() < m){
				cout << "Данные в файле кончились.\n";
				break;
			}
			cout << "Прочитано слово ";
			write_vector(infoword);
			vector<short> codeword = infoword * genmatr;//создаем кодовое слово
			cout << endl;
			cout << "Получаем кодовое слово по формуле c = i * G" << endl;
			cout << "Получено кодовое слово c = ";
			write_vector(codeword);
			cout << endl;

			bool er_flag;
			vector<short> false_codeword = codeword;
			cout << "Имитировать помеху при передаче (одиночная ошибка)? (0/1) "; cin >> er_flag;
			int error_num;
			if (er_flag) {
				error_num = invert_rand_bit(false_codeword);
				cout << "Был инвертирован " << error_num + 1 << "-й бит кодового слова." << endl;
			}

			cout << endl;
			cout << "Принято кодовое слово: "; write_vector(false_codeword); cout << endl;
			CheckMatr chmatr_transp(k, n);
			chmatr_transp.transMatr();
			vector<short>syndrome;
			syndrome = false_codeword * chmatr_transp;// создание синдрома
			cout << endl;
			cout << "Получаем синдром по формуле s = y * H" << endl;
			cout << "Синдром s = ";
			write_vector(syndrome);
			cout << endl;
			error_num = check_for_errors(syndrome);
			if (error_num != -1)
			{
				cout << "Обнаружена ошибка в " << error_num << "-м бите. Инвертируем этот бит" << endl;
				invert_k_bit(false_codeword, error_num - 1);
			}
			else cout << "Синдром равен 0, ошибок не обнаружено" << endl;

			vector<short> new_infoword = get_infoword(false_codeword);
			cout << "Отбросив биты с номерами, равными степени 2, получим информационное слово ";
			write_vector(new_infoword);
			cout << endl << endl;

		}
		fclose(f);
		//cout << "Принятое сообщение: "<<itog<<endl;
		cout<<"Информационное слово полученное из принятого сообщения: "<<s2<<endl;
		cout << "Повторить кодирование? (0/1): "; cin >> end_flag;
		system("cls");
	}
}
