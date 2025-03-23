#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
	int ValidateUserGuess(int UserInput, int RandNum);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestValidateUserGuess
{
	TEST_CLASS(UnitTestValidateUserGuess)
	{
	public:
		
		TEST_METHOD(TestValidateUserGuess01)//tests the user's guess and outputs a hint if their guess is lower
		{
			int target = 65;//fixed target number
			int UserGuess = 32; //user's guess(lower)

			int result = ValidateUserGuess(UserGuess, target);

			Assert::AreEqual(target, result); //check if they are equal
		}
		TEST_METHOD(TestValidateUserGuess02)//tests the user's guess and outputs a hint if their guess is higher
		{
			int target = 65;//fixed target number
			int UserGuess = 87; //user's guess(higher)

			int result = ValidateUserGuess(UserGuess, target);

			Assert::AreEqual(target, result); //check if they are equal
		}
		TEST_METHOD(TestValidateUserGuess03)//tests the user's guess and outputs a hint if their guess is correct
		{
			int target = 65;//fixed target number
			int UserGuess = 65; //user's guess(correct)

			int result = ValidateUserGuess(UserGuess, target);

			Assert::AreEqual(target, result); //check if they are equal
		}
	};
}
