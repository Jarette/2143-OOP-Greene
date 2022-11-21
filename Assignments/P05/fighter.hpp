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
*		  This Hpp file contains all classes the pertain to the fighters in this 
*     program. Where there is a class that function as a Base Fighter with 
*     all virtual methods that are all methods that the all the combantants 
*     would need. Then there are there are derived sub classes of base fighter
*     Warrior,Wizard,Archer,Elf,Dragonborn. Then classes to fill both groups of 
*     fighters, Attackers and Defenders, which contains vectors of pointers of 
*     of all of the different classes where the user gives the size of the 
*     Attacker group while the defender's group size is based on the size of 
*     the Attacker group, 100:1 ratio
*
*  Usage:
*        N/A
*
*  Files:
*           weapon.hpp          :contains class to create weapons
*           helper.hpp          :contains functions to tokenize a string
*           fighter.hpp         :contains classes to represent thee different
*                                fighters
*
*****************************************************************************/
// neccesary libraries
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "weapon.hpp"
#include "helpers.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>

//using namespace std
using namespace std;

#pragma once
/**
 * Public : fRand
 *
 * Description:
 *        
 *    allows to get a random double number with a given range of 
 *    double  
 * 
 * Params:
 *      double        fMin
 *      double        fMax
 *
 * Returns:
 *     double         :random double generated
 */ 
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
/**
 * BaseFighter
 * 
 * Description: 
 *     This class is the base fighter for every class of fighter to be 
 *     derived from. Containing the attributes and methods that are used 
 *      by all of the classes and allowing for methods to be overridden 
 *      by these classes
 * 
 * Public Methods
 *                        BaseFighter()
 *     virtual double     attack()
 *     virtual int        getHP()
 *     virtual  void      setHP(int h)
 *     virtual  void      setHP(double h)
 *      virtual double    getRR()
 *     virtual string     getname()
 *     virtual bool        isAlive()
 *      virtual int        getspeed()
 *     virtual MaxHp      getMaxHP()
 *     friend double      fRand(double,double)
 *      virtual string    Print()
 *     friend ostream&    operator<<(ostream& os, BaseFighter& f)
 *                             
 * 
 * Private Methods:   
 *        string          name
 *        Weapon          *weapon
 *        int             HP
 *        double          RR
 *        int             speed
 *        int             MaxHP 
 * 
 * Usage:
 *     BaseFighter BF()     //created a base fighter
 *     BF.attack()          // uses the fighter's weapon
 *     BF.getHP()           // returns the current HP of fighter
 *     BF.setHP(10)         // sets the HP of the fighter to 10
 *     BF.setHP(10.01)      // sets the HP using a double
 *     BF.getRR()           // returns the Regeneration Rate of fighter
 *     BF.getname()         //returns the name of the fighter
 *     BF.isAlive()         //checks if the fighter's HP is 0 or not
 *     BF.getspeed()        //returns the speed of the fighter
 *     BF.getMaxHP()        //returns the Max amount of the HP the fighter can have
 *     cout << BF           // displays all relevant information about the fighter
 *                          // on sreeen
 *   
 *    
*/ 
class BaseFighter {
protected:

