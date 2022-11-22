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
*		This Hpp file contains function that allows for a string to be 
*       vector and get split based on a delimiter. The vector can be passed
*       into a function/method so that the seperate information in the string 
*       can be used. Example the tokenize function creates a string like -> [2.d.4] 
*       and that string can be passed into the dice class methods to create 
*       a set of die.
*
*  Usage:
*        N/A
*
*  Files:
*           helper.hpp          :contains functions to tokenize a string
*
*****************************************************************************/
// neccesary Libraries
#include <iostream>
#include <vector>
#include <random>
#include <string>

//using namespace std
using namespace std;

#pragma once
/**
 * Public : tokenize
 *
 * Description:
 *        
 *     Splits a string into parts based on a delimiter
 *
 *      For example the string: "2.d.12" would be turned into 
 *      a vector => ["2","d","12"] and returned
 * 
 * Params:
 *      string      s
 *      string      delimiter
 *
 * Returns:
 *      vector<string>      the tokenize string 
 */
vector<string> tokenize(string s,string delimiter){
    size_t pos = 0;
    vector<string> tokens;
    while ((pos = s.find(delimiter)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens;
}
/**
 * Public : randomChoice
 *
 * Description:
 *        
 *     Chooses a random item from a vector of strings
 * 
 *      Example: 
 *          given => ["1.d.4","1.d.6","1.d.8"]
 *          Choose one of the 3 choices at random and return it.
 * 
 * Params:
 *      vector<string>      choices
 *
 * Returns:
 *      string      the choice from the possible selection 
 */
string randomChoice(vector<string> choices){
    return choices[rand() % choices.size()];
}