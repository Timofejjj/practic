#include <iostream>
#include "List.h"

int main()
{
    MyList list;
    list.AddFirst(23);
    list.AddFirst(1);
    list.AddFirst(4);
    list.AddFirst(2);
    list.AddFirst(3);
    for (ListIterator iterator(&list); iterator.HasFinished(); iterator.Next())
    {
        std::cout << iterator.CurrentItem() << '\n';
    }
    return 0;
}