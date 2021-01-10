#include "pch.h"
#include "CppUnitTest.h"
#include "../scale-focus-project-bletchley/Data.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTests
{
	TEST_CLASS(checkInRangeUnitTests)
	{
	public:
		
		TEST_METHOD(shouldReturnFalseIfInvalidDataIsPassed)
		{
			int testData[] = { 1, 2, 8, 6 };

			bool result = checkInRange(testData);

			Assert::AreEqual(false, result);
		}

		TEST_METHOD(shouldReturnTrueIfValidDataIsPassed)
		{
			int testData[] = { 3, 4, 7, 2 };

			bool result = checkInRange(testData);

			Assert::AreEqual(true, result);
		}
	};
}
