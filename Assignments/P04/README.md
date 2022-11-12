## P04 - Rock Paper Scissors Lizard Spock 
### Jarette Greene
### Description: 

     This Program is used to play the game Rock Paper Scissors Lizard Spock from the popular 
     TV show Big Bang Theory. This uses a randomizer functions, maps to determine the winner 
     and unicode emojis to display the different weapon/selection that the user or the Compiler
     can use. This program as two modes, a CPU vs CPU where the compiler generates two random 
     weapons and pits them against each other and Player vs CPU where the user can choose a weapon 
     then go against a random weapon chosen by the compiler 

### Files

|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   |[main.cpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P04/main.cpp)| Main driver of my list program . |
|   2   |[Emoji.h](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P03/blackjack.hpp)| Contains all classes need to play blackjack.|


### Instructions

- This program requires you to have the Emoji.h file.

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
