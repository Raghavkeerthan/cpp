#include <iostream>
int main()
{
    double a=5.5;
    double b=9.9;
    int swap=a;
    a=b;
    b=swap;
    std::cout << b;
    return 0;
}