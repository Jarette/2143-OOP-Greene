
/*****************************************************************************
*
*  Author:           Jarette Greene
*  Email:            jarettegreene09@gmail.com
*  Label:            P04
*  Title:            Rock Paper Scissors Lizard Spock
*  Course:           CMPS 2143
*  Semester:         Fall 2022
*
*  Description:
*		  This Program is used to Pplay the game Rock, Paper, Scissor, Lizard, Spock
*     ,The game for the hit show Big Bang Theory. This is through the use of 
*     data structures like maps, and function to allow for the compiler to give
*     random numbers, techniques in Object Oriented Programming like 
*     inheritance and emojis to help visualize the game. This game has two modes
*     one mode that puts the computer against itself by assigning the computer 
*     two random choices then pit them aganst eachother but if there is a tie it 
*     repeats until a winner is determined. The second mode is the player vs the
*     computer where the user can enter a character and pit it agaisnt a random
*     character determined by the computer and fight until someone wins.
*
*  Usage:
*        N/A
*
*  Files:
*			main.cpp				:driver program
*			emoji.h         : this contains all the emojis needed 
*
*****************************************************************************/
// Neccessary Libraries
#include "emoji.h"    //https://github.com/99x/emojicpp
#include <functional> // needed for `bind`
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <string>
#include <unistd.h> 
#include <stdio.h>


// Defining the emojis 
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
 * Tester
 * 
 * Description: 
 *      This class is used to test the random number generators by creating an
 *      array with the same sides as some die. Then counting the values generated
 *      between 1 and die size. There should be an equal number in every slot, which
 *      for a 20 sided die is about .05 or 5 percent in each.
 * 
 * Public Methods
 *                            Tester()
 *                            Tester(int)                
 *      void                  initArr()
 *      void                  load(int i)
 *      void                  distro(double[],double)
 * 
 * Private Methods:
 *      int                   *arr   
 *      int                   size
 * 
 * Usage:
 *      
 *      Tester T1             //creates a tester with a default size of 20
 *      Tester T1(5)          //creates a tester of a size 5
 *      T1.initArr()          // inititlizes the array   
 *      T1.load(2)            // add random value to distribution table at location 2
 *      T1.distro(res[],total)// generate  the distribution table
 *    
*/  
class Tester {
  int *arr;
  int size;

public:
/**
 * Public : Tester
 *
 * Description:
 *        
 *      Constructor of Tester Class that sets the size of the array to 20 and
 *      initializes the values to 0 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      N/A
 */
  Tester() : size{20} {
    arr = new int[size + 1];
    initArr();
  }
/**
 * Public : Tester
 *
 * Description:
 *        
 *      Constructor of Tester Class that sets the size of the array to given integer and
 *      initializes the values to 0 
 * 
 * Params:
 *      int       the size of the array 
 *
 * Returns:
 *      N/A
 */
  Tester(int size) : size{size} {
    arr = new int[size + 1];
    initArr();
  }
/**
 * Public : initArr
 *
 * Description:
 *        
 *      Method used to initilize the array of the class to 0
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      N/A
 */
  void initArr() {
    for (int i = 0; i < size + 1; i++) {
      arr[i] = 0;
    }
  }

