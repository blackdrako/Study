#pragma once
#include <iostream>
#include "LogMatr.h"
#include <string>
#include <math.h>

using namespace std;

class Decoder
{
	int r, k, n;
	string code_message;
	CheckMatr tr_ch_matr;
	GeneratorMatr g_matr;
public:
	Decoder(int r);
	void setCodeMessage(const string c_mes) { code_message = c_mes; }
	void printDecoderInfo();
	string getCode();
	string getCodeFor_Sir_Hyena_Co();
};

