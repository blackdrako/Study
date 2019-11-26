#include <windows.h>
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
// ��������� ���������� ������ ������
#undef max

// ��������
const float PRECISION = 1E-5f;

// ����� ��� ��������
using namespace std;

/*-----------------------------������---------------------------------*/

// ���� ����� ������������ ����� ���� �� �������� (float) � ������� - ���������� ��� �������� ��� ���.
// ���� ������� ������ �����������, �� �������� �� ����������, ����������� � float - ����������
class Fvar {
public:
	float value = 0;
	bool exist = false;

	Fvar() : value(0), exist(false) {};
	Fvar(float value) : value(value), exist(true) {};
};

// ����� - �����
class Point {
public:
	int x, y;

	Point() :x(0), y(0) {};

	Point(int x, int y) : x(x), y(y) {};
};

/*-----------------------------����---------------------------------*/

// ���� ����������� ������� float'��
vector<float> scanNewArray(int n) {
	vector<float> array;

	float tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		array.push_back(tmp);
	}

	return array;
}

// ���� ������� m * n �� float'�� (m*n? ��� �� ����������... )
vector<vector<float>> scanNewMatr(int m, int n) {
	vector<vector<float>> matrix;
	float tmp;
	for (int i = 0; i < m; ++i) {
		matrix.push_back(vector<float>());
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			matrix[i].push_back(tmp);
		}
	}
	return matrix;
}

/*-----------------------------�����---------------------------------*/

// ����� ����������� �������
void printArray(const vector<float> &array) {
	for (size_t i = 0; i < array.size(); ++i) {
		printf("%-5.2g", array[i]); // �������� �� cout?
	}
	cout << endl;
}

// ����� �������
void printMatr(vector<vector<float>> matrix) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[i].size(); ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

// ����� �������, ��������� �� Fvar
void printMatr(vector<vector<Fvar>> matrix) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[i].size(); ++j) {
			if ((matrix[i][j]).exist) {
				// ������������� �� ������ ����, ������ ���� 7, �������� 3
				printf("%-7.3g", (matrix[i][j]).value);
			}
			else {
				printf("-      ");
			}
		}
		cout << endl;
	}
}


// ����� ������� �����
void printArray(vector<Point> array) {
	for (size_t i = 0; i < array.size(); ++i) {
		printf("(%i,%i)->", array[i].y, array[i].x);
	}
	cout << endl;
}

/*-----------------------------��������������� �������---------------------------------*/

// ���������� ����� (x, y), � ������� ��������� ����������� ������� � �������. ������ � ������� � ��������� ignoreX, ignoreY �� �����������
Point findMin(const vector<vector<float>> &matrix, int ignoreY = -1, int ignoreX = -1) {
	Point MinElement = Point(0, 0);
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[i].size(); ++j) {
			if ((matrix[i][j] < matrix[MinElement.y][MinElement.x]) && (i != ignoreY) && (j != ignoreX)) {
				MinElement.y = i;
				MinElement.x = j;
			}
		}
	}
	return MinElement;
}

// �������� ������ �� �������
template <typename T>
void deleteRow(vector<vector<T>> &matrix, int Row) {
	matrix.erase(matrix.cbegin() + Row);
}

// �������� ������� �� �������
template <typename T>
void deleteCol(vector<vector<T>> &matrix, int Column) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		matrix[i].erase(matrix[i].cbegin() + Column);
	}
}

/*---------------------------------------------����� ���������� ���������-------------------------------------------*/

