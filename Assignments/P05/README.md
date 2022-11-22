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

- This program requires you to have the weapon.hpp,helpers.hpp,fighter.hpp,dice.hpp and input.dat.

### Example Command
```
 // asking the users for the name of the input file
  cout << "What is the name of the file containing the attackers: ";
  cin >> file_name;
  infile.open(file_name);
  cout << flush;
  system("clear");
  
  // creating both groups 
  Attackers attack(infile);
  Defender defend(attack.Size());
  A_Team_count = attack.Size();
  D_team_count = defend.Size();
  
  // the fight starting
    while (current_attacker->isAlive() && current_defender->isAlive()) {

// determining who goes first based on speed 
      if (current_defender->getspeed() >= current_attacker->getspeed()) {
        // defender going first
        current_attacker->setHP(current_attacker->getHP() -
                                current_defender->attack());
        if (current_attacker->isAlive() == true) {
          //if attacker doesnt die then the attacker get to attack 
          current_defender->setHP(current_defender->getHP() -
                                  current_attacker->attack());
        }
      } else {
        //attacker attacks first
        current_defender->setHP(current_defender->getHP() -
                                current_attacker->attack());
        if (current_defender->isAlive() == true) {
          //if the defender dies then the defender attacks 
          current_attacker->setHP(current_attacker->getHP() -
                                  current_defender->attack());
        }
      }
      // the fighter regenerate health
      attack.regen();
      defend.regen();
      round_count++;
    }
```
