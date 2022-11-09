#include "emoji.h"    //https://github.com/99x/emojicpp
#include <functional> // needed for `bind`
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <string>
#include <unistd.h> 
#include <stdio.h>


using namespace std;
#define ROCK u8"\U0000270A"
#define PAPER u8"\U0000270B"
#define SCISSORS u8"\U0001F44C"
#define LIZARD u8"\U0001F918"
#define SPOCK u8"\U0001F596"

#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"

/**
 * This class is used to test the random number generators by creating an
 * array with the same sides as some die. Then counting the values generated
 * between 1 and die size. There should be an equal number in every slot, which
 * for a 20 sided die is about .05 or 5 percent in each.
 *
 */
class Tester {
  int *arr;
  int size;

public:
  Tester() : size{20} {
    arr = new int[size + 1];
    initArr();
  }

  Tester(int size) : size{size} {
    arr = new int[size + 1];
    initArr();
  }

  void initArr() {
    for (int i = 0; i < size + 1; i++) {
      arr[i] = 0;
    }
  }

  // add random value to distribution table
  void load(int i) { arr[i]++; }

  // generate  the distribution table
  void distro(double res[], double total) {
    for (int i = 0; i < size + 1; i++) {
      res[i] = (double)arr[i] / total;
    }
  }
};

/**
 * RandRoll
 * @description: A class to implement roll playing dice rolls.
 * @methods:
 * private:
 *      int Random(Max) : returns a value between 0 and max.
 *      int Random(Min , Max) : returns a value between min and max
 *      void init(int , int)  : initialize class
 * public:
 *      DieRoll()
 *      DieRoll(int)
 *      DieRoll(int,int)
 *      void setDie(int)    : set sides
 *      int Roll(int,int)   :  NEEDS FIXING!!!!!!
 */
class DieRoll {
  int sides;

  int Random(int max) { return 1 + (rand() % max); }

  // min = 40 max = 100
  int Random(int min, int max) { return 1 + min + (rand() % (max - min)); }
  void init(int _seed, int _sides) {
    sides = _sides;
    srand(_seed);
  }

public:
  DieRoll() {
    // cout << "default base" << endl;
    init(time(0), 6);
  }
  DieRoll(int _seed) {
    // cout << "overloaded const" << endl;
    init(_seed, 6);
  }
  DieRoll(int _seed, int _sides) {
    // cout << "overloaded const" << endl;
    init(_seed, _sides);
  }

  void setDie(int _sides) { sides = _sides; }

  // NEEDS FIXING!!!
  int Roll(int sides, int times) {
    int sum = 0;
    while (times--) {
      sum += Random(sides);
    }
    return sum;
  }
};

/**
 * RandRoll
 * @description: A random die roller using a "better" random
 *      number generator. Docs: https://www.cplusplus.com/reference/random/
 *
 * @methods:
 *     int Roll(int)    : give the "sides" will return an int between 1 and
 * sides inclusive.
 *
 */
class RandRoll {
  default_random_engine generator;
  uniform_int_distribution<int> dieMap[21];

public:
  /**
   * Constructor
   *
   * @description: Create an stl array that has the common dice values
   *              loaded as uniform distribution types.
   *
   *  Wasteful, as not every array location has a uniform distribution
   *  associated with it. Could you make it less wasteful?
   */
  RandRoll() {
    dieMap[4] = uniform_int_distribution<int>(1, 4);
    dieMap[6] = uniform_int_distribution<int>(1, 6);
    dieMap[8] = uniform_int_distribution<int>(1, 8);
    dieMap[10] = uniform_int_distribution<int>(1, 10);
    dieMap[12] = uniform_int_distribution<int>(1, 12);
    dieMap[20] = uniform_int_distribution<int>(1, 20);
  }

  /**
   * Generate a random number depending on the "sides" of the dice.
   */
  int Roll(int sides) {
    int diceRoll = dieMap[sides](generator);
    return diceRoll;
  };
};

/**
 * Hands
 *
 * @description: A static class that only has references to
 *      emojis for printing out Rock Paper Scissors Lizard Spock
 *
 * @methods:
 *      string RandHand()   : returns a random hand (emoji)
 *      string Rock()       : returns the emoji for "rock"
 *      string Paper()      : returns the emoji for "paper"
 *      string Scissors()   : returns the emoji for "scissors"
 *      string Lizard()     : returns the emoji for "lizard"
 *      string Spock()      : returns the emoji for "spock"
 */
struct Hands {
  const string rock = ROCK2;
  const string paper = PAPER2;
  const string scissors = SCISSORS2;
  const string lizard = LIZARD2;
  const string spock = SPOCK2;

  static map<string, string> Emojis; // stl map
  //         name  , emoji

  static map<string, string> Names; // stl map
  //         emoji  , name

  static string RandHand() {
    auto it = Emojis.begin(); // iterator to front of map

    std::advance(it, rand() % Emojis.size()); // advance some random amnt
                                              //   of steps

    string random_hand = it->second; // grab emoji from map

    return random_hand; // return rand emoji
  }

  static string Rock() { return Emojis["rock"]; }
  static string Paper() { return Emojis["paper"]; }
  static string Scissors() { return Emojis["scissors"]; }
  static string Lizard() { return Emojis["lizard"]; }
  static string Spock() { return Emojis["spock"]; }
};

// initialize static data member for
// hands struct (class)
map<string, string> Hands::Emojis = {{"rock", ROCK2},
                                     {"paper", PAPER2},
                                     {"scissors", SCISSORS2},
                                     {"lizard", LIZARD2},
                                     {"spock", SPOCK2}};
