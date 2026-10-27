#include "pch.h"
#include "CppUnitTest.h"
#include "..\PR_6_4r\Lab6_4r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
    TEST_CLASS(UnitTest64rec)
    {
    public:

        TEST_METHOD(TestSumPositive)
        {
            double a[] = { 2, -9, 3, -1.5, 0.5, 4 };
            // 2 + 3 + 0.5 + 4 = 9.5
            double s = SumPositive(a, 6, 0);
            Assert::AreEqual(9.5, s, 0.0001);
        }

        TEST_METHOD(TestProductBetween)
        {
            double a[] = { 2, -9, 3, -1.5, 0.5, 4 };
            // max by abs: -9 (a[1]), min by abs: 0.5 (a[4])
            Assert::AreEqual(1, IndexMaxAbs(a, 6, 1, 0));
            Assert::AreEqual(4, IndexMinAbs(a, 6, 1, 0));
            // between them: 3 * (-1.5) = -4.5
            double p = Product(a, 2, 4);
            Assert::AreEqual(-4.5, p, 0.0001);
        }
    };
}
