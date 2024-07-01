#include "List.h"

MyList::MyList()
{
    first = nullptr;
}

MyList::MyList(int a)
{
    first = new SElement(a, nullptr);
}

MyList::MyList(int a, int b, int c)
{
    first = new SElement(a, nullptr);
    SElement* temp = new SElement(b, nullptr);
    first->next = temp;
    temp = new SElement(c, nullptr);
    first->next->next = temp;
}

MyList::~MyList()
{
    while (first != nullptr)
        this->DeleteElement();
}

bool MyList::Empty()
{
    return (nullptr == first);
}

void MyList::ToVector(std::vector<int>& Vec)
{
    Vec.clear();
    for (SElement* temp = first; temp != nullptr; temp = temp->next)
        Vec.push_back(temp->data);
}

int MyList::Count() {
    if (Empty())
        return 0;
    SElement* temp = first;


