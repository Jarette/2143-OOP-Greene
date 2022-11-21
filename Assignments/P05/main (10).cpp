#include "dice.hpp"
#include "fighter.hpp"
#include "helpers.hpp"
#include "weapon.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;
int Percentages(int, int);
int main() {
  srand(time(0));
  int round_count = 0;
  int attacker_wins = 0;
  int defender_wins = 0;
  int attacker_size;
  int temp;
  BaseFighter *current_attacker;
  BaseFighter *current_defender;
  int CAV = 0;
  int CDV = 0;
  int i = 0;
  int testCount = 0;
  cout << "how much attackers are there: ";
  cin >> attacker_size;
  cout << flush;
  system("clear");

  Attackers attack(attacker_size);
  Defender defend(attacker_size);
  while ((attack.Size() > 0) && (defend.Size() > 0)) {
    int count = 0;
    current_attacker = &attack[0];
    current_defender = &defend[0];
    temp = 0;
    while ((current_defender->getname() != current_attacker->getname()) &&
           (temp < defend.Size())) {
      temp++;
      if (temp < defend.Size()) {
        current_defender = &defend[temp];
      }
    }
    if (temp == (defend.Size())) {
      temp = 0;
      current_defender = &defend[temp];
    }
    cout << "# of Attackers: " << attack.Size() << "               "
         << "# of Defenders: " << defend.Size() << endl;
    cout << "Attacker: " << *current_attacker << " vs "
         << "Defender: " << *current_defender << endl;

    while (current_attacker->isAlive() && current_defender->isAlive()) {

      if (current_defender->getspeed() >= current_attacker->getspeed()) {
        current_attacker->setHP(current_attacker->getHP() -
                                current_defender->attack());
        if (current_attacker->isAlive() == true) {
          current_defender->setHP(current_defender->getHP() -
                                  current_attacker->attack());
        }
      } else {
        current_defender->setHP(current_defender->getHP() -
                                current_attacker->attack());
        if (current_defender->isAlive() == true) {
          current_attacker->setHP(current_attacker->getHP() -
                                  current_defender->attack());
        }
      }
      attack.regen();
      defend.regen();
      round_count++;
    }
    if (current_attacker->isAlive() == false) {
      cout << "ATTACKER DIED.";
      cout << flush;
      sleep(1);
      system("clear");
      attack.remove();
      defender_wins++;
    }
    if (current_defender->isAlive() == false) {
      cout << "DEFENDER DIED.";
      cout << flush;
      sleep(1);
      system("clear");
      defend.remove(temp);
      temp = 0;
      attacker_wins++;
    }
  }
  if (defend.Size() == 0) {
    cout << "ATTACKERS WIN!!" << endl;
    cout << "Total rounds fought: " << round_count << endl;
    cout << "Number of attacker rounds won: " << attacker_wins << " "
         << Percentages(round_count, attacker_wins) << "%" << endl;
    cout << "Number of Defender rounds won: " << defender_wins << " "
         << Percentages(round_count, defender_wins) << "%" << endl;
  }
  if (attack.Size() == 0) {
    cout << "DEFENDERS WIN!!";
    cout << "Total rounds fought: " << round_count << endl;
    cout << "Number of attacker rounds won: " << attacker_wins << " "
         << Percentages(round_count, attacker_wins) << "%" << endl;
    cout << "Number of Defender rounds won: " << defender_wins << " "
         << Percentages(round_count, defender_wins) << "%" << endl;
  }
}
int Percentages(int total, int n) {
  double temp = (double)n / total;
  return temp * 100;
}