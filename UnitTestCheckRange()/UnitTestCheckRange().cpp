#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
	int CheckRange(int UserInput);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCheckRange
{
	TEST_CLASS(UnitTestCheckRange)
	{
	public:
		
		TEST_METHOD(TestCheckRange01)//test if the players guess is below the range
		{
			int LowGuess = -4; //below range
			int result = CheckRange(LowGuess);

			Assert::AreEqual(0, result);//
		}
		TEST_METHOD(TestCheckRange02)//test if the players guess is above the range
		{
			int HighGuess = 456; //above range
			int result = CheckRange(HighGuess);

			Assert::AreEqual(0, result);//
		}
	};
}