// 
vector<vector<Fvar>> least_cost(vector<vector<float>> Costs, vector<float> Consumer, vector<float> Stock, int ignoreY = -1, int ignoreX = -1) {
	vector<vector<Fvar>> tmpMatrix;
	vector<vector<Point>> fix;

	for (size_t i = 0; i < Costs.size(); ++i) {
		tmpMatrix.push_back(vector<Fvar>());
		fix.push_back(vector<Point>());
		for (size_t j = 0; j < Costs[0].size(); ++j) {
			tmpMatrix[i].push_back(Fvar());
			fix[i].push_back(Point(j, i));
		}
	}

	Point minElement;
	do {
		minElement = findMin(Costs, ignoreY, ignoreX);
		printf("����� ���������� ������� � ������� (x=%i,y=%i), ������ ", minElement.x, minElement.y);
		if (Consumer[minElement.x] < Stock[minElement.y]) {
			//tmpMatrix[minElement.y][minElement.x] = Consumer[minElement.x];
			tmpMatrix[fix[minElement.y][minElement.x].y][fix[minElement.y][minElement.x].x] = Fvar(Consumer[minElement.x]);
			deleteCol(Costs, minElement.x);
			deleteCol(fix, minElement.x);
			printf("%i-�� ������� � ������� ����� �������:\n", minElement.x + 1);

			Stock[minElement.y] -= Consumer[minElement.x];
			Consumer[minElement.x] -= Consumer[minElement.x];
			Consumer.erase(Consumer.cbegin() + minElement.x);

		}
		else if (Consumer[minElement.x] > Stock[minElement.y]) {
			//tmpMatrix[minElement.y][minElement.x] = Stock[minElement.y];
			tmpMatrix[fix[minElement.y][minElement.x].y][fix[minElement.y][minElement.x].x] = Fvar(Stock[minElement.y]);
			deleteRow(Costs, minElement.y);
			deleteRow(fix, minElement.y);
			printf("%i-�� ������ � ������� ����� �������:\n", minElement.y + 1);

			Consumer[minElement.x] -= Stock[minElement.y];
			Stock[minElement.y] -= Stock[minElement.y];
			Stock.erase(Stock.cbegin() + minElement.y);

			ignoreY--;
		}
		else if (Consumer[minElement.x] == Stock[minElement.y]) {
			tmpMatrix[fix[minElement.y][minElement.x].y][fix[minElement.y][minElement.x].x] = Fvar(Stock[minElement.y]);
			deleteRow(Costs, minElement.y);
			deleteRow(fix, minElement.y);
			printf("%i-�� ������ � ������� ����� �������:\n", minElement.y + 1);

			Consumer[minElement.x] -= Stock[minElement.y];
			Stock[minElement.y] -= Stock[minElement.y];
			Stock.erase(Stock.cbegin() + minElement.y);
			ignoreY--;
		}

		//printArray(Consumer);
		//printArray(Stock);
		puts("������� ���������:"); printMatr(Costs);
		puts("����:"); printMatr(tmpMatrix);

		//printArray(Consumer);
		//printArray(Stock);
		puts("");
	} while (Costs.size() != 0);
	//tmpMatrix[fix[0][0].y][fix[0][0].x] = Stock[0];

	return tmpMatrix;
}

// ��� �������� c++
int find_equal(vector<Point> * path, Point el) {
	int c = 0;
	for (size_t i = 0; i < path->size(); ++i) {
		if ((fabs((*path)[i].x - el.x) < PRECISION) && (fabs((*path)[i].y - el.y)) < PRECISION) c++;
	}
	return c;
}

bool find_intersection(vector<Point> * path, Point el) {
	// � ��������� ������-�� ����� ����� float
	int dx1, dy1, dx, dy, S;
	for (size_t i = 1; i < path->size() - 1; ++i) {
		if (((*path)[i].x == el.x) || ((*path)[i].y == el.y)) {
			//printf("x1=%i y1=%i, x2=%i y2=%i, x=%i y=%i\n",(*path)[path->size()-1].x,(*path)[path->size()-1].y,el.x,el.y,(*path)[i].x,(*path)[i].y);
			dx1 = (*path)[path->size() - 1].x - el.x;
			dy1 = (*path)[path->size() - 1].y - el.y;

			dx = (*path)[i].x - (*path)[path->size() - 1].x;
			dy = (*path)[i].y - (*path)[path->size() - 1].y;

			S = dx1 * dy - dx * dy1;
			if (S == 0) {
				return true;
			}
		}
	}
	return false;
}

