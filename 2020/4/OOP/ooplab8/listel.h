#ifndef LISTEL_H
#define LISTEL_H
#include <iostream>
using namespace std;

template <class Type>
class ListEl{
    Type data;
    ListEl* next_link;
    ListEl* prev_link;
public:
    ListEl();
    ListEl(Type data);
    void set_next_link(ListEl* link);
    void set_prev_link(ListEl* link);
    void set_data(Type data);
    Type get_data();
    ListEl *get_next();
    ListEl *get_prev();
    void print();
};

#endif // LISTEL_H
