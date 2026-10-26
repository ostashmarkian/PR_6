#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_6/Lab6_1i.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:

        TEST_METHOD(TestCount)
        {
            int t[] = { 4, -3, 0, 7, 12, -2, 6, 5 };
            // підходять 4, 0, 12, 6
            int k = Count(t, 8);
            Assert::AreEqual(4, k);
        }

        TEST_METHOD(TestSum)
        {
            int t[] = { 4, -3, 0, 7, 12, -2, 6, 5 };
            // 4 + 0 + 12 + 6 = 22
            int s = Sum(t, 8);
            Assert::AreEqual(22, s);
        }
	};
}
