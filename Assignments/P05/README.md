## P05 - Bolinverse Fight Club
### Jarette Greene
### Description: 

     This Program simulates an an attack on the Bolin build of Midwestern State 
     University where 1000s of attackers rush into one after the other and the 
     defenders inside bolin which there are 1 defender for every 100 attackers 
     and these attackers and defenders all have classes. They can either be a
     Warrior, Wizard, Archer, Elf and Dragonborn. Where each class have stats
     based on their class and the battle runs until all of one group is defeated
     (all members die). This is done through the use of OOP prinicples like 
     Inheritance and Polymorphism. The groups were creating using pointers 
     from a basefighter class to all of its its derived subfighter class 
     then randomized.

### Files

|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   |[main.cpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P05/main.cpp)| Main driver. |
|   2   |[weapon.hpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P05/weapon.hpp)| contains a to create the weapons.|
|   3   |[helper.hpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P05/helpers.hpp)| containing functions to help create special dices.|
|   4   |[fighter.hpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P05/fighter.hpp)| contains the classes for all the fighters.|
|   5   |[dice.hpp](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P05/dice.hpp)| contains classes to create various die .|
|   6   |[input.dat](https://github.com/Jarette/2143-OOP-Greene/blob/main/Assignments/P05/input.dat)| input file.|
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
