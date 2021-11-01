#include <iostream>
#include "DataStruture/LinearList/LinkedList.hpp"
#define MAGENTA    "\033[35m"
#define NONE_COLOR "\033[0m"

int main()
{
    printf("linked list\n");
    DataStruture::LinkedList<int> list = DataStruture::LinkedList<int>();
    list.Travel();
    for (int i = 0; i < 5; i++)
    {
        list.Append(i);
        list.Travel();
    }
    std::cout << MAGENTA << "--- Test Insert(1, -1 ) : " << NONE_COLOR;
    list.Insert(1, -1);
    list.Travel();
    std::cout << MAGENTA << "--- Test Insert(2,1024) : " << NONE_COLOR;
    list.Insert(2, 1024);
    list.Travel();
    std::cout << MAGENTA << "--- Test Insert(3,  2 ) : " << NONE_COLOR;
    list.Insert(3, 2);
    list.Travel();

    std::cout << MAGENTA << "--- Test Remove(-1) : " << NONE_COLOR;
    std::cout <<list.Remove(-1);
    list.Travel();
    std::cout << MAGENTA << "--- Test Remove(0)  : " << NONE_COLOR;
    std::cout <<list.Remove(0);
    list.Travel();
    std::cout << MAGENTA << "--- Test Remove(10) : " << NONE_COLOR;
    std::cout <<list.Remove(10);
    list.Travel();
    std::cout << MAGENTA << "--- Test Remove(300): " << NONE_COLOR;
    std::cout <<list.Remove(300);
    list.Travel();


    return 0;
}