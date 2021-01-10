#include "pch.h"
#include "CppUnitTest.h"
#include "../scale-focus-project-bletchley/Data.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTests
{
	TEST_CLASS(checkForRepeatingNumbersUnitTests)
	{
	public:

		TEST_METHOD(shouldReturnTrueIfRepeatingNumbersArePassed)
		{
			int testData[] = { 1, 7, 4, 7 };

			bool result = checkForRepeatingNumbers(testData);

			Assert::AreEqual(true, result);
		}

		TEST_METHOD(shouldReturnFalseIfNotRepeatingNumbersArePassed)
		{
			int testData[] = { 1, 6, 4, 7 };

			bool result = checkForRepeatingNumbers(testData);

			Assert::AreEqual(false, result);
		}

	};
}
