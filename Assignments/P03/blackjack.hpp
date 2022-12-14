/*****************************************************************************
*
*  Author:           Jarette Greene
*  Email:            jarettegreene09@gmail.com
*  Label:            P03
*  Title:            BlackJack 
*  Course:           CMPS 2143
*  Semester:         Fall 2022
*
*  Description:
*		  This is an hpp file that contains all of the neccessasry classes and functiosn
*     to create the game blackjack
*
*  Usage:
*        N/A
*
*  Files:
*			main.cpp				:driver program
*			blackjack.hpp   :contains all classes anf functions neccessary
*     color.h         :contains all the color codes for the cards 
*
*****************************************************************************/
// neccesary libraries
#include "colors.h"
#include <algorithm> // std::random_shuffle
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
#include <unistd.h> //makesure to un comment this before running. This was just commented to remove an error in vscode
#include <stdio.h>

using namespace std;
/**
	* Public : doubleline
	*
	* Description:
	*      adds two blank lines to the code
	*
	* Params:
	*      N/A
	*
	* Returns:
	*      N/A
	*/
void doubleline(){
  cout << endl;
  cout <<endl;
}
//declaring varibales
const string spade = "♠";
const string diamond = "♦";
const string heart = "♥";
const string club = "♣";

const string suits[4] = {"♠", "♥", "♦", "♣"};

string Black = "0";
string Red = "1";
string Green = "2";
string Yellow = "3";
string Blue = "4";
string Purple = "5";
string Cyan = "6";
string White = "7";
string Default = "9";
/**
 * Public printColor
 * 
 * Description: 
 *   to display a string with a fore and background color
 * 
 * Params
 *    string    out: the string that will be given the color
 *    int       fg: integer to indicate the foreground color
 *    int       bg: interfer to indicate the background color
 * 
 * Returns:
 *    N/A
 */
void printColor(string out, int fg, int bg = 9) {
	cout << "\033[0;3" << fg << ";4" << bg << "m" << out << "\033[0;39;49m";
}

