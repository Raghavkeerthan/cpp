#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    int a;
    
    cout<<"Enter number between 1-9  ";
    cin>>a;
    while(a>9){
        cout<<"enter only number between 1-9 :";
        cin>>a;
    }
    cout<<"thank you for shopping";
    return 0;
}