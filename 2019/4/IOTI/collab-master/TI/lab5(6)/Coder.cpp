#include "Coder.h"
#include <iomanip>

Coder::Coder(int r) : r(r), message(), 
					ch_matr(r, (int)pow(2, r) - 1), 
					g_matr((int)pow(2, r) - 1 - r, (int)pow(2, r) - 1){
	n = (int)pow(2, r) - 1;
	k = n - r;
	// соре за небольшой костыль
}

void Coder::printCoderInfo() {
	cout << "\tПараметры кодера: " << endl << endl;
	cout << "Количество проверочных бит r = " << r << "\nДлина кодового слова n = " << n << "\nДлина информационного слова k = " << k << endl << endl;
	cout << "Проверочная матрица H " << r << "x" << n << endl;
	cout << ch_matr << endl;;
	cout << "Порождающая матрица G " << k << "x" << n << endl;
	cout << g_matr << endl;
}

/*****************************************************/

string get_prefix(int a, int l) { // переводит десятичное число в двоичную форму длины l
	string prefix(l, '0');
	int i = l - 1;
	while (a > 0) {
		prefix[i] = (a & 1) + '0';
		i--;
		a = a >> 1;
	}
	return prefix;
}

string vec_to_str(vector<short> v) {
	string str;
	for (int i = 0; i < v.size(); i++)
		str += v[i] + '0';
	return str;
}

void write_vector(const vector<short>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
}

void write_vector1(const vector<short>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

void print_head() {
	cout << "|  №  | Информационное слово |  Кодовое слово  |" << endl;
	cout << "+-----+----------------------+-----------------+" << endl;
}
/*****************************************************/

string Coder::getCode() {
	string code_mes;
	int l = k;					//длина префикса!!
	int d = k - (message.size() + l) % k;	// кол-во добавочных бит в последний блок ( с учётом первого доп. байта!!!!)
	string tmp(d, '0');
	message = get_prefix(d, l) + message + tmp;	// к началу инф. слова приписываем 1 байт - число доп бит, а в конец - сами добавочный биты (нули)
	int i = 0;
	while (i < message.size()) {
		vector<short> infoword;
		for (; infoword.size() < k; i++)
			infoword.push_back(message[i] - '0');
		vector<short> codeword = infoword * g_matr;
		code_mes += vec_to_str(codeword);
	}
	return code_mes;
}

string Coder::getCodeFor_Sir_Hyena_Co() {
	string code_mes, last_block;
	int l = k;					//длина префикса!!
	int d = k - (message.size() + l) % k;	// кол-во добавочных бит в последний блок ( с учётом первого доп. байта!!!!)
	if (d == k) d = 0;
	for (int i = message.size() - (message.size() + l) % k; i < message.size(); i++)
		last_block += message[i];
	cout << "Информационное сообщение:" << message << endl;
	cout << "Длина сообщения: " << message.size() << endl << endl;;
	///cout << "Далее сообщение модифицируется: к началу сообщения припиывается " << l << " бит, последний блок дополняется до полного нулями." << endl << endl;
	///cout << "Длина сообщения с учётом первых " << l << " бит равна " << message.size() + l << " бит и сообщение разбивается на " << (message.size() + l + d)/k << " блоков";
	///if (d == 0) cout << "нацело." << endl << endl;
	///else cout << ", последний блок не полный (" << (message.size() + l) % k << " бит)" << endl << endl;
	string tmp(d, '0');
	
	///cout << "Добавим в начало сообщения " << l << " бит - кол-во добавленных в последний блок бит: " << get_prefix(d, l) << endl << endl;
	cout << "Разобьём собщение на блоки: " << endl;
	int i = 0, count = 0;
	cout << "|  №  | Информационное слово |" << endl;
	cout << "+-----+----------------------+" << endl;
	while (i < message.size()) {
		count++;
		vector<short> infoword;
		for (; infoword.size() < k && i < message.size(); i++)
			infoword.push_back(message[i] - '0');
		cout << "|" << setw(5) << count << "|";
		for (int j = 0; j < ((22 - infoword.size()) / 2 + ((22 - infoword.size()) % 2 == 0 ? 0 : 1)); j++)
			cout << ' ';
		write_vector1(infoword);
			for (int j = 0; j < ((22 - infoword.size()) / 2); j++)
				cout << ' ';
		cout << "|" << endl;
		cout << "+-----+----------------------+" << endl;
	}
	message = get_prefix(d, l) + message + tmp;	// к началу инф. слова приписываем 1 байт - число доп бит, а в конец - сами добавочный биты (нули)

	if (d != 0) {
		cout << endl << "Последний блок не полный, дополним его " << d << " нулями: " << last_block + tmp << endl << endl;
	}
	cout << "Добавим в начало сообщения 1 блок, несущий информацию о добавленных в последний блок битах: " << get_prefix(d, l) << endl << endl;
	cout << "Информационное сообщение после модификации (первые " << l << " бит - кол-во добавленных в последний блок бит, последние " << d << " бит - добавленные в последний бок биты):" << endl;
	cout << message << endl;
	cout << "Длина модифицированного сообщения равна " << message.size() << endl;
	i = 0; count = 0;
	cout << endl;
	print_head();
	while (i < message.size()) {
		count++;
		vector<short> infoword;
		for (; infoword.size() < k; i++)
			infoword.push_back(message[i] - '0');
		cout << "|" << setw(5) << count << "|      ";
		write_vector1(infoword);
		vector<short> codeword = infoword * g_matr;
		//cout << "Полученное кодовое слово: ";
		cout << "     | ";
		write_vector1(codeword);
		cout << " |" << endl;
		cout << "+-----+----------------------+-----------------+" << endl;
		code_mes += vec_to_str(codeword);
	}
	cout << endl << "Закодированное сообщение: ";
	cout << code_mes << endl << endl;
	return code_mes;
}
