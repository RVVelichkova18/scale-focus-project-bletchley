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
            cout << RED << MSG_INVALID_SYMBOL_TRY_AGAIN << RESET << RESET;
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

