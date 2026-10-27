#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// заповнення масиву випадковими дійсними числами з діапазону [Low, High]
void Create(double* a, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + (High - Low) * (rand() / (double)RAND_MAX);
}

// виведення масиву у вигляді [1.00, 2.00, 3.00]
void Print(double* a, const int size)
{
    cout << fixed << setprecision(2);
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            cout << a[i];
        else
            cout << a[i] << ", ";
    }
    cout << "]" << endl;
}

// сума додатних елементів
double SumPositive(double* a, const int size)
{
    double s = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > 0)
            s += a[i];
    return s;
}

// індекс максимального за модулем елемента
int IndexMaxAbs(double* a, const int size)
{
    int imax = 0;
    for (int i = 1; i < size; i++)
        if (fabs(a[i]) > fabs(a[imax]))
            imax = i;
    return imax;
}

// індекс мінімального за модулем елемента
int IndexMinAbs(double* a, const int size)
{
    int imin = 0;
    for (int i = 1; i < size; i++)
        if (fabs(a[i]) < fabs(a[imin]))
            imin = i;
    return imin;
}

// добуток елементів з індексами від from до to (to не включно)
double Product(double* a, const int from, const int to)
{
    double p = 1;
    for (int i = from; i < to; i++)
        p *= a[i];
    return p;
}

// впорядкування елементів з непарними номерами за спаданням (метод вибору)
void SortOddDesc(double* a, const int size)
{
    for (int i = 1; i + 2 < size; i += 2) {
        double max = a[i];
        int imax = i;
        for (int j = i + 2; j < size; j += 2)
            if (a[j] > max) {
                max = a[j];
                imax = j;
            }
        a[imax] = a[i];
        a[i] = max;
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

    Create(a, n, -10, 10);
    Print(a, n);

    cout << "sum of positive = " << SumPositive(a, n) << endl;

    int iMax = IndexMaxAbs(a, n);
    int iMin = IndexMinAbs(a, n);
    int from = (iMax < iMin ? iMax : iMin) + 1;
    int to = (iMax < iMin ? iMin : iMax);

    cout << "max by abs: a[" << iMax << "], min by abs: a[" << iMin << "]" << endl;
    if (from < to)
        cout << "product between = " << Product(a, from, to) << endl;
    else
        cout << "there are no elements between them" << endl;

    SortOddDesc(a, n);
    Print(a, n);

    delete[] a;
    return 0;
}
