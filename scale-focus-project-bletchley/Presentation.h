#pragma once
#include <string>
#include <conio.h>
#include <time.h>
using namespace std;

//Makes you choose one of the two options
int chooseOption();

//Makes you enter numbers until they fit the range
bool enterNumbersNoRep(int* code);

//Makes you enter numbers until they don't repeat
bool enterNumbersWithRep(int* code, bool rep);

//Inputs the user code without displaying it
void enterHidden(int* code);

//Inputs the user code without displaying it and checks for repeating numbers
void enterHiddenNoRep(int* code);

//Counts digits that are or aren't on the same position and displays the result
void processGuesses(int* code, bool rep);

//Inputs the user's code and start playing level one of the game
int processlevelOne(int* code, bool rep);

//Generate random code and start playing level two of the game
int processlevelTwo(int* code, bool rep);

//Shows the main menu
void displayMainMenu();

//Shows what are the options for level one
void displayLevelOneOptions();

//Shows what are the options for level two
void displayLevelTwoOptions();

//Displays the rules of the game and some tips
int displayGameOverview();

//Displays multiple space characters
void spaces(int n);

//Displays greeting message
void displayGreeting();