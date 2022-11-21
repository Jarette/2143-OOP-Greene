#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "weapon.hpp"
#include "helpers.hpp"
#include <algorithm>
#include <cstdlib>

using namespace std;

#pragma once

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
class BaseFighter {
protected:

    string name;
    Weapon *weapon;
    int HP;
    double RR;
    int speed;
    int MaxHP;
public:
    BaseFighter() {
        name = "None";
        weapon = new Weapon;
    }

    virtual double attack(){
        return weapon->use();
    }
virtual int getHP(){
  return HP;
}
virtual void setHP(int h){
  HP = h;
}
virtual void setHP(double h){
  HP = h;
}
virtual double getRR(){
  return RR;
}
virtual string getname(){
  return name;
}
virtual bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}
virtual int getspeed(){
  return speed;
}
virtual int getMaxHP(){
  return MaxHP;
}
friend double fRand(double, double);
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

 friend ostream& operator<<(ostream& os, BaseFighter& f) {
        return os << f.Print();
    }


};

class Warrior : public BaseFighter{
private: 
  int HP;
  double RR;
public:
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

class Wizard : public BaseFighter{
private: 
  int HP;
  double RR;
public:
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

class Archer : public BaseFighter{
private: 
  int HP;
  double RR;
public:
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
class Elf : public BaseFighter{
private: 
  int HP;
  double RR;
  Weapon *weapon2;
public:
  Elf(){
   
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

double attack(){
  return (weapon->use()+weapon2->use());
}
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

class Dragonborn: public BaseFighter{
private: 
  int HP;
  double RR;
  Weapon *weapon2;
public:
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
bool isAlive(){
  if(HP<=0){
    return false;
  }
  else{
    return true;
  }
}

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
 BaseFighter& operator[](int index){
   
   if(index > attackers.size()){
     cout << "invalid index";
     return *attackers[0];
     
   }
   else{
    
     return *attackers[index];
   }
 }
int Size(){
  return attackers.size();
}
void remove(){
  if(attackers.size()==1){
    attackers.pop_back();
  }
  else{
    attackers.erase(attackers.begin());
  } 
}
void regen(){
  if(attackers.front()->getHP()<attackers.front()->getMaxHP()){
    attackers.front()->setHP((int)(attackers.front()->getHP()+(attackers.front()->getHP()*attackers.front()->getRR())));
    if(attackers.front()->getHP()>attackers.front()->getMaxHP()){
      attackers.front()->setHP(attackers.front()->getMaxHP());
    }
  }
}
};
class Defender{
private: 
vector <BaseFighter *> defender;
int size;
protected:
public:
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
BaseFighter& operator[](int index){
   
   if(index > defender.size()){
     cout << "invalid index";
     return *defender[0];
     
   }
   else{
    
     return *defender[index];
   }
 }
int Size(){
  return defender.size();
}
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