bool calc_cycle(vector<vector<float>> * cost, vector<vector<Fvar>> * pVector, vector<Point> * path, vector<Point> * result) {
	int tmpi = (*path)[(*path).size() - 1].x, tmps = (*cost)[0].size();
	//printf("%i ",find_equal(path,(*path)[(*path).size() - 1]));
	//printArray(*path);
	if (find_equal(path, (*path)[(*path).size() - 1]) == 1) {
		for (size_t i = (*path)[(*path).size() - 1].x + 1; i < (*pVector)[0].size(); ++i) {
			//printMatr(*cost);
			//printf("%i,%i ",(*path)[(*path).size()-1].y,i);
			if (!find_intersection(path, Point(i, (*path)[(*path).size() - 1].y)))
				if (fabs((*pVector)[(*path)[(*path).size() - 1].y][i].exist)) {
					path->push_back(Point(i, (*path)[(*path).size() - 1].y));
					//printArray(*path); puts("");
					calc_cycle(cost, pVector, path, result);
					//if (CycleFinded) return true;
					path->pop_back();
				}
		}

		for (size_t i = (*path)[(*path).size() - 1].y + 1; i < (*pVector).size(); ++i) {
			//printf("%i,%i ",(*path)[(*path).size()-1].y,i);
			if (!find_intersection(path, Point((*path)[(*path).size() - 1].x, i)))
				if (((*pVector)[i][(*path)[(*path).size() - 1].x].exist)) {
					path->push_back(Point((*path)[(*path).size() - 1].x, i));
					//printArray(*path); puts("");
					calc_cycle(cost, pVector, path, result);
					//if (CycleFinded) return true;
					path->pop_back();
				}
		}

		for (int i = (*path)[(*path).size() - 1].y - 1; i >= 0; --i) {
			//printf("%i,%i = %f\n",i,(*path)[(*path).size() - 1].x,(*pVector)[i][(*path)[(*path).size() - 1].x]);
			if (!find_intersection(path, Point((*path)[(*path).size() - 1].x, i)))
				if (((*pVector)[i][(*path)[(*path).size() - 1].x].exist)) {
					path->push_back(Point((*path)[(*path).size() - 1].x, i));
					//printArray(*path); puts("");
					calc_cycle(cost, pVector, path, result);
					//if (CycleFinded) return true;
					path->pop_back();
				}
		}

		for (int i = (*path)[(*path).size() - 1].x - 1; i >= 0; --i) {
			//printf("%i,%i = %f\n",i,(*path)[(*path).size() - 1].y);
			if (!find_intersection(path, Point(i, (*path)[(*path).size() - 1].y)))
				if (((*pVector)[(*path)[(*path).size() - 1].y][i].exist)) {
					path->push_back(Point(i, (*path)[(*path).size() - 1].y));
					//printArray(*path); puts("");
					calc_cycle(cost, pVector, path, result);
					//if (CycleFinded) return true;
					path->pop_back();
				}
		}
	}
	else {

		if (((*path)[0].x == (*path)[(*path).size() - 1].x) && ((*path)[0].y == (*path)[(*path).size() - 1].y)) {
			if (path->size() > 3) {
				if ((result->size() == 0) || (path->size() < result->size())) {
					*result = *path;
				}
			}
			return true;
		}
	}
	return false;
}

