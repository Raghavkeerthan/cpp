#include <iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{  
    long elapsedseconds=time(0);
    srand(elapsedseconds);
    int number=rand() % 10;
    cout<<number;
    return 0;
}