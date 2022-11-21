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
|   1   |[main.cpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P04/main.cpp)| Main driver. |
|   2   |[emoji.h](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P04/emoji.h)| Contains unicode emojis.|


### Instructions

- This program requires you to have the emoji.h file.

### Example Command
```
 // asking the user what type of game they would like to play 
  choice = Game.gametype();


// the CPU vs CPU game 
  while (choice == 1) {

    do {
        cout << flush;
        system("clear");

      // display both weapons of the CPUs
      Game.CPU_Game_display(CPU1, CPU2);

      // get the result of the battle 
      result = Game.getresult(CPU1.getCname(), CPU2.getCname());
     // check fot the result and display approipriate message 
      if (result == 1) {
        cout << endl;
        cout << endl;
        cout << "CPU 1 wins!!";
        cout << endl;
        cout << flush;
        sleep(4);
        system("clear");
      } else if (result == -1) {
        cout << endl;
        cout << endl;
        cout << "CPU 2 wins!!";
        cout << endl;
         cout << flush;
        sleep(4);
        system("clear");
      } else {
        // if the battle was a tie restarts and tries again 
        cout << endl;
        cout << endl;
        cout << "Its a Tie, Restarting....";
        cout << endl;
        CPU1.changehand();
        CPU2.changehand();
         cout << flush;
        sleep(4);
        system("clear");
      }
    } while (result == 0);
          }
```
