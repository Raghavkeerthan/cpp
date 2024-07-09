 #include <iostream>
 #include<cmath>
 #include<cstdlib>
 using namespace std;
 int main()
 {
   int numb;
   do{
    cout<<"Enter a value from 0-10 ";
    cin>>numb;}
    while(numb<0 || numb>10);
    cout<<"thank you for choosing";

   
    return 0;
 }