#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>  // For strcmp

extern "C" char* ValidateUserGuess(int* UserInput, int RandNum);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestValidateUserGuess
{
	TEST_CLASS(UnitTestValidateUserGuess)
	{
	public:

		TEST_METHOD(TestValidateUserGuess01)//tests the user's guess and outputs a hint if their guess is lower
		{
			int target = 65;       // fixed target number
			int UserGuess = 32;    // user's guess (lower)

			char* result = ValidateUserGuess(&UserGuess, target);
			char* expected = "Your guess is LOWER than the actual number";

			
			Assert::IsTrue(strcmp(expected, result) == 0);
		}

		TEST_METHOD(TestValidateUserGuess02)//tests the user's guess and outputs a hint if their guess is higher
		{
			int target = 65;       // fixed target number
			int UserGuess = 87;    // user's guess (higher)

			char* result = ValidateUserGuess(&UserGuess, target);
			char* expected = "Your guess is HIGHER than the actual number";

			Assert::IsTrue(strcmp(expected, result) == 0);
		}

		TEST_METHOD(TestValidateUserGuess03)//tests the user's guess when it is correct
		{
			int target = 65;       // fixed target number
			int UserGuess = 65;    // user's guess (correct)

			char* result = ValidateUserGuess(&UserGuess, target);
			char* expected = "";   // Empty string on correct guess

			Assert::IsTrue(strcmp(expected, result) == 0);
		}
	};
}

