#include "pch.h"
#include "CppUnitTest.h"

extern "C" int CheckRange(int*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCheckRange
{
	TEST_CLASS(UnitTestCheckRange)
	{
	public:

		//Verify guess is below the range
		TEST_METHOD(TestCheckRange01)
		{
			int LowGuess = -4; // below range
			int result = CheckRange(&LowGuess);

			Assert::AreEqual(0, result);
		}

		//Verify guess is above the range
		TEST_METHOD(TestCheckRange02)
		{
			int HighGuess = 456; // above range
			int result = CheckRange(&HighGuess);

			Assert::AreEqual(0, result);
		}
	};
}
