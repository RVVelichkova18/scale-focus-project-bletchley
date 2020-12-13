#include <iostream>
#include <time.h>   
using namespace std;

int randomInt() {
    return rand() % (7 - 0 + 1) + 0;
}


int main() {
    srand(time(NULL));
}
