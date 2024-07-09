#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
   srand(time(0));
   int dice1=(rand()%6)+1;
   int dice2=(rand()%6)+1;
   cout<<"dice1 :"<<dice1 <<endl<<"dice2 :"<<dice2;


    return 0;
}
