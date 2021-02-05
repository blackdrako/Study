#ifndef DECK_H
#define DECK_H
#include <doublelinkedlist.h>

template <class Type>
class Deck{
    DoubleLinkedList<Type> list;
    unsigned current_size;
    unsigned max_size;
public:
    Deck(unsigned size);
    void push_back(Type data);
    void push_front(Type data);
    Type pop_back();
    Type pop_front();
    int is_empty();
    void clear();
};

#endif // DECK_H
