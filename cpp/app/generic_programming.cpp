// generic_programming.cpp

#include <iostream>
#include <string>
using namespace std;

template <typename T> // or template <class T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a    = b;
    b    = temp;
}
int main(void)
{
    int a = 1;
    int b = 2;
    Swap(a, b);

    return 0;
}

