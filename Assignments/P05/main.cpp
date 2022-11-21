/*****************************************************************************
*
*  Author:           Jarette Greene
*  Email:            jarettegreene09@gmail.com
*  Label:            P05
*  Title:            BolNiverse Fight Club
*  Course:           CMPS 2143
*  Semester:         Fall 2022
*
*  Description:
*     This Program simulates an an attack on the Bolin build of Midwestern State 
*     University where 1000s of attackers rush into one after the other and the 
*     defenders inside bolin which there are 1 defender for every 100 attackers 
*     and these attackers and defenders all have classes. They can either be a
*     Warrior, Wizard, Archer, Elf and Dragonborn. Where each class have stats
*     based on their class and the battle runs until all of one group is defeated
*     (all members die). This is done through the use of OOP prinicples like 
*     Inheritance and Polymorphism. The groups were creating using pointers 
*     from a basefighter class to all of its its derived subfighter class 
*     then randomized.
*
*  Usage:
*        N/A
*
*  Files:
*           helper.hpp          :contains class to tokenize a string
*           dice.hpp            :contains all the dice classes
*           fighter.hpp         :contains classes to represent thee different
*                                fighters
*           weapon.hpp          :contains the class to create the weapon used by the fighters
*           main.cpp            : main program driver
*
*****************************************************************************/
// neccesary Libraries
#include "dice.hpp"
#include "fighter.hpp"
#include "helpers.hpp"
#include "weapon.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <fstream>
//using namespace standard
using namespace std;
// function prototypes
int Percentages(int, int);
int main() {

  // random generator seed
  srand(time(0));

  // all variables
  ifstream infile;
  int round_count = 0;
  int attacker_wins = 0;
  int defender_wins = 0;
  string file_name;
  int temp;
  BaseFighter *current_attacker;
  BaseFighter *current_defender;
  int A_Team_count;
  int D_team_count;

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

  //loop to run until all fighters in any group dies 
  while ((attack.Size() > 0) && (defend.Size() > 0)) {
    int count = 0;
    current_attacker = &attack[0];
    current_defender = &defend[0];
    temp = 0;
    // finding matching defender to fight attacker
    while ((current_defender->getname() != current_attacker->getname()) &&
           (temp < defend.Size())) {
      temp++;
      if (temp < defend.Size()) {
        current_defender = &defend[temp];
      }
    }
    // lets the leading defender fight if there is no matching fighter
    if (temp == (defend.Size())) {
      temp = 0;
      current_defender = &defend[temp];
    }
    cout << "# of Attackers: " << attack.Size() << "               "
         << "# of Defenders: " << defend.Size() << endl;
    cout << "Attacker: " << *current_attacker << " vs "
         << "Defender: " << *current_defender << endl;

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
    // checks for winner, removes and displays winner based on who won 
    if (current_attacker->isAlive() == false) {
      cout << "ATTACKER DIED.";
      cout << flush;
      usleep(175000);
      system("clear");
      attack.remove();
      defender_wins++;
    }
    if (current_defender->isAlive() == false) {
      cout << "DEFENDER DIED.";
      cout << flush;
      usleep(175000);
      system("clear");
      defend.remove(temp);
      temp = 0;
      attacker_wins++;
    }
  }
  // displaying victory messages based on which side wins 
  if (defend.Size() == 0) {
    cout << "ATTACKERS WIN!!" << endl;
     cout << "Original # of Attackers: " << A_Team_count << "               "
         << "Original # of Defenders: " << D_team_count << endl;
    cout << "Total rounds fought: " << round_count << endl;
    cout << "Number of attacker rounds won: " << attacker_wins << " "
         << Percentages(round_count, attacker_wins) << "%" << endl;
    cout << "Number of Defender rounds won: " << defender_wins << " "
         << Percentages(round_count, defender_wins) << "%" << endl;
  }
  if (attack.Size() == 0) {
    cout << "DEFENDERS WIN!!" << endl;
    cout << "Original # of Attackers: " << A_Team_count << "               "
         << "Original # of Defenders: " << D_team_count << endl;
    cout << "Total rounds fought: " << round_count << endl;
    cout << "Number of attacker rounds won: " << attacker_wins << " "
         << Percentages(round_count, attacker_wins) << "%" << endl;
    cout << "Number of Defender rounds won: " << defender_wins << " "
         << Percentages(round_count, defender_wins) << "%" << endl;
  }
  infile.close();
}
/**
 * Public : Percentages
 *
 * Description:
 *        
 *     used to caluculate percentages
 * 
 * Params:
 *      int     total
 *      int     n
 *
 * Returns:
 *      int     resulting percentages
 */
int Percentages(int total, int n) {
  double temp = (double)n / total;
  return temp * 100;
}