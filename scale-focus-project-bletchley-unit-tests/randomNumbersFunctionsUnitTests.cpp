#include "pch.h"
#include "CppUnitTest.h"
#include "../scale-focus-project-bletchley/Data.h"
#include "randomInt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTests
{
	TEST_CLASS(randomNumbersFunctionsUnitTests)
	{
	public:

		TEST_METHOD(shouldReturnExpectedRandomNumbersWithRepetitions)
		{
			RANDOM_CONTEXT var = { new int[4]{1, 7, 7, 4}, 0, 4 };
			pFakeRandomInt = &var;

			int randomNumbers[4];
			randomNumberWithRepetition(randomNumbers);

			Assert::AreEqual(1, randomNumbers[0]);
			Assert::AreEqual(7, randomNumbers[1]);
			Assert::AreEqual(7, randomNumbers[2]);
			Assert::AreEqual(4, randomNumbers[3]);

			delete var.numbers;
			pFakeRandomInt = nullptr;
		}

		TEST_METHOD(shouldReturnExpectedUniqueRandomNumbersWithoutRepetitions)
		{
			RANDOM_CONTEXT var = { new int[4]{ 0, 3, 7, 4 }, 0, 4 };
			pFakeRandomInt = &var;

			int randNumbers[4];
			randomNumberNoRepetition(randNumbers);

			Assert::AreEqual(0, randNumbers[0]);
			Assert::AreEqual(3, randNumbers[1]);
			Assert::AreEqual(7, randNumbers[2]);
			Assert::AreEqual(4, randNumbers[3]);

			randomInt();

			delete var.numbers;
			pFakeRandomInt = nullptr;
		}

		TEST_METHOD(shouldReturnExpectedNonUniqueRandomNumbersWithoutRepetitions)
		{
			RANDOM_CONTEXT var = { new int[5]{ 0, 3, 3, 4, 5 }, 0, 5 };
			pFakeRandomInt = &var;

			int randNumbers[4];
			randomNumberNoRepetition(randNumbers);

			Assert::AreEqual(0, randNumbers[0]);
			Assert::AreEqual(3, randNumbers[1]);
			Assert::AreEqual(4, randNumbers[2]);
			Assert::AreEqual(5, randNumbers[3]);

			delete var.numbers;
			pFakeRandomInt = nullptr;
		}
	};
}
