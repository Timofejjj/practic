#include <iostream>
#include "List.h"

int main()
{
    MyList list1;
    list1.AddFirst(7);
    list1.AddFirst(4);
    list1.Print();
    std::cout << "\n";
    list1.AddFirst(6);
    list1.AddFirst(2);
    list1.Print();
    std::cout << "\n";
    list1.DeleteElement();
    list1.Print();
    std::cout << "\n";
    std::cout << (list1.Empty() ? "list1 empty\n" : "list1 not empty\n");

    MyList list2;
    list2.AddFirst(10);
    list2.AddFirst(20);
    list2.Print();
    std::cout << "\n";
    list2.DeleteElement();
    list2.Print();
    std::cout << "\n";
    std::cout << (list2.Empty() ? "list2 empty\n" : "list2 not empty\n");

    std::vector<int> Vector1;
    list1.ToVector(Vector1);
    for (int value : Vector1) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::vector<int> Vector2;
    list2.ToVector(Vector2);
    for (int value : Vector2) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}

