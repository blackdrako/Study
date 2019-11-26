/*					TODO
Реализовать алгоритм декодирования decode(...)
Сверить и отладить блочное кодирование
Сменить название переменных в encode(...) на названия из decode(...)
*/
#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <queue>
#include <sstream>
#include <bitset>
using namespace std;
struct symb {
	string s;		//символ
	double prob;	//вероятность

	string codeSH;	//Код по Шеннону
	string codeH;	//Код по Хаффману
	
	//Мне стыдно за это
	//НЕ ИСПОЛЬЗОВАТЬ НИГДЕ, КОСТЫЛЬ!
	int code[256];	//код по Шеннону
	int top;		//длина кода по Шеннону
};

//Возвращает 1, если сумма вероятностей в массиве а равна 1
int checkProb(symb* a, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i].prob;
	}
	if (sum == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
//сортирует массив символов а по неубыванию вероятностей
void sortProb(symb* a, int n) {
	double min = a[0].prob;
	int minPos = 0, pos = 0;
	while (pos != n) {
		min = a[pos].prob;
		minPos = pos;
		for (int i = pos; i < n; i++) {
			if (a[i].prob < min) {
				min = a[i].prob;
				minPos = i;
			}
		}
		swap(a[pos], a[minPos]);
		pos++;
	}
}
//считывает символы и вероятности их появления в масссив а
symb* readAlphabet(int n) {
	symb* a = new symb[n];
	cout << "Введите символы и их вероятности" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i].s >> a[i].prob;
		a[i].top = -1;
	}
	sortProb(a, n);
	return a;
	/*if (checkProb(a, n)) {
		sortProb(a, n);
		return a;
	}
	else {
		exit(1);
	}*/
}
//выводит массив а на экран. ДОБАВИТЬ ВОЗМОЖНОСТЬ ВЫВОДА КОДА ХАФФМАНА
void printAlphabet(symb* a, int n) {
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i].s << " Вероятность:" << a[i].prob << " \t";
		cout << "Ш-Ф: " << a[i].codeSH << " \t";
		/*for (int k = 0; k <= a[i].top; k++) {
			cout << a[i].code[k];
		}*/
		cout << " X: " << a[i].codeH << endl;
	}
}
//записывает в поле code код символа 
void getCodes(int l, int h, symb* s) {
	double pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
	int i, k, j;
	if ((l + 1) == h || l == h || l > h) {
		if (l == h || l > h)
			return;
		s[h].code[++(s[h].top)] = 0;
		s[l].code[++(s[l].top)] = 1;
		return;
	}
	else {
		for (i = l; i <= h - 1; i++)
			pack1 = pack1 + s[i].prob;
		pack2 = pack2 + s[h].prob;
		diff1 = pack1 - pack2;
		if (diff1 < 0)
			diff1 = diff1 * -1;
		j = 2;
		while (j != h - l + 1) {
			k = h - j;
			pack1 = pack2 = 0;
			for (i = l; i <= k; i++)
				pack1 = pack1 + s[i].prob;
			for (i = h; i > k; i--)
				pack2 = pack2 + s[i].prob;
			diff2 = pack1 - pack2;
			if (diff2 < 0)
				diff2 = diff2 * -1;
			if (diff2 >= diff1)
				break;
			diff1 = diff2;
			j++;
		}
		k++;
		for (i = l; i <= k; i++)
			s[i].code[++(s[i].top)] = 1;
		for (i = k + 1; i <= h; i++)
			s[i].code[++(s[i].top)] = 0;
		getCodes(l, k, s);
		getCodes(k + 1, h, s);
	}
}
//Переводит коды Шеннона-Фано из интового массива в строку. Обязательно вызывать после получения кодов Ш-Ф!
void codeToStr(symb* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i].codeSH = "";
		for (int k = 0; k <= a[i].top; k++) {
			char tmp = a[i].code[k] + 48;
			a[i].codeSH += tmp;
		}
	}
}
//утилки для getCodesH
struct Node {
	string value, code;
	double amount;
	Node* left;
	Node* right;

	bool operator() (const Node& x, const Node& y) const {
		return x.amount > y.amount;
	}