  /**
 * Public : load
 *
 * Description:
 *        
 *       add random value to distribution table
 * 
 * Params:
 *      int       the index of the part of the array random value will be stored 
 *
 * Returns:
 *      N/A
 */
  void load(int i) { arr[i]++; }

  
/**
 * Public : distro
 *
 * Description:
 *        
 *      generates  the distribution table
 * 
 * Params:
 *      double[]     the distrubution table
 *      double       the values stored in the distrubution table
 *
 * Returns:
 *      N/A
 */
  void distro(double res[], double total) {
    for (int i = 0; i < size + 1; i++) {
      res[i] = (double)arr[i] / total;
    }
  }
};


  /**
 * DieRoll
 * 
 * Description: 
 * 
 *        A class to implement roll playing dice rolls.
 * 
 *      
 * Public Methods
 *                             DieRoll()
 *                             DieRoll(int)
 *                             DieRoll(int,int)
 *      void                   setDie(int)    : set sides
 *      int                     Roll(int,int)   :  NEEDS FIXING!!!!!!
 * 
 * 
 * Private Methods:
 *     int                     Random(Max) : returns a value between 0 and max.
 *     int                     Random(Min , Max) : returns a value between min and max
 *     void                    init(int , int)  : initialize class
 * 
 * Usage:
 *      
 *      DieRoll D1            // sets default 6 sided die
 *      DieRoll D1(2)         // sets die randomizer seed to 2
 *      DieRoll D1(2,10)      // sets die randomizer seer to 2 and sides to 10
 *      D1.setDie(6)          // sets the sides of the die to 6
 *      D1.Roll(6,2)          // rolls a 6 sided die 2 times and gives u the result
 * 
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
/**
 * Public : DieRoll
 *
 * Description:
 *        
 *      Constructor that sets the randomizer seed to 0 and create a 6 sided die
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      N/A
 */
  DieRoll() {
    // cout << "default base" << endl;
    init(time(0), 6);
  }
  /**
 * Public : DieRoll
 *
 * Description:
 *        
 *      Constructor that sets the randomizer seed  and create a 6 sided die
 * 
 * Params:
 *      int         this is the new randomizer seed of the die
 *
 * Returns:
 *      N/A
 */
  DieRoll(int _seed) {
    // cout << "overloaded const" << endl;
    init(_seed, 6);
  }

  /**
 * Public : DieRoll
 *
 * Description:
 *        
 *      Constructor that sets the randomizer seed  and sides of the die
 * 
 * Params:
 *      int         this is the new randomizer seed of the die
 *      int         this the amount of sides the die will have
 * 
 * Returns:
 * 
 *      N/A
 */
  DieRoll(int _seed, int _sides) {
    // cout << "overloaded const" << endl;
    init(_seed, _sides);
  }
 /**
 * Public : setDie
 *
 * Description:
 *        
 *      This allows you the change how many sides the die would have 
 * 
 * Params:
 *      
 *      int         this the amount of sides the die will have
 * 
 * Returns:
 * 
 *      N/A
 */
  void setDie(int _sides) { sides = _sides; }

 /**
 * Public : Roll
 *
 * Description:
 *        
 *      rolls a die of given sides for a given number of time and returns the 
 *      resulting value.
 * 
 * Params:
 *      
 *      int         this the amount of sides the die will have
 *      int         the amount of times the die is rolled 
 * 
 * Returns:
 * 
 *      int       the resulting value from all the rolls 
 */
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
 * 
 * Description: 
 * 
 *       A random die roller using a "better" random
 *      number generator. Docs: https://www.cplusplus.com/reference/random/
 * 
 *      
 * Public Methods
 *                         RandRoll()
 *      int                Roll(int)
 * 
 * 
 * Private Methods:
 *     
 *      default_random_engine         generator
 *      uniform_it_distrubution<int>  dieMap[21]
 * 
 * Usage:
 *      
 *       RandRoll D1          //creates die of many different sizes
 *       D1.Roll(size)        //rolls die of given size and returns result
 * 
*/ 
class RandRoll {
  default_random_engine generator;
  uniform_int_distribution<int> dieMap[21];

public:
  
   /**
 * Public : RandRoll
 *
 * Description:
 *        
 *      Constructor that create an stl array that has the common dice values
 *      loaded as uniform distribution types.
 * 
 *      Wasteful, as not every array location has a uniform distribution
 *      associated with it. Could you make it less wasteful?
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      N/A
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
 * Public : Roll
 *
 * Description:
 *        
 *      Generate a random number depending on the "sides" of the dice.
 *      
 * 
 * Params:
 *      
 *      int       this is the amount of sides 
 * 
 * Returns:
 * 
 *      returns the result of the roll
 */
  int Roll(int sides) {
    int diceRoll = dieMap[sides](generator);
    return diceRoll;
  };
};


/**
 * Hands
 * 
 * Description: 
 * 
 *       A static class that only has references to
 *      emojis for printing out Rock Paper Scissors Lizard Spock
 * 
 *      
 * Public:
 *      
 *      const string                    rock = ROCK2;
 *      const string                    paper = PAPER2;
 *      const string                    scissors = SCISSORS2;
 *      const string                    lizard = LIZARD2;
 *      const string                    spock = SPOCK2;
 *      static map<string, string>      Emojis;
 *      static map<string, string>      Names
 *      static string                   RandHand() 
 *      static string                   Rock() 
 *      static string                   Paper() 
 *      static string                   Scissors()
 *      static string                   Lizard()
 *      static string                   Spock()
 * 
 * Usage:
 *      
 *       Hands H1                      // creates hand
 *       Hands::Rock()                 // returns emoji specified
 *       Hands::Names[Hands::Rock()]   // gives the name of the spcififed emoji
 *       Hands::RandHand()             // creates random emoji
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
/**
 * Public : RandHand
 *
 * Description:
 *        
 *      generates a random weapon emoji 
 *      
 * 
 * Params:
 *      
 *      N/A 
 * 
 * Returns:
 * 
 *      string :  returns the random emoji generating 
 */
  static string RandHand() {
    auto it = Emojis.begin(); // iterator to front of map

    std::advance(it, rand() % Emojis.size()); // advance some random amnt
                                              //   of steps

    string random_hand = it->second; // grab emoji from map

    return random_hand; // return rand emoji
  }