// initialize static data member for
// hands struct (class)
map<string, string> Hands::Names = {{ROCK2, "rock"},
                                    {PAPER2, "paper"},
                                    {SCISSORS2, "scissors"},
                                    {LIZARD2, "lizard"},
                                    {SPOCK2, "spock"}};

/**
 * Rock Paper Scissors Lizard Spock
 *
 * @description: A class to run the rock papers scissors game
 *
 * Scissors cuts Paper
 * Paper covers Rock
 * Rock crushes Lizard
 * Lizard poisons Spock
 * Spock smashes Scissors
 * Scissors decapitates Lizard
 * Lizard eats Paper
 * Paper disproves Spock
 * Spock vaporizes Rock
 * Rock crushes Scissors
 */
class Player : public Hands {
private:
  string hand;

protected:
public:
  Player() { hand = RandHand(); }
  void changehand() { hand = RandHand(); }
  string getCname() { return Hands::Names[hand]; }
  void sethand(string a) { hand = Hands::Emojis[a]; }

  friend ostream &operator<<(ostream &os, const Player &P) {
    return os << P.hand;
  }
};
class RPSLS : public DieRoll, public Hands {
private:
  map<string, map<string, int>> winchartmap;
  string characters[5] = {"rock", "paper", "scissors", "lizard", "spock"};

public:
  RPSLS() {
    int rules[][5] = {{0, -1, 1, 1, -1},
                      {1, 0, -1, -1, 1},
                      {-1, 1, 0, 1, -1},
                      {-1, 1, -1, 0, 1},
                      {1, -1, 1, -1, 0}};
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        winchartmap[characters[i]][characters[j]] = rules[i][j];
      }
    }
  }
  int gametype() {
    int choice;
    cout << "Enter the number that corresponds with game you would like to "
            "play: "
         << endl;
    cout << "1. CPU vs CPU" << endl;
    cout << "2. Player vs CPU" << endl;
    cout << "Enter Choice: ";
    cin >> choice;
    cout << endl;
    while (choice != 1 && choice != 2) {
      cout << "Please enter 1 or 2: ";
      cin >> choice;
      cout << endl;
    }
    return choice;
  }
  void CPU_Game_display(Player P1, Player P2) {
    cout << endl;
    cout << "CPU 1 weapon: " << P1;
    cout << endl;
    cout << endl;
    cout << "CPU 2 weapon: " << P2;
  }
  int ContinueMenu() {
    int choice;
    cout << endl;
    cout << "Would you like to Continue: " << endl;
    cout << "Enter 1 for Yes" << endl;
    cout << "Enter 2 for No" << endl;
    cin >> choice;
    while (choice != 1 && choice != 2) {
      cout << "Please enter 1 or 2: ";
      cin >> choice;
      cout << endl;
    }
    if (choice == 2) {
      choice = 3;
    }
    return choice;
  }
  string PchoiceMenu() {
    string choice;
    cout << endl;
    cout << "Please enter choice of weapon: " << endl;
    cout << "Enter the word rock , paper, scissors , lizard or spock to "
            "select: ";
    cin >> choice;
    cout << endl;
    while (choice != "rock" && choice != "paper" && choice != "scissors" &&
           choice != "lizard" && choice != "spock") {
      cout << "Enter the word rock , paper, scissors , lizard or spock to "
              "select: ";
      cin >> choice;
      cout << endl;
    }
    return choice;
  }
    void Player_game_menu(Player P1, Player P2) {
    cout << endl;
    cout << "Player 1 weapon: " << P1;
    cout << endl;
    cout << endl;
    cout << "CPU  weapon: " << P2;
  }
  void LoadingMessage(string m){
  cout << m;
  cout << flush;
  sleep(2);
  system("clear");
}
  int getresult(string a, string b) { return winchartmap[a][b]; }

  RPSLS(int seed) : DieRoll(seed) { cout << "Rock: " << Rock() << endl; }
};

int main() {
  int choice, result;
  string Pchoice;
  RPSLS Game;
  Player CPU1;
  Player CPU2;
  Player P1;
  choice = Game.gametype();


  while (choice == 1) {

    do {
        cout << flush;
        system("clear");
      Game.CPU_Game_display(CPU1, CPU2);
      result = Game.getresult(CPU1.getCname(), CPU2.getCname());
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
    choice = Game.ContinueMenu();
    if (choice == 1) {
      CPU1.changehand();
      CPU2.changehand();
    }
  }
  while (choice == 2) {
      cout << flush;
  system("clear");
    cout << endl;
      Pchoice = Game.PchoiceMenu();
      P1.sethand(Pchoice);
    do {
         cout << flush;
        system("clear");
      Game.Player_game_menu(P1,CPU1);
      cout << endl;
      result = Game.getresult(P1.getCname(), CPU1.getCname());
      if (result == 1) {
        cout << endl;
        cout << "Player 1 wins!!";
        cout << endl;
        cout << flush;
        sleep(4);
        system("clear");
      } else if (result == -1) {
        cout << endl;
        cout << "CPU  wins!!";
        cout << endl;
        cout << flush;
        sleep(4);
        system("clear");
      } else {
        cout << endl;
        cout << "Its a Tie, Restarting....";
        cout << endl;
        CPU1.changehand();
        cout << flush;
        sleep(4);
        system("clear");
        Pchoice = Game.PchoiceMenu();
        P1.sethand(Pchoice);
      }
    } while (result == 0);
    choice = Game.ContinueMenu();
    if (choice == 1) {
      CPU1.changehand();
      cout << endl;
      choice = 2;
    }
  }
  cout << flush;
  system("clear");
  cout << "Thank you for Playing";

  return 0;
}