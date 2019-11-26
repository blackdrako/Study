#include "Decoder.h"
#include <iomanip>

Decoder::Decoder(int r) : r(r), code_message(),
							tr_ch_matr(r, (int)pow(2, r) - 1),
							g_matr((int)pow(2, r) - 1 - r, (int)pow(2, r) - 1) {
	n = (int)pow(2, r) - 1;
	k = n - r;
	tr_ch_matr.transMatr();
	// соре за небольшой костыль
}

void Decoder::printDecoderInfo() {
	cout << "\tПараметры декодера:" << endl;
	cout << "Количество проверочных бит r = " << r << "\nдлина кодового слова n = " << n << "\nдлина информационного слова k = " << k << endl << endl;
	cout << "Транспонированная проверочная матрица H_тр " << r << "x" << n << endl;
	cout << tr_ch_matr << endl;;
	cout << "Порождающая матрица G " << k << "x" << n << endl;
	cout << g_matr << endl;
}

/*************************************************/

namespace decoder {

	int invert_k_bit(vector<short>& v, int k)
	{
		v[k] = (v[k] + 1) % 2;
		return k;
	}

	int bin_to_dec(vector<short> & v)
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

	bool check_syndrome(const vector<short> & synd)
	{
		for (int i = 0; i < synd.size(); i++)
			if (synd[i] == 1)
				return false;
		return true;
	}

	int check_for_errors(vector<short> & synd)
	{
		if (check_syndrome(synd))
			return -1;
		else
		{
			int error_num = bin_to_dec(synd);
			return error_num;
		}
	}

	vector<short> get_infoword(vector<short> & codeword)
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

	string vec_to_str(vector<short> v) {
		string str;
		for (int i = 0; i < v.size(); i++)
			str += v[i] + '0';
		return str;
	}

	int get_prefix(string & mes, int l) {
		string tmp;
		int num = 0;
		for (int i = 0; i < l; i++)
			tmp += mes[i];
		for (int i = 0; i < l; i++) {
			num = num << 1;
			num |= tmp[i] - '0';
		}
		return num;
	}

	string get_info_message(string mes, int l, int num) {
		string info_mes;
		for (int i = l; i < mes.size() - num; i++)
			info_mes += mes[i];
		return info_mes;
	}

	void write_vector(const vector<short> & v)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
		cout << endl;
	}

	void write_vector1(const vector<short> & v)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
	}

	void print_head() {
		cout << "|  №  |  Принятое слово  | Синдром |  Кодовое слово  | Информационное слово |" << endl;
		cout << "+-----+------------------+---------+-----------------+----------------------+" << endl;
	}
}
/**********************************************************/

using namespace decoder;

string Decoder::getCode() {
	string message;
	vector<short> syndrome;
	int l = k;				// длина префикса!!
	int i = 0;
	while (i < code_message.size()) {
		vector<short> codeword;
		for (; codeword.size() < n; i++)
			codeword.push_back(code_message[i] - '0');
		syndrome = codeword * tr_ch_matr;
		int error_num = check_for_errors(syndrome);
		if (error_num != -1)
			invert_k_bit(codeword, error_num - 1);
		vector<short> infoword = get_infoword(codeword);
		message += vec_to_str(infoword);
	}
	int num = get_prefix(message, l);
	return get_info_message(message, l, num);
}

string Decoder::getCodeFor_Sir_Hyena_Co() {
	string message;
	vector<short> syndrome;
	int l = k;				// длина префикса!!
	int i = 0, count = 0;
	cout << "Принятое сообщение: ";
	cout << code_message << endl << endl;
	print_head();
	while (i < code_message.size()) {
		count++;
		vector<short> codeword;
		for (; codeword.size() < n; i++)
			codeword.push_back(code_message[i] - '0');
		cout << "|" << setw(5) << count << "|  ";
		write_vector1(codeword); cout << " |   ";
		syndrome = codeword * tr_ch_matr;
		write_vector1(syndrome); cout << "  | ";
		int error_num = check_for_errors(syndrome);
		if (error_num != -1) 
			invert_k_bit(codeword, error_num - 1);
		write_vector1(codeword); cout << " |      ";
		vector<short> infoword = get_infoword(codeword);
		//cout << "Отбросив биты с номерами, равными степени 2, получим информационное слово ";
		write_vector1(infoword); cout << "     |" << endl;
		cout << "+-----+------------------+---------+-----------------+----------------------+" << endl;
		message += vec_to_str(infoword);
	}
	int num = get_prefix(message, l);
	//cout << "Полученное закодированное сообщение: ";
	//cout << message << endl;
	cout << "Отбросим добавочные биты и получим информационное сообщение: ";
	string result = get_info_message(message, l, num);
	cout << result << endl << endl;
	return result;
}