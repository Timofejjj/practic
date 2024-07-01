#pragma once
#include <iostream>
#include <vector>

struct SElement
{
    int data;
    SElement* next;
    SElement(int data_, SElement* next_)
        : data{ data_ }, next{ next_ } {};
    ~SElement() = default;
};

class MyList
{
private:
    SElement* first;

public:
    MyList();
    MyList(int a);
    MyList(int a, int b, int c);
    ~MyList();
    bool Empty();
    void AddFirst(int Value);
    int DeleteElement();
    void Print();
    int Count();
    int Get(int);
    void ToVector(std::vector<int>&);
};

