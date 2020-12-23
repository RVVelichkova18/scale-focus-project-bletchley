#include <iostream>
#include <time.h>   
using namespace std;

int readInt();
bool checkInRange(int num);
bool checkForRepeatingNumbers(int* userGuess);

int randomInt();
int* randomNumberWithRepetition(int* num);
int* randomNumberNoRepetition(int* num);

int checkForSameNumberAndPosition(int* code, int* userGuess);
int checkOnlyForSameNumbers(int* code, int* userGuess);
//void outputResult(int* code, int* userGuess);

void displayMainMenu();
void displayLevelOneOptions();
void displayLevelTwoOptions();


//Checks if the input is number
int readInt() {

    int num;

    while (!(cin >> num)) {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl;
        cout << "You have to enter a number! Please try again: ";
    }
 
    return num;
   
}

//Checks if the number is in the range from 0 to 7
bool checkInRange(int num) {
    if (num >= 0 and num <= 7)
        return true;
    return false;
}

//Checks if there are repeating numbers 
bool checkForRepeatingNumbers(int* userGuess) {

    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < i; j++) {
            if (userGuess[i] == userGuess[j]) {
                return true;
            }
        }
    }

    return false;
}


//Returns random number from 0 to 7
int randomInt() {
    return rand() % (7 - 0 + 1) + 0;
}

//Returns array with random numbers that can be repeated
int* randomNumberWithRepetition(int* num) {

    for (int i = 0; i < 4; i++) {
        num[i] = randomInt();
    }

    return num;
}

//Returns array with random numbers that can't be repeated
int* randomNumberNoRepetition(int* num) {

    num[0] = randomInt();

    bool noRep;

    for (int i = 1; i < 4; i++) {

        noRep = false;

        while (noRep == false) {

            int check = 0;

            num[i] = randomInt();

            for (int j = 0; j < i; j++) {

                if (num[i] != num[j])
                    check++;
            }

            if (check == i)
                noRep = true;
        }

    }

    return num;
}


//Checks if there are numbers that are same and they are on the same position
int checkForSameNumberAndPosition(int* code, int* userGuess) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        if (code[i] == userGuess[i]) {
            count++;
            userGuess[i] = userGuess[i] * (-1);
        }
    }

    return count;
}

//Checks if trere are numbers that are same but they aren't on the same position
int checkOnlyForSameNumbers(int* code, int* userGuess) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (code[i] == userGuess[j] and i != j and code[i] != abs(userGuess[i])) {
                count++;
                userGuess[j] = userGuess[j] * (-1);
                break;
            }
        }
    }

    return count;
}

//Makes you enter numbers until they fit the range
void enterNumbers(int* code) {
    cout << endl;
    cout << "Enter 4 digits: ";

    for (int i = 0; i < 4; i++)
    {
        
        code[i] = readInt();
        while (code[i] < 0 or code[i]>7)
        {
            cout << endl;
            cout << "The digits you enter have to be between 0 and 7! Please try again: ";
            code[i] = readInt();
        }
    }

    cout << endl;
}

//Makes you enter numbers until they don't repeat
void enterCode(int* code, bool rep) {
    enterNumbers(code);
    if (rep == false) {
        while (checkForRepeatingNumbers(code) == true) {
            cout << "There must not be repeating digits! Please, try again: ";
            enterNumbers(code);
        }
     }
}


void processGuesses(int* code, bool rep){
    int guesses = 0, cows, bulls = 0;
    int userInput[4];

    while (guesses < 13 and bulls < 4) {
        guesses++;
        cout << "Guess #" << guesses << endl;
        enterCode(userInput, rep);

        bulls = checkForSameNumberAndPosition(code, userInput);
        cows = checkOnlyForSameNumbers(code, userInput);

        cout << endl;

        cout << "Cows: " << cows << "     " << "Bulls: " << bulls << endl;

    }

    cout << endl;

    if (bulls == 4)
        cout << "YAY! You guessed the code!" << endl;
    else
        cout << "Oh, no! You didn't guess the code!" << endl;
    cout << endl;
}

int chooseOption() {

    int choice;

    cout << "Do you want to return to the main menu?" << endl << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl << endl;
    cout << "Enter an option: ";

    choice = readInt();
    while (choice < 1 or choice>2) {
        cout << endl;
        cout << "The number you enter has to be either 1 or 2! Please try again: ";
        choice = readInt();
    }

    system("cls");

    return choice;
}

//Count the number of guesses when player play vs player
int levelOne(int* code, bool rep) {

 enterCode(code, rep);
    
 processGuesses(code, rep);

 return chooseOption();
}

//Count the number of guesses when player play vs computer
int levelTwo(int* code, bool rep) {

    if (rep == true)
        randomNumberWithRepetition(code);
    else
        randomNumberNoRepetition(code);

    cout << endl;
    cout << "The program has generated 4 random digits";
    for (int i = 0; i < 4; i++) {
        cout << code[i] << " ";
    }
    cout << endl<<endl;

    processGuesses(code, rep);

    return chooseOption();
}

