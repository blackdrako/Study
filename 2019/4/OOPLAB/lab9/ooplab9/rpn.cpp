#include "rpn.h"

int calc_tokens(vector<Token*> tokens){
    stack<int> calc_stack;
    int a,b;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]->get_id()==operand_id){
            calc_stack.push(tokens[i]->get_value());
        }else{
            a = calc_stack.top();
            calc_stack.pop();
            b = calc_stack.top();
            calc_stack.pop();
            calc_stack.push(tokens[i]->calc(a,b));
        }
    };
};


string infix_to_postfix(string str){
    string result;
    string current_token;
    stack<Token*> token_stack;
    vector<string> sep_str;
    //разбиение строки на список элементов
    while(str.length()!=0){
        int  sep_index=str.find(" ",0);
        current_token = str.substr(0,sep_index);
        str.erase(0,sep_index+1);
        sep_str.push_back(current_token);
    }
    //непосредственно преобразование в ОПЗ
    Token* temp;
    string temp_str;
    bool flag = true;
    for(int i=0,size=sep_str.size();i<size;i++){
        if(sep_str[i]==STR_PLUS){
            if(!token_stack.empty()){
                flag = true;
                while(flag&&(token_stack.top()->get_prior()>sum_priority)){
                    temp_str=token_stack.top()->get_str();
                    result=result+temp_str+" ";
                    token_stack.pop();
                    if(token_stack.empty()){
                        flag = false;
                    };
                };
            };
            temp=create_token(sum_id);
            token_stack.push(temp);
        }else if(sep_str[i]==STR_SUB){
            if(!token_stack.empty()){
                flag = true;
                while(flag&&(token_stack.top()->get_prior()>sub_priority)){
                    temp_str=token_stack.top()->get_str();
                    token_stack.pop();
                    result=result+temp_str+" ";
                    if(token_stack.empty()){
                        flag = false;
                    };
                };
            };
            temp=create_token(subst_id);
            token_stack.push(temp);
        }else if(sep_str[i]==STR_MULT){
            if(!token_stack.empty()){
                flag = true;
                while(flag&&(token_stack.top()->get_prior()>mult_priority)){
                    temp_str=token_stack.top()->get_str();
                    token_stack.pop();
                    result=result+temp_str+" ";
                    if(token_stack.empty()){
                        flag = false;
                    };
                };
            };
            temp=create_token(mult_id);
            token_stack.push(temp);
        }else if(sep_str[i]==STR_DIV){
            if(!token_stack.empty()){
                flag = true;
                while(flag&&(token_stack.top()->get_prior()>div_priority)){
                    temp_str=token_stack.top()->get_str();
                    token_stack.pop();
                    result=result+temp_str+" ";
                    if(token_stack.empty()){
                        flag = false;
                    };
                };
            };
            temp=create_token(div_id);
            token_stack.push(temp);
        }else if(sep_str[i]==STR_OPEN_BRC){
            temp=create_token(open_brc_id);
            token_stack.push(temp);
        }else if(sep_str[i]==STR_CLOSE_BRC){
            while(token_stack.top()->get_id()!=open_brc_id){
                if(token_stack.empty()){
                    cout<<QString::fromUtf8("Неверно поставлен разделитель или скобки не согласованны.").toLocal8Bit().data();
                    exit(1);
                };
                temp_str=token_stack.top()->get_str();
                token_stack.pop();
                result=result+temp_str+" ";
            };
            token_stack.pop();
        }else{
            result=result+sep_str[i]+" ";
        }
    }
    while(!token_stack.empty()){
        temp_str=token_stack.top()->get_str();
        token_stack.pop();
        result=result+temp_str+" ";
    }
    return result;
};

Token* create_token(Token_id id){
    Token* temp;
    switch(id){
        case operand_id:
            temp = new Operand(0);
        break;
        case sum_id:
            temp = new OperatorPlus();
        break;
        case subst_id:
            temp = new OperatorMinus();
        break;
        case mult_id:
            temp = new OperatorMult();
        break;
        case div_id:
            temp = new OperatorDiv();
        break;
        case open_brc_id:
            temp = new Open_bracket();
        break;
        case close_brc_id:
            temp = new Close_bracket();
        break;
    }
    return temp;
};

vector<Token*> str_to_token(string str){
    vector<Token*> token_vector;
    vector<string> sep_str;
    //разбиение строки на список элементов
    while(str.length()!=0){
        int  sep_index=str.find(" ",0);
        string current_token = str.substr(0,sep_index);
        str.erase(0,sep_index+1);
        sep_str.push_back(current_token);
    }
    for(int i=0,size=sep_str.size();i<size;i++){
        if(sep_str[i]==STR_PLUS){
            token_vector.push_back(create_token(sum_id));
        }
        else if(sep_str[i]==STR_SUB){
            token_vector.push_back(create_token(subst_id));
        }
        else if(sep_str[i]==STR_MULT){
            token_vector.push_back(create_token(mult_id));
        }
        else if(sep_str[i]==STR_DIV){
            token_vector.push_back(create_token(div_id));
        }
        else{
            Operand* temp = new Operand(stoi(sep_str[i]));
            token_vector.push_back(temp);
        }
    }
};
