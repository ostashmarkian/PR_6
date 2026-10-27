#include "pch.h"
#include "CppUnitTest.h"
#include "..\PR_6_3r\Lab6_3r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63rec
{
    TEST_CLASS(UnitTest63rec)
    {
    public:

        TEST_METHOD(TestSumNeg)
        {
            int a[] = { 3, -2, 5, -4 };
            // -2 + (-4) = -6
            int s = SumNeg(a, 4, 0);
            Assert::AreEqual(-6, s);
        }

        TEST_METHOD(TestSumNegTemplate)
        {
            double c[] = { -1.5, 2, -0.5 };
            // -1.5 + (-0.5) = -2
            double s = SumNeg<double>(c, 3, 0);
            Assert::AreEqual(-2.0, s, 0.0001);
        }
    };
}
