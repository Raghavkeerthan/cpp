#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
    char x;
    double temp;
    cout<<"enter the temp in C or F  :";

    cin>>x;
    switch(x){
        case 'C':
        cout<<"ENter the temp    you want to convert to F"<<endl;
        cin>>temp;
        cout<<((1.8)*(temp))+32<<"F";
        break;
        case 'F':
        cout<<"enter the temp you want to convert into C"<<endl;
        cin>>temp;
        cout<<((temp)-32)*(0.555555)<<"C";
        break;
        default:
        cout<<"enter temp either in C or F";
    }
    




    return 0;
}