#include "Coder.h"
#include <iomanip>

Coder::Coder(int r) : r(r), message(), 
					ch_matr(r, (int)pow(2, r) - 1), 
					g_matr((int)pow(2, r) - 1 - r, (int)pow(2, r) - 1){
	n = (int)pow(2, r) - 1;
	k = n - r;
	// ���� �� ��������� �������
}

void Coder::printCoderInfo() {
	cout << "\t��������� ������: " << endl << endl;
	cout << "���������� ����������� ��� r = " << r << "\n����� �������� ����� n = " << n << "\n����� ��������������� ����� k = " << k << endl << endl;
	cout << "����������� ������� H " << r << "x" << n << endl;
	cout << ch_matr << endl;;
	cout << "����������� ������� G " << k << "x" << n << endl;
	cout << g_matr << endl;
}

/*****************************************************/

string get_prefix(int a, int l) { // ��������� ���������� ����� � �������� ����� ����� l
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
	cout << "|  �  | �������������� ����� |  ������� �����  |" << endl;
	cout << "+-----+----------------------+-----------------+" << endl;
}
/*****************************************************/

string Coder::getCode() {
	string code_mes;
	int l = k;					//����� ��������!!
	int d = k - (message.size() + l) % k;	// ���-�� ���������� ��� � ��������� ���� ( � ������ ������� ���. �����!!!!)
	string tmp(d, '0');
	message = get_prefix(d, l) + message + tmp;	// � ������ ���. ����� ����������� 1 ���� - ����� ��� ���, � � ����� - ���� ���������� ���� (����)
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
	int l = k;					//����� ��������!!
	int d = k - (message.size() + l) % k;	// ���-�� ���������� ��� � ��������� ���� ( � ������ ������� ���. �����!!!!)
	if (d == k) d = 0;
	for (int i = message.size() - (message.size() + l) % k; i < message.size(); i++)
		last_block += message[i];
	cout << "�������������� ���������:" << message << endl;
	cout << "����� ���������: " << message.size() << endl << endl;;
	///cout << "����� ��������� ��������������: � ������ ��������� ������������ " << l << " ���, ��������� ���� ����������� �� ������� ������." << endl << endl;
	///cout << "����� ��������� � ������ ������ " << l << " ��� ����� " << message.size() + l << " ��� � ��������� ����������� �� " << (message.size() + l + d)/k << " ������";
	///if (d == 0) cout << "������." << endl << endl;
	///else cout << ", ��������� ���� �� ������ (" << (message.size() + l) % k << " ���)" << endl << endl;
	string tmp(d, '0');
	
	///cout << "������� � ������ ��������� " << l << " ��� - ���-�� ����������� � ��������� ���� ���: " << get_prefix(d, l) << endl << endl;
	cout << "�������� �������� �� �����: " << endl;
	int i = 0, count = 0;
	cout << "|  �  | �������������� ����� |" << endl;
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
	message = get_prefix(d, l) + message + tmp;	// � ������ ���. ����� ����������� 1 ���� - ����� ��� ���, � � ����� - ���� ���������� ���� (����)

	if (d != 0) {
		cout << endl << "��������� ���� �� ������, �������� ��� " << d << " ������: " << last_block + tmp << endl << endl;
	}
	cout << "������� � ������ ��������� 1 ����, ������� ���������� � ����������� � ��������� ���� �����: " << get_prefix(d, l) << endl << endl;
	cout << "�������������� ��������� ����� ����������� (������ " << l << " ��� - ���-�� ����������� � ��������� ���� ���, ��������� " << d << " ��� - ����������� � ��������� ��� ����):" << endl;
	cout << message << endl;
	cout << "����� ����������������� ��������� ����� " << message.size() << endl;
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
		//cout << "���������� ������� �����: ";
		cout << "     | ";
		write_vector1(codeword);
		cout << " |" << endl;
		cout << "+-----+----------------------+-----------------+" << endl;
		code_mes += vec_to_str(codeword);
	}
	cout << endl << "�������������� ���������: ";
	cout << code_mes << endl << endl;
	return code_mes;
}
