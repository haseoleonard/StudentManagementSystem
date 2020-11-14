#include <exception>
#include <stdexcept>
#include <new>
#define MAX_LIST 50
#define MIN_LIST 10
#pragma once
template <class T>
class ArrayList
{
private:
    /* data */
    T **_list;
    int _size;
    int _listSize;
    bool needExpansion();
    void expandArray();
    bool isValidIndex(int index);

public:
    ArrayList(/* args */);
    bool add(const T &object);
    T *get(int index);
    int length() { return _size; };
    T *removeAt(int index);
    bool isEmpty() { return _size == 0; };
    void clear();
    ~ArrayList()
    {
        delete[] & _list;
    };
};
#include "ArrayList.inl"