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
void outputResult(int* code, int* userGuess);


void displayMainMenu();
void displayLevelOneOptions();
void displayLevelTwoOptions();


int main() {
    srand(time(NULL));

    /*int code[4] = { 0,7,7,7 };
    int userGuess[4] = { 7,4,2,4 };

    outputResult(code, userGuess);
    
    for (int i = 0; i < 4; i++)
        cout << code[i] << " ";
    cout << endl;
  

    for (int i = 0; i < 4; i++)
        cout << userGuess[i] << " ";
    cout << endl;
    */

    int num[4], num1[4];
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
    }
}




int readInt() {

    int num;

    while (!(cin >> num)) {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl;
        cout << "You have to enter a whole number!" << endl;
        cout << endl;
    }

    return num;
}

bool checkInRange(int num) {
    if (num >= 0 and num <= 7)
        return true;
    return false;
}

bool checkForRepeatingNumbers(int* userGuess) {

    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < i; j++) {
            if (userGuess[i] == userGuess[j]) {
                return false;
            }
        }
    }

}


int randomInt() {
    return rand() % (7 - 0 + 1) + 0;
}

int* randomNumberWithRepetition(int* num) {

    for (int i = 0; i < 4; i++) {
        num[i] = randomInt();
    }

    return num;
}

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

void outputResult(int* code, int* userGuess)
{
    cout << "The count of guessed numbers which are at the same position as in the code is: " << checkForSameNumberAndPosition(code, userGuess) << endl;
    cout << "The count of guessed numbers which are not at the same position as in the code is: " << checkOnlyForSameNumbers(code, userGuess) << endl;
}






void displayMainMenu()
{
    cout << "___________________________________" << endl;
    cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "|   Welcome to our Enigma game!   |" << endl;
    cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "|                                 |" << endl;
    cout << "|  1) Level 1: Player vs Player   |" << endl;
    cout << "|  2) Level 2: Player vs Computer |" << endl;
    cout << "|  3) Exit                        |" << endl;
    cout << "|_________________________________|" << endl;
    int choice;
    cin >> choice;
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
    default:
        cout << "No such a option in the menu! Please try again!" << endl;
        break;
    }
}

void displayLevelOneOptions()
{
    cout << "_____________________________________________" << endl;
    cout << "|                  LEVEL 1                  |" << endl;
    cout << "|                                           |" << endl;
    cout << "|          |  Player vs Player  |           |" << endl;
    cout << "|                                           |" << endl;
    cout << "|  1) Task 1: Play with Unrepeatable digits |" << endl;
    cout << "|  2) Task 2: Play with Repeatable digits   |" << endl;
    cout << "|  3) Return to the Main Menu               |" << endl;
    cout << "|___________________________________________|" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        //WORK HERE
        break;
    case 2:
        //WORK HERE
        break;
    case 3:
        displayMainMenu();
        break;
    default:
        cout << "No such a option in the menu! Please try again!" << endl;
        break;
    }

}

void displayLevelTwoOptions()
{
    cout << "_____________________________________________" << endl;
    cout << "|                  LEVEL 2                  |" << endl;
    cout << "|                                           |" << endl;
    cout << "|         |  Player vs Computer  |          |" << endl;
    cout << "|                                           |" << endl;
    cout << "|  1) Task 1: Play with Unrepeatable digits |" << endl;
    cout << "|  2) Task 2: Play with Repeatable digits   |" << endl;
    cout << "|  3) Return to the Main Menu               |" << endl;
    cout << "|___________________________________________|" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        //WORK HERE
        break;
    case 2:
        //WORK HERE
        break;
    case 3:
        displayMainMenu();
        break;
    default:
        cout << "No such a option in the menu! Please try again!" << endl;
        break;
    }

}