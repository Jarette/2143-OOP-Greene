// neccesary libraries
#include "colors.h"
#include <algorithm> // std::random_shuffle
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
#include <unistd.h>
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
 *                                    CardContainer(); *not implemented*
 *                                    CardContainer(int);*not implemented*
 *    void                            Add(Card*);
 *    bool                            isEmpty(); *not implemented*   
 *    void                            Order();   *not implemented
 *    void                            Remove();
 *    void                            Shuffle(); *not implemented*
 *    int                             Size()
 *    vector<Card *> :: iterator      Next();
 *    friend ostream                  &operator << (ostream &os, const CardContainer&cards)
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
 *    CC1[0]                          // allow for access to card in container similarly to a 
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
	int Size(){
    return Cards.size();
  };
	vector<Card *>::iterator Next();
	friend ostream &operator<<(ostream &os, const CardContainer &cards);
  Card& operator[](int);
};

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

CardContainer::CardContainer() {
	it = Cards.begin();
}

void CardContainer::Add(Card *C) {
	Cards.push_back(C);
}

vector<Card *>::iterator CardContainer::Next() {
	if (it == Cards.end()) {
		it = Cards.begin();
	}
	return it++;
}
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
void CardContainer:: Remove(){
  Cards.erase(Cards.begin());
}
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

class Deck : public CardContainer {
protected:
	int deckSize;

public:
	Deck();
	Deck(int);
	Card *Draw();
	friend ostream &operator<<(ostream &os, Deck &cards) {
		for (int i = 0; i < cards.deckSize+1; i++) {
			os << PrintCard(*cards.Next());
		}
		return os;
	}
  int getdecksize(){
    return deckSize;
  }
  void randomInsert(Card * C){
    Cards.insert(Cards.begin()+((rand() % deckSize+1)+1),C);
  }
    
};

Deck::Deck() {
	deckSize = 52;
	for (int i = 0; i < deckSize+1; i++) {
		Add(new Card(i));
	}
  random_shuffle(Cards.begin(),Cards.end());
}
Deck :: Deck(int a){
  deckSize = a*52;
	for (int i = 0; i < deckSize+1; i++) {
		Add(new Card(i));
	}
  random_shuffle(Cards.begin(),Cards.end());
}


/*
  _   _    _    _   _ ____
 | | | |  / \  | \ | |  _ \
 | |_| | / _ \ |  \| | | | |
 |  _  |/ ___ \| |\  | |_| |
 |_| |_/_/   \_\_| \_|____/
*/
class Hand :public CardContainer {
protected:
public:
	Hand(Deck &D1){
    Add(&D1[0]);
    D1.Remove();
  }
	int Size() {
		return Cards.size();
	}
	void Sort();
  void add_to_hand(Deck &D1){
    Add(&D1[0]);
    D1.Remove();
  }
  void showhand(){
    cout << this;
  }
  void showparthand(int index){
    cout << this[index];
  }
};
class Player : public CardContainer {
private:
	string name;
	int age;
	int bank;

protected:
	CardContainer hand;

public:
	Player() {
		name = "Jarette";
		age = 23;
		bank = 20000;
	}
	Player(string n, int a, int b) {
		name = n;
		age = a;
		bank = b;
	}
  string getname(){
    return name;
  }
  int getage(){
    return age;
  }
  int getbank(){
    return bank;
  }
  void setbank(int b){
    bank = b;
  }
	void add_to_hand(Deck &D1) {
		hand.Add(&D1[0]);
		D1.Remove();
    D1.Add(new Card(rand() % 52));
	}
	void showhand() {
    cout << endl;
		cout << hand;
		cout << endl;
	}
	void showparthand(int index) {
		cout << hand[index];
	}
	int getcardrank(int index) {
		return hand[index].getRank();
	}
	int gethandsize() {
		return hand.Size();
	}
  void emptyhand(){
    hand.Reset();
  }
};
class Dealer : public Player{
private:
  string Dname;
protected:
public:
 Dealer(){
   Dname ="Rich Uncle Pennybags";
 }
string getDname(){
  return Dname;
}
};
class Game {
private:
protected:
int playerhandvalue;
int dealerhandvalue;
public:
	void playerHvalue(Player P) {
		int value = 0;
		int temp = 0;
		for (int i = 0; i < P.gethandsize(); i++) {
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
void dealerHvalue(Dealer D){
  int value=0;
  int temp =0;
  for(int i = 0; i < D.gethandsize();i++){
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
  int getplayervalue(){
    return playerhandvalue;
  }
  int getdealervalue(){
    return dealerhandvalue;
  }
  void setplayervalue(int n){
    playerhandvalue = n;
  }
  void setdealervalue(int n){
    dealerhandvalue = n;
  }
	bool isbust(int val) {
		if (val > 21) {
			return true;
		} else {
			return false;
		}
	}
	bool istwentyone(int val) {
		if (val == 21) {
			return true;
		} else {
			return false;
		}
	}
	bool lessthan21(int val){
    if(val < 21){
      return true;
    }
    else{
      return false;
    }
  }
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
void ResetGame(Player &P,Dealer &D){
  P.emptyhand();
  D.emptyhand();
  setplayervalue(0);
  setdealervalue(0);
}
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
void LoadingMessage(string m){
  cout << m;
  cout << flush;
  sleep(2);
  system("clear");
}
void OutofMoney(){
  cout << flush;
  sleep(2);
  system("clear");
  cout << "Thank you for Playing :)";
  cout << endl;
  cout << "But you are out of money so I think you should go home now :)";
}
};


