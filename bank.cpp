#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int withdrawcode(int balance , int withdraw){
    cout<<"YOUR CURRENT BALANCE IS $ ";
    cout<< balance-withdraw;
}
int depositecode(int balance,int deposite){
    cout<<"YOUR CURRENT BALANCE IS $"<<balance + deposite<<endl;
}
   int main(){
   int deposite;
   int choice;
   int balance=0;
   int withdraw;

     cout<<"PRESS 1 TO SHOW YOUR CURRENT BALANCE"<<endl;
     cout<<"PRESS 2 TO WITHDRAW THE MONEY"<<endl;
     cout<<"PRESS 3 TO DEPOSITE THE MONEY"<<endl;
     cout<<"PRESS 4 TO EXIT"<<endl;
     cin>>choice;
      
        switch(choice){
        case 1:cout<<"YOUR BALANCE IS $"<<balance;
        break;
        case 2:cout<<"ENTER THE AMOUNT YOU WANT TO WITHDRAW ";
               cin>>withdraw;
               withdrawcode(balance,withdraw); 
        break; 
        case 3:cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSITE ";
               cin>>deposite;
               depositecode(deposite,balance);
        break;       
        case 4:cout<<"THANK YOU FOR VISITING";
        break;
        default:cout<<"INVALID ENTRY";
        
    }
      
    return 0;


   } 



