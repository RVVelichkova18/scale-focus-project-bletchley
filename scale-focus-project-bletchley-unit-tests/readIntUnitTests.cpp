#include "pch.h"
#include "CppUnitTest.h"
#include "../scale-focus-project-bletchley/Data.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTests
{
	TEST_CLASS(readIntUnitTests)
	{
	public:

		TEST_METHOD(shouldReturnTheNumberWithoutOutput)
		{
			stringstream input, output, expectedOutput;
			string expectedOutputStr = "";
			input << "3" << endl;

			int result = readInt(input, output);

			Assert::AreEqual(3, result);
			Assert::AreEqual(expectedOutputStr, output.str());
		}

		TEST_METHOD(shouldReturnTheNumberWithOutput)
		{
			stringstream input, output, expectedOutput;

			//Compose input
			input << "number" << endl << "3" << endl;

			//Compose output
			expectedOutput << endl << RED << MSG_INVALID_SYMBOL_TRY_AGAIN << RESET;

			int result = readInt(input, output);

			string expectedOutputStr = expectedOutput.str();

			Assert::AreEqual(3, result);
			Assert::AreEqual(expectedOutputStr, output.str());
		}
	};
}
