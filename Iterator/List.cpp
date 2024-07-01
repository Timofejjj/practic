#include "List.h"

MyList::MyList() : head(nullptr) {}

MyList::MyList(int a)
{
    head = new Node(a, nullptr);
}

MyList::MyList(int a, int b, int c)
{
    head = new Node(a, nullptr);
    Node* temp = new Node(b, nullptr);
    head->next = temp;
    temp = new Node(c, nullptr);
    head->next->next = temp;
}

MyList::~MyList()
{
    while (head != nullptr)
        this->RemoveFirst();
}

bool MyList::IsEmpty() const
{
    return (nullptr == head);
}

void MyList::AddAtFront(int value)
{
    Node* newNode = new Node(value, head);
    head = newNode;
}

int MyList::RemoveFirst()
{
    if (head == nullptr)
        return -1;
    Node* temp = head;
    head = head->next;
    int value = temp->data;
    delete temp;
    return value;
}

void MyList::Display() const
{
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        std::cout << temp->data << " ";
}

int MyList::Size() const
{
    if (IsEmpty())
        return 0;
    Node* temp = head;
    int count = 1;
    while (temp->next != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int MyList::GetElement(int index) const
{
    Node* el = head;
    for (int i = 0; i < index; i++)
        el = el->next;
    return el->data;
}

void MyList::ToVector(std::vector<int>& vec) const
{
    vec.clear();
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        vec.push_back(temp->data);
}

// Конструктор итератора
ListIterator::ListIterator(MyList* aList) : list(aList), currentIndex(0) {}

void ListIterator::MoveToStart()
{
    currentIndex = 0;
}

void ListIterator::MoveNext()
{
    currentIndex++;
}

bool ListIterator::HasFinished() const
{
    return currentIndex >= list->Size();
}

int ListIterator::Current() const
{
    return list->GetElement(currentIndex);
}
