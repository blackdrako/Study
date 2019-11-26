#include <iostream>
#include <Windows.h>
#include <string>
#include "Coder.h"
#include "Decoder.h"
#include "CommunicationChannel.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string code, tmp;
	bool flag1 = true;
	while (flag1) {
		cout << "Использовать тестовые данные(0) или ввести сообщение  вручную(1)?: ";
		bool flag;
		cin >> flag;
		if (flag) cin >> code;
		else {
			code = "0101010010100101110101011010111101111010011000111111010010101000";
			tmp = code;
			cout << "Тестовые данные:" << endl << "Сообщение: " << code << endl << "Длина сообщения: " << code.size() << endl;
		}
		Coder c(4);
		c.setMessage(code);
		c.printCoderInfo();
		code = c.getCodeFor_Sir_Hyena_Co();

		CommunicationChannel chanel(4, code);
		chanel.addErrorsFor_Sir_Hyena_Co();

		Decoder d(4);
		d.setCodeMessage(code);
		d.printDecoderInfo();
		code = d.getCodeFor_Sir_Hyena_Co();
		cout << endl << "Переданное сообщение: " << endl << tmp << endl;
		cout << "Принятое сообщение: " << endl << code << endl;
		cout << "Повторить? (0/1) ";
		cin >> flag1;
	}
}