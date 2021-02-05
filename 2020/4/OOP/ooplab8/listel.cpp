#include "listel.h"

template <class Type>
ListEl<Type>::ListEl(){
    this->next_link=nullptr;
    this->prev_link=nullptr;
};

template <class Type>
ListEl<Type>::ListEl(Type data):data(data){
    this->next_link=nullptr;
    this->prev_link=nullptr;
};

template <class Type>
void ListEl<Type>::set_next_link(ListEl<Type>* link){
    this->next_link=link;
};

template <class Type>
void ListEl<Type>::set_prev_link(ListEl<Type>* link){
    this->prev_link=link;
};

template <class Type>
void ListEl<Type>::set_data(Type data){
    this->data=data;
};

template <class Type>
Type ListEl<Type>::get_data(){
    return this->data;
};

template <class Type>
ListEl<Type> *ListEl<Type>::get_next(){
    return this->next_link;
};

template <class Type>
ListEl<Type> *ListEl<Type>::get_prev(){
    return this->prev_link;
};

template <class Type>
void ListEl<Type>::print(){
    cout<<"Data: "<<this->data<<endl;
};
