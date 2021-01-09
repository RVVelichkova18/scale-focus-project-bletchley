#pragma once
#include <string>
#include <conio.h>
#include <time.h>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[1;91m" 
#define GREEN   "\033[1;92m" 
#define YELLOW  "\033[1;93m"  
#define BLUE    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define WHITE   "\033[4;37m"

//Checks if the input is number
int readInt();

int* readIntGuess(int* code);

//Checks if the digits are from 0 to 7
bool checkInRange(int* code);

//Checks if there are repeating numbers 
bool checkForRepeatingNumbers(int* userGuess);

//Returns random number from 0 to 7
int randomInt();

//Returns array with random numbers that can be repeated
int* randomNumberWithRepetition(int* num);

//Returns array with random numbers that can't be repeated
int* randomNumberNoRepetition(int* num);

//Checks if there are numbers that are same and they are on the same position
int checkForSameNumberAndPosition(int* code, int* userGuess);

//Checks if trere are numbers that are same but they aren't on the same position
int checkOnlyForSameNumbers(int* code, int* userGuess);

//Makes you enter numbers until they fit the range
bool enterNumbersNoRep(int* code);

//Makes you enter numbers until they don't repeat
bool enterNumbersWithRep(int* code, bool rep);

void enterHidden(int* code);

void enterHiddenNoRep(int* code);

void processGuesses(int* code, bool rep);

int processlevelOne(int* code, bool rep);

int processlevelTwo(int* code, bool rep);
