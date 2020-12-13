#include <iostream>
#include <time.h>   
using namespace std;

int randomInt() {
    return rand() % (7 - 0 + 1) + 0;
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

int main() {
    srand(time(NULL));
}