// Card labels
const string ranks[13] =
	{"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};


// declaring classes like prototypes
class CardContainer;
class Hand;
/*
   ____    _    ____  ____
  / ___|  / \  |  _ \|  _ \
 | |     / _ \ | |_) | | | |
 | |___ / ___ \|  _ <| |_| |
  \____/_/   \_\_| \_\____/

*/
/**
 * Card
 * 
 * Description: 
 *    This Class is uses uni code to create a visual representation of a
 *    normal playing card with a custom for and background colors and 
 *    also contains overloaded operators that allows the card to function
 *    similarly to cards in real life
 * 
 * Public Methods
 *                          Card()
 *                          Card(int)
 *                          string Repr() *not implemented*
 *    bool                  operator < (const Card&)
 *    bool                  operator > (const Card&)
 *    bool                  operator == (const Card&)
 *    bool                  operator != (const Card&) 
 *    friend                Hand *Hand implemented but not used*
 *    friend ostream        &operator <<(ostream &os, const Card &card)
 *    friend Class          CardContainer
 *    int                   getRank()
 *    string                getRankChar()
 *    string                getSuitChar()
 *    string                getfColor()
 *    string                getbColor()
 * 
 * Protected Methods:
 *    
 *     int                  suitNum
 *     int                  rank
 *     int                  number
 *     int                  value
 *     string               suitChar
 *     string               rankChar
 *     string               fcolor
 *     string               bcolor
 * 
 * Usage:
 *    
 *     Card C;                //creates a blank card
 *     Card C2(4);            //creates a card with color suit and rank based on the integer passed
 *     C < C1;                // using bool operators to check if C is less than C1
 *     C > C1;                // using bool operators to check if C is greater than C1
 *     C == C!;               // using bool operators to check if C and C1 are equal 
 *     cout << C;             // using ostream ooperator to print a card
 *     C.getRank();           // returns the rank of the card
 *     C.getSuitChar();       // returns the suit character of the card
 *     C.getfColor();         // returns the foreground color of the card
 *     C.getbColor();        //returns the background color of the card
*/  
class Card {
protected:
	int suitNum;	 // value 0-3 : num index of suit
	int rank;		 // 0-13      : num value of rank
	int number;		 // 1-52      : unique value determines card
	int value;		 // 1-14      : numeric value used for comparison
	string suitChar; // "♠", "♦", "♣", "♥"
	string rankChar; // Ace, 1 ,2 ,3 ... Q, K
	string fcolor;   // Spade=blue, Diamond=red, etc.
	string bcolor;

public:
	friend class Hand;
	Card();
	Card(int);
	string Repr();
	bool operator<(const Card &);
	bool operator>(const Card &);
	bool operator==(const Card &);
	bool operator!=(const Card &);

	friend ostream &operator<<(ostream &os, const Card &card);
  // gives the CardContainer class access to the Methods of the Card Class
	friend class CardContainer;
  /**
 * Public : getRank
 *
 * Description:
 *     A Function that returns the rank of a card
 *
 * Params:
 *      N/A
 *
 * Returns:
 *      int     the numerical rank of a card (the value)
 */
	int getRank() {
		return rank;
	}
  /**
 * Public : getRankChar
 *
 * Description:
 *     A Function that returns the character that represents the card's rank
 *
 * Params:
 *      N/A
 *
 * Returns:
 *      string     the character representation of the rank of a card (the value)
 */
	string getRankChar() {
		return rankChar;
	}
 /**
 * Public : getSuitChar
 *
 * Description:
 *     A Function that returns the suit of a card
 *
 * Params:
 *      N/A
 *
 * Returns:
 *      string     the character that respresents the suit of the card
 */
	string getSuitChar() {
		return suitChar;
	}
/**
 * Public : getfColor
 *
 * Description:
 *     A Function that returns the foreground color of a card 
 *
 * Params:
 *      N/A
 *
 * Returns:
 *      string     the color used for the foreground of the card
 */
	string getfColor() {
		return fcolor;
	}
/**
 * Public : getbColor
 *
 * Description:
 *     A Function that returns the background color of a card 
 *
 * Params:
 *      N/A
 *
 * Returns:
 *      string     the color used for the background of the card
 */
	string getbColor() {
		return bcolor;
	}
};

/**
 * Public : operator <<
 *
 * Description:
 *      Overload ostream and send the string representation "Repr"
 *      of the card.
 *
 *      We don't need the scope resolution operator (Card::) since
 *      this is a "friend" of card.
 *
 * Params:
 *      [ostream&] : os
 *      [Card]     : obj
 *
 * Returns:
 *      [ostream&]
 */
ostream &operator<<(ostream &os, const Card &card) {
	os << "\033[0;3" << card.fcolor << ";4" << card.bcolor << "m";
	os << "┌────┐\n";
	os << "│";
	// rank 9 is really 10
	if (card.rank != 9) {
		os << " ";
	}
	os << card.rankChar << " " << card.suitChar << "│\n";
	os << "└────┘";
	os << "\033[0;39;49m";

	return os;
}
/**
 * Public : PrintCard
 *
 * Description:
 *      function that is used to print a card
 *
 * Params:
 *      [Card*]     : obj
 *
 * Returns:
 *      string      a string that contains a card
 */
string PrintCard(Card *card) {
	string c = "";
	c += "\033[0;3" + card->getfColor() + ";4" + card->getbColor() + "m";
	c += "┌────┐\n";
	c += "│";
	// rank 9 is really 10
	if (card->getRank() != 9) {
		c += " ";
	}
	c += to_string(card->getRank()) + " " + card->getSuitChar() + "│\n";
	c += "└────┘";
	c += "\033[0;39;49m";

	return c;
}
/**
 * Public : Card
 *
 * Description:
 *      This is a constructor that creates a single blank card
 *      of no value
 *
 * Params:
 *      N/A
 *
 * Returns:
 *      N/A
 */
Card::Card() {
	// fcolor = to_string(1+ rand() % 7);
	fcolor = to_string(0);
	bcolor = "7";
}

/**
 * Public : Card
 *
 * Description:
 *      Represents a single card in a deck of cards to include a
 *      value along with rank and suit. We are assuming a standard
 *      card type in a deck of playing cards.
 *
 * Params:
 *      int :  value from 0 - 51 that represents a card in a deck.
 *
 * Returns:
 *      None
 */
Card::Card(int num) {
	number = num;
	suitNum = number / 13;
	suitChar = suits[suitNum];
	// fcolor = to_string(1+ rand() % 7);
	fcolor = to_string(suitNum + 2);
	bcolor = "9";
	rank = number % 13;
	rankChar = ranks[rank];
}
/**
 * Public : operator <
 *
 * Description:
 *      Overloaded bool operator that allows you to compare the value of two cards to 
 *      see if the value of the card of the left is less than the one on the right
 *
 * Params:
 *      [Card]     : obj
 *
 * Returns:
 *      [bool]
 */
bool Card::operator<(const Card &rhs) {
	return this->rank < rhs.rank;
}
/**
 * Public : operator >
 *
 * Description:
 *      Overloaded bool operator that allows you to compare the value of two cards to 
 *      see if the value of the card of the left is greater than the one on the right
 *
 * Params:
 *      [Card]     : obj
 *
 * Returns:
 *      [bool]
 */
bool Card::operator>(const Card &rhs) {
	return this->rank > rhs.rank;
}
/**
 * Public : operator ==
 *
 * Description:
 *      Overloaded bool operator that allows you to compare the value of two cards to 
 *      see if the value of the card of the left is equal the one on the right
 *
 * Params:
 *      [Card]     : obj
 *
 * Returns:
 *      [bool]
 */
bool Card::operator==(const Card &rhs) {
	return this->rank == rhs.rank;
}
/**
 * Public : operator !=
 *
 * Description:
 *      Overloaded bool operator that allows you to compare the value of two cards to 
 *      see if the value of the card of the left is not equal the one on the right
 *
 * Params:
 *      [Card]     : obj
 *
 * Returns:
 *      [bool]
 */
bool Card::operator!=(const Card &rhs) {
	return this->rank != rhs.rank;
}

/*
   ____    _    ____  ____   ____ ___  _   _ _____  _    ___ _   _ _____ ____
  / ___|  / \  |  _ \|  _ \ / ___/ _ \| \ | |_   _|/ \  |_ _| \ | | ____|  _ \
 | |     / _ \ | |_) | | | | |  | | | |  \| | | | / _ \  | ||  \| |  _| | |_) |
 | |___ / ___ \|  _ <| |_| | |__| |_| | |\  | | |/ ___ \ | || |\  | |___|  _ <
  \____/_/   \_\_| \_\____/ \____\___/|_| \_| |_/_/   \_\___|_| \_|_____|_| \_\
*/
/**
 * Card Containter
 * 
 * Description: 
 *    This is a Class that is design to hold a vector of Card pointers and perform 
 *    various operations unto this set of cards. This class also has access to the 
 *    methods used in the Cards Class
 *    
 * Public Methods:
 *                                    CardContainer(); 
 *                                    CardContainer(int);*not implemented*
 *    void                            Add(Card*);
 *    bool                            isEmpty(); *not implemented*   
 *    void                            Order();   *not implemented
 *    void                            Remove();
 *    void                            Shuffle(); *not implemented*
 *    int                             Size();
 *    vector<Card *> :: iterator      Next(); 
 *    friend ostream                  &operator << (ostream &os, const CardContainer&cards);
 *    Card&                           operator [](int);
 * 
 * Protected Methods:
 *    vector <Card *>                 Cards;  a vector of cards
 *    vector <Card *>::interator      it;     an interator that traverses the cards
 *  
 * 
 * Usage:
 * 
 *    CardContainer CC1               // creates an instance of a card container
 *    CC1.Add(&Card)                  // accepts the address of a card and adds it to the container
 *    CC1.Remove()                    // removes the first card in the container
 *    CC1.Reset()                     // removes all cards from the container
 *    CC1.Size()                      // returns the number of cards in the container
 *    cout << CC1                     // displays all the cards in the container 
 *    CC1[0]                          // allow for access to card in container similarly to an array
*/  
class CardContainer {
protected:
	vector<Card *> Cards;
	vector<Card *>::iterator it;

public:
	CardContainer();
	CardContainer(int);
	void Add(Card *);
	bool isEmpty();
	void Order();
	//Card *Remove();
  void Remove();
	void Reset();
	void Shuffle();
  /**
 * Public : Size
 *
 * Description:
 *      returns the amount of card held in the container
 * Params:
 *      N/A
 * 
 * Returns:
 *      int     the number of cards in the container
 */
	int Size(){
    return Cards.size();
  };
	vector<Card *>::iterator Next();
	friend ostream &operator<<(ostream &os, const CardContainer &cards);
  Card& operator[](int);
};
/**
 * Public : operator <<
 *
 * Description:
 *      Overloading ostream to that it traverses the vector of cards and 
 *      displays all cards in thier approipriate order 
 *
 * Params:
 *      [ostream&] : os
 *      [CardContainer]     : obj
 *
 * Returns:
 *      [ostream&]
 */
ostream &operator<<(ostream &os, const CardContainer &c) {
	for (int i = 0; i < c.Cards.size(); i++) {
		os << "\033[0;3" << c.Cards[i]->getfColor() << ";4"
		   << c.Cards[i]->getbColor() << "m";
		os << "┌────┐";
		os << "\033[0;39;49m";
	}
	os << endl;
	for (int i = 0; i < c.Cards.size(); i++) {
		os << "\033[0;3" << c.Cards[i]->getfColor() << ";4"
		   << c.Cards[i]->getbColor() << "m";
		os << "│";
		if (c.Cards[i]->getRank() != 9) {
			os << " ";
		}
		os << c.Cards[i]->getRankChar() << " " << c.Cards[i]->getSuitChar()
		   << "│";
		os << "\033[0;39;49m";
	}
	os << endl;
	for (int i = 0; i < c.Cards.size(); i++) {
		os << "\033[0;3" << c.Cards[i]->getfColor() << ";4"
		   << c.Cards[i]->getbColor() << "m";
		os << "└────┘";
		os << "\033[0;39;49m";
	}
	os << endl;

	return os;
}
 /**
 * Public : Card
 *
 * Description:
 *      Default Constructor that initializes the iterator of the card container
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
 */
CardContainer::CardContainer() {
	it = Cards.begin();
}
/**
 * Public : Add
 *
 * Description:
 *      Method that pushes a new card point on the back of the card container vector
 * 
 * Params:
 *     Card     *C : A card pointer
 * 
 * Returns:
 *      N/A
 */
void CardContainer::Add(Card *C) {
	Cards.push_back(C);
}
/**
 * Public : Next
 *
 * Description:
 *      Method that moves the iterator forward to the card after the current card
 * 
 * Params:
 *     N/A
 * 
 * Returns:
 *      N/A
 */
vector<Card *>::iterator CardContainer::Next() {
	if (it == Cards.end()) {
		it = Cards.begin();
	}
	return it++;
}
/**
 * Public : operator[]
 *
 * Description:
 *     Overloaded the [] operators so that the user can access the cards in the vector 
 *     similarly to the how items are accessed in an array
 * 
 * Params:
 *     int      index : this is the index of the card 
 * 
 * Returns:
 *      Card&     returns the address of a card
 */
 Card& CardContainer:: operator[](int index){
   // because the if part returns nothing   
   if(index > Cards.size()){
     cout << "invalid index";
     return *Cards[0];
     
   }
   else{
    
     return *Cards[index];
   }
 }
 /**
 * Public : Remove
 *
 * Description:
 *      This methods is used to remove the card that is at the front of the container
 * 
 * Params:
 *     N/A
 * 
 * Returns:
 *      N/A
 */
void CardContainer:: Remove(){
  Cards.erase(Cards.begin());
}
/**
 * Public : Reset
 *
 * Description:
 *      This method empty the container
 * 
 * Params:
 *     N/A
 * 
 * Returns:
 *      N/A
 */
void CardContainer::Reset(){
  Cards.erase(Cards.begin(),Cards.begin()+Cards.size());
}


/*
  ____  _____ ____ _  __
 |  _ \| ____/ ___| |/ /
 | | | |  _|| |   | ' /
 | |_| | |__| |___| . \
 |____/|_____\____|_|\_\
*/
/**
 * Deck : Public Container
 * 
 * Description: 
 *    This is a class to represent the deck of a card and has all the methods and 
 *    uses that you would expect of a deck of cards. This Class is also derived from
 *    the card container class so it has access to all of card container class 
 *    methods 
 *    
 * Public Methods:
 *                            Deck();
 *                            Deck(int);
 *     Card                   *Draw(); *not implemented*
 *     friend ostream         &operator << (ostream &os, Deck &cards);
 *     int                    getdecksize(); 
 *     void                   randomInsert(Card *C);
 *     
 * Protected Methods:
 * 
 *     int                    deckSize : This is the amount of cards in the deck 
 * 
 * Usage:
 *     Deck D1;                // creates a shuffle deck of default size of 52
 *     Deck D2(2);             // creates a shuffled deck of size 2*52
 *     cout << D1;             // displays all the cards in the deck 
 *     D1.getdecksize         // returns the amount of cards in the deck
 *     D1.randomInsert        // places card in a random position in the deck
 *     D1.Add(&Card)          // Deck having access to methods of card container 
*/  
class Deck : public CardContainer {
protected:
	int deckSize;

public:
	Deck();
	Deck(int);
	Card *Draw();
  /**
 * Public : operator <<
 *
 * Description:
 *      Overloading ostream to that it traverses the vector of cards and 
 *      displays all cards in thier approipriate order 
 *
 * Params:
 *      [ostream&] : os
 *      [Deck]     : obj
 *
 * Returns:
 *      [ostream&]
 */
	friend ostream &operator<<(ostream &os, Deck &cards) {
		for (int i = 0; i < cards.deckSize+1; i++) {
			os << PrintCard(*cards.Next());
		}
		return os;
	}
/**
 * Public : getdecksize
 *
 * Description:
 *      This method returns the number of cards in the deck 
 * 
 * Params:
 *     N/A
 * 
 * Returns:
 *      int         returns the number of cards in the deck 
 */
  int getdecksize(){
    return deckSize;
  }
/**
 * Public : randomInsert
 *
 * Description:
 *      This method places a random card in a random position in the the deck 
 * 
 * Params:
 * 
 *     Card       *C : this is the card to be inserted 
 * 
 * Returns:
 *      N/A
 */
  void randomInsert(Card * C){
    Cards.insert(Cards.begin()+((rand() % deckSize+1)+1),C);
  }
    
};
/**
 * Public : Deck
 *
 * Description:
 *      This is a Default constructor that creates a deck of size 52 and shuffles
 *      the contents 
 * 
 * Params:
 * 
 *     N/A
 * 
 * Returns:
 *      N/A
 */
Deck::Deck() {
	deckSize = 52;
	for (int i = 0; i < deckSize+1; i++) {
		Add(new Card(i));
	}
  random_shuffle(Cards.begin(),Cards.end());
}
/**
 * Public : Deck
 *
 * Description:
 *      This is a Default constructor that creates a deck of size a*52 and shuffles
 *      the contents 
 * 
 * Params:
 * 
 *     int      a: this in is multiplied by 52 to get the size of the deck 
 * 
 * Returns:
 *      N/A
 */
Deck :: Deck(int a){
  deckSize = a*52;
	for (int i = 0; i < deckSize+1; i++) {
		Add(new Card(i));
	}
  random_shuffle(Cards.begin(),Cards.end());
}
/**
 * Player : public Cardcontainer
 * 
 * Description: 
 *    This is a Class to represent the player of the blackjack game and all
 *    different this that a player would have access to when playing blackjack.
 *    This class is also derived from the Card Container class so has access to
 *    all its functions and  methods of a Card Container
 *    
 * Public Methods:
 *                       
 *                      Player();
 *                      Player(string n, int a, int b);
 *    string            getname();
 *    int               getage();
 *    int               getbank();
 *    void              setbank(int b);
 *    void              add_to_hand(Deck &D1);
 *    void              showhand();
 *    void              showparthand(int index);
 *    int               getcardrank(int index);
 *    int               gethadsize();
 *    void              emptyhand();
 *     
 * Protected Methods:
 * 
 *    CardContainer     hand; : this is the players hand
 * 
 * Private  Methods: 
 * 
 *    string            name;  : the name of the player
 *    int               age;   : the age of the player 
 *    int               bank;  : the bank of the player
 * 
 * Usage:
 *     
 *    Player P1;                  // Uses default parameters to create Player
 *    Player P2("Bob",21,1000);    // uses passed parameters to initialize Player
 *    P1.getname();               // returns the player name
 *    P1.getage();                // return age of player
 *    P1.getbank();               // return the bank amount
 *    P1.setbank();               //used to change the bank amount
 *    P1.add_to_hand(D1);          // adds a card to the players hand from the deck
 *    P1.showhand();              // displays the whole hand of the player
 *    P1.showparthand(0);         // shows the first card in the hand 
 *    P1.getcardrank(0);          // gets the rank of the card in the first card
 *    P1.gethandsize();           // get the amount of cards in the players hands
 *    P1.emptyhand();             // empties the hand of the player                
*/  
class Player : public CardContainer {
private:
	string name;
	int age;
	int bank;

protected:
	CardContainer hand;

public:
/**
 * Public : Player
 *
 * Description:
 * 
 *      This is a Default constructor that uses default parameters to create an instance of 
 *      a Player
 * 
 * Params:
 * 
 *     N/A
 * 
 * Returns:
 *      N/A
 */
	Player() {
		name = "Jarette";
		age = 23;
		bank = 20000;
	}
/**
 * Public : Player
 *
 * Description:
 * 
 *      This is a Default constructor that uses default parameters to create an instance of 
 *      a Player
 * 
 * Params:
 * 
 *     string     n: represents the name of the player
 *     int        a: represents the age of the player
 *     int        b: represents the bank of the player
 * 
 * Returns:
 *      N/A
 */
	Player(string n, int a, int b) {
		name = n;
		age = a;
		bank = b;
	}
  /**
 * Public : getname
 *
 * Description:
 * 
 *      This is a method that returns the name of the player
 * 
 * Params:
 * 
 *     N/A
 * 
 * Returns:
 *      string        the name of the player
 */
  string getname(){
    return name;
  }
  /**
 * Public : getage
 *
 * Description:
 * 
 *      This is a method that returns the age of the player
 * 
 * Params:
 * 
 *     N/A
 * 
 * Returns:
 *      int        the age of the player
 */
  int getage(){
    return age;
  }
/**
 * Public : getbank
 *
 * Description:
 * 
 *      This is a method that returns the bank of the player
 * 
 * Params:
 * 
 *     N/A
 * 
 * Returns:
 *      int        the bank of the player
 */
  int getbank(){
    return bank;
  }
/**
 * Public : set
 *
 * Description:
 * 
 *      This is a method that allows you to set a new value for the bank
 * 
 * Params:
 * 
 *     int      b: the new value of bank 
 * 
 * Returns:
 *     N/A
 */
  void setbank(int b){
    bank = b;
  }
/**
 * Public : add_to_hand
 *
 * Description:
 * 
 *      This is a function that adds a card to the hand then removes a card from the deck 
 *      and inserts a random card into the deck.
 * 
 * Params:
 * 
 *     Deck      &D1: the deck used to play the game
 * 
 * Returns:
 *     N/A
 */
	void add_to_hand(Deck &D1) {
		hand.Add(&D1[0]);
		D1.Remove();
    D1.Add(new Card(rand() % 52));
	}
  /**
 * Public : showhand
 *
 * Description:
 * 
 *      This is a function that displays the entire hand of the player
 * 
 * Params:
 * 
 *    N/A
 * 
 * Returns:
 *     N/A
 */
	void showhand() {
    cout << endl;
		cout << hand;
		cout << endl;
	}
   /**
 * Public : showparthand
 *
 * Description:
 * 
 *      This is a function gives access to the specific card in the players hand 
 * 
 * Params:
 * 
 *    int     index: used to get the card location
 * 
 * Returns:
 *     N/A
 */
	void showparthand(int index) {
		cout << hand[index];
	}
/**
 * Public : getcardrank
 *
 * Description:
 * 
 *      this function allows the player get the rank (value) of a specified card
 * 
 * Params:
 * 
 *    int     index: used to get the card location
 * 
 * Returns:
 *    int     the rank of the card
 */
	int getcardrank(int index) {
		return hand[index].getRank();
	}
  /**
 * Public : gethandsize
 *
 * Description:
 * 
 *      this function returns the size of the players hand 
 * 
 * Params:
 * 
 *    N/A
 * 
 * Returns:
 *     int    the size of the hand 
 */
	int gethandsize() {
		return hand.Size();
	}
/**
 * Public : emptyhand
 *
 * Description:
 * 
 *      this function removes all cards from the player's hands 
 * 
 * Params:
 * 
 *    N/A
 * 
 * Returns:
 *     N/A
 */
  void emptyhand(){
    hand.Reset();
  }
};
/**
 * Dealer : public Player
 * 
 * Description: 
 * 
 *    This is a class that represents the dealer of the blackjack game. This class is 
 *    derived from the Player class
 *    
 * Public Methods:
 * 
 *                          Dealer
 *    string                getDname;
 *                   
 * Private  Methods: 
 * 
 *    string                Dname; : the dealers name
 * 
 * 
 * Usage:
 *     
 *    Dealer House               //initializing dealer class 
 *    House.add_to_house(D1)    // uses methods from player class
 *            
*/  
class Dealer : public Player{
private:
  string Dname;
protected:
public:
/**
 * Public : Dealer
 *
 * Description:
 * 
 *      this is a default constructor to initialize the dealer class
 * 
 * Params:
 * 
 *    N/A
 * 
 * Returns:
 *     N/A
 */
 Dealer(){
   Dname ="Rich Uncle Pennybags";
 }
 /**
 * Public : getDname
 *
 * Description:
 * 
 *      this is a function uses to get the dealer's name
 * 
 * Params:
 * 
 *    N/A
 * 
 * Returns:
 *     string     returns the name of the dealer 
 */
string getDname(){
  return Dname;
}
/*
 
   /$$$$$$                                   
  /$$__  $$                                  
 | $$  \__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ 
 | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$
 | $$|_  $$  /$$$$$$$| $$ \ $$ \ $$| $$$$$$$$
 | $$  \ $$ /$$__  $$| $$ | $$ | $$| $$_____/
 |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$
  \______/  \_______/|__/ |__/ |__/ \_______/
                                             
                                             
                                             
 
*/
};
/**
 * Game
 * 
 * Description: 
 *    This is a Class to represent the player of the blackjack game and all
 *    different this that a player would have access to when playing blackjack.
 *    This class is also derived from the Card Container class so has access to
 *    all its functions and  methods of a Card Container
 *    
 * Public Methods:
 *    void             PlayerHvalue(Player P)
 *    void             dealerHvalue(Dealer D)
 *    int              getplayervalue()
 *    int              getdealervalue()
 *    void             setplayervalue(int n)
 *    void             setplayervalue(int n)
 *    bool             isbust(int val)
 *    bool             istwentyone(int val)
 *    bool             lessthan21(int val)
 *    void             Playerturndispaly(Player P, Dealer D, int bet)    
 *    void             Dealerturndisplay(Player P, Dealer D, int bet)  
 *    int              PlayerChoiceMenu()      
 *    void             ResetGame(Player &P,Dealer &D) 
 *    void             PlayerWon(Player &P, int bet)
 *    void             DealerWon(Player &P, int bet)
 *    void             Busted(Player &P, int bet)
 *    void             LoadingMessage(string m)
 *    void             OutofMoney() 
 * 
 * Protected Methods:
 *    
 *    int             playerhandvalue;  : the total value of the player's hand
 *    int             dealerhandvalue;  : the total value of the dealer's hand
 * 
 * Usage:
 *    
 *    Game BLJ                                    //creating an instance of the game 
 *    BLJ.playerHvalue / BLJ.dealerHvalue         //calculates the value of total value of the player's hand and dealer's hand value 
 *    BLJ.getplayervalue()                   // returns the current hand value of the player
 *    BLJ.getdealervalue()                   // returns the current hand value of the dealer
 *    BLJ.setplayervalue(int n)               // assigns an int to the player value variable
 *    BLJ.setdealervalue(int n)             // assigns an in to the dealer value variable 
 *    BLJ.isbust(a)                          // checks if the value passed is over 21
 *    BLJ.istwentyone(a)                    // checks if the value passed  is 21
 *    BLJ.lessthan21(a)                     // checks if value passed is less than 21
 *    BLJ.Playerturndisplay(P1,House,bet)       // displays all the elements of the game neccesary for the player's turn
 *    BLJ.Dealerturndisplay(P1,House,bet)     // displays all elements neccessary for thr dealer's turn
 *    BLJ.PlayerChoiceMenu()                  //displays a menu and returns the option selected
 *    BLJ.ResetGame(P1,Hosue)               //restarts game at the end of round
 *    BLJ.PlayerWon(P1,bet)               //performs calculations for when the player wins 
 *    BLJ.Dealerwon(P1,bet)               // performs calculations for when the dealer wins
 *    BLJ.Busted(P1,bet)                  // performs calculations for when the player busts
 *    BLJ.Loading Message                 // function that flashes a message on screen for 2 seconds
 *    BLJ.OutofMoney                      // displays a message for when the player bank is <= 0  
 * 
 *               
*/  
class Game {
private:
protected:
int playerhandvalue;
int dealerhandvalue;
public:
/**
 * Public : playerHvalue
 *
 * Description:
 * 
 *    This functions adds the values of all cards in the player's hand
 *    It also accounts for aces and allows the user to choose if the 
 *    value of the ace is 1 or 11
 * 
 * Params:
 * 
 *    Player      P : represents the player
 * 
 * Returns:
 *     N/A
 */
	void playerHvalue(Player P) {
		int value = 0;
		int temp = 0;
		for (int i = 0; i < P.gethandsize(); i++) {
      // checking for an ace and ask player what they would like the value to be 
			if (P.getcardrank(i) == 0) {
				cout << "would you like your ACE to count as 11 or a 1?:"
					 << endl;
				cin >> temp;
				while (temp != 1 && temp != 11) {
					cout << "Please enter 1 or 11: " << endl;
					cin >> temp;
				}
				value = value + temp;
			} 
      else if(P.getcardrank(i)== 10 || P.getcardrank(i)==11|| P.getcardrank(i)==12){
        value = value+10;
      }
      else {
				value = value + (P.getcardrank(i) + 1);
			}
		}
		playerhandvalue = value;
	}
  /**
 * Public : playerHvalue
 *
 * Description:
 * 
 *    This functions adds the values of all cards in th hand hand
 *    It also accounts for aces by havinng the value be 1 unless the dealer
 *    would win if the value is 11 
 * 
 * Params:
 * 
 *    Player      D : represents the dealer
 * 
 * Returns:
 *    N/A
 */
void dealerHvalue(Dealer D){
  int value=0;
  int temp =0;
  for(int i = 0; i < D.gethandsize();i++){
    //handling aces
    if(D.getcardrank(i)==0){
      if((value + 11) == 21){
        value = value + 11;
      }
      else{
        value = value +1;
      }
    }
    else if(D.getcardrank(i)==10||D.getcardrank(i)==11||D.getcardrank(i)==12){
      value = value+10;
    }
    else{
      value = value + (D.getcardrank(i)+1);
    }
  }
  dealerhandvalue = value;
}
/**
 * Public : getplayervalue
 *
 * Description:
 * 
 *    This function will return the current value of the hand of the player
 * 
 * Params:
 *    
 *    N/A
 * 
 * Returns:
 *     int        the value of player's hand  
 */
  int getplayervalue(){
    return playerhandvalue;
  }
  /**
 * Public : getdealervalue
 *
 * Description:
 * 
 *    This function will return the current value of the hand of the dealer
 * 
 * Params:
 * 
 *    N/A
 * 
 * Returns:
 *     int        the value of player's hand  
 */
  int getdealervalue(){
    return dealerhandvalue;
  }
    /**
 * Public : setplayervalue
 *
 * Description:
 * 
 *    This function will set a new integer as the hand value of the player
 * 
 * Params:
 * 
 *   int         n : the new hand value
 * 
 * Returns:
 *    N/A
 */
  void setplayervalue(int n){
    playerhandvalue = n;
  }
      /**
 * Public : setdealervalue
 *
 * Description:
 * 
 *    This function will set a new integer as the hand value of the dealer
 * 
 * Params:
 * 
 *   int         n : the new hand value
 * 
 * Returns:
 *    N/A
 */
  void setdealervalue(int n){
    dealerhandvalue = n;
  }
/**
 * Public : isbust
 *
 * Description:
 * 
 *    this fucntion checks if the value passed is over 21
 * 
 * Params:
 * 
 *   int         val : the value to be checked
 * 
 * Returns:
 *    bool        a true or false value 
 */
	bool isbust(int val) {
		if (val > 21) {
			return true;
		} else {
			return false;
		}
	}
  /**
 * Public : istwentyone
 *
 * Description:
 * 
 *    this function checks if the value passed is 21
 * 
 * Params:
 * 
 *   int         val : the value to be checked
 * 
 * Returns:
 *    bool        a true or false value 
 */
	bool istwentyone(int val) {
		if (val == 21) {
			return true;
		} else {
			return false;
		}
	}
/**
 * Public : isless than
 *
 * Description:
 * 
 *    this function checks if the value passed is less than 21
 * 
 * Params:
 * 
 *   int         val : the value to be checked
 * 
 * Returns:
 *    bool        a true or false value 
 */
	bool lessthan21(int val){
    if(val < 21){
      return true;
    }
    else{
      return false;
    }
  }
/**
 * Public : Playerturndisplay
 *
 * Description:
 * 
 *    this function displays all the information that is needed for the player on 
 *    the player's turn
 * 
 * Params:
 * 
 *   Player       P : the player
 *   Dealer       D : the dealer
 *   int          bet : the current amount of money bet in that round 
 * 
 * Returns:
 *    N/A
 */
void Playerturndispaly(Player P, Dealer D, int bet){
  cout << "DEALER: ";
  cout << endl;
  cout << "Dealer's name tag: " << D.getDname();
  cout << endl;
  cout << "Dealer's hand: ";
  doubleline();
  D.showparthand(0);
  doubleline();

  cout << "======================================" << endl;

  cout << endl;
  cout << "PLAYER: ";
  cout << endl;
  cout << "Name: " << P.getname();
  cout << endl;
  cout << "age: " << P.getage();
  cout << endl;
  cout << "Current bank:$" << P.getbank();
  cout << endl;
  cout << "Your current bet:$" << bet;
  cout << endl;
  cout << "Your Hand: ";
  doubleline();
  P.showhand();
  playerHvalue(P);
  cout << "Current Hand Value: " << getplayervalue();
  cout << endl;
  
}
/**
 * Public : Dealerturndisplay
 *
 * Description:
 * 
 *    this function displays all the information that is needed for the player on 
 *    the dealer's turn
 * 
 * Params:
 * 
 *   Player       P : the player
 *   Dealer       D : the dealer
 *   int          bet : the current amount of money bet in that round 
 * 
 * Returns:
 *    N/A
 */
void Dealerturndisplay(Player P, Dealer D, int bet){
  cout << "DEALER: ";
  cout << endl;
  cout << "Dealer's name tag: " << D.getDname();
  cout << endl;
  cout << "Dealer's hand: ";
  doubleline();
  D.showhand();
  cout << endl;
  dealerHvalue(D);
  cout << "Current dealer hand value: " << getdealervalue();
  doubleline();

  cout << "======================================" << endl;

  cout << endl;
  cout << "PLAYER: ";
  cout << endl;
  cout << "Name: " << P.getname();
  cout << endl;
  cout << "age: " << P.getage();
  cout << endl;
  cout << "Current bank:$" << P.getbank();
  cout << endl;
  cout << "Your current bet:$" << bet;
  cout << endl;
  cout << "Your Hand: ";
  doubleline();
  P.showhand();
  cout << "Current Hand Value: " << getplayervalue();
  cout << endl;
}
/**
 * Public : PlayerMenu
 *
 * Description:
 * 
 *    displays a menu and allows the user ot choose an option and allowed the user
 *    to pick an option
 * 
 * Params:
 *      
 *    N/A 
 *    
 * Returns:
 *    int     this is the choice the player made
 */
int PlayerChoiceMenu(){
  int choice= 0;
  cout << endl;
  cout << "What would you like to do? Enter the correspoding number to enter you choice.";
  cout << endl;
  cout << "Enter 1 to HIT";
  cout << endl;
  cout << "Enter 2 to STAND";
  cout << endl;
  cout << "Enter 3 to EXIT TABLE";
  cout << endl;
  cout << "Enter choice: ";
  cin >> choice;
  cout << endl;
  while(choice > 3 || choice < 0){
    cout << "Please re-enter choice: ";
    cin >> choice;
    cout << endl;
  }
  if(choice == 3){
    return -1;
  }
  else{
  return choice;
  }
}
/**
 * Public : ResetGame
 *
 * Description:
 * 
 *    This function empties both the hand of the player and the dealer
 * 
 * Params:
 *      
 *    Player        &P  : the player
 *    Dealer        &D  : the dealer
 *    
 * Returns:
 *    N/A
 */
void ResetGame(Player &P,Dealer &D){
  P.emptyhand();
  D.emptyhand();
  setplayervalue(0);
  setdealervalue(0);
}
/**
 * Public : PlayerWon
 *
 * Description:
 * 
 *    This function displays a message when the player wins and adds approipriate amount
 *    to the bank
 * 
 * Params:
 *      
 *    Player        &P  : the player
 *    Dealer        &D  : the dealer
 *    
 * Returns:
 *    N/A
 */
void PlayerWon(Player &P, int bet){
  int winlose = 0;
  cout << "You won this round. CONGRATULATIONS";
  cout << endl;
  cout << "You won: $" << (bet*2);
  winlose = P.getbank()+(bet*2);
  P.setbank(winlose);
  cout << endl;
  cout << "Your Current bank: $" << P.getbank();
}
/**
 * Public : DealerWon
 *
 * Description:
 * 
 *    This function displays a message when the player loses and takes away approipriate amount
 *    from the bank
 * 
 * Params:
 *      
 *    Player        &P  : the player
 *    Dealer        &D  : the dealer
 *    
 * Returns:
 *    N/A
 */
void DealerWon(Player &P, int bet){
  int winlose = 0;
   cout << "You Lost to the house. :(";
   cout << endl;
   cout << "You lose: $" << (bet*2);
   winlose = P.getbank() - (bet*2);
   P.setbank(winlose);
   cout << endl;
   cout << "Your Current bank: $" << P   .getbank();
}
/**
 * Public : Busted
 *
 * Description:
 * 
 *    This function displays a message when the player loses 
 *    because their hand value when over 21 then subtracts approipriate amount
 *    from the bank
 * 
 * Params:
 *      
 *    Player        &P  : the player
 *    Dealer        &D  : the dealer
 *    
 * Returns:
 *    N/A
 */
void Busted(Player &P, int bet){
  int winlose = 0;
  cout << "You BUSTED. :(";
  cout << endl;
  cout << "You lose: $" << (bet*2);
  winlose = P.getbank() - (bet*2);
  P.setbank(winlose);
  cout << endl;
  cout << "Your Current bank: $" << P.getbank();
}
/**
 * Public : LoadingMessage
 *
 * Description:
 * 
 *    This function flashes a message on screen for two seconds 
 * 
 * Params:
 *      
 *    string          m: the message
 *    
 * Returns:
 *    N/A
 */
void LoadingMessage(string m){
  cout << m;
  cout << flush;
  sleep(2);
  system("clear");
}
/**
 * Public : OutofMoney
 *
 * Description:
 * 
 *    This function displays a message on the screen to tell the player that thier 
 *    bank is empty   
 * 
 * Params:
 *      
 *    N/A
 *    
 * Returns:
 *    N/A
 */
void OutofMoney(){
  cout << flush;
  sleep(2);
  system("clear");
  cout << "Thank you for Playing :)";
  cout << endl;
  cout << "But you are out of money so I think you should go home now :)";
}
};


