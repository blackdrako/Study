#pragma once
#include <iostream>
#include "LogMatr.h"
#include <string>
#include <math.h>

using namespace std;

class Coder
{
	int r, k, n;
	string message;
	CheckMatr ch_matr;
	GeneratorMatr g_matr;
public:
	Coder(int r);
	void setMessage(const string mes) { message = mes; }
	void printCoderInfo();
	string getCode();
	string getCodeFor_Sir_Hyena_Co();
};

