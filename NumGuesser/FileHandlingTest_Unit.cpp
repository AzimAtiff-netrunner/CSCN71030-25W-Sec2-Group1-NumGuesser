#include "pch.h"
#include "CppUnitTest.h"
#include "ScoringTest.h"
#include "FileHandling_Test.h"  // Include header file


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileHandlingTests
{
	TEST_CLASS(FileHandlingTest_Unit)
	{
	public:

		TEST_METHOD(TestSaveScores)
		{
			Player players[2] = { {"Alice", {85, 90, 78}}, {"Bob", {92, 88, 79}} };
			saveScores(players, 2, "test_scores.txt");

			FILE* file;
			errno_t err = fopen_s(&file, "test_scores.txt", "r");
			Assert::AreEqual(0, err);
			fclose(file);
		}


		TEST_METHOD(TestLoadScores)
		{
			Player players[2] = { {"Alice", {85, 90, 78}}, {"Bob", {92, 88, 79}} };
			saveScores(players, 2, "test_scores.txt");

			Player loadedPlayers[2];
			int numPlayers = 0;
			loadScores(loadedPlayers, &numPlayers, "test_scores.txt");

			Assert::AreEqual(2, numPlayers);
			Assert::AreEqual(std::string("Alice"), std::string(loadedPlayers[0].name));
			Assert::AreEqual(85, loadedPlayers[0].scores[0]);
		}

		TEST_METHOD(TestDeleteScoreFile)
		{
			saveScores(nullptr, 0, "test_scores.txt");
			int result = deleteScoreFile("test_scores.txt");
			Assert::AreEqual(0, result);

			FILE* file;
			errno_t err = fopen_s(&file, "test_scores.txt", "r");
			Assert::AreNotEqual(0, err);
		}
	};
}
