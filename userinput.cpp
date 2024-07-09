#include <iostream>
using namespace std;
int main()
{
    cout << "enter the temp in fahrenheit :";
    double temp_F;
    cin >> temp_F;
    double temp_C=(temp_F-32)/(1.8);

    cout <<"Temp in celsius is :"<< temp_C;

    return 0;
}