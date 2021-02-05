#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <listel.h>

template <class Type>
class DoubleLinkedList{
    ListEl<Type>* list_start;
    ListEl<Type>* list_end;
    ListEl<Type>* list_current;
public:
    DoubleLinkedList();
    void add_el(Type element);
    Type pop_el();
    Type get_el();
    void ptr_to_start();
    void ptr_to_end();
    int is_end();
    void clear();
    void next_el();
    void prev_el();
    void print();
};

#endif // DOUBLELINKEDLIST_H