/**
 * Public : Rock
 *
 * Description:
 *        
 *      generates the rock emoji
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      string :  returns the rock emoji 
 */
  static string Rock() { return Emojis["rock"]; }
  /**
 * Public : Paper
 *
 * Description:
 *        
 *      generates the paper emoji
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      string :  returns the paper emoji 
 */
  static string Paper() { return Emojis["paper"]; }
  /**
 * Public : Scissors
 *
 * Description:
 *        
 *      generates the scissor emoji
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      string :  returns the scissor emoji 
 */
  static string Scissors() { return Emojis["scissors"]; }
  /**
 * Public : Lizard
 *
 * Description:
 *        
 *      generates the lizard emoji
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      string :  returns the lizard emoji 
 */
  static string Lizard() { return Emojis["lizard"]; }
  /**
 * Public : Spock
 *
 * Description:
 *        
 *      generates the spock emoji
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      string :  returns the spock emoji 
 */
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
 * Player: Public Hands
 * 
 * Description: 
 * 
 *       Class created to represent the user player of the game
 *       or the cpu player
 * 
 *      
 * Public Methods
 *                         Player()
 *      void              changehand()
 *      string            getCname()
 *      void              sethand(string a);
 *      friend ostream&   operator <<(ostream &, const Player) 
 * 
 * 
 * Private Methods:
 *     
 *      string              hand   
 *      
 * Usage:
 *      
 *       Player P1        // creates a player with a random hand 
 *       P1.changehand()  // gives the player a random hand 
 *       P1.getCname      // returns the name of what the player hand is 
 *       P1.sethand       // Lets the player set the hand they want 
 *       cout << P1       // displays the hand 
*/ 
class Player : public Hands {
private:
  string hand;

protected:
public:
  /**
 * Public : Player
 *
 * Description:
 *        
 *      A constructor class that gives the hand a random weapon
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      N/A
 */
  Player() { hand = RandHand(); }
 /**
 * Public : changehand()
 *
 * Description:
 *        
 *      This methods gives a new random weapon to the player hand 
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      N/A
 */
  void changehand() { hand = RandHand(); }
 /**
 * Public : getCname()
 *
 * Description:
 *        
 *      This methods returns the name of the weapon in the hand 
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *      string : the name of the weapon
 */
  string getCname() { return Hands::Names[hand]; }
  /**
 * Public : sethand
 *
 * Description:
 *        
 *      This method allows the player to give the hand a chosen weapon 
 *      
 * 
 * Params:
 *      
 *      string     : the name of the weapon chosen
 * 
 * Returns:
 * 
 *      N/A
 */
  void sethand(string a) { hand = Hands::Emojis[a]; }

