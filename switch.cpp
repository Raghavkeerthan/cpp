#include <iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    int doantion;
    cout<<"enter the bank you want to donate 1=SBI or 2=HDFC or 3=APB :";
    cin>>doantion;
    switch(doantion)
    {
        case 1:
        cout<<"thank you for donating to SBI";
        break;
        case 2:
        cout<<"thank you for doanting to HDFC";
        break;
        case 3:
        cout<<"tank you for doanting to APB";
        break;

    default:cout<<"enter only 1,2,3";
    }
    return 0;
}