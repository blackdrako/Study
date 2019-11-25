#include "optimal_code.hpp"

using namespace std;

//Методы класса Symbol
Symbol::Symbol(string symb,double prob):symb(symb),prob(prob){};
Symbol::Symbol(string symb,double prob,unsigned long pos):symb(symb),prob(prob),pos(pos){};

double Symbol::get_prob(){
    return this->prob;
};
string Symbol::get_symb(){
    return this->symb;
};
string Symbol::get_code(){
return this->code;
};
unsigned long Symbol::get_pos(){
    return this->pos;
};
void Symbol::set_prob(double a){
    this->prob=a;
};
void Symbol::set_symb(string origin){
    this->symb=origin;
};
void Symbol::set_code(string code){
    this->code=code;
};
void Symbol::set_pos(unsigned long pos){
	this->pos=pos;
};

void Symbol::clear_code(){
	this->code.clear();
};

void Symbol::print(){
    cout<<"\""<<this -> symb<<"\" - "<<this->prob;
};

void Symbol::print_code(){
    cout<<"\""<<this -> symb<<"\" - "<<this->prob <<" - "<< this->code;
};

//Методы класса Alphabet
Alphabet::Alphabet(unsigned long size):size(size){};

void Alphabet::read(){
    cout<<"Введите алфавит размера "<<this->size<<" :\n"; 
    string t_symb;
    double t_prob,sum_prob;
    bool input_flag=true;
	while(input_flag){
		sum_prob=0;
		this->arr.clear();
		for(unsigned long i=0;i<this->size;i++){
			cin>>t_symb>>t_prob;
			sum_prob+=t_prob;
			this->arr.push_back(Symbol(t_symb,t_prob,i+1));    
		};
		#ifdef _RGZ
			t_prob=fabs(1-sum_prob);
			this->size++;
			this->arr.push_back(Symbol(string(" "),t_prob,this->size));
			input_flag=false;
		#else	
			if(fabs(1-sum_prob)<EPS){
				input_flag=false;
			}
			else cout << "Сумма вероятностей появления символов не равна 1. Повторите ввод."<<endl; 
		#endif	
	}

};

void Alphabet::file_read(ifstream& input_file,ofstream& out){
	string t_symb;
    double t_prob,sum_prob;
	string temp_str;
	getline(input_file,temp_str);
	out<<"Алфавит:"<<endl;
	sum_prob=0;
	this->arr.clear();
	for(unsigned long i=0;i<this->size;i++){
		getline(input_file,temp_str);
		out<<temp_str<<endl;
		t_symb=temp_str.substr(0,temp_str.find(" ",0));
		t_prob=stod(temp_str.substr(temp_str.find(" ",0),temp_str.length()));
		sum_prob+=t_prob;
		this->arr.push_back(Symbol(t_symb,t_prob,i+1));    
	};
		t_prob=fabs(1-sum_prob);
		this->size++;
		this->arr.push_back(Symbol(string(" "),t_prob,this->size));
};

unsigned long Alphabet::get_size(){
	return this->size;
};

void Alphabet::print(){
	cout<<endl;
    for(unsigned long i=0;i<this->size;i++){
        cout<<this->arr[i].get_pos()<<". ";
        this->arr[i].print();
        cout<<"\n";
    };
};

void Alphabet::print_codes(){
	cout.setf(ios::fixed);
    cout.precision(20);
	cout<<endl;
    for(unsigned long i=0;i<this->size;i++){
        this->arr[i].print_code();
		cout<<endl;
    };
};

Symbol Alphabet::operator[](int i){
	return this->arr[i];
};

//Возвращает сумму вероятностей алфавита с элемента begin по end.
double Alphabet::sum_probs(int begin,int end){
	double t_sum=0;
	for(int i=begin;i<end;i++){
		t_sum+=this->arr[i].get_prob();
	}
	return t_sum;
};

//Шаг алгоритма Шеннона-Фано.
void Alphabet::shennoncode_build_step(int begin,int end){
	//номер элемента делящий алфавит на 2 части суммы вероятностей которых равны.
	int mid=begin;
	double min_diff,diff=1;
	//Пока разность вероятностей между левой и правой частью уменьшается сдвигает mid вправо.
	do{
		mid++;
		min_diff=diff;
		diff=fabs(this->sum_probs(begin,mid)-this->sum_probs(mid,end));
	}while(diff<min_diff);
	//Возвращаемся к середенному элементу
	mid--;
	//Условия остановки рекурсии: 1.Начальный элемент последовательности равен конечному 2.Между начальным и конечным элеметом нет других элементов.
	if((begin!=end)&&(abs(begin-end)!=1)){
		//Заполняем коды символов
		for(int i=begin;i<mid;i++){
			this->arr[i].set_code(this->arr[i].get_code()+"0");
		}
		for(int i=mid;i<end;i++){
			this->arr[i].set_code(this->arr[i].get_code()+"1");
		}
		//Применяем шаг алгоритма к правому и левому подмасиву относительно mid.
		this->shennoncode_build_step(begin,mid);
		this->shennoncode_build_step(mid,end);
	}
};

