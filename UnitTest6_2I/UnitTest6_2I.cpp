#include "pch.h"
#include "CppUnitTest.h"
#include "..\PR_6_2i\Lab_6_2i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62iter
{
    TEST_CLASS(UnitTest62iter)
    {
    public:

        TEST_METHOD(TestSumEven)
        {
            int a[] = { 3, -4, 7, 10, -1, 0 };
            // -4 + 10 + 0 = 6
            int s = SumEven(a, 6);
            Assert::AreEqual(6, s);
        }
    };
}
