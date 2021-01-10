#pragma once
#include <stdlib.h>

struct RANDOM_CONTEXT {
	int* numbers = nullptr;
	int index = 0;
	int size = 0;
} *pFakeRandomInt;

int randomInt()
{
	return pFakeRandomInt->numbers[pFakeRandomInt->index++ % pFakeRandomInt->size];
}
