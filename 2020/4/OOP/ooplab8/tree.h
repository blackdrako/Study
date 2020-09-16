#ifndef TREE_H
#define TREE_H

template <class T,int size>
class Tree
{
private:
    T data;
    Tree* sons[size];
public:
    Tree(T data);
    ~Tree();
    void add_nth(int n, Tree* t);
    Tree* get_nth(int n);
    T get_data();
    void set_data(T data);
    void print();
};


#endif // TREE_H
