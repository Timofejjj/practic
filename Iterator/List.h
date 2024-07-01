#pragma once
#include <iostream>
#include <vector>

// Структура элемента списка
struct Node
{
    int data;
    Node* next;
    Node(int data_, Node* next_)
        : data{ data_ }, next{ next_ } {};
    ~Node() = default;
};

// Класс MyList
class MyList
{
private:
    Node* head;

public:
    MyList();
    MyList(int a);
    MyList(int a, int b, int c);
    ~MyList();
    bool IsEmpty() const;
    void AddAtFront(int value);
    int RemoveFirst();
    void Display() const;
    int Size() const;
    int GetElement(int index) const;
    void ToVector(std::vector<int>& vec) const;
};

// Абстрактный класс Iterator
class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual void MoveToStart() = 0;
    virtual void MoveNext() = 0;
    virtual bool HasFinished() const = 0;
    virtual int Current() const = 0;
protected:
    Iterator() = default;
};

// Класс ListIterator, наследующий Iterator
class ListIterator : public Iterator
{
public:
    ListIterator(MyList* aList);
    virtual void MoveToStart();
    virtual void MoveNext();
    virtual bool HasFinished() const;
    virtual int Current() const;

private:
    MyList* list;
    int currentIndex;
};