	Node(const string& value = "", double amount = 0, Node* left = 0, Node* right = 0) {
		this->value = value;	 //множество символом узла
		this->code = "";		 //строковое с кодом
		this->amount = amount;	 //сколько раз втретилось
		this->left = left;		 //левый ребенок
		this->right = right;	 //правый ребенок
	}

	//объединение деревьев
	Node* join(Node x) {
		return new Node(x.value + value, x.amount + amount, new Node(x), this);
	}

	//генерация кодов
	void make_code(string code) {
		this->code = code;
		if (left != 0 || right != 0) {
			left->make_code(code + "0");
			right->make_code(code + "1");
		}
	}

	int searchSymb(symb* a, int n, string key) {
		for (int i = 0; i < n; i++) {
			if (a[i].s == key) return i;
		}
		return NULL;
	}

	string to_str(symb* a, int n) {
		ostringstream x;//это поток вывода, он упрощает(нет) вывод, не трогать
		if (left != 0 || right != 0) {
			//x << "\t\"" << code << ": " << value << "[" << amount << "]\" -> \"" << left->code << ": " << left->value << "[" << left->amount << "]\";\n";
			left->to_str(a, n);
			//x << "\t\"" << code << ": " << value << "[" << amount << "]\" -> \"" << right->code << ": " << right->value << "[" << right->amount << "]\";\n";
			right->to_str(a, n);
		}
		else {
			///x << "\t\"" << code << ": " << value << "[" << amount << "]\"\n";
			int pos = searchSymb(a, n, value);
			a[pos].codeH = code;
		}
		return x.str();
	}

	//построение дерева
	static Node* builder(priority_queue<Node, vector<Node>, Node> graph) {
		while (graph.size() > 1) {
			Node* n = new Node(graph.top());
			graph.pop();
			graph.push(*n->join(*new Node(graph.top())));
			graph.pop();
		}
		return new Node(graph.top());
	}
};
//Записывает в массив а коды codesH символов s по Хаффману
void getCodesH(symb *a, int n) {
	string s;
	priority_queue<Node, vector<Node>, Node> graph;
	for (int i = 0; i < n; i++) {
		graph.emplace(s = a[i].s, a[i].prob);
	}
	Node* tr = Node::builder(graph);
	tr->make_code("");
	tr->to_str(a, n);
}
//Записывает в массив res н-граммы, построенные на алфавите frs. src - массив, хранящий символы и вероятности н-1-грамма
void getNgramms(symb * src, int m, symb * frs, int l, symb * res, int n) {
	int k = 0, d = 0;
	for (int i = 0; i < n; i++) {
		if (k == l) {
			k = 0;
			d++;
		}
		res[i].s = src[d].s;
		res[i].prob = src[d].prob;
		k++;
	}
	k = 0;
	for (int i = 0; i < n; i++) {
		if (k == l) {
			k = 0;
		}
		res[i].s += frs[k].s;
		res[i].prob *= frs[k].prob;
		k++;
	}
}
//возвращает среднюю длину кодов, хранящихся в массиве а. Добавить возможность вычислять либо дл. кода Шеннона, либо Хаффмана
void averageLen(symb * a, int n, int blockSize) {
	double maxlen = 0, maxlen1 = 0, maxlen2 = 0;
	for (int i = 0; i < n; i++) {
		//maxlen += a[i].prob * a[i].top;
		maxlen1 += a[i].prob * a[i].codeSH.length();
		maxlen2 += a[i].prob * a[i].codeH.length();
	}
	cout << "По Шеннону-Фано: " << maxlen1/blockSize;
	cout << ", по Хаффману: " << maxlen2/blockSize << endl;
}
	
//Возвращает этропию алфавита источника а размером n.
double entropy(symb * a, int n) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i].prob * log2(a[i].prob);
	}
	return -res;
}

string decode(string str, symb * a, int n, int blockSize) {
	return NULL;
}
//Возвращает массив с н-граммами и их вероятностями. Размер массива высчитывать отдельно! curn = (int)pow(n, blockSize);
symb* nGramms(symb* a, int n, int blockSize) {
	int prevn = n, curn = n*n;
	symb* prev;
	symb* cur = new symb[curn];
	getNgramms(a, n, a, n, cur, curn);
	for (int i = 1; i < blockSize - 1; i++) {
		prevn = curn;
		prev = new symb[prevn];
		prev = cur;
		
		curn = curn * n;
		cur = new symb[curn];

		getNgramms(prev, prevn, a, n, cur, curn);
	}
	return cur;
}


