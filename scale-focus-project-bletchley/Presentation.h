#pragma once
#include <string>
#include <conio.h>
#include <time.h>
using namespace std;

int chooseOption();

//Makes you enter numbers until they fit the range
bool enterNumbersNoRep(int* code);

//Makes you enter numbers until they don't repeat
bool enterNumbersWithRep(int* code, bool rep);

void enterHidden(int* code);

void enterHiddenNoRep(int* code);

void processGuesses(int* code, bool rep);

int processlevelOne(int* code, bool rep);

int processlevelTwo(int* code, bool rep);

//Shows the main menu
void displayMainMenu();

//Shows what are the options for level one
void displayLevelOneOptions();

//Shows what are the options for level two
void displayLevelTwoOptions();

int displayGameOverview();

void spaces(int n);

void displayGreeting();