 /**
 * Public : operator <<
 *
 * Description:
 *        
 *      overloaded operator to display the weapon stored in hand
 *      
 * 
 * Params:
 *      
 *      ostream&      : the ostream operator used to display to the screen
 *      Player        : the Player that hand will be displayed
 * 
 * Returns:
 * 
 *      ostream       : the Player's hand 
 */
  friend ostream &operator<<(ostream &os, const Player &P) {
    return os << P.hand;
  }
};

 /**
 * RPSLS
 * 
 * Description: 
 * 
 *       A class to run the rock papers scissors game
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
 *      
 * Public Methods
 *                          RPSLS()  
 *      int                 gametype()
 *      void                CPU_Game_display(Player P1, Player P2)
 *      int                 ContinueMenu()
 *      string              PchoiceMenu()
 *      void                Player_game_menu(Player P1, Player P2)
 *      int                 getresult(string a, string b)
 * 
 * Private Methods:
 *     map<string, map<string, int>> winchartmap
 *     string                         characters[5] = {"rock", "paper", "scissors", "lizard", "spock"}   
 *      
 * Usage:
 *      
 *     RPSLS Game                       //create an instance of the game
 *     Game.gametype                    // displays menu and allows the user to pick the type of game they would like to play
 *    Game.CPU_Game_display(P1,P2)      // displays the game for CPU vs CPU
 *    Game.ContinueMenu()               // menu that askes the user if they would like to continue playign the game
 *    Game.PchoiceMenu()                // menu to give the user the choice of weapon
 *    Game.Player_game_menu(P1,P2)      // displays the game when its Plaer vs CPU
 *    Game.getresult(a,b)               // gives the result of the battle
 *    
*/ 
class RPSLS : public DieRoll, public Hands {
private:
  map<string, map<string, int>> winchartmap;
  string characters[5] = {"rock", "paper", "scissors", "lizard", "spock"};

public:
/**
 * Public : RPSLS
 *
 * Description:
 *        
 *      Constructor that sets the rules of the game 
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *     N/A
 */
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
/**
 * Public : gametype
 *
 * Description:
 *        
 *      method that is used to display a menu and get the user's choice 
 *      
 * 
 * Params:
 *      
 *      N/A
 * 
 * Returns:
 * 
 *     int    the user's choice 
 */
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
  /**
 * Public : CPU_Game_display
 *
 * Description:
 *        
 *      This method displays all neccessary information for the CPU VS CPU game
 *      
 * 
 * Params:
 *      
 *      Player       : the first CPU player
 *      Player       : the second CPU player
 * 
 * Returns:
 * 
 *    N/A
 */
  void CPU_Game_display(Player P1, Player P2) {
    cout << endl;
    cout << "CPU 1 weapon: " << P1;
    cout << endl;
    cout << endl;
    cout << "CPU 2 weapon: " << P2;
  }
  /**
 * Public : ContinueMenu
 *
 * Description:
 *        
 *      This displays a menu for the user to say if they would like to continue the game 
 *      
 * 
 * Params:
 *      
 *    N/A
 * 
 * Returns:
 * 
 *    int  : the user's choice
 */
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
    /**
 * Public : PchoiceMenu
 *
 * Description:
 *        
 *      This method displays a menu for the user to choose which weapon they would like 
 *      to to have 
 *      
 * 
 * Params:
 *      
 *    N/A
 * 
 * Returns:
 * 
 *    string   : the weapon the player choose
 */
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
 /**
 * Public : Player_game_menu
 *
 * Description:
 *        
 *      This method displays all neccessary information for the Player VS CPU game
 *      
 * 
 * Params:
 *      
 *      Player       : the player
 *      Player       : the CPU player
 * 
 * Returns:
 * 
 *    N/A
 */
    void Player_game_menu(Player P1, Player P2) {
    cout << endl;
    cout << "Player 1 weapon: " << P1;
    cout << endl;
    cout << endl;
    cout << "CPU  weapon: " << P2;
  }
/**
 * Public : getresult
 *
 * Description:
 *        
 *      This method gives the result of the battle 
 *      
 * 
 * Params:
 *      
 *      string    : the first weapon 
 *      string    : the second weapon 
 * 
 * Returns:
 * 
 *    int    : the result of the battle 
 */
  int getresult(string a, string b) { return winchartmap[a][b]; }

};

int main() {

  // declaring neccesary variables and objects 
  int choice, result;
  string Pchoice;
  RPSLS Game;
  Player CPU1;
  Player CPU2;
  Player P1;

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
    // if the user would like to continue resets the game and start again 
    choice = Game.ContinueMenu();
    if (choice == 1) {
      CPU1.changehand();
      CPU2.changehand();
    }
  }

  // this is the Player vs CPU game 
  while (choice == 2) {
      cout << flush;
  system("clear");
    cout << endl;
    //  asking the user for thier weapon and setting the hand 
      Pchoice = Game.PchoiceMenu();
      P1.sethand(Pchoice);
    do {
         cout << flush;
        system("clear");
        // displaying the weapons of Player and CPU and gets the result of the battle
      Game.Player_game_menu(P1,CPU1);
      cout << endl;
      result = Game.getresult(P1.getCname(), CPU1.getCname());

      // displays message based on result 
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
        // if the battle is a tie then ask the user for new weapon and tries again 
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
    // asking the user if they would like to continue if so restart
    choice = Game.ContinueMenu();
    if (choice == 1) {
      CPU1.changehand();
      cout << endl;
      choice = 2;
    }
  }
  // when the user decides to quit 
  cout << flush;
  system("clear");
  cout << "Thank you for Playing";

  return 0;
}