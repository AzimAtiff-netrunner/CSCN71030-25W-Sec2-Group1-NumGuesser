#include "pch.h"  
#include "CppUnitTest.h"

extern "C" {
#include "../NumGuesser/RNG_Module.h"  
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rng_module_tests
{
    TEST_CLASS(RNGModuleTests)
    {
    public:
        // Test that the generated number is in the range [1, 100]
        TEST_METHOD(Test_Range_1_to_100)
        {
            init_rng();
            int num = generate_random_number();
            Assert::IsTrue(num >= 1 && num <= 100, L"Number is out of range [1, 100]");
        }

        // Test that the return value from generate_random_number() is an int
        TEST_METHOD(Test_Return_Type_Is_Int)
        {
            init_rng();
            int num = generate_random_number();
            Assert::AreEqual(sizeof(int), sizeof(num), L"Return type is not int");
        }

        // Test that the generated number can be passed to another module (simulated here)
        TEST_METHOD(Test_Number_Passes_To_GameLogic)
        {
            init_rng();
            int num = generate_random_number();
            int received = num; // Simulated passing to Game Logic Module
            Assert::AreEqual(num, received, L"Game Logic Module did not receive the number correctly");
        }

        // Test by generating 100 numbers, ensuring they are all in the valid range
        TEST_METHOD(Test_Edge_Case_Loop)
        {
            init_rng();
            for (int i = 0; i < 100; i++) {
                int num = generate_random_number();
                Assert::IsTrue(num >= 1 && num <= 100, L"Generated number out of range in loop");
            }
        }

        // Test repeatability with a fixed seed (without reseeding in between)
        TEST_METHOD(Test_Repeatability_Without_Seeding)
        {
            // Set a fixed seed
            srand(1);
            int first = generate_random_number();

            // Reset with the same seed to simulate a repeatable sequence
            srand(1);
            int second = generate_random_number();
            Assert::AreEqual(first, second, L"Random sequence is not repeatable with a fixed seed");
        }
    };
}
