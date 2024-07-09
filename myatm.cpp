#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
void showbalance(double balance);
double deposite(double balance);
double withdraw(double balance);

int main(){
    double balance=1000;
    int choice;
    cout<<"*************ATM MACHINE*************"<<endl;
    do{
    cout<<"Press 1 to show your current balance"<<endl;
    
    cout<<"Press 2 to withdraw "<<endl;

    cout<<"Press 3 to deposite"<<endl;
    cout<<"Press 4 to exit"<<endl;
    cin>>choice;
    cin.clear();
    fflush(stdin);
    switch(choice){    
    case 1:showbalance(balance);cout<<endl;
    break;
    case 2:cout<<"Enter the amount you want to withdraw"<<endl;balance=withdraw(balance);cout<<balance<<endl;
    break;
    case 3:cout<<"Enter amount you want to deposite "<<endl;balance=deposite(balance);cout<<balance<<endl;
    break;
    case 4:cout<<"Thank You for visiting";
    break;
    default:
        cout<<"You press INVALID option"<<endl;
 }}
 while(choice!=4);

    return 0;
}
void showbalance(double balance){
     cout<<"Your current balance is $"<<setprecision(2)<<fixed<<balance;
    
}
double withdraw(double balance){
    double amount;
    cin>>amount;
    if(amount>balance){
        cout<<"insufficent balance"<<endl;
        cout<<"Your current balance is $";
        return balance;
    }
    else if(amount<0){
        cout<<"Enter valid amount"<<endl;
        cout<<"Your current balance is $";
        return balance;
    }
    else{
        cout<<"Your current balance is $";
        return balance-amount;

    }
    
 }
double deposite(double balance){
    double amount;
    cin>>amount;
    if(amount<0){
        cout<<"Enter valid amount "<<endl;
        cout<<"Your current balance is $";
        return balance;
    }
    else
    cout<<"Your current balance is $";
    return balance+amount;

}