void Alphabet::build_code_arr(int mode){
	//Сортировка алфавита по убыванию вероятностей.
	sort(this->arr.begin(),this->arr.end(), [](Symbol& a, Symbol& b){
			if(a.get_prob()==b.get_prob()){
				return a.get_pos()<b.get_pos();
			}
			return a.get_prob()>b.get_prob();
		});
	for(unsigned long i=0;i<this->size;i++){
		this->arr[i].clear_code();
	}
	//Заполнение кодов символов.
	switch (mode){
		case SHENNON_FANO_CODE:
			this->shennoncode_build_step(0,this->size);
			break;
		break;
		case HUFFMAN_CODE:
			this->getHuffmanCodes();
			break;
		default:
			cout<<"НЕКОРЕКТНЫЙ ВЫБОР АЛГОРИТМА ПОСТРОЕНИЯ ОПТИМАЛЬНОГО КОДА"<<endl<<"ИСПРАВЬТЕ ИСХОДНЫЙ КОД"<<endl;
			exit(1);
		break;
	};
};

Alphabet Alphabet::build_nsized_Alphabet(int n) {
	//Получение н-грамм зависит от лексикографического порядка исходного алфавита, важно отсортировать его.
	sort(this->arr.begin(), this->arr.end(), [](Symbol& a, Symbol& b) {
		return a.get_pos() < b.get_pos();
		});
	//Размер исходного алфавита.
	unsigned long m = this->size;
	//Создание результирующего алфавита размером m^n 
	unsigned long new_size = (int)round(pow(m, n));
	Alphabet newAlphabet(new_size);
	//Временные переменные для формирования нового символа алфавита.
	string t_symb; double t_prob;
	//Массив индексов символов исходного алфавита, 0-ой элемент сигнальный для остановки алгоритма.
	//unsigned long index_arr[n + 1];
	unsigned long* index_arr = new unsigned long[n + 1];
	for (int i=0;i<=n;i++) index_arr[i]=0;
	//Инициализация временной переменной вероятности символа.
	t_prob=1;	
	//Переменная для записи номера символа в алфавите.
	do{
		//Построение нового символа алфавита.
		for(int i=1;i<=n;i++){
			int index = index_arr[i];
			t_symb+=this->arr[index].get_symb();
			t_prob*=this->arr[index].get_prob();
		};
		//Запись символа в новый алфавит
		Symbol temp(t_symb,t_prob);
		newAlphabet.arr.push_back(temp);
		//Очистка временных переменных
		t_symb.clear();
		t_prob=1;

		int last=n; index_arr[last]++;
		//Перенос единицы при переполнении разрядов.
		while(index_arr[last]==m){
			index_arr[last]=0;
			index_arr[last-1]+=1;
			last--;
		};
	} while(index_arr[0]==0);

	//Подпись позиций символов в новом алфавите для лексикографической сортировки.
	unsigned long i=1;
	for(auto iter=newAlphabet.arr.begin();iter!=newAlphabet.arr.end();iter++){
		iter->set_pos(i);
		i++;
	};

	return newAlphabet;
};

unsigned Alphabet::get_symbol_size(){
	return arr[arr.size()-1].get_symb().length();
};


string Alphabet::encode_text(string str){
	//Результирующий код.
	string result_code;

	unsigned block_size = this->get_symbol_size();
	//Кол-во символов дописанных для дополнения последнего блока.
	unsigned addition_symbols = block_size - ((str.length())%block_size);
	#ifndef _RGZ
		//Записываем в заголовок размер 1 блока.	
		result_code+=num_to_binstr(block_size);
	#endif

	//Записываем в заголовок кол-во дописанных символов в последний блок.	
	result_code+=num_to_binstr(addition_symbols);

	//Дописываем последний блок до полного, если он не целый.
	for(unsigned i=0;i<addition_symbols;i++)	str+=str[0];
	//Вычисляем размер текста в блоках.
	unsigned str_block_count=str.length()/block_size;
	for(unsigned i=0;i<str_block_count;i++){
		//Срез строки размером равным размеру блока.
		string block_slice;
		block_slice=str.substr(i*block_size,block_size);
		//Поиск символа в алфавите.
		int symbol_index=-1,j=0;
		bool flag=true;
		while((j<this->size)&&flag){
			if(this->arr[j].get_symb()==block_slice){
				symbol_index=j;
				flag=false;
			}
			j++;
		};
		//Запись кода символа в результирующий код.
		if(flag){
			cout<<"Слово не удовлетворяет алфавиту."<<endl;
			exit(1);
		}
		else result_code+=this->arr[symbol_index].get_code();
	};
	return result_code;
};

