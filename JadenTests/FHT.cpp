#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"  
#include "CppUnitTest.h"
#include <cstdio>  

extern "C" {
#include "../NumGuesser/FileHandling.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace filehandling_module_tests
{
    const char* testFile = "high_score.txt";  // Using the same file as defined in the module

    TEST_CLASS(FileHandlingModuleTests)
    {
    public:
        // TC-FILE-001: Verify that after saving a high score, loading it returns the same value.
        TEST_METHOD(Test_SaveAndLoadHighScore)
        {
            int expectedScore = 42;
            save_high_score(expectedScore);
            int loadedScore = load_high_score();
            Assert::AreEqual(expectedScore, loadedScore, L"Loaded high score should match the saved value");
        }

        // TC-FILE-002: Verify that if the file does not exist, load_high_score returns 0.
        TEST_METHOD(Test_LoadHighScore_FileNotExist)
        {
            // Remove file if exists
            remove(testFile);
            int loadedScore = load_high_score();
            Assert::AreEqual(0, loadedScore, L"If file doesn't exist, high score should default to 0");
        }

        // TC-FILE-003: Verify that saving a new high score overwrites the previous one.
        TEST_METHOD(Test_SaveHighScore_Overwrite)
        {
            save_high_score(30);
            save_high_score(55);
            int loadedScore = load_high_score();
            Assert::AreEqual(55, loadedScore, L"Loaded high score should be the most recently saved value");
        }

        // TC-FILE-004: Verify that loading from a file with invalid content returns 0.
        TEST_METHOD(Test_LoadHighScore_InvalidContent)
        {
            FILE* file = fopen(testFile, "w");
            if (file)
            {
                fprintf(file, "invalid_data");
                fclose(file);
            }
            int loadedScore = load_high_score();
            // Since our implementation doesn't explicitly check for invalid data,
            // fscanf will fail and score remains 0.
            Assert::AreEqual(0, loadedScore, L"Loaded high score should be 0 when file content is invalid");
        }

        // TC-FILE-005: Verify that saving and loading multiple times works consistently.
        TEST_METHOD(Test_MultipleSaveLoadCycles)
        {
            for (int i = 1; i <= 5; i++)
            {
                save_high_score(i * 10);
                int loadedScore = load_high_score();
                Assert::AreEqual(i * 10, loadedScore, L"Loaded high score should match the saved value in each cycle");
            }
        }
    };
}

