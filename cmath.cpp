#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout<<"Enter the radius of cirlce :";
    double radius;
    cin>>radius;
    double pi=3.14;
    double area=pow(radius,2)*pi;
   
    cout<<"area of circle is :"<<area;
    return 0;
}