int search_Symb(symb *a, int n, string x) {
	for (int i = 0; i < n; i++) {
		if (a[i].s == x) {
			return i;
		}
	}
	return NULL;
}

string encode(symb* a, int n, string msg, int blockSize, bool isH) {
	string tmp = "", prefix = "", res = "";
	bitset <3> z(blockSize); //Добавочная строка, которая указывает на размер блока
	cout << "Добавим к сообщению 3 бита - размер блока: " << z << endl;
	prefix += z.to_string();
	prefix += " ";

	cout << "Разобъем сообщение на блоки:" << endl;
	for (int i = 0; i < (msg.length() / blockSize); i++) {
		for (int rPos = 0; rPos < blockSize; rPos++) {
			tmp += msg[(i * blockSize) + rPos];
		}
		int pos = search_Symb(a, n, tmp);
		cout << tmp << ": ";
		if (isH) {
			cout << a[pos].codeH;
			res += a[pos].codeH;
			res += " ";
		}
		else {
			cout << a[pos].codeSH;
			res += a[pos].codeSH;
			res += " ";
		}
		cout << endl;
		tmp = "";
	}
	if (msg.length() % blockSize) {
		cout << "Последний блок не полный, добавим к нему " << msg.length() % blockSize << " символ(ов)." << endl;
		cout << "Также добавим к сообщению количество символов, которые нужно будет отбросить при декодировании:";
		bitset <3> z(msg.length() % blockSize);
		prefix += z.to_string();
		prefix += " ";
		cout << z.to_string() << endl;
		for (int i = msg.length() - (msg.length() % blockSize); i < msg.length(); i++) {
			tmp += msg[i];
		}
		while (tmp.length() < blockSize) {
			tmp += a[0].s[0];
		}
		cout << tmp << ": ";
		int pos = search_Symb(a, n, tmp);
		if (isH) {
			cout << a[pos].codeH;
			res += a[pos].codeH;
			res += " ";
		}
		else {
			cout << a[pos].codeSH;
			res += a[pos].codeSH;
		}
		cout << endl;
	}
	res = prefix + res;
	return res;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество символов" << endl;
	cin >> n;
	symb* a = readAlphabet(n);
	getCodes(0, n - 1, a);
	codeToStr(a, n);
	getCodesH(a, n);

	cout << "Полученный алфавит, вероятности и коды:" << endl;
	printAlphabet(a, n);
	cout << "Энтропия источника:" << entropy(a, n) << endl;
	cout << "Средняя длинна кода:"  << endl;
	averageLen(a, n, 1);

	string inp;
	cout << "Введите сообщение, которое нужно закодировать: " << endl;
	cin >> inp;

	cout << "При кодировании использовать коды Хаффмана(1) или Шеннона-Фано(0)? " << endl;
	bool isH;
	cin >> isH;
	cout << isH;

	cout << "Использовать поблочное кодирование? 0/1" << endl;
	int mode;
	cin >> mode;

	if (mode) {
		int blockSize;
		cout << "Введите длину блоков" << endl;
		cin >> blockSize;
		if (blockSize > 4) {
			cout << "С данной длиной блока вычисление кодов будет длиться долго. Продолжить? 0/1" << endl;
			cin >> mode;
			if (mode == 0) exit(2);
		}
		symb* res = nGramms(a, n, blockSize);
		int resn = (int)pow(n, blockSize);
		for (int i = 0; i < resn; i++) {
			res[i].top = -1;
		}
		sortProb(res, resn);
		getCodes(0, resn - 1, res);
		codeToStr(res, resn);
		getCodesH(res, resn);
		cout << "Полученные коды для " << blockSize << "-грамм: " << endl;
		sortProb(res, resn);

		printAlphabet(res, resn);
		cout << "Средняя длинна кода:" << endl;
		averageLen(res, resn, blockSize);
		string resultStr = encode(res, resn, inp, blockSize, isH);
		cout << "Результат кодирования сообщения " << inp << ":" << endl;
		cout << resultStr;
	}
	else {
		string resultStr = encode(a, n, inp, 1, isH);
		cout << "Результат кодирования сообщения " << inp << ":" << endl;
		cout << resultStr;
	}
	
}
