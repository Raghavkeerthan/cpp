#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<ctime>
using namespace std;

char playerchoice(char player);
int computerchoice(int computer);





int main(){
    cout<<"*******ROCK PAPER SCISSORS*********"<<endl;
    char player;
    
    int computer;
    player=playerchoice(player);
    
    computer=computerchoice(computer);
    switch(player){
       case 'r':if(computer==1){cout<<"It's a Tie !";}
                else if(computer==2){cout<<"OH NOO You Lost";}
                else{cout<<"HURRAY You WOn";}
        break;
        case 'p':if(computer==1){cout<<"HURRAY You Won";}
                else if(computer==2){cout<<"It's a Tie";}
                else{cout<<"OH NOO You Lost";}
        break;
        case 's':if(computer==1){cout<<"OH NOO You Lost";}
                else if(computer==2){cout<<"HURRAY You Won";}
                else{cout<<"It's a Tie";}
        break;
        
    }
    
    
   

   

    return 0;
}
char playerchoice(char player){
     char playerchoice;
     cout<<"Choose One "<<endl;
     cout<<"Press r for ROCK"<<endl;
     cout<<"Press p for PAPER"<<endl;
     cout<<"Press s for SCISSORS"<<endl;
     do{
     cin>>playerchoice;
     cin.clear();
     fflush(stdin);
        switch(playerchoice){  
        case 'r':cout<<"You chose ROCK"<<endl;
        break;
        case 'p':cout<<"You chose PAPER"<<endl;
        break;
        case 's':cout<<"You chose SCISSORS"<<endl;
        break;
        default:cout<<"Choose valid option"<<endl;
        }
        
    } while(playerchoice!='r' && playerchoice!='s'&& playerchoice!='p');
    return playerchoice;
    
    

    
      
}

int computerchoice(int computer){
     srand(time(0));
      int numb=rand()%3 + 1;
      switch(numb){
        case 1:cout<<"Computer Chose Rock"<<endl;
        break;
        case 2:cout<<"Computer chose Paper"<<endl;
        break;
        case 3:cout<<"Computer chose Scissors"<<endl;
        break;

      }
    return numb;  
    

}

        
    

