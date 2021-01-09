#include <iostream>
#include "Data.h"
#include "Presentation.h"
using namespace std;

int chooseOption() {

    int choice;

    spaces(48);
    cout << "1) Return to the Main Menu" << endl;
    spaces(48);
    cout << "2) Exit" << endl << endl;
    cout << "Enter an option: ";

    choice = readInt();

    while (choice < 1 or choice>2) {
        cout << endl;
        cout << RED << "The number you enter has to be either 1 or 2! Please, try again: " << RESET;
        choice = readInt();
    }

    system("cls");

    return choice;
}

void displayMainMenu() {

    int choice = 0;

    while (choice != 4) {
        cout << endl;
        spaces(42); cout << " _________________________________" << endl;
        spaces(42); cout << "|                                 |" << endl;
        spaces(42); cout << "|         |  MAIN MENU  |         |" << endl;
        spaces(42); cout << "|                                 |" << endl;
        spaces(42); cout << "|  1) Level 1: Player vs Player   |" << endl;
        spaces(42); cout << "|  2) Level 2: Player vs Computer |" << endl;
        spaces(42); cout << "|  3) Show game description       |" << endl;
        spaces(42); cout << "|  4) Exit                        |" << endl;
        spaces(42); cout << "|_________________________________|" << endl;

        cout << endl;


        cout << "Enter an option: ";
        choice = readInt();

        while (choice > 4 or choice < 1) {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 4! Please, try again: " << RESET;
            choice = readInt();
        }


        system("cls");

        switch (choice) {
        case 1:
            displayLevelOneOptions();
            break;
        case 2:
            displayLevelTwoOptions();
            break;
        case 3:
            if (displayGameOverview() == 2)
                exit(0);
            break;
        case 4:
            exit(0);
            break;
        }
    }
}

void displayLevelOneOptions() {
    spaces(37); cout << " ___________________________________________" << endl;
    spaces(37); cout << "|                                           |" << endl;
    spaces(37); cout << "|                  LEVEL 1                  |" << endl;
    spaces(37); cout << "|                                           |" << endl;
    spaces(37); cout << "|          |  Player vs Player  |           |" << endl;
    spaces(37); cout << "|                                           |" << endl;
    spaces(37); cout << "|  1) Task 1: Play with Unrepeatable digits |" << endl;
    spaces(37); cout << "|  2) Task 2: Play with Repeatable digits   |" << endl;
    spaces(37); cout << "|  3) Return to the Main Menu               |" << endl;
    spaces(37); cout << "|  4) Exit                                  |" << endl;
    spaces(37); cout << "|___________________________________________|" << endl;

    cout << endl;

    int choice;
    cout << "Enter an option: ";
    choice = readInt();

    while (choice > 4 or choice < 1) {
        cout << endl;
        cout << RED << "The number you enter has to be between 1 and 4! Please, try again: " << RESET;
        choice = readInt();
    }

    int code[4];

    system("cls");

    switch (choice) {
    case 1:
        if (processlevelOne(code, false) == 2)
            exit(0);
        break;
    case 2:
        if (processlevelOne(code, true) == 2)
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

void displayLevelTwoOptions() {
    spaces(37); cout << " ___________________________________________" << endl;
    spaces(37); cout << "|                                           |" << endl;
    spaces(37); cout << "|                  LEVEL 2                  |" << endl;
    spaces(37); cout << "|                                           |" << endl;
    spaces(37); cout << "|         |  Player vs Computer  |          |" << endl;
    spaces(37); cout << "|                                           |" << endl;
    spaces(37); cout << "|  1) Task 1: Play with Unrepeatable digits |" << endl;
    spaces(37); cout << "|  2) Task 2: Play with Repeatable digits   |" << endl;
    spaces(37); cout << "|  3) Return to the Main Menu               |" << endl;
    spaces(37); cout << "|  4) Exit                                  |" << endl;
    spaces(37); cout << "|___________________________________________|" << endl;

    cout << endl;

    int choice;
    cout << "Enter an option: ";
    choice = readInt();

    while (choice > 4 or choice < 1) {
        cout << endl;
        cout << RED << "The number you enter has to be between 1 and 4! Please, try again: " << RESET;
        choice = readInt();
    }

    int code[4];

    system("cls");

    switch (choice) {
    case 1:
        if (processlevelTwo(code, false) == 2)
            exit(0);
        break;
    case 2:
        if (processlevelTwo(code, true) == 2)
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

int displayGameOverview() {
    cout << endl;
    spaces(25); cout << "                               GAME DESCRIPTION AND TIPS" << endl << endl;
    spaces(25); cout << "  The Germans place a combination of 4 random digits in the range between 0 and 7," << endl;
    spaces(25); cout << " indicating the coordinates of their battleships. The code breaker should guess the" << endl;
    spaces(25); cout << " number within 13 tries using the board. The codebreaker places their guesses. The" << endl;
    spaces(25); cout << "Germans should give a feedback whether only a number is guessed or a number and its" << endl;
    spaces(25); cout << "     position. If the code breaker reaches the 13th try and hasn't guessed the" << endl;
    spaces(25); cout << "                combination the game is over and The Germans win." << endl << endl << endl;
    spaces(25); cout << WHITE << "Tip 1: Input the digits with one space between each one while guessing!" << RESET << endl << endl;
    spaces(25); cout << WHITE << "Tip 2: If you are playing as the Germans, input the digits without spaces between them!" << RESET << endl << endl;
    spaces(25); cout << WHITE << "Tip 3: If you enter more numbers than you are required, the surplus numbers will be" << RESET << endl;
    spaces(25); cout << WHITE << "passed to the next input(s)!" << RESET << endl << endl;
    spaces(25); cout << WHITE << "Tip 4: You can quit guessing any time by entering the number 10!" << RESET << endl << endl << endl;
    return chooseOption();
}

void spaces(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

void displayGreeting() {
    spaces(42); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    spaces(42); cout << "|   Welcome to our Enigma game!  |" << endl;
    spaces(42); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}