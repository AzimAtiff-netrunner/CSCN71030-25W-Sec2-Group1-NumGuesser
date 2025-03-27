#include "pch.h"  // Ensure pch.h is the first include (or stdafx.h if that's what your project uses)
#include "CppUnitTest.h"

extern "C" {
#include "../NumGuesser/Scoring.h"  // Adjust the relative path as necessary
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace scoring_module_tests
{
    TEST_CLASS(ScoringModuleTests)
    {
    public:
        // TC-SCORE-001: Verify that calculate_score_data() returns correct currentScore and highScore.
        TEST_METHOD(Test_CalculateScoreData_ValidAttempts)
        {
            int attempts = 5;
            int prevHighScore = 80;
            ScoreData data = calculate_score_data(attempts, prevHighScore);
            int expectedCurrentScore = 100 / attempts; // MAX_SCORE / attempts
            Assert::AreEqual(expectedCurrentScore, data.currentScore, L"Current score should equal MAX_SCORE / attempts");
            Assert::AreEqual(prevHighScore, data.highScore, L"High score should be passed correctly");
        }

        // TC-SCORE-002: Verify calculate_score_data() returns 0 currentScore when attempts is 0.
        TEST_METHOD(Test_CalculateScoreData_ZeroAttempts)
        {
            ScoreData data = calculate_score_data(0, 90);
            Assert::AreEqual(0, data.currentScore, L"Current score should be 0 when attempts is 0");
        }

        // TC-SCORE-003: Verify that get_random_bonus() returns a bonus within range [0, 49].
        TEST_METHOD(Test_GetRandomBonus_Range)
        {
            int bonus = get_random_bonus();
            Assert::IsTrue(bonus >= 0 && bonus < 50, L"Random bonus should be between 0 and 49");
        }

        // TC-SCORE-004: Verify calculate_score_ptr() computes score correctly.
        TEST_METHOD(Test_CalculateScorePtr)
        {
            int attempts = 4;
            int score = 0;
            calculate_score_ptr(attempts, &score);
            int expectedScore = 100 / attempts;
            Assert::AreEqual(expectedScore, score, L"Score computed via pointer should equal MAX_SCORE / attempts");
        }

        // TC-SCORE-005: Verify that multiple calls to get_random_bonus() return values within range.
        TEST_METHOD(Test_GetRandomBonus_MultipleCalls)
        {
            for (int i = 0; i < 10; i++)
            {
                int bonus = get_random_bonus();
                Assert::IsTrue(bonus >= 0 && bonus < 50, L"Each bonus should be in range [0, 49]");
            }
        }
    };
}



