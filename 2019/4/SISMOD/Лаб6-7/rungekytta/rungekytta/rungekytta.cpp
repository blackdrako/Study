// rungekytta.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "koshi.h"
#define  EPS 0.000000001
double var_7(double x, double y) {
	return x * sin(x) + y / x;
}

void print_result(double** table, int step) {
	printf("x%0* y%0*\n", 5, 5);
	for (int i = 0; i < step; i++) {
		printf("%f %f\n", table[i][0], table[i][1]);
	}
	printf("\n");
}

int main() {
	double y0, a, b;
	int step, temp_step;
	double** result;
	y0 = 1;
	a = 1.570796327;
	b = 2.570796327;
	step = 8;
	func f = var_7;
	method_func method;

	method = method_euler;
	temp_step = step;
	result = runge_eps(method, var_7, a, b, y0, EPS, &temp_step, 1);
	printf("\nEuler's method calc on %d steps \n", temp_step);
	print_result(result, temp_step);
	free(result);

	method = method_euler_cauchy;
	temp_step = step;
	result = runge_eps(method, var_7, a, b, y0, EPS, &temp_step, 2);
	printf("\nEuler-Cauchy method calc on %d steps\n", temp_step);
	print_result(result, temp_step);
	free(result);

	method = method_mod_euler;
	temp_step = step;
	result = runge_eps(method, var_7, a, b, y0, EPS, &temp_step, 2);
	printf("\nmodificaton of Euler's method calc on %d steps\n", temp_step);
	print_result(result, temp_step);
	free(result);

	method = method_runge_kutta;
	temp_step = step;
	result = runge_eps(method, var_7, a, b, y0, EPS, &temp_step, 4);
	printf("\nRunge-Kutta method calc on %d steps \n", temp_step);
	print_result(result, temp_step);
	free(result);


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
