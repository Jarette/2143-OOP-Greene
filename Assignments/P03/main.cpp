321 lines (1236 sloc)  35.7 KB

/*****************************************************************************
*
*  Author:           Jarette Greene
*  Email:            jarettegreene09@gmail.com
*  Label:            P03
*  Title:            BlackJack 
*  Course:           CMPS 2143
*  Semester:         Fall 2022
*
*  Description:
*		  This Program is used to play a simple game of black jack and demonstrate
*     how the different kinds of inheritance as used. BlackJack is a game that 
*     where two players (The Player and the Dealer) play against eachother
*     where the player makes a bet then both party are given 2 random cards 
*     at the beginning of the round then can choose to keep drawing random 
*     cards (starting with the Player) from a deck until the person drawing 
*     card values equals to 21 which means they immediately win, greater than 
*     21 which is an immediate lose or stopping at any number less than 21. 
*     Then the next player (Dealer) has to draw cards until they get a value
*     higher than the value the the Player stopped at or gets 21 themelves. 
*     If the Player wins they win double the money they bet but if they lose
*     they lose double the money they bet. This continues until the player 
*     either chooses to quit or loses all money. 
*
*  Usage:
*        N/A
*
*  Files:
*			main.cpp				:driver program
*			blackjack.hpp   :contains all classes anf functions neccessary
*     color.h         :contains all the color codes for the cards 
*
*****************************************************************************/
//Neccesary Libraries
#include "blackjack.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <unistd.h> 
#include <stdio.h>

// allowing for use of  standard library
using namespace std;

int main() {
	srand(time(0));
  
  // delcaring and initializing objects and variables
  Dealer House;
  Game BlackJ;
  string pname;
  int P_age, Pbank, decknum, select = 0,bet =0, winlose = 0;
  
  // asking player for thier name and age
  cout << "Please Enter name: ";
  cin >> pname;
  doubleline();
  cout << "Please enter age: ";
  cin >> P_age;
  doubleline();
  // checkig if age is over 18 if not ends program
  if(P_age<18){
    
    cout << "You are underage. Go home kiddo :)";
  }
  else{

    // asking the player for how large they would like thier bank to be 
    cout << "Please enter how much money you would like to play with: ";
    cin >> Pbank;
    doubleline();

    // initializing Player object
    Player P1(pname,P_age,Pbank);
    system("clear");
    Deck D1;
    do{
      
      // adding the two initial cards
      House.add_to_hand(D1);
      House.add_to_hand(D1);

      P1.add_to_hand(D1);
      P1.add_to_hand(D1);

      // asking the player to set amount of money they would like to bet (antee)
      cout << "How much would you like to bet: ";
      cin >> bet;
      cout << endl;
      // making sure the user cant get larger than thier bank
      while (bet > P1.getbank()){
        cout << "Your bet is greater than the money available. Please enter new bet: $";
        cin>>bet;
        cout << endl;
      }
      cout << flush;
      system("clear");
      //Beginning game and showing the player thier hand 
      BlackJ.LoadingMessage("SETTING TABLE......");
      BlackJ.Playerturndispaly(P1, House, bet);
      cout << endl;
      // cheecking if the player can still add to thier hand or if they still want to play 
      while(BlackJ.lessthan21(BlackJ.getplayervalue())&& select != -1 && select != 4){
        //asking  the player if they would like to quit, hit or stand
        select = BlackJ.PlayerChoiceMenu();
        cout << flush;
        system("clear");
        // if the player wants to hit 
        if(select == 1){
          P1.add_to_hand(D1);
          BlackJ.LoadingMessage("DEALING.....");
          BlackJ.Playerturndispaly(P1,House,bet);
          // breaks loop if they already have a value >= 21
          if(!BlackJ.lessthan21(BlackJ.getplayervalue())){
            select = 4;
            system("clear");
          }
        }
        // if the player would like to stand 
        else if(select==2){
          select = 4;
        }
        else{
          // if the player wants to quit
          system("clear");
          cout << "Thank you for Playing :)";
          cout << endl;
          cout << "You have: $" << P1.getbank();
  
        }
      }
      // stops the players turn but continues the game 
      if(select == 4&& select != -1){
        select = 0;
      }
      //making sure that the player didnt quit
      if(select != -1){
          // checking if the player already has 21
        if(BlackJ.getplayervalue()==21){
          cout << flush;
          sleep(2);
          system("clear");
        }
        // beginning the dealers turn 
        BlackJ.LoadingMessage("BEGINNING DEALER'S TURN");
        if(BlackJ.istwentyone(BlackJ.getplayervalue())||BlackJ.isbust(BlackJ.getplayervalue())){
          // displaying the dealer's hand
          BlackJ.Dealerturndisplay(P1, House , bet);
          cout << flush;
          sleep(4);
          system("clear");
        }
        // checking to make to see if the player is not bust 
      if(!BlackJ.istwentyone(BlackJ.getplayervalue())){
        if(!BlackJ.isbust(BlackJ.getplayervalue())){
          cout << endl;
          BlackJ.Dealerturndisplay(P1, House , bet);
          cout << flush;
          sleep(4);
          system("clear");
          // checking if the dealer's hand value is less than or equal to the players
          // then add a card
          while(BlackJ.getdealervalue() <= BlackJ.getplayervalue()){
            House.add_to_hand(D1);
            BlackJ.LoadingMessage("DEALING.....");
            BlackJ.Dealerturndisplay(P1, House,bet);
            cout << flush;
            sleep(4);
            system("clear");
          }
          // all conditionals to check establish who won the round 
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
