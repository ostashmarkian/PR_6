#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// заповнення масиву випадковими дійсними числами (рекурсивно)
void Create(double* a, const int size, const double Low, const double High, int i)
{
    if (i < size) {
        a[i] = Low + (High - Low) * (rand() / (double)RAND_MAX);
        Create(a, size, Low, High, i + 1);
    }
}

// виведення у вигляді [1.00, 2.00, 3.00] (рекурсивно)
void Print(double* a, const int size, int i)
{
    if (i == 0)
        cout << fixed << setprecision(2) << "[";

    if (i == size - 1)
        cout << a[i] << "]" << endl;
    else {
        cout << a[i] << ", ";
        Print(a, size, i + 1);
    }
}

// сума додатних елементів (рекурсивно)
double SumPositive(double* a, const int size, int i)
{
    if (i < size) {
        if (a[i] > 0)
            return a[i] + SumPositive(a, size, i + 1);
        else
            return SumPositive(a, size, i + 1);
    }
    return 0;
}

// індекс максимального за модулем елемента (виклик з i = 1, imax = 0)
int IndexMaxAbs(double* a, const int size, int i, int imax)
{
    if (i < size) {
        if (fabs(a[i]) > fabs(a[imax]))
            imax = i;
        return IndexMaxAbs(a, size, i + 1, imax);
    }
    return imax;
}

// індекс мінімального за модулем елемента (виклик з i = 1, imin = 0)
int IndexMinAbs(double* a, const int size, int i, int imin)
{
    if (i < size) {
        if (fabs(a[i]) < fabs(a[imin]))
            imin = i;
        return IndexMinAbs(a, size, i + 1, imin);
    }
    return imin;
}

// добуток елементів з індексами від i до to (to не включно)
double Product(double* a, int i, const int to)
{
    if (i < to)
        return a[i] * Product(a, i + 1, to);
    return 1;
}

// пошук максимального серед елементів з непарними номерами, починаючи з j
void Max(double* a, const int size, double& max, int& imax, int j)
{
    if (a[j] > max) {
        max = a[j];
        imax = j;
    }
    if (j + 2 < size)
        Max(a, size, max, imax, j + 2);
}

// впорядкування елементів з непарними номерами за спаданням (виклик з i = 1)
void SortOddDesc(double* a, const int size, int i)
{
    if (i + 2 < size) {
        double max = a[i];
        int imax = i;
        Max(a, size, max, imax, i + 2);
        a[imax] = a[i];
        a[i] = max;
        SortOddDesc(a, size, i + 2);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = "; cin >> n;
    if (n < 1) {
        cout << "n must be > 0" << endl;
        return 0;
    }

    double* a = new double[n];

    Create(a, n, -10, 10, 0);
    Print(a, n, 0);

    cout << "sum of positive = " << SumPositive(a, n, 0) << endl;

    int iMax = IndexMaxAbs(a, n, 1, 0);
    int iMin = IndexMinAbs(a, n, 1, 0);
    int from = (iMax < iMin ? iMax : iMin) + 1;
    int to = (iMax < iMin ? iMin : iMax);

    cout << "max by abs: a[" << iMax << "], min by abs: a[" << iMin << "]" << endl;
    if (from < to)
        cout << "product between = " << Product(a, from, to) << endl;
    else
        cout << "there are no elements between them" << endl;

    SortOddDesc(a, n, 1);
    Print(a, n, 0);

    delete[] a;
    return 0;
}