    string name;
    Weapon *weapon;
    int HP;
    double RR;
    int speed;
    int MaxHP;
public:
/**
 * Public : BaseFighter
 *
 * Description:
 *        
 *    Default constructor to create a base fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */ 
    BaseFighter() {
        name = "None";
        weapon = new Weapon;
    }
/**
 * Public : attack
 *
 * Description:
 *        
 *    uses the fighter's weapon and returns the damage dealt
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     double      :the damage dealt
 */ 
    virtual double attack(){
        return weapon->use();
    }
/**
 * Public : getHP
 *
 * Description:
 *        
 *    Returns the current HP of the fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     int      :The current HP of the fighter
 */ 
virtual int getHP(){
  return HP;
}
/**
 * Public : setHP
 *
 * Description:
 *        
 *    sets the current HP of the fighter
 * 
 * Params:
 *      int     h: the new HP of the fighter
 *
 * Returns:
 *    N/A
 */ 
virtual void setHP(int h){
  HP = h;
}
/**
 * Public : setHP
 *
 * Description:
 *        
 *    sets the current HP of the fighter
 * 
 * Params:
 *      double     h: the new HP of the fighter
 *
 * Returns:
 *    N/A
 */ 
virtual void setHP(double h){
  HP = h;
}
/**
 * Public : getRR
 *
 * Description:
 *        
 *    Returns the Regeneration Rate of the fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     double      :The current Regeneration Rate of the fighter
 */
virtual double getRR(){
  return RR;
}
/**
 * Public : getname
 *
 * Description:
 *        
 *    Returns the name of the fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     string      :The name of the fighter
 */
virtual string getname(){
  return name;
}
/**
 * Public : isAlive
 *
 * Description:
 *        
 *    Checks if the fighter's curren HP is 0 if it is 
 *    or less then return false of else return true
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     bool      :true or false
 */
virtual bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
/**
 * Public : getspeed
 *
 * Description:
 *        
 *    Returns the speed of the fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     string      :The speed of the fighter
 */
virtual int getspeed(){
  return speed;
}
/**
 * Public : getMaxHP
 *
 * Description:
 *        
 *    Returns the max possible HP of the fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     string      :The max possible hp of the fighter
 */
virtual int getMaxHP(){
  return MaxHP;
}
//defined outside of class 
friend double fRand(double, double);
/**
 * Public : Print
 *
 * Description:
 *        
 *    Methods creates a string with all the relevant information of the 
 *    fighter in a specified format [name,weapon name,weapon damage,]
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     string      :The resulting string
 */
    virtual string Print(){
      string temp = "";
      temp += "["; 
      temp += name;
      temp+= " , ";
      temp+= "[";
      temp+= weapon->getName();
      temp+=" , ";
      temp+= weapon->getDamage();
      temp+= "]";
      temp+= "]";
      return temp;
    }
/**
 * Public : operator<<
 *
 * Description:
 *        
 *    overloaded ostream operator to display the string created from 
 *    the Print method
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      ostream&    :what will be passed to ostream
 */
 friend ostream& operator<<(ostream& os, BaseFighter& f) {
        return os << f.Print();
    }


};
/**
 * Warrior: Public BaseFighter
 * 
 * Description: 
 *     This is a Warrior fighter class that is derived from the Base Fighter class
 *     and overrides all the methods of BaseFighter
 * 
 * Public Methods
 *                        Warrior()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getRR()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *                            
 * 
 * Private Methods:   
 *        int             HP
 *        double          RR 
 * 
 * Usage:
 *     Warrior War()        //created a Warrior fighter
 *     War.attack()          // uses the fighter's weapon
 *     War.getHP()           // returns the current HP of fighter
 *     War.setHP(10)         // sets the HP of the fighter to 10
 *     War.setHP(10.01)      // sets the HP using a double
 *     War.getRR()           // returns the Regeneration Rate of fighter
 *     War.getname()         //returns the name of the fighter
 *     War.isAlive()         //checks if the fighter's HP is 0 or not
 *     War.getspeed()        //returns the speed of the fighter
 *     War.getMaxHP()        //returns the Max amount of the HP the fighter can have
 *     cout << War           // displays all relevant information about the fighter
 *                          // on sreeen
 *   
 *    
*/ 
class Warrior : public BaseFighter{
private: 
  int HP;
  double RR;
public:
/**
 * Public : Warrior
 *
 * Description:
 *        
 *    Default constructor to create a Warrior fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
  Warrior(){
    
    name = "Warrior";
    HP = (rand()%8+3);
    MaxHP = HP;
    RR = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%2+1);
    if(WD==1){
      weapon = new Weapon("Sword","1.d.4");
      }
    else{
      weapon = new Weapon("Sword","1.d.6");
    }  
  }
  // All overriden from the BaseFighter Class
double attack(){
  return weapon->use();
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getRR(){
  return RR;
}
string getname(){
  return name;
}
bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int getspeed(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
};
/**
 * Wizard: Public BaseFighter
 * 
 * Description: 
 *     This is a Wizard fighter class that is derived from the Base Fighter class
 *     and overrides all the methods of BaseFighter
 * 
 * Public Methods
 *                        Wizard()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getRR()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *                            
 * 
 * Private Methods:   
 *        int             HP
 *        double          RR 
 * 
 * Usage:
 *     Wizard Wiz()           //created a wizard fighter
 *     Wiz.attack()          // uses the fighter's weapon
 *     Wiz.getHP()           // returns the current HP of fighter
 *     Wiz.setHP(10)         // sets the HP of the fighter to 10
 *     Wiz.setHP(10.01)      // sets the HP using a double
 *     Wiz.getRR()           // returns the Regeneration Rate of fighter
 *     Wiz.getname()         //returns the name of the fighter
 *     Wiz.isAlive()         //checks if the fighter's HP is 0 or not
 *     Wiz.getspeed()        //returns the speed of the fighter
 *     Wiz.getMaxHP()        //returns the Max amount of the HP the fighter can have
 *     cout << Wiz           // displays all relevant information about the fighter
 *                          // on sreeen
 *   
 *    
*/ 
class Wizard : public BaseFighter{
private: 
  int HP;
  double RR;
public:
/**
 * Public : Wizard
 *
 * Description:
 *        
 *    Default constructor to create a Wizard fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
  Wizard(){
    name = "Wizard";
    HP = (rand()%8+3);
    MaxHP = HP;
    RR = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%4+1);
    if(WD==1){
      weapon = new Weapon("Magic","1.d.20");
      }
    else if (WD==2){
      weapon = new Weapon("Magic","2.d.10");
    }  
    else if (WD == 3){
      weapon = new Weapon("Magic","3.d.6");
    }
    else{
      weapon = new Weapon("Magic","5.d.4");
    }
  }
// all overriden methods from the BaseFighter Class
double attack(){
  return weapon->use();
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getRR(){
  return RR;
}
bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int getspeed(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
};
/**
 * Archer: Public BaseFighter
 * 
 * Description: 
 *     This is a Archer fighter class that is derived from the Base Fighter class
 *     and overrides all the methods of BaseFighter
 * 
 * Public Methods
 *                        Archer()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getRR()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *                            
 * 
 * Private Methods:   
 *        int             HP
 *        double          RR 
 * 
 * Usage:
 *     Archer Arc()           //created a Archer fighter
 *     Arc.attack()          // uses the fighter's weapon
 *     Arc.getHP()           // returns the current HP of fighter
 *     Arc.setHP(10)         // sets the HP of the fighter to 10
 *     Arc.setHP(10.01)      // sets the HP using a double
 *     Arc.getRR()           // returns the Regeneration Rate of fighter
 *     Arc.getname()         //returns the name of the fighter
 *     Arc.isAlive()         //checks if the fighter's HP is 0 or not
 *     Arc.getspeed()        //returns the speed of the fighter
 *     Arc.getMaxHP()        //returns the Max amount of the HP the fighter can have
 *     cout << Arc           // displays all relevant information about the fighter
 *                          // on sreeen
 *   
 *    
*/ 
class Archer : public BaseFighter{
private: 
  int HP;
  double RR;
public:
/**
 * Public : Wizard
 *
 * Description:
 *        
 *    Default constructor to create a Archer fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
  Archer(){
    srand(time(0));
    name = "Archer";
    HP = (rand()%8+3);
    MaxHP = HP;
    RR = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%3+1);
    
    if(WD==1){
      weapon = new Weapon("Bow","1.d.8");
      }
    else if (WD==2){
      weapon = new Weapon("Bow","2.d.4");
    }  
    else{
      weapon = new Weapon("Bow","1.d.10");
    }
  }
// overridden methods of the Base Fighter
double attack(){
  return weapon->use();
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getRR(){
  return RR;
}
bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int getspeed(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
};
/**
 * Elf: Public BaseFighter
 * 
 * Description: 
 *     This is a Elf fighter class that is derived from the Base Fighter class
 *     and overrides all the methods of BaseFighter but adds another weapon 
 * 
 * Public Methods
 *                        Elf()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getRR()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *     string             Print()                        
 * 
 * Private Methods:   
 *        int             HP
 *        double          RR 
 *        Weapon          *weapon2
 * 
 * Usage:
 *     Elf El()               //created a Elf fighter
 *     El.attack()          // uses the fighter's weapon
 *     El.getHP()           // returns the current HP of fighter
 *     El.setHP(10)         // sets the HP of the fighter to 10
 *     El.setHP(10.01)      // sets the HP using a double
 *     El.getRR()           // returns the Regeneration Rate of fighter
 *     El.getname()         //returns the name of the fighter
 *     El.isAlive()         //checks if the fighter's HP is 0 or not
 *     El.getspeed()        //returns the speed of the fighter
 *     El.getMaxHP()        //returns the Max amount of the HP the fighter can have
 *     cout << El           // displays all relevant information about the fighter
 *                          // on sreeen
 *   
 *    
*/ 
class Elf : public BaseFighter{
private: 
  int HP;
  double RR;
  Weapon *weapon2;
public:
  Elf(){
/**
 * Public : Elf
 *
 * Description:
 *        
 *    Default constructor to create an Elf fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
    name = "Elf";
    HP = (rand()%8+3);
    MaxHP = HP;
    RR = RR = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%4+1);
    if(WD==1){
      weapon = new Weapon("Magic","1.d.20");
      }
    else if (WD==2){
      weapon = new Weapon("Magic","2.d.10");
    }  
    else if (WD == 3){
      weapon = new Weapon("Magic","3.d.6");
    }
    else{
      weapon = new Weapon("Magic","5.d.4");
    }
    int WD2 = (rand()%2+1);
    if(WD2==1){
      weapon2 = new Weapon("Sword","1.d.4");
      }
    else{
      weapon2 = new Weapon("Sword","1.d.6");
    } 

  }
/**
 * Public : attack
 *
 * Description:
 *        
 *    uses the fighter's weapon and returns the damage dealt. Since
 *    Elf has two weapons it combines the damage of both weapons
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     double      :the damage dealt
 */ 
double attack(){
  return (weapon->use()+weapon2->use());
}
//overridden methods from BaseFighter clsss
int getHP(){
  return HP;
}
void setHP(double h){
  HP = h;
}
void setHP(int h){
  HP = h;
}
double getRR(){
  return RR;
}
bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
int getspeed(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
/**
 * Public : Print
 *
 * Description:
 *        
 *    Methods creates a string with all the relevant information of the 
 *    fighter in a specified format [name,[weapon 1 name,weapon1 damage],[weapon 2 name,
 *    weapon 2 damage]]
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     string      :The resulting string
 */
 string Print(){
      string temp = "";
      temp += "["; 
      temp += name;
      temp+= " , ";
      temp+= "[";
      temp+= weapon->getName();
      temp+=" , ";
      temp+= weapon->getDamage();
      temp+= "]";
      temp+= "[";
      temp+= weapon2->getName();
      temp+=" , ";
      temp+= weapon2->getDamage();
      temp+= "]";
      temp+= "]";
      return temp;
    }
};
/**
 * Dragonborn: Public BaseFighter
 * 
 * Description: 
 *     This is a Dragonborn fighter class that is derived from the Base Fighter class
 *     and overrides all the methods of BaseFighter but adds another weapon 
 * 
 * Public Methods
 *                        Dragonborn()
 *     double             attack()
 *     int                getHP()
 *     void               setHP(int h)
 *     void               setHP(double h)
 *     double             getRR()
 *     string             getname()
 *     bool               isAlive()
 *     int                getspeed()
 *     MaxHp              getMaxHP()
 *     friend double      fRand(double,double)
 *     string             Print()                        
 * 
 * Private Methods:   
 *        int             HP
 *        double          RR 
 *        Weapon          *weapon2
 * 
 * Usage:
 *     Dragronborn DB()     //created a Dragonborn fighter
 *     DB.attack()          // uses the fighter's weapon
 *     DB.getHP()           // returns the current HP of fighter
 *     DB.setHP(10)         // sets the HP of the fighter to 10
 *     DB.setHP(10.01)      // sets the HP using a double
 *     DB.getRR()           // returns the Regeneration Rate of fighter
 *     DB.getname()         //returns the name of the fighter
 *     DB.isAlive()         //checks if the fighter's HP is 0 or not
 *     DB.getspeed()        //returns the speed of the fighter
 *     DB.getMaxHP()        //returns the Max amount of the HP the fighter can have
 *     cout << DB           // displays all relevant information about the fighter
 *                          // on sreeen   
*/
class Dragonborn: public BaseFighter{
private: 
  int HP;
  double RR;
  Weapon *weapon2;
public:
/**
 * Public : Dragonborn
 *
 * Description:
 *        
 *    Default constructor to create an Dragonborn fighter 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
  Dragonborn(){
    name = "DragonBorn";
    HP = (rand()%8+3);
    MaxHP = HP;
    RR = fRand(0.15,0.75);
    speed = rand()%10+1;
    int WD = (rand()%4+1);
    if(WD==1){
      weapon = new Weapon("Magic","1.d.20");
      }
    else if (WD==2){
      weapon = new Weapon("Magic","2.d.10");
    }  
    else if (WD == 3){
      weapon = new Weapon("Magic","3.d.6");
    }
    else{
      weapon = new Weapon("Magic","5.d.4");
    }
    int WD2 = (rand()%2+1);
    if(WD2==1){
      weapon2 = new Weapon("Fire","1.d.6");
      }
    else{
      weapon2 = new Weapon("Fire","1.d.8");
    } 

  }
//overridden method from BaseFighter
bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
/**
 * Public : attack
 *
 * Description:
 *        
 *    uses the fighter's weapon and returns the damage dealt. Since
 *    Dragonborn has two weapons it combines the damage of both weapons
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     double      :the damage dealt
 */ 
double attack(){
  return (weapon->use()+weapon2->use());
}
int getHP(){
  return HP;
}
void setHP(int h){
  HP = h;
}
void setHP(double h){
  HP = h;
}
double getRR(){
  return RR;
}
int getspeed(){
  return speed;
}
int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
/**
 * Public : Print
 *
 * Description:
 *        
 *    Methods creates a string with all the relevant information of the 
 *    fighter in a specified format [name,[weapon 1 name,weapon1 damage],[weapon 2 name,
 *    weapon 2 damage]]
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     string      :The resulting string
 */
string Print(){
      string temp = "";
      temp += "["; 
      temp += name;
      temp+= " , ";
      temp+= "[";
      temp+= weapon->getName();
      temp+=" , ";
      temp+= weapon->getDamage();
      temp+= "]";
      temp+= "[";
      temp+= weapon2->getName();
      temp+=" , ";
      temp+= weapon2->getDamage();
      temp+= "]";
      temp+= "]";
      return temp;
    }
};
/**
 * Attackers
 * 
 * Description: 
 *     This is a class uses a vector containing a group of BaseFighter Pointers then 
 *     points these pointers to a fighter class (dynamic polymorphispm) and fills the 
 *     vector with these pointers to create a group of attackers 
 * 
 * Public Methods
 *                        Attackers()                      
 *                        Attackers(int s)
 *                        Attackers(ifstream& in)
 *    BaseFighter&        operator[](int index)
 *    int                 Size()
 *    void                remove()
 *    void                regen()
 * 
 * Private Methods:   
 *    vector<BaseFighter *>     attackers
 *    int                       Warcount
 *    int                       Wizcount
 *    int                       Archcount
 *    int                       Elfcount
 *    int                       DBcount
 *    int                       size
 * Usage:
 *    
 *    Attackers att             //create attacker group of default size of 1000
 *    Attacker  att(100)        //create attacker group of size 100
 *    Attacker  att(infile)     //creates attacker group from data in input file
 *    att.Size()                //displays the current amount of attackers in the group
 *    att.remove()              //removes the first attacker from the group
 *    att.regen()               //gives HP back to the attacker in the front
 *    att[0]                    // accessing the first element of the group of attackers
 *     
*/
class Attackers{
private:
vector<BaseFighter *> attackers;
int Warcount;
int Wizcount;
int Archcount;
int Elfcount;
int DBcount;
int size;
protected:
public:
/**
 * Public : Attackers
 *
 * Description:
 *        
 *    Default constructor of the attacker class that fills the vector 
 *    with 1000 elements and varies the types of fighter based on a ratio
 *    then randomizes the group
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
Attackers(){
  srand(time(0));
  Warcount = 1000*0.35;
  Archcount = 1000*0.35;
  Wizcount = 1000*0.20;
  Elfcount = 1000*0.05;
  DBcount = 1000*0.05;
  for(int i = 0; i < Warcount; i++){
    attackers.push_back(new Warrior);
  }
  for(int i = 0; i < Archcount; i++){
    attackers.push_back(new Archer);
  }
  for(int i = 0; i < Wizcount; i++){
    attackers.push_back(new Wizard);
  }
  for(int i = 0; i < Elfcount; i++){
    attackers.push_back(new Elf);
  }
  for(int i = 0; i < DBcount; i++){
    attackers.push_back(new Dragonborn);
  }
  size = attackers.size();
  random_shuffle(attackers.begin(),attackers.end());
}
/**
 * Public : Attackers
 *
 * Description:
 *        
 *    Default constructor of the attacker class that fills the vector 
 *    with a given number of elements and varies the types of fighter based on a ratio
 *    then randomizes the group
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
Attackers(int s){
  srand(time(0));
  Warcount = s*0.35;
  Archcount = s*0.35;
  Wizcount = s*0.20;
  Elfcount = s *0.05;
  DBcount = s *0.05;
  for(int i = 0; i < Warcount; i++){
    attackers.push_back(new Warrior);
  }
  for(int i = 0; i < Archcount; i++){
    attackers.push_back(new Archer);
  }
  for(int i = 0; i < Wizcount; i++){
    attackers.push_back(new Wizard);
  }
  for(int i = 0; i < Elfcount; i++){
    attackers.push_back(new Elf);
  }
  for(int i = 0; i < DBcount; i++){
    attackers.push_back(new Dragonborn);
  }
  size = attackers.size();
  random_shuffle(attackers.begin(),attackers.end());
}
/**
 * Public : Attackers
 *
 * Description:
 *        
 *    Default constructor of the attacker class that fills the vector 
 *    with data from an input file and varies the types of fighter based on a ratio
 *    then randomizes the group
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
Attackers(ifstream& in){
  string fighter;
  in >> fighter;
  while(!in.eof()){
    if(fighter == "Warrior"){
      Warcount++;
    }
    else if(fighter == "Archer"){
      Archcount++;
    }
    else if(fighter == "Wizard"){
      Wizcount++;
    }
    else if(fighter == "Elf"){
      Elfcount++;
    }
    else{
      DBcount++;
    }
    in>>fighter;
  }
  for(int i = 0; i < Warcount; i++){
    attackers.push_back(new Warrior);
  }
  for(int i = 0; i < Archcount; i++){
    attackers.push_back(new Archer);
  }
  for(int i = 0; i < Wizcount; i++){
    attackers.push_back(new Wizard);
  }
  for(int i = 0; i < Elfcount; i++){
    attackers.push_back(new Elf);
  }
  for(int i = 0; i < DBcount; i++){
    attackers.push_back(new Dragonborn);
  }
  size = attackers.size();
  random_shuffle(attackers.begin(),attackers.end());
  
}
/**
 * Public : operator[]
 *
 * Description:
 *        
 *   Overloading the [] operators to access the elements
 *   using the class name similarly to an array
 * 
 * Params:
 *      int     index
 *
 * Returns:
 *     Basefighter&     the address of the fighter in storage
 */
 BaseFighter& operator[](int index){
   
   if(index > attackers.size()){
     cout << "invalid index";
     return *attackers[0];
     
   }
   else{
    
     return *attackers[index];
   }
 }
 /**
 * Public : Size
 *
 * Description:
 *        
 *   returns the size of the attacker group
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     int      the size of the group of attackers
 */
int Size(){
  return attackers.size();
}
/**
 * Public : remove
 *
 * Description:
 *        
 *   removes the first element from the vector
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
void remove(){
  if(attackers.size()==1){
    attackers.pop_back();
  }
  else{
    attackers.erase(attackers.begin());
  } 
}
/**
 * Public : regen
 *
 * Description:
 *        
 *   gives HP back to the attacker at the front of the group based on its
 *   regeneration rate
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
void regen(){
  if(attackers.front()->getHP()<attackers.front()->getMaxHP()){
    attackers.front()->setHP((int)(attackers.front()->getHP()+(attackers.front()->getHP()*attackers.front()->getRR())));
    if(attackers.front()->getHP()>attackers.front()->getMaxHP()){
      attackers.front()->setHP(attackers.front()->getMaxHP());
    }
  }
}
};
/**
 * Attackers
 * 
 * Description: 
 *     This is a class uses a vector containing a group of BaseFighter Pointers then 
 *     points these pointers to a fighter class (dynamic polymorphispm) and fills the 
 *     vector with these pointers to create a group of defenders and this group of 
 *    defenders are based on the size of the group of attackers 100 attackers to 1 
 *    defenders
 * 
 * Public Methods
 *                        Defender()                      
 *                        Defender(int n)
 *    BaseFighter&        operator[](int index)
 *    int                 Size()
 *    void                remove(int i)
 *    void                regen()
 * 
 * Private Methods:   
 *    vector<BaseFighter *>     attackers
 *    int                       size
 * Usage:
 *    
 *    Defender  def             //create def group of default size of 10 (1000/10)
 *    Defender  def(100)        //create attacker group of size of (100/100)
 *    def.Size()                //displays the current amount of defenders in the group
 *    def.remove(0)              //removes the first defenders from the group
 *    def.regen()               //gives HP back to the defenders in the front
 *    def[0]                    // accessing the first element of the group of defenders
 *     
*/
class Defender{
private: 
vector <BaseFighter *> defender;
int size;
protected:
public:
/**
 * Public : Defender
 *
 * Description:
 *        
 *    Default constructor of the defender class that fills the vector 
 *    with 1000/10 elements and varies the types of fighter are random
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
Defender(){
  size = 1000/100;
  int select;
  for(int i = 0; i < size; i++){
    select = rand()%5+1;
    if(select == 1){
      defender.push_back(new Warrior);
    }
    else if(select == 2){
      defender.push_back(new Wizard);
    }
    else if(select == 3){
      defender.push_back(new Archer);
    }
    else if(select == 4){
      defender.push_back(new Elf);
    }
    else{
      defender.push_back(new Dragonborn);
    }
  }
  size = defender.size();
  random_shuffle(defender.begin(), defender.end());
}
/**
 * Public : Defender
 *
 * Description:
 *        
 *    Default constructor of the defender class that fills the vector 
 *    with n/10 elements and varies the types of fighter are random
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
Defender(int n){
  size = n/100;
  int select;
  for(int i = 0; i < size; i++){
    select = rand()%5+1;
    if(select == 1){
      defender.push_back(new Warrior);
    }
    else if(select == 2){
      defender.push_back(new Wizard);
    }
    else if(select == 3){
      defender.push_back(new Archer);
    }
    else if(select == 4){
      defender.push_back(new Elf);
    }
    else{
      defender.push_back(new Dragonborn);
    }
  }
  size = defender.size(); 
  random_shuffle(defender.begin(), defender.end());
}
/**
 * Public : operator[]
 *
 * Description:
 *        
 *   Overloading the [] operators to access the elements
 *   using the class name similarly to an array
 * 
 * Params:
 *      int     index
 *
 * Returns:
 *     Basefighter&     the address of the fighter in storage
 */
BaseFighter& operator[](int index){
   
   if(index > defender.size()){
     cout << "invalid index";
     return *defender[0];
     
   }
   else{
    
     return *defender[index];
   }
 }
  /**
 * Public : Size
 *
 * Description:
 *        
 *   returns the size of the defender group
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     int      the size of the group of attackers
 */
int Size(){
  return defender.size();
}
/**
 * Public : remove
 *
 * Description:
 *        
 *   removes an element from the group of defender based on the number 
 *  passed in 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
void remove(int i){
  if(defender.size()==1){
    defender.pop_back();
  }
  else{
    if(i <= 0){
      defender.erase(defender.begin());
    }
    else{
      defender.erase(defender.begin()+i);
    }
    
  } 
}
/**
 * Public : regen
 *
 * Description:
 *        
 *   gives HP back to the all the members of the defender group based on all of 
 *   thier own personal regeneration rates 
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *     N/A
 */
void regen(){
  for(int i = 0; i < defender.size(); i++){
    if(defender[i]->getHP()<defender[i]->getMaxHP()){
   defender[i]->setHP((int)(defender[i]->getHP()+(defender[i]-> getHP()*defender[i]->getRR())));
    if(defender[i]->getHP()>defender[i]->getMaxHP()){
      defender[i]->setHP(defender[i]->getMaxHP());
    }
  }
  }
}
};