void Distribution_method(vector<vector<float>> * Cost, vector<float> * Consumer, vector<float> * Stock) {
	float S = 0, delta = 0, mindelta = 0;
	size_t index = 0;
	vector<vector<Point>> Cycles;
	int sign = 1;

	puts("����� ������ ���� � ������� ������ ���������� ���������:");
	vector<vector<Fvar>> pVector = least_cost(*Cost, *Consumer, *Stock);
	printMatr(pVector);

	do {
		S = 0;
		mindelta = numeric_limits<float>::max();
		index = 0;
		for (size_t i = 0; i < (pVector).size(); ++i) {
			for (size_t j = 0; j < (pVector)[i].size(); ++j) {
				if (fabs((pVector)[i][j].value) > PRECISION) {
					S += (*Cost)[i][j] * (pVector)[i][j].value;
				}
			}
		}

		puts("������ ����� ���������:");
		for (size_t i = 0; i < (pVector).size(); ++i) {
			for (size_t j = 0; j < (pVector)[i].size(); ++j) {
				if (!(pVector)[i][j].exist) {
					puts("/////////////////////////");
					vector<Point> path, result;
					path.push_back(Point(j, i));

					(pVector)[i][j] = Fvar((*Cost)[i][j]);
					calc_cycle(Cost, &pVector, &path, &result);
					(pVector)[i][j].exist = false; (pVector)[i][j].value = 0;

					if (result.size() != 0) {
						printArray(result);
						delta = 0;
						sign = 1;
						int ptsize = result.size();

						//printArray(result);
						for (size_t k = 0; k < result.size() - 1; ++k) {
							delta += sign * (*Cost)[result[k].y][result[k].x];
							sign *= -1;
						}

						printf("delta%i%i=%f\n", i + 1, j + 1, delta);
						Cycles.push_back(result);
						if (delta < mindelta) {
							index = Cycles.size() - 1;
							mindelta = delta;
						}
					}
				}
			}
		}


		if (mindelta >= 0) {
			cout << "\n��� ��� ��� ������ > 0, ������������� �������� ���� �� �� ������.\n����������� ������� ���������:" << endl;
			printMatr(pVector);
			break;
		}
		else {
			cout << "\n��� ��� ����� ����� ���� ������������� ��������, ������������� �� ����� �������� ����.\n��� ���������� ������ ��������� ����:" << endl;
		}

		float minInNeg = numeric_limits<float>::max();
		for (size_t i = 1; i < Cycles[index].size(); i += 2) {
			if (minInNeg > ((pVector)[((Cycles[index])[i]).y][(Cycles[index])[i].x].value)) {
				minInNeg = ((pVector)[((Cycles[index])[i]).y][(Cycles[index])[i].x].value);
			}
		}


		sign = 1;
		printArray(Cycles[index]); puts("");
		for (size_t i = 0; i < Cycles[index].size() - 1; i++) {
			if (sign == 1) {
				((pVector)[((Cycles[index])[i]).y][(Cycles[index])[i].x].value) += minInNeg;
			}
			else {
				if (fabs((pVector)[((Cycles[index])[i]).y][(Cycles[index])[i].x].value - minInNeg) < PRECISION) {
					((pVector)[((Cycles[index])[i]).y][(Cycles[index])[i].x].exist) = false;
				}
				((pVector)[((Cycles[index])[i]).y][(Cycles[index])[i].x].value) -= minInNeg;
			}
			sign *= -1;
		}
		puts("�������� ����� ������� ����:");
		printMatr(pVector);
		puts("\n� �������� �������� ������\n");
	} while (1);

	S = 0;
	for (size_t i = 0; i < (pVector).size(); ++i) {
		for (size_t j = 0; j < (pVector)[i].size(); ++j) {
			if (fabs((pVector)[i][j].value) > PRECISION) {
				S += (*Cost)[i][j] * (pVector)[i][j].value;
			}
		}
	}
	printf("\n> F(x)=%.4g", S);
}

// ��������, ��������� ����� �������
float sum(vector<float> * vec) {
	float S = 0;
	for (size_t i = 0; i < vec->size(); ++i) {
		S += (*vec)[i];
	}
	return S;

}

