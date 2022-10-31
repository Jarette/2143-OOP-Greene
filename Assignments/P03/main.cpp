#include "blackjack.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>


using namespace std;

int main() {
	srand(time(0));
  Dealer House;
  Game BlackJ;
  string pname;
  int P_age, Pbank, decknum, select = 0,bet =0, winlose = 0;
  
  cout << "Please Enter name: ";
  cin >> pname;
  doubleline();
  cout << "Please enter age: ";
  cin >> P_age;
  doubleline();
  if(P_age<18){
    
    cout << "You are underage. Go home kiddo :)";
  }
  else{
    cout << "Please enter how much money you would like to play with: ";
    cin >> Pbank;
    doubleline();

    Player P1(pname,P_age,Pbank);
    system("clear");
    Deck D1;
    do{
      
      House.add_to_hand(D1);
      House.add_to_hand(D1);

      P1.add_to_hand(D1);
      P1.add_to_hand(D1);

      cout << "How much would you like to bet: ";
      cin >> bet;
      cout << endl;
      while (bet > P1.getbank()){
        cout << "Your bet is greater than the money available. Please enter new bet: $";
        cin>>bet;
        cout << endl;
      }
      cout << flush;
      system("clear");
      BlackJ.LoadingMessage("SETTING TABLE......");
      BlackJ.Playerturndispaly(P1, House, bet);
      cout << endl;
      while(BlackJ.lessthan21(BlackJ.getplayervalue())&& select != -1 && select != 4){
        select = BlackJ.PlayerChoiceMenu();
        cout << flush;
        system("clear");
        if(select == 1){
          P1.add_to_hand(D1);
          BlackJ.LoadingMessage("DEALING.....");
          BlackJ.Playerturndispaly(P1,House,bet);
          if(!BlackJ.lessthan21(BlackJ.getplayervalue())){
            select = 4;
            system("clear");
          }
        }
        else if(select==2){
          select = 4;
        }
        else{
          system("clear");
          cout << "Thank you for Playing :)";
          cout << endl;
          cout << "You have: $" << P1.getbank();
  
        }
      }
      if(select == 4&& select != -1){
        select = 0;
      }
      
      if(select != -1){
        if(BlackJ.getplayervalue()==21){
          cout << flush;
          sleep(2);
          system("clear");
        }
        BlackJ.LoadingMessage("BEGINNING DEALER'S TURN");
        if(BlackJ.istwentyone(BlackJ.getplayervalue())||BlackJ.isbust(BlackJ.getplayervalue())){
          BlackJ.Dealerturndisplay(P1, House , bet);
          cout << flush;
          sleep(4);
          system("clear");
        }
      if(!BlackJ.istwentyone(BlackJ.getplayervalue())){
        if(!BlackJ.isbust(BlackJ.getplayervalue())){
          cout << endl;
          BlackJ.Dealerturndisplay(P1, House , bet);
          cout << flush;
          sleep(4);
          system("clear");
          while(BlackJ.getdealervalue() <= BlackJ.getplayervalue()){
            House.add_to_hand(D1);
            BlackJ.LoadingMessage("DEALING.....");
            BlackJ.Dealerturndisplay(P1, House,bet);
            cout << flush;
            sleep(4);
            system("clear");
          }
          if(!BlackJ.istwentyone(BlackJ.getdealervalue())){
            if(BlackJ.isbust(BlackJ.getdealervalue())){
              BlackJ.PlayerWon(P1,bet);
              doubleline();
              BlackJ.ResetGame(P1, House); 
            }
            else{
               BlackJ.DealerWon(P1,bet);
              if(P1.getbank() <=0){
                BlackJ.OutofMoney();
              }
              else{
              doubleline();
              BlackJ.ResetGame(P1, House);
              }
            }
          }
          else{
            BlackJ.DealerWon(P1,bet);
              if(P1.getbank() <=0){
                BlackJ.OutofMoney();
              }
              else{
              doubleline();
              BlackJ.ResetGame(P1, House);
              }
          }
        }
        else{
          BlackJ.Busted(P1,bet);
          if(P1.getbank() <=0){
             BlackJ.OutofMoney();
          }
          else{
            doubleline();
            BlackJ.ResetGame(P1, House);
          }
        }
      }
      else{
        BlackJ.PlayerWon(P1,bet);
        doubleline();
        BlackJ.ResetGame(P1,House);
      }
    }
    else{
      cout << endl;
    }
      
    }
    while((P1.getbank()>0) && select != -1);
  }

 }
