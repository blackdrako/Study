#include "deck.h"

template <class Type>
Deck<Type>::Deck(unsigned size):max_size(size),current_size(0),list(DoubleLinkedList<Type>()){};

template <class Type>
void Deck<Type>::push_back(Type data){
    this->list.ptr_to_end();
    this->list.add_el(data);
    this->current_size++;
};

template <class Type>
void Deck<Type>::push_front(Type data){
    this->list.ptr_to_start();
    this->list.add_el(data);
    this->current_size++;
};

template <class Type>
Type Deck<Type>::pop_back(){
    this->list.ptr_to_end();
    this->current_size--;
    return this->list.pop_el();
};

template <class Type>
Type Deck<Type>::pop_front(){
    this->list.ptr_to_start();
    this->current_size--;
    return this->list.pop_el();
};

template <class Type>
int Deck<Type>::is_empty(){
    return this->current_size==0;
};

template <class Type>
void Deck<Type>::clear(){
    this->list.clear();
    this->current_size=0;
};