int checkBalance(vector<float> * vec1, vector<float> * vec2) {
	//if(vec1->size()==vec2->size()) {!!!
	if (fabs(sum(vec1) - sum(vec2)) < PRECISION) {
		return 1;
	}
	//}
	return 0;
}

void Potential_method(vector<vector<float>> * Cost, vector<float> * Consumer, vector<float> * Stock) {
	float S = 0, delta = 0, index = 0, mindelta = 0;
	vector<vector<Point>> Cycles;
	int sign = 1, ignoreY = -1, ignoreX = -1;

	if (!checkBalance(Consumer, Stock)) {
		printf("��� ��� ������ �� ������� (%.4g!=%.4g) ������� ", sum(Consumer), sum(Stock));
		if ((Consumer->size() > Stock->size()) || (sum(Consumer) > sum(Stock))) {
			printf("������ ���������� (� %.2g ��. ���������) � ������� ������� ������ � ����� ������� ����������:\n", sum(Consumer) - sum(Stock));
			Stock->push_back(sum(Consumer) - sum(Stock));
			Cost->push_back(vector<float>());
			for (size_t i = 0; i < (*Cost)[0].size(); ++i) {
				(*Cost)[Cost->size() - 1].push_back(0);
			}
			printMatr(*Cost); puts("");
			ignoreY = Cost->size() - 1;
		}
		else if ((Consumer->size() < Stock->size()) || (sum(Consumer) < sum(Stock))) {
			printf("������ ����������� (� %.2g ��. ���������) � ������� ������� ������� � ����� ������� ����������:\n", sum(Stock) - sum(Consumer));
			Consumer->push_back(sum(Stock) - sum(Consumer));
			for (size_t i = 0; i < (*Cost).size() - 1; ++i) {
				(*Cost)[i].push_back(0);
			}
			printMatr(*Cost); puts("");
			ignoreY = Cost->size() - 1;
		}
	}

	puts("����� ������ ���� � ������� ������ ���������� ���������:");

	vector<vector<Fvar>> pVector = least_cost(*Cost, *Consumer, *Stock, ignoreY, ignoreX);
	printMatr(pVector);

	do {
		S = 0;
		mindelta = numeric_limits<float>::max();
		index = 0;
		for (size_t i = 0; i < (pVector).size(); ++i) {
			for (size_t j = 0; j < (pVector)[i].size(); ++j) {
				if (fabs((pVector)[i][j].value) > PRECISION) {
					S += (*Cost)[i][j] * (pVector)[i][j].value;
				}
			}
		}

		/////////////////////////////////////////////////

		//           �������� ���ר� ����������� !!!
		vector<float> U;// = (float*)calloc((pVector).size(), sizeof(float));
		vector<float> V;// = (float*)calloc((pVector)[0].size(), sizeof(float));
		for (size_t i = 0; i < (pVector).size(); ++i) U.push_back(0);
		for (size_t i = 0; i < (pVector)[0].size(); ++i) V.push_back(0);


		for (size_t i = 0; i < (pVector).size(); ++i) {
			for (size_t j = 0; j < (pVector)[i].size(); ++j) {
				if ((pVector)[i][j].exist) {
					printf("v%i+u%i=%.4g\n", j + 1, i + 1, (*Cost)[i][j]);
				}
			}
		}

		for (size_t i = 0; i < U.size(); ++i) {
			printf("u%i=", i + 1); scanf_s("%f", &(U[i]));
		}
		for (size_t i = 0; i < V.size(); ++i) {
			printf("v%i=", i + 1); scanf_s("%f", &(V[i]));
		}

		Point negindex; negindex.x = -1; negindex.y = -1;
		for (size_t i = 0; i < (pVector).size(); ++i) {
			for (size_t j = 0; j < (pVector)[i].size(); ++j) {
				if (!(pVector)[i][j].exist) {
					printf("delta%i%i=c%i%i-(u%i+v%i)=%.4g\n", i + 1, j + 1, i + 1, j + 1, i + 1, j + 1, ((*Cost)[i][j] - (U[i] + V[j])));
					if (((*Cost)[i][j] - (U[i] + V[j])) < -PRECISION) {
						negindex.y = i; negindex.x = j;
					}
				}
			}
		}

		if (negindex.x == -1) {
			puts("\n��� ��� ��� ������ > 0, ������������� �������� ���� �� �� ������.\n����������� ������� ���������:");
			printMatr(pVector);
			break;
		}
		else {
			puts("\n��� ��� ����� ����� ���� ������������� ��������, ������������� �� ����� �������� ����.\n��� ���������� ������ ��������� ����:");
		}

		/////////////////////////////////////////////////

		puts("������ ���� ���������:");

		puts("/////////////////////////");
		vector<Point> path, result;
		path.push_back(negindex);
		(pVector)[negindex.y][negindex.x] = Fvar((*Cost)[negindex.y][negindex.x]);
		calc_cycle(Cost, &pVector, &path, &result);
		(pVector)[negindex.y][negindex.x] = Fvar(0);
		printArray(result);
		sign = 1;

		float minInNeg = numeric_limits<float>::max();
		for (size_t i = 1; i < result.size(); i += 2) {
			if (minInNeg > ((pVector)[((result)[i]).y][(result)[i].x].value)) {
				minInNeg = ((pVector)[((result)[i]).y][(result)[i].x].value);
			}
		}

		S = 0;
		for (size_t k = 0; k < result.size() - 1; ++k) {
			S += sign * (*Cost)[result[k].y][result[k].x] * minInNeg;
			sign *= -1;
		}

		sign = 1;
		for (size_t i = 0; i < result.size() - 1; i++) {
			if (sign == 1) {
				((pVector)[((result)[i]).y][(result)[i].x].value) += minInNeg;
			}
			else {
				if (fabs(((pVector)[((result)[i]).y][(result)[i].x].value) - minInNeg) < PRECISION)
					((pVector)[((result)[i]).y][(result)[i].x].exist) = false;
				((pVector)[((result)[i]).y][(result)[i].x].value) -= minInNeg;
			}
			sign *= -1;
		}
		puts("�������� ����� ������� ����:");
		printMatr(pVector);
		puts("\n� �������� �������� ������\n");

	} while (1);

	S = 0;
	for (size_t i = 0; i < (pVector).size(); ++i) {
		for (size_t j = 0; j < (pVector)[i].size(); ++j) {
			if (fabs((pVector)[i][j].value) > PRECISION) {
				S += (*Cost)[i][j] * (pVector)[i][j].value;
			}
		}
	}
	printf("\n> F(x)=%.4g", S);
}

int main() {
	SetConsoleCP(1251);		  // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251. ����� ������ ����� �������� ����� ������� �� Lucida Console ��� Consolas

	int n = 0, m = 0;
	vector<vector<float>> Cost_matrix;
	vector<float> Consumer, Stock;

	cout << "������� ���������� ������� m � ������������ n:" << endl;
	cout << "m: "; cin >> m;
	cout << "n: "; cin >> n;

	cout << "������� ������� ���������:" << endl;
	Cost_matrix = scanNewMatr(m, n);
	puts("�����������:");
	Consumer = scanNewArray(n);
	puts("������:");
	Stock = scanNewArray(m);

	puts("---------------");

	int answer = 0;
	printf("����� ������� ������ ������ ������ (1-������� �����������, 2-����������������� �������):");
	scanf_s("%i", &answer);
	if (answer == 2) {
		Distribution_method(&Cost_matrix, &Consumer, &Stock);
	}
	else {
		Potential_method(&Cost_matrix, &Consumer, &Stock);
	}


	//printf("%f", Cost_matrix[2][3]);


	return 0;
}