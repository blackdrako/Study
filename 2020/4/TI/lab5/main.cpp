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

void write_vector(const vector<short>& v)//����� ������� ���
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

void read_vector(vector<short>& V, int m, FILE *f)// ����������� ������� ���
{
	for (int i = 0; i < m; i++)
	{
		int c;
		c = fgetc(f);
		if (c == EOF){
			EOF_FLAG = 1;
			return;
		}
		V.push_back(c - '0');// ���������� � int
	}
}

int invert_rand_bit(vector<short>& v)// �������������� ���������� ����
{
	srand(time(NULL));
	int k = rand() % v.size();
	v[k] = (v[k] + 1) % 2;
	return k;
}

int invert_k_bit(vector<short>& v, int k)//�������������� �-��� ����
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

bool check_syndrome(const vector<short>& synd)// �������� ��������
{
	for (int i = 0; i < synd.size(); i++)
		if (synd[i] == 1)
			return false;
	return true;
}

int check_for_errors(vector<short>& synd)//���������� �������� ��������
{
	if (check_syndrome(synd))
		return -1;
	else
	{
		int error_num = bin_to_dec(synd);
		return error_num;
	}
}

vector<short> get_infoword(vector<short>& codeword)//��������� ��������������� ����� �� ��������
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
		cout << "������� ���������� ����������� ��� r = ";
		cin >> k;
		n = pow(2, k) - 1;
		m = n - k;
		cout << "���������� ����������� ��� r = " << k << "\n����� �������� ����� n = " << n << "\n����� ��������������� ����� k = " << m << endl << endl;
		CheckMatr chmatr(k, n);//����������� ������� H
		chmatr.createCheckMatr();//��������� ����������� ������� H
		cout << "������������� ����������� ������� H" << k << "x" << n << endl;
		cout << chmatr << endl;;// ����� ����������� ������� H
		GeneratorMatr genmatr(m, n);//����������� �������
		genmatr.createGeneratorMatr();//�������� ����������� �������
		cout << "������������� ����������� ������� G" << m << "x" << n << endl;
		cout << genmatr << endl;;//����� ����������� �������

		vector<short> infoword;//�������������� �����
		int count = 0;
		FILE *f = fopen("file.txt", "r");
		char s[1000],s2[1000];
		fscanf(f, "%s", s);//���������� ��������������� ����� �� �����
		cout << "� ����� �������� ���������\n" << s << endl;//����� ��������������� ����� �� �����
		int len = strlen(s);//������ ��������������� �����
		int t = len / m;//��� �� ������ �������������� �����
		cout << "����� ��������� " << len << endl;
		cout << "�������� ��������� �� �����: " << endl;
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
			cout << "����� ��������� �� ������ ����� ��������������� �����. ��������� ��������� �� " << (t + 1)*m << " ��������." << endl;
			for (int i = 0; i < t; i++){
				s[len + i] = '0';
			}
			s[len + (len % m)] = '\0';
		}
		t = m - (len % m);
		int tr=t;
		//cout << "� ������ ��������� ����� ���������� ���������� ����������� �������� (" << t << ")" << endl;
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
		cout << "�������� �������� ���������� �����." << endl;
		fclose(f);
		f = fopen("file_dop.txt", "w");
		//fprintf(f, "%s", tmp);
		fprintf(f, "%s", s);
		fclose(f);
		f = fopen("file_dop.txt", "r");
		cout << endl;
		while (!EOF_FLAG){// ���� �� ����� �����
			count ++;
			cout << "������ ���� ����� "<< count << "\n";
			infoword.clear();
			read_vector(infoword, m, f);
			if (infoword.size() < m){
				cout << "������ � ����� ���������.\n";
				break;
			}
			cout << "��������� ����� ";
			write_vector(infoword);
			vector<short> codeword = infoword * genmatr;//������� ������� �����
			cout << endl;
			cout << "�������� ������� ����� �� ������� c = i * G" << endl;
			cout << "�������� ������� ����� c = ";
			write_vector(codeword);
			cout << endl;

			bool er_flag;
			vector<short> false_codeword = codeword;
			cout << "����������� ������ ��� �������� (��������� ������)? (0/1) "; cin >> er_flag;
			int error_num;
			if (er_flag) {
				error_num = invert_rand_bit(false_codeword);
				cout << "��� ������������ " << error_num + 1 << "-� ��� �������� �����." << endl;
			}

			cout << endl;
			cout << "������� ������� �����: "; write_vector(false_codeword); cout << endl;
			CheckMatr chmatr_transp(k, n);
			chmatr_transp.transMatr();
			vector<short>syndrome;
			syndrome = false_codeword * chmatr_transp;// �������� ��������
			cout << endl;
			cout << "�������� ������� �� ������� s = y * H" << endl;
			cout << "������� s = ";
			write_vector(syndrome);
			cout << endl;
			error_num = check_for_errors(syndrome);
			if (error_num != -1)
			{
				cout << "���������� ������ � " << error_num << "-� ����. ����������� ���� ���" << endl;
				invert_k_bit(false_codeword, error_num - 1);
			}
			else cout << "������� ����� 0, ������ �� ����������" << endl;

			vector<short> new_infoword = get_infoword(false_codeword);
			cout << "�������� ���� � ��������, ������� ������� 2, ������� �������������� ����� ";
			write_vector(new_infoword);
			cout << endl << endl;

		}
		fclose(f);
		//cout << "�������� ���������: "<<itog<<endl;
		cout<<"�������������� ����� ���������� �� ��������� ���������: "<<s2<<endl;
		cout << "��������� �����������? (0/1): "; cin >> end_flag;
		system("cls");
	}
}
