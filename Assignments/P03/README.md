## P02 - Vector Class
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
|   2   |[blackjack.cpp]()| Contains all classes need to play blackjack.|
|   3   |[color.h]()| This contains all the colors for the cards.|

### Instructions

- This program does not require any non standard libraries 

### Example Command
```
 cout << V1;              //displays entire vector
 outfile << V1;
 
 V1[0] = 9;              // allows to access data in vector using array indexing 
    
 V3 = V1 + V2;          // used to add the elements of 2 vectors and save to new vector
 
 V3 = V1 - V2;           // used to subtract the elements of 2 vectors and save to new vector
 
 V3 = V1 / V2;           // used to divide the elements of 2 vectors and save to new vector
 
 V3 = V1 * V2;          // used to multiply the elements of 2 vectors and save to new vector
 
 (V1 == V2);             // used to check if both vectors are the same and returns true or false 
```
