#include <iostream>
using namespace std;
int main()
{
    double sales=95000;
    double state_tax=(4*sales)/100;
    double country_tax=(2*sales)/100;
    cout <<"state_tax="<<state_tax << endl

         <<"country_tax="<<country_tax<<endl

         <<"total_sales="<<(sales-(state_tax+country_tax));

    return 0;
}