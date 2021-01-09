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

int chooseOption();

//Shows the main menu
void displayMainMenu();

//Shows what are the options for level one
void displayLevelOneOptions();

//Shows what are the options for level two
void displayLevelTwoOptions();

int displayGameOverview();

void spaces(int n);

void displayGreeting();