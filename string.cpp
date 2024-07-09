#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
    string name;
    cout<<"enter your username  :";
    getline(cin,name);//to e=get entire sentence
    cout<<"hello "<<name<<endl;
    cout<<"your name has ";
    cout<<name.length()<<" letters ";//if u want to know the lenght of the string
    name.append("@gmai.com");//if you want to add anything at the end of the string
    name.empty();//when string is not entered
    name.clear();//to clear the string;
    name.at(0);//to know the charater at a given posion
    name.insert(0,"@");//to insert a character in the required position
    name.find(' ');//to find a particular character in the string
    name.erase(0,9);//to remove a particular part in the string

    return 0;
}