#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_6_2r.cpp\Lab6_2r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rec
{
    TEST_CLASS(UnitTest62rec)
    {
    public:

        TEST_METHOD(TestSumEven)
        {
            int a[] = { 3, -4, 7, 10, -1, 0 };
            // -4 + 10 + 0 = 6
            int s = SumEven(a, 6, 0);
            Assert::AreEqual(6, s);
        }
    };
}
