#include "pch.h"
#include "CppUnitTest.h"
#include "../scale-focus-project-bletchley/Data.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTests
{
	TEST_CLASS(checkNumbersUnitTests)
	{
	public:

		TEST_METHOD(shouldReturnCountOfHowManyNumbersWithPositionsAreGuessed)
		{
			int testDataRight[] = { 3, 5, 2, 7 };
			int testDataGuess[] = { 4, 5, 2, 1 };

			int result = checkForSameNumberAndPosition(testDataRight, testDataGuess);

			//Expected: 2 numbers (5, 2) from the test data
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(shouldReturnCountOfHowManyNumbersAreGuessedWithoutPositionBeingTheSame)
		{
			int testDataRight[] = { 3, 5, 2, 7 };
			int testDataGuess[] = { 7, 3, 2, 5 };

			int result = checkOnlyForSameNumbers(testDataRight, testDataGuess);

			//Expected: 3 numbers (7, 3, 5) from the test data
			Assert::AreEqual(3, result);
		}
	};
}
