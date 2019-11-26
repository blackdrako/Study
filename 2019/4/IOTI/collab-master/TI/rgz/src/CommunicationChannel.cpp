#include "CommunicationChannel.h"
#include <time.h>

string CommunicationChannel::addErrors() {
	srand(time(NULL));
	int i; // индекс начала очередного блока
	for (i = 0; i < code.size(); i += n) {
		int k = rand() % (n*2);
		if (k < n)
			code[k + i] = (code[k + i] - '0' + 1) % 2 + '0';
	}
	return code;
}

void CommunicationChannel::addErrorsFor_Sir_Hyena_Co() {
	srand(time(NULL));
	cout << "\tКанал связи: " << endl;
	cout << "Сообщение, переданное в канал связи:" << endl;
	cout << code << endl;
	int i; // индекс начала очередного блока
	for (i = 0; i < code.size(); i += n) {
		int k = rand() % (n + 5);
		if (k < n) {
			code[k + i] = (code[k + i] - '0' + 1) % 2 + '0';
			cout << "Внесена ошибка в " << k + i + 1 << " бит." << endl;
		}
	}
	cout << "Сообщение, вышедшее из канала связи:" << endl;
	cout << code << endl << endl;
}