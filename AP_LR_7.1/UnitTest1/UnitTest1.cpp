#include "pch.h"
#include "CppUnitTest.h"
#include ".../AP_LR_7.1/AP_LR_7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

namespace UnitTestLab11
{
    TEST_CLASS(UnitTestLab1)
    {
    public:

        TEST_METHOD(TestCalc)
        {
            int rowCount = 2;
            int colCount = 2;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                a[i] = new int[colCount];
            }

            a[0][0] = 10; // індекси (0,0) кратні 3 -> ігнорується
            a[0][1] = 5;  // підходить за критерієм
            a[1][0] = 2;  // підходить за критерієм
            a[1][1] = 4;  // підходить за критерієм

            int S = 0;
            int k = 0;

            Calc(a, rowCount, colCount, S, k);

            Assert::AreEqual(11, S);
            Assert::AreEqual(3, k);

            for (int i = 0; i < rowCount; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}