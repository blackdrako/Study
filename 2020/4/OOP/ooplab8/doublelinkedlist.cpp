#include "doublelinkedlist.h"

template <class Type>
DoubleLinkedList<Type>::DoubleLinkedList(){
    this->list_start= new ListEl<Type>();
    this->list_end= new ListEl<Type>();
    this->list_current=this->list_start;

};

template <class Type>
void DoubleLinkedList<Type>::add_el(Type element){
    ListEl<Type> *temp_ptr = new ListEl<Type>(element);

    if(this->list_current->get_next()==nullptr){
        temp_ptr->set_next_link(nullptr);
        temp_ptr->set_prev_link(list_current);
    }else{
        temp_ptr->set_next_link(this->list_current->get_next());
        temp_ptr->set_prev_link(list_current);
        this->list_current->get_next()->set_prev_link(temp_ptr);
    }
    this->list_current->set_next_link(temp_ptr);
    this->next_el();
};

template <class Type>
Type DoubleLinkedList<Type>::pop_el(){
    Type temp=this->list_current->get_data();
    ListEl<Type> *pr=this->list_current->get_prev();
    ListEl<Type> *nx=this->list_current->get_next();
    pr->set_next_link(nx);
    nx->set_prev_link(pr);
    return temp;
};

template <class Type>
Type DoubleLinkedList<Type>::get_el(){
    return this->list_current->get_data();
};

template <class Type>
void DoubleLinkedList<Type>::ptr_to_start(){
    this->list_current=this->list_start;
    this->next_el();
};

template <class Type>
void DoubleLinkedList<Type>::ptr_to_end(){
    this->list_current=this->list_end;
    this->prev_el();

};

template <class Type>
void DoubleLinkedList<Type>::clear(){
    this->ptr_to_start();
    while(this->list_current!=this->list_end){
        this->pop_el();
    }
};


template <class Type>
int DoubleLinkedList<Type>::is_end(){
    return this->list_current==this->list_end;
};

template <class Type>
void DoubleLinkedList<Type>::next_el(){
    this->list_current=this->list_current->get_next();
};

template <class Type>
void DoubleLinkedList<Type>::prev_el(){
    this->list_current=this->list_current->get_prev();
};

template <class Type>
void DoubleLinkedList<Type>::print(){
    ListEl<Type> *temp_pos=this->list_current;
    this->ptr_to_start();
    int num=1;
    while(this->list_current!=this->list_end){
        cout<<"Element : "<<num<<endl;
        this->list_current->print();
        this->next_el();
        num++;
    };
    this->list_current=temp_pos;
};
