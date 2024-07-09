#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
    cout<<"*************SIMPLECALCULATOR**********"<<endl;
      double numb_1;
   cout<<"enter your #1 number: ";
   cin>>numb_1;
   double numb_2;
   cout<<"enter your #2 number: ";
   cin>>numb_2;
    char op;  
   cout<<"what operation you want to do  ";
   cin>>op;     //to assign an operator from the user 
  do{

   
  
   switch(op)
   {
    case '+':
    cout<<"your result is "<<(numb_1+numb_2);
    break;
    case '-':
    cout<<"your result is "<<(numb_1-numb_2);
    break;
    case '*':
    cout<<"your result is "<<(numb_1*numb_2);
    break;
    case'/':
    cout<<"your result is "<<(numb_1/numb_2);
    break;
   }
   while(op= '+' || op= '-'|| op= '*'||op='/')

    return 0;
}