#include <iostream>
//#include <Windows.h>
#include <math.h>
#include <string>
#include <bitset>
#include <limits>
#include "LogMatr.h"
#include <time.h>
#include <stdio.h>

using namespace std;

int EOF_FLAG = 0;

void write_vector(const vector<short>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

void read_vector(vector<short>& V, int m, FILE *f)
{
	for (int i = 0; i < m; i++)
	{
		int c;
		c = fgetc(f);
		if (c == EOF){
			EOF_FLAG = 1;
			return;
		}
		V.push_back(c - '0');
	}
}

int invert_rand_bit(vector<short>& v)
{
	srand(time(NULL));
	int k = rand() % v.size();
	v[k] = (v[k] + 1) % 2;
	return k;
}

int invert_k_bit(vector<short>& v, int k)
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

bool check_syndrome(const vector<short>& synd)
{
	for (int i = 0; i < synd.size(); i++)
		if (synd[i] == 1)
			return false;
	return true;
}

int check_for_errors(vector<short>& synd)
{
	if (check_syndrome(synd))
		return -1;
	else
	{
		int error_num = bin_to_dec(synd);
		return error_num;
	}
}

vector<short> get_infoword(vector<short>& codeword)
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
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
    system("chcp 65001");
    system("cls");
	int end_flag = 1;
	while (end_flag)
	{
		int m, n, k = 0;
		cout << "Введите количество проверочных бит r = ";
		cin >> k;
		//k = 4;
		//cout << "Введите длину информационного слова: ";
		//cin >> m;
		//n = m + k;
		n = pow(2, k) - 1;
		m = n - k;
		//while (n + 1 > pow(2, k))
		//{
		//	k++;
		//	n = m + k;
		//}
		cout << "Количество проверочных бит r = " << k << "\nдлина кодового слова n = " << n << "\nдлина информационного слова k = " << m << endl << endl;
		CheckMatr chmatr(k, n);
		chmatr.createCheckMatr();
		cout << "Сгенерирована проверочная матрица H" << k << "x" << n << endl;
		cout << chmatr << endl;;
		GeneratorMatr genmatr(m, n);
		genmatr.createGeneratorMatr();
		cout << "Сгенерирована порождающая матрица G" << m << "x" << n << endl;
		cout << genmatr << endl;;

		vector<short> infoword;
		int count = 0;
		//cout << "Введите информационное слово i = ";
		FILE *f = fopen("file.txt", "r");

		char s[1000];
		fscanf(f, "%s", s);
		cout << "В файле хранится сообщение\n" << s << endl;
		cout << "Кодируем поблочно содержимое файла." << endl;
		fclose(f);
		f = fopen("file.txt", "r");
		cout << endl;
		while (!EOF_FLAG){
			count ++;
			cout << "Читаем блок номер "<< count << "\n";
			infoword.clear();
			read_vector(infoword, m, f);
			if (infoword.size() < m){
				cout << "Данные в файле кончились.\n";
				break;
			}
			cout << "Прочитано слово ";
			//cout << EOF_FLAG;
			write_vector(infoword);
			vector<short> codeword = infoword * genmatr;
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
			//cout << endl << "Вычисление синдрома\n";
			syndrome = false_codeword * chmatr_transp;
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
		cout << "Повторить кодирование? (0/1): "; cin >> end_flag;
		system("cls");
	}
}