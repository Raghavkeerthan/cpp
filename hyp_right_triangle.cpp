#include <iostream>
#include <cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    double side_a;
    cout<<"enter the value of side a :";
    cin>>side_a;
    double side_b;
    cout<<"enter the value of side b :";
    cin>>side_b;
    double hyp=sqrt(pow(side_a,2)+pow(side_b,2));
    cout<<"hyp of the triangle is "<<hyp;

    return 0;
}
