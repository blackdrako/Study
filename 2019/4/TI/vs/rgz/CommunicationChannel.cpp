#include "CommunicationChannel.h"
#include <time.h>

string CommunicationChannel::addErrors() {
	srand(time(NULL));
	int i; // ������ ������ ���������� �����
	for (i = 0; i < code.size(); i += n) {
		int k = rand() % (n*2);
		if (k < n)
			code[k + i] = (code[k + i] - '0' + 1) % 2 + '0';
	}
	return code;
}

void CommunicationChannel::addErrorsFor_Sir_Hyena_Co() {
	srand(time(NULL));
	cout << "\t����� �����: " << endl;
	cout << "���������, ���������� � ����� �����:" << endl;
	cout << code << endl;
	int i; // ������ ������ ���������� �����
	for (i = 0; i < code.size(); i += n) {
		int k = rand() % (n + 5);
		if (k < n) {
			code[k + i] = (code[k + i] - '0' + 1) % 2 + '0';
			cout << "������� ������ � " << k + i + 1 << " ���." << endl;
		}
	}
	cout << "���������, �������� �� ������ �����:" << endl;
	cout << code << endl << endl;
}