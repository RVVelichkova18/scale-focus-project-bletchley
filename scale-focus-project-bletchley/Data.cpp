#include <iostream>
#include "Data.h"
#include "Presentation.h"
using namespace std;

int readInt(istream& input, ostream& output)
{

    int num;

    while (!(input >> num)) 
    {
        input.clear();
        input.ignore(INT_MAX, '\n');
        output << endl;
        output << RED << MSG_INVALID_SYMBOL_TRY_AGAIN << RESET;
    }

    return num;

}

int* readIntGuess(int* code)
{

    int index = 0;

    while (index < 4) 
    {
        while (!(cin >> code[index])) 
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl;
            cout << RED << "You have to enter a digit! Please, try again: " << RESET;
            index = 0;
        }

        index++;
        
    }

    return code;
}

bool checkInRange(int* code)
{
    for (int i = 0; i < 4; i++) 
    {
        if (code[i] < 0 or code[i] > 7) 
        {

            return false;
        }
    }
    return true;
}

bool checkForRepeatingNumbers(int* userGuess) 
{

    for (int i = 1; i < 4; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (userGuess[i] == userGuess[j]) 
            {
                return true;
            }
        }
    }

    return false;
}

int randomInt() 
{
    return rand() % (7 - 0 + 1) + 0;
}

int* randomNumberWithRepetition(int* num) 
{

    for (int i = 0; i < 4; i++) 
    {
        num[i] = randomInt();
    }

    return num;
}

int* randomNumberNoRepetition(int* num) 
{

    num[0] = randomInt();

    bool noRep;

    for (int i = 1; i < 4; i++) 
    {

        noRep = false;

        while (noRep == false) 
        {

            int check = 0;

            num[i] = randomInt();

            for (int j = 0; j < i; j++) 
            {

                if (num[i] != num[j]) 
                {
                    check++;
                }
            }

            if (check == i)
            {
                noRep = true;
            }
        }

    }

    return num;
}

int checkForSameNumberAndPosition(int* code, int* userGuess) 
{
    int count = 0;

    for (int i = 0; i < 4; i++) 
    {
        if (code[i] == userGuess[i]) 
        {
            count++;
            userGuess[i] = userGuess[i] * (-1);
        }
    }

    return count;
}

int checkOnlyForSameNumbers(int* code, int* userGuess) 
{
    int count = 0;

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if (code[i] == userGuess[j] and i != j and code[i] != abs(userGuess[i])) 
            {
                count++;
                userGuess[j] = userGuess[j] * (-1);
                break;
            }
        }
    }

    return count;
}

bool enterNumbersNoRep(int* code) 
{

    bool quit = false;

    readIntGuess(code);

    for (int i = 0; i < 4; i++) 
    {
        if (code[i] == 10) 
        {
            quit = true;
            break;
        }
    }

    if (quit == false) 
    {
        while (checkInRange(code) == false) 
        {
            cout << endl;
            cout << RED << "You have to enter a digit between 0 and 7! Please, try again: " << RESET;
            readIntGuess(code);
        }
    }

    cout << endl;

    return quit;
}

bool enterNumbersWithRep(int* code, bool rep) 
{

    bool quit = enterNumbersNoRep(code);

    if (quit == false) 
    {
        if (rep == false) 
        {
            while (checkForRepeatingNumbers(code) == true) 
            {
                cout << RED << "There must not be repeating digits! Please, try again: " << RESET;
                enterNumbersNoRep(code);
            }
        }
    }

    return quit;
}

void enterHidden(int* code) 
{
    string strCode = "";
    int digit;

    while (strCode.size() < 4) 
    {

        digit = _getch();
        cout << YELLOW << '*' << RESET;

        while (digit < 48 or digit>57) 
        {
            cout << endl;
            strCode = "";
            cout << endl << RED << "You have to enter a digit! Please, try again: " << RESET;
            digit = _getch();
            cout << YELLOW << '*' << RESET;
        }

        while (digit > 55) 
        {
            cout << endl;
            strCode = "";
            cout << endl << RED << "You have to enter a digit between 0 and 7! Please, try again: " << RESET;
            digit = _getch();
            cout << YELLOW << '*' << RESET;
        }

        strCode.push_back(digit);

        cout << " ";

    }

    cout << endl;

    for (int i = 0; i < 4; i++) 
    {
        code[i] = strCode[i] - 48;
    }
}

void enterHiddenNoRep(int* code) 
{

    enterHidden(code);

    while (checkForRepeatingNumbers(code) == true) 
    {
        cout << endl << RED << "There must not be repeating digits! Please, try again: " << RESET;
        enterHidden(code);
    }
}

void processGuesses(int* code, bool rep) 
{
    int guesses = 0, cows, bulls = 0;
    int userInput[4];
    bool quit;

    cout << endl;

    spaces(49);
    cout << BLUE << "PLAYER (THE ALLIANCE)" << RESET << endl << endl;

    spaces(39);
    cout << "(Enter WITH spaces between the digits!)" << endl << endl;

    while (guesses < 13 and bulls < 4) 
    {
        guesses++;

        cout << " ----------" << endl;
        cout << "| GUESS #" << guesses << " |" << endl;
        cout << " ----------" << endl;

        cout << endl;

        cout << "Enter 4 digits: ";

        quit = enterNumbersWithRep(userInput, rep);

        if (quit == true) 
        {

            spaces(45);
            cout << "You've chosen to quit guessing!" << endl << endl;
            break;
        }

        bulls = checkForSameNumberAndPosition(code, userInput);
        cows = checkOnlyForSameNumbers(code, userInput);


        spaces(32);

        cout << "Guessed numbers: " << cows << "     " << "Guessed numbers and positions: " << bulls << endl << endl << endl;

    }

    cout << endl;

    if (bulls == 4) 
    {
        spaces(24);
        cout << GREEN << "CONGRATULATIONS! You cracked the code! Now we know the coordinates of" << endl;
        spaces(18);
        cout << "the German battleships and will be able to destroy them once and for all! Great job!" << RESET << endl << endl;
    }
    else 
    {
        spaces(18);
        cout << RED << "OH NO! You didn't crack the code (it was";
        for (int i = 0; i < 4; i++) {
            cout << " " << code[i];
        }
        cout << ")! We still know nothing about the German " << endl;
        spaces(14);
        cout << "battleships' coordinates. But this war isn't over yet... we still have a chance of saving the world." << RESET << endl << endl;
    }
    cout << endl;
}

int processlevelOne(int* code, bool rep) 
{
    cout << endl;

    spaces(50);
    cout << PURPLE << "PLAYER (THE GERMANS)" << RESET << endl << endl;

    cout << "Enter 4 digits (without spaces between them): ";

    if (rep == true) 
    {
        enterHidden(code);
    }
    else 
    {
        enterHiddenNoRep(code);
    }

    cout << endl;

    processGuesses(code, rep);

    return chooseOption();
}

int processlevelTwo(int* code, bool rep) 
{

    cout << endl;

    spaces(20);
    cout << "THE COORDINATES OF THE GERMANS ARE A 4 - DIGIT CODE! TRY TO GUESS IT AND SAVE US!";

    if (rep == true)
    {
        randomNumberWithRepetition(code);
    }
    else 
    {
        randomNumberNoRepetition(code);
    }

    cout << endl << endl << endl;

    processGuesses(code, rep);

    return chooseOption();
}