string Alphabet::decode_text(string code){
	//Результирующий текст
	string result_text;
	#ifndef _RGZ
		unsigned block_size = binstr_to_num(code.substr(0,8));
		unsigned addition_symbols = binstr_to_num(code.substr(8,8));
		//Удаление заголовка из кода для дальнейшего декодирования.
		code.erase(0,16);
	#else
		//Считывание заголовка размером 8 бит - кол-во дописанных символов.
		unsigned addition_symbols = binstr_to_num(code.substr(8,8));
		//Удаление заголовка из кода для дальнейшего декодирования.
		code.erase(0,8);
	#endif
	//Каждый шаг цикла добавляет в результирующую строку блок из исходного алфавита, и удаляет из строки с кодом код блока.
	while(code.length()!=0){
		bool flag=true;
		unsigned size_of_slice=1;
		unsigned j;
		//Поиск блока с кодом размером size_of_slice
		while((size_of_slice<=60)&&flag){
			j=0;
			string slice=code.substr(0,size_of_slice);
			//Поиск кода совпадающего с slice
			while((j<this->size)&&flag){
				if(this->arr[j].get_code()==slice){
					flag=false;
				}
				else j++;
			};
			size_of_slice++;
		};
		result_text+=arr[j].get_symb();
		//Удаление кода из начала строки
		code.erase(0,size_of_slice-1);
	}
	//Удаление добавленных при кодировке символов.
	result_text.erase((result_text.length()-addition_symbols),addition_symbols);
	return result_text;
};


int Alphabet::search_symb(string str){
	int symbol_index=-1,j=0;
	bool flag=true;
	while((j<this->size)&&flag){
		if(this->arr[j].get_symb()==str){
			symbol_index=j;
			flag=false;
		}
		j++;
	};
	return symbol_index;
}

//Вспомогательные функции
string num_to_binstr(unsigned num){
	bitset<8> result((unsigned char)num);
	return result.to_string();
};

unsigned binstr_to_num(string str){
	bitset<8> result(str);
	return (unsigned)result.to_ulong();
};
  
//Дерево для кодов Хаффмана
MinHeapNode::MinHeapNode(Symbol symb):symb(symb){ 
        left = NULL;
		right = NULL; 
}; 
  
//Компаратор для узлов дерева. 
struct compare { 
    bool operator()(MinHeapNode* l, MinHeapNode* r){ 
        return (l->symb.get_prob() > r->symb.get_prob()); 
    } 
}; 
  
//Метод обходит дерево root, и сохраняет коды символов алфавита.
void Alphabet::storeCodesHuffman(struct MinHeapNode* root, string str) { 
	int symb_index;
	if (root==NULL) 
        return; 
    //Элемент "$" останавливает обход.
    if (root->symb.get_symb() != "$"){
		symb_index=this->search_symb(root->symb.get_symb());
		this->arr[symb_index].set_code(str); 
	}
    this->storeCodesHuffman(root->right, str + "1"); 
    this->storeCodesHuffman(root->left, str + "0"); 
} 


//Вносит символы в алфавита в очередь с приоритетами и строит по ней дерево для получения кодов.
void Alphabet::getHuffmanCodes(){ 
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
    struct MinHeapNode *left, *right, *top; 
    //Создаем дерево.
	for (auto v=this->arr.begin(); v!=this->arr.end(); v++) 
        minHeap.push(new MinHeapNode(*v)); 
	//Пока не появилась вершина включающая в себя все символы алфавита.
	while (minHeap.size() != 1){
		//Берем 2 элемента как левого и правого потомка текущего узла. 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
		//Получаем узел склеивая символы.
        top = new MinHeapNode(Symbol("$",left->symb.get_prob() + right->symb.get_prob())); 
        top->left = left; 
        top->right = right; 
		//Заносим узел обратно в очередь.
		minHeap.push(top); 
    }
	//Сохраняем коды. 
    this->storeCodesHuffman(minHeap.top(), ""); 
};
  