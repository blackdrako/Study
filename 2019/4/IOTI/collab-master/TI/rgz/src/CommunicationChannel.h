#pragma once
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class CommunicationChannel
{
	int r, n;
	string& code;
public:
	CommunicationChannel(int r, string& code) : r(r), n((int)pow(2, r) - 1), code(code) {}
	string addErrors();
	void addErrorsFor_Sir_Hyena_Co();
};

