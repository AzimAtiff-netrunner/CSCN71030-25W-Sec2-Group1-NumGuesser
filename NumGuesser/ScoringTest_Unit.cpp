#include "pch.h"
#include "CppUnitTest.h"
#include "ScoringTest.h"  // Include header file


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ScoringTests
{
	TEST_CLASS(ScoringTest_Unit)
	{
	public:

		TEST_METHOD(TestUpdateScores)
		{
			Player testPlayer = { "Alice", {0, 0, 0} };
			updateScores(&testPlayer, 1, 85);
			Assert::AreEqual(85, testPlayer.scores[1]);
		}

		TEST_METHOD(TestCalculateTotalScore)
		{
			Player testPlayer = { "Alice", {90, 85, 80} };
			int totalScore = calculateTotalScore(testPlayer);
			Assert::AreEqual(255, totalScore);
		}

		TEST_METHOD(TestFindTopScorer)
		{
			Player players[2] = {
				{"Alice", {90, 85, 80}},
				{"Bob", {92, 88, 79}}
			};
			Player topScorer = findTopScorer(players, 2);
			Assert::AreEqual(std::string("Bob"), std::string(topScorer.name));
		}
	};
}
