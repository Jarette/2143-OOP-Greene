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
*		    This Hpp file contains class used to create the weapon that the 
*       fighter will be used. Contianing the name and damage that the 
*       weapon will do based on the roll of a specified set of dice
*
*  Usage:
*        N/A
*
*  Files:
*           helper.hpp          :contains functions to tokenize a string
*           dice.hpp            :contains classes to create dices
*           weapon.hpp          :contains the class to create the weapon used by the fighters
*
*****************************************************************************/
//necessary Libraries
#include <iostream>
#include <string>
#include <vector>

#include "dice.hpp"
#include "helpers.hpp"

//using namespace standard
using namespace std;

#pragma once
/**
 * Weapon
 * 
 * Description: 
 *      This class is used to represent the weapons that the fighters
 *      will be using in the main driver. This class gives the name of
 *      and the damage the dice may be able to do based on a dice roll
 * 
 * Public Methods
 *                            Weapon()
 *                            Weapon(vector<string> choices)                
 *                            Weapon(string n, string d)
 *      double                use()
 *      string                getName()
 *      string                getDamage()
 *      friend ostream&       operator<<(ostream& os, const Weapon& w)
 * 
 * Private Methods:   
 *      string                   name
 *      string                   damage
 *      Dice*                    die
 * Usage:
 *      
 *      Weapon W1                     //creates a default weapon of Fist&Feet 
 *                                    // default damage
 *      Weapom W2("1.d.10","2.d.4")   //creates weapon that damage is random of 
 *                                    //the choices passed
 *      Weapon W3("Sword","1.d.10")   //creates a weapon with the parameters passed
 *      W3.use()                      // rolls the dice to return the damage dealt
 *                                    // by weapons
 *      W3.getName()                  // returns the name of the weapon
 *      W3.getDamage()                // returns the dice used for this weapon
 *      cout << W3                    // using ostream to output the name and damage
 *                                    // of the weapon
 *        
 *    
*/ 
class Weapon {
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice*  die;

public:
/**
 * Public : Weapon
 *
 * Description:
 *        
 *     Construct a new Base Weapon object
 *     Also invokes the Dice class constructor with the "die" type
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      N/A 
 */
    Weapon() {
        name = "Fists&Feet";
        damage = "1.d.4";
        die = new Dice(damage);
    }
/**
 * Public : Weapon
 *
 * Description:
 *        
 *     Overloaded Constructor for a new Base Weapon object
 *     Also invokes the Dice class constructor with the "die" type
 * 
 * Params:
 *      vector<string>          choices
 *
 * Returns:
 *      N/A 
 */
    Weapon(vector< string > choices) {
        name = "Fists&Feet";
        damage = randomChoice(choices);
        die = new Dice(damage);
    }
/**
 * Public : Weapon
 *
 * Description:
 *        
 *     Overloaded Constructor for a new Base Weapon object
 *     Also invokes the Dice class constructor with the "die" type
 * 
 * Params:
 *      string            n
 *      string            d
 *
 * Returns:
 *      N/A 
 */
    Weapon(string n, string d){
      name = n;
      damage = d;
      die = new Dice(damage);
    }
/**
 * Public : use
 *
 * Description:
 *        
 *     This method invokes the roll method of the weapon's
 *     die to give the damage that the weapon just dealt
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      double      :the results of the roll 
 */
    double use() {
        return die->roll();
    }
/**
 * Public : getName
 *
 * Description:
 *        
 *     This method returns the name of the weapon
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      string        : the name of the weapon
 */
    string getName(){
      return name;
    }
/**
 * Public : getDamage
 *
 * Description:
 *        
 *     This method returns the dice that corresponds to the weapon
 * 
 * Params:
 *      N/A
 *
 * Returns:
 *      string        : the kind of dice rolled for this weapo
 */
    string getDamage(){
      return damage;
    }
/**
 * Public : operator<<
 *
 * Description:
 *        
 *     overloaded the ostream operator to allow it to display the
 *     [name and damage] of the weapon using the << operators 
 * 
 * Params:
 *      ostream         &os
 *      Weapon&          w
 *
 * Returns:
 *      ostream&         what will be passed to ostream
 */
    friend ostream& operator<<(ostream& os, const Weapon& w) {
        return os << "[" << w.name << " , " << w.damage << "]";
    }
};