#include "tree.h"
#include <iostream>
#include <exception>
template<class T, int size>
Tree<T,size>::Tree(T data) : data(data)
{
    for (long unsigned int i = 0; i < size; i++) {
        sons[i] = nullptr;
    }
}
template <class T, int size>
Tree<T, size>::~Tree(){
    for (int i = 0; i < size; i++) {
        if (sons[i] != nullptr) {
            delete sons[i];
        }
    }
}

template<class T, int size>
void Tree<T, size>::add_nth(int n, Tree* t){
        if (n >= size || n < 0) {
            throw std::out_of_range("Can't add element");
        }
        else {
            sons[n] = t;
        }
    }

template<class T, int size>
Tree<T, size>* Tree<T, size>::get_nth(int n) {
    if (n >= size || n < 0) {
        throw std::out_of_range("Can't get element");
    }
    else {
        return sons[n];
    }
}

template<class T, int size>
T Tree<T, size>::get_data() {
    return this->data;
}

template<class T, int size>
void Tree<T, size>::set_data(T data) {
    this->data = data;
}

template <class T, int size>
void Tree<T, size>::print() {
    std::cout << data;
    std::cout << '(';
    for (int i = 0; i < size; i++) {
        if (sons[i]) {
            sons[i]->print();
        }
    }
    std::cout << ')';
}
