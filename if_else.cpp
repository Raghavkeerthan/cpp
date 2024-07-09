#include <iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
    double age;
    cout<<"enter your age :";
    cin>>age;
    if(age>18)
    {
        cout<<"you can enter";}
    else if(age==18)
    {
        cout<<"show your ID";
    }    
    else
    {
        cout<<"you are not allowed";
    }
    ;
    return 0;
}