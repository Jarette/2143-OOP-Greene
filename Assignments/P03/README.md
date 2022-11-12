## P03 - Black Jack
### Jarette Greene
### Description: 

     This Program is used to play a simple game of black jack and demonstrate
     how the different kinds of inheritance as used. BlackJack is a game that 
     where two players (The Player and the Dealer) play against eachother
     where the player makes a bet then both party are given 2 random cards 
     at the beginning of the round then can choose to keep drawing random 
     cards (starting with the Player) from a deck until the person drawing 
     card values equals to 21 which means they immediately win, greater than 
     21 which is an immediate lose or stopping at any number less than 21. 
     Then the next player (Dealer) has to draw cards until they get a value
     higher than the value the the Player stopped at or gets 21 themelves. 
     If the Player wins they win double the money they bet but if they lose
     they lose double the money they bet. This continues until the player 
     either chooses to quit or loses all money. 

### Files

|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   |[main.cpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P03/main.cpp)| Main driver of my list program . |
|   2   |[blackjack.hpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P03/blackjack.hpp)| Contains all classes need to play blackjack.|
|   3   |[color.h](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P03/color.h)| This contains all the colors for the cards.|

### Instructions

- This program requires you to have the blackjack.hpp and color.h 

### Example Command
```
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
```
