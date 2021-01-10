#include <iostream>
#include "Data.h"
#include "Presentation.h"
#include "randomInt.h"
using namespace std;


int main()
{
    srand(time(NULL));

    displayGreeting();
    displayMainMenu();
}