/*void outputResult(int* code, int* userGuess)
{
    cout << "The count of guessed numbers which are at the same position as in the code is: " << checkForSameNumberAndPosition(code, userGuess) << endl;
    cout << "The count of guessed numbers which are not at the same position as in the code is: " << checkOnlyForSameNumbers(code, userGuess) << endl;
}*/

//Shows the main menu
void displayMainMenu()
{ 
   
    int choice = 0;

    while (choice != 3) {
        cout << endl;
        cout << " _________________________________" << endl;
        cout << "|                                 |" << endl;
        cout << "|         |  MAIN MENU  |         |" << endl;
        cout << "|                                 |" << endl;
        cout << "|  1) Level 1: Player vs Player   |" << endl;
        cout << "|  2) Level 2: Player vs Computer |" << endl;
        cout << "|  3) Exit                        |" << endl;
        cout << "|_________________________________|" << endl;

        cout << endl;


        cout << "Enter an option: ";
        choice = readInt();

        while (choice > 3 or choice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 4! Please try again: ";
            choice = readInt();
        }


        system("cls");

        switch (choice)
        {
        case 1:
            displayLevelOneOptions();
            break;
        case 2:
            displayLevelTwoOptions();
            break;
        case 3:
            exit(0);
            break;
        }
    }
}

//Shows what are the options for level one
void displayLevelOneOptions()
{
    cout << endl;
    cout << "_____________________________________________" << endl;
    cout << "|                  LEVEL 1                  |" << endl;
    cout << "|                                           |" << endl;
    cout << "|          |  Player vs Player  |           |" << endl;
    cout << "|                                           |" << endl;
    cout << "|  1) Task 1: Play with Unrepeatable digits |" << endl;
    cout << "|  2) Task 2: Play with Repeatable digits   |" << endl;
    cout << "|  3) Return to the Main Menu               |" << endl;
    cout << "|  4) Exit                                  |" << endl;
    cout << "|___________________________________________|" << endl;

    cout << endl;

    int choice;
    cout << "Enter an option: ";
    choice = readInt();

    while (choice > 4 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 4! Please try again: ";
        choice = readInt();
    }

    int code[4];

    system("cls");

    switch (choice)
    {
    case 1:
        if (levelOne(code, false) == 2)
            exit(0);
        break;
    case 2:
        if (levelOne(code, true) == 2)
            exit(0);
        break;
    case 3:
        displayMainMenu();
        break;
    case 4:
        exit(0);
        break;
    }

}

//Shows what are the options for level two
void displayLevelTwoOptions()
{
    cout << endl;
    cout << "_____________________________________________" << endl;
    cout << "|                  LEVEL 2                  |" << endl;
    cout << "|                                           |" << endl;
    cout << "|         |  Player vs Computer  |          |" << endl;
    cout << "|                                           |" << endl;
    cout << "|  1) Task 1: Play with Unrepeatable digits |" << endl;
    cout << "|  2) Task 2: Play with Repeatable digits   |" << endl;
    cout << "|  3) Return to the Main Menu               |" << endl;
    cout << "|  4) Exit                                  |" << endl;
    cout << "|___________________________________________|" << endl;

    cout << endl;

    int choice;
    cout << "Enter an option: ";
    choice = readInt();

    while (choice > 4 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 4! Please try again: ";
        choice = readInt();
    }

    int code[4];

    system("cls");

    switch (choice)
    {
    case 1:
        if (levelTwo(code, false) == 2)
            exit(0);
        break;
    case 2:
        if (levelTwo(code, true) == 2)
            exit(0);
        break;
    case 3:
        displayMainMenu();
        break;
    case 4:
        exit(0);
        break;
    }

}

void displayGameOverview()
{
    cout << "The Germans place a combination of 4 random numbers in the range between 0 and 7," << endl;
    cout << "indicating the coordinates of their battleships.The code breaker should guess the" << endl;
    cout << "number within 13 tries using the board.The codebreaker places their guesses. The " << endl;
    cout << "Germans should give a feedback whether just a number is guessed or a number and is" << endl;
    cout << "on a correct place. If the code breaker reach the 13th try and hasn’t guessed the " << endl;
    cout << "combination the game is over and The Germans win." << endl;
}
int main() {
    srand(time(NULL));

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|   Welcome to our Enigma game!  |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    displayMainMenu();

    /*    int code[4] = { 1,2,2,2 };
   int userGuess[4] = { 1,2,3,2 };

   outputResult(code, userGuess);

   for (int i = 0; i < 4; i++)
       cout << code[i] << " ";
   cout << endl;


   for (int i = 0; i < 4; i++)
       cout << userGuess[i] << " ";
   cout << endl;
   */

   /*int num[4], num1[4];
   randomNumberWithRepetition(num);
   randomNumberNoRepetition(num1);

   for (int i = 0; i < 4; i++)
   {
       cout << num[i] << " ";
   }

   cout << endl<<endl;

   for (int i = 0; i < 4; i++)
   {
       cout << num1[i] << " ";
   }*/
}