#include "optimal_code.hpp"

using namespace std;

//������ ������ Symbol
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

//������ ������ Alphabet
Alphabet::Alphabet(unsigned long size):size(size){};

void Alphabet::read(){
    cout<<"������� ������� ������� "<<this->size<<" :\n"; 
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
			else cout << "����� ������������ ��������� �������� �� ����� 1. ��������� ����."<<endl; 
		#endif	
	}

};

void Alphabet::file_read(ifstream& input_file,ofstream& out){
	string t_symb;
    double t_prob,sum_prob;
	string temp_str;
	getline(input_file,temp_str);
	out<<"�������:"<<endl;
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

//���������� ����� ������������ �������� � �������� begin �� end.
double Alphabet::sum_probs(int begin,int end){
	double t_sum=0;
	for(int i=begin;i<end;i++){
		t_sum+=this->arr[i].get_prob();
	}
	return t_sum;
};

//��� ��������� �������-����.
void Alphabet::shennoncode_build_step(int begin,int end){
	//����� �������� ������� ������� �� 2 ����� ����� ������������ ������� �����.
	int mid=begin;
	double min_diff,diff=1;
	//���� �������� ������������ ����� ����� � ������ ������ ����������� �������� mid ������.
	do{
		mid++;
		min_diff=diff;
		diff=fabs(this->sum_probs(begin,mid)-this->sum_probs(mid,end));
	}while(diff<min_diff);
	//������������ � ����������� ��������
	mid--;
	//������� ��������� ��������: 1.��������� ������� ������������������ ����� ��������� 2.����� ��������� � �������� �������� ��� ������ ���������.
	if((begin!=end)&&(abs(begin-end)!=1)){
		//��������� ���� ��������
		for(int i=begin;i<mid;i++){
			this->arr[i].set_code(this->arr[i].get_code()+"0");
		}
		for(int i=mid;i<end;i++){
			this->arr[i].set_code(this->arr[i].get_code()+"1");
		}
		//��������� ��� ��������� � ������� � ������ ��������� ������������ mid.
		this->shennoncode_build_step(begin,mid);
		this->shennoncode_build_step(mid,end);
	}
};

void Alphabet::build_code_arr(int mode){
	//���������� �������� �� �������� ������������.
	sort(this->arr.begin(),this->arr.end(), [](Symbol& a, Symbol& b){
			if(a.get_prob()==b.get_prob()){
				return a.get_pos()<b.get_pos();
			}
			return a.get_prob()>b.get_prob();
		});
	for(unsigned long i=0;i<this->size;i++){
		this->arr[i].clear_code();
	}
	//���������� ����� ��������.
	switch (mode){
		case SHENNON_FANO_CODE:
			this->shennoncode_build_step(0,this->size);
			break;
		break;
		case HUFFMAN_CODE:
			this->getHuffmanCodes();
			break;
		default:
			cout<<"����������� ����� ��������� ���������� ������������ ����"<<endl<<"��������� �������� ���"<<endl;
			exit(1);
		break;
	};
};

Alphabet Alphabet::build_nsized_Alphabet(int n) {
	//��������� �-����� ������� �� ������������������� ������� ��������� ��������, ����� ������������� ���.
	sort(this->arr.begin(), this->arr.end(), [](Symbol& a, Symbol& b) {
		return a.get_pos() < b.get_pos();
		});
	//������ ��������� ��������.
	unsigned long m = this->size;
	//�������� ��������������� �������� �������� m^n 
	unsigned long new_size = (int)round(pow(m, n));
	Alphabet newAlphabet(new_size);
	//��������� ���������� ��� ������������ ������ ������� ��������.
	string t_symb; double t_prob;
	//������ �������� �������� ��������� ��������, 0-�� ������� ���������� ��� ��������� ���������.
	//unsigned long index_arr[n + 1];
	unsigned long* index_arr = new unsigned long[n + 1];
	for (int i=0;i<=n;i++) index_arr[i]=0;
	//������������� ��������� ���������� ����������� �������.
	t_prob=1;	
	//���������� ��� ������ ������ ������� � ��������.
	do{
		//���������� ������ ������� ��������.
		for(int i=1;i<=n;i++){
			int index = index_arr[i];
			t_symb+=this->arr[index].get_symb();
			t_prob*=this->arr[index].get_prob();
		};
		//������ ������� � ����� �������
		Symbol temp(t_symb,t_prob);
		newAlphabet.arr.push_back(temp);
		//������� ��������� ����������
		t_symb.clear();
		t_prob=1;

		int last=n; index_arr[last]++;
		//������� ������� ��� ������������ ��������.
		while(index_arr[last]==m){
			index_arr[last]=0;
			index_arr[last-1]+=1;
			last--;
		};
	} while(index_arr[0]==0);

	//������� ������� �������� � ����� �������� ��� ������������������ ����������.
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
	//�������������� ���.
	string result_code;

	unsigned block_size = this->get_symbol_size();
	//���-�� �������� ���������� ��� ���������� ���������� �����.
	unsigned addition_symbols = block_size - ((str.length())%block_size);
	#ifndef _RGZ
		//���������� � ��������� ������ 1 �����.	
		result_code+=num_to_binstr(block_size);
	#endif

	//���������� � ��������� ���-�� ���������� �������� � ��������� ����.	
	result_code+=num_to_binstr(addition_symbols);

	//���������� ��������� ���� �� �������, ���� �� �� �����.
	for(unsigned i=0;i<addition_symbols;i++)	str+=str[0];
	//��������� ������ ������ � ������.
	unsigned str_block_count=str.length()/block_size;
	for(unsigned i=0;i<str_block_count;i++){
		//���� ������ �������� ������ ������� �����.
		string block_slice;
		block_slice=str.substr(i*block_size,block_size);
		//����� ������� � ��������.
		int symbol_index=-1,j=0;
		bool flag=true;
		while((j<this->size)&&flag){
			if(this->arr[j].get_symb()==block_slice){
				symbol_index=j;
				flag=false;
			}
			j++;
		};
		//������ ���� ������� � �������������� ���.
		if(flag){
			cout<<"����� �� ������������� ��������."<<endl;
			exit(1);
		}
		else result_code+=this->arr[symbol_index].get_code();
	};
	return result_code;
};

string Alphabet::decode_text(string code){
	//�������������� �����
	string result_text;
	#ifndef _RGZ
		unsigned block_size = binstr_to_num(code.substr(0,8));
		unsigned addition_symbols = binstr_to_num(code.substr(8,8));
		//�������� ��������� �� ���� ��� ����������� �������������.
		code.erase(0,16);
	#else
		//���������� ��������� �������� 8 ��� - ���-�� ���������� ��������.
		unsigned addition_symbols = binstr_to_num(code.substr(8,8));
		//�������� ��������� �� ���� ��� ����������� �������������.
		code.erase(0,8);
	#endif
	//������ ��� ����� ��������� � �������������� ������ ���� �� ��������� ��������, � ������� �� ������ � ����� ��� �����.
	while(code.length()!=0){
		bool flag=true;
		unsigned size_of_slice=1;
		unsigned j;
		//����� ����� � ����� �������� size_of_slice
		while((size_of_slice<=60)&&flag){
			j=0;
			string slice=code.substr(0,size_of_slice);
			//����� ���� ������������ � slice
			while((j<this->size)&&flag){
				if(this->arr[j].get_code()==slice){
					flag=false;
				}
				else j++;
			};
			size_of_slice++;
		};
		result_text+=arr[j].get_symb();
		//�������� ���� �� ������ ������
		code.erase(0,size_of_slice-1);
	}
	//�������� ����������� ��� ��������� ��������.
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

//��������������� �������
string num_to_binstr(unsigned num){
	bitset<8> result((unsigned char)num);
	return result.to_string();
};

unsigned binstr_to_num(string str){
	bitset<8> result(str);
	return (unsigned)result.to_ulong();
};
  
//������ ��� ����� ��������
MinHeapNode::MinHeapNode(Symbol symb):symb(symb){ 
        left = NULL;
		right = NULL; 
}; 
  
//���������� ��� ����� ������. 
struct compare { 
    bool operator()(MinHeapNode* l, MinHeapNode* r){ 
        return (l->symb.get_prob() > r->symb.get_prob()); 
    } 
}; 
  
//����� ������� ������ root, � ��������� ���� �������� ��������.
void Alphabet::storeCodesHuffman(struct MinHeapNode* root, string str) { 
	int symb_index;
	if (root==NULL) 
        return; 
    //������� "$" ������������� �����.
    if (root->symb.get_symb() != "$"){
		symb_index=this->search_symb(root->symb.get_symb());
		this->arr[symb_index].set_code(str); 
	}
    this->storeCodesHuffman(root->right, str + "1"); 
    this->storeCodesHuffman(root->left, str + "0"); 
} 


//������ ������� � �������� � ������� � ������������ � ������ �� ��� ������ ��� ��������� �����.
void Alphabet::getHuffmanCodes(){ 
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
    struct MinHeapNode *left, *right, *top; 
    //������� ������.
	for (auto v=this->arr.begin(); v!=this->arr.end(); v++) 
        minHeap.push(new MinHeapNode(*v)); 
	//���� �� ��������� ������� ���������� � ���� ��� ������� ��������.
	while (minHeap.size() != 1){
		//����� 2 �������� ��� ������ � ������� ������� �������� ����. 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
		//�������� ���� �������� �������.
        top = new MinHeapNode(Symbol("$",left->symb.get_prob() + right->symb.get_prob())); 
        top->left = left; 
        top->right = right; 
		//������� ���� ������� � �������.
		minHeap.push(top); 
    }
	//��������� ����. 
    this->storeCodesHuffman(minHeap.top(), ""); 
};
  