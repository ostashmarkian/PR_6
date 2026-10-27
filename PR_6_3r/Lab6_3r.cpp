#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ---------- звичайні функції ----------

// заповнення масиву випадковими числами (рекурсивно)
void Create(int* a, const int size, const int Low, const int High, int i)
{
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

// виведення у вигляді [1, 2, 3] (рекурсивно)
void Print(int* a, const int size, int i)
{
    if (i == 0)
        cout << "[";

    if (i == size - 1)
        cout << a[i] << "]" << endl;
    else {
        cout << a[i] << ", ";
        Print(a, size, i + 1);
    }
}

// сума від'ємних елементів масиву (рекурсивно)
int SumNeg(int* a, const int size, int i)
{
    if (i < size) {
        if (a[i] < 0)
            return a[i] + SumNeg(a, size, i + 1);
        else
            return SumNeg(a, size, i + 1);
    }
    return 0;
}

// ---------- шаблони функцій ----------

template <typename T>
void Create(T* a, const int size, const int Low, const int High, int i)
{
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create<T>(a, size, Low, High, i + 1);
    }
}

template <typename T>
void Print(T* a, const int size, int i)
{
    if (i == 0)
        cout << "[";

    if (i == size - 1)
        cout << a[i] << "]" << endl;
    else {
        cout << a[i] << ", ";
        Print<T>(a, size, i + 1);
    }
}

template <typename T>
T SumNeg(T* a, const int size, int i)
{
    if (i < size) {
        if (a[i] < 0)
            return a[i] + SumNeg<T>(a, size, i + 1);
        else
            return SumNeg<T>(a, size, i + 1);
    }
    return T();
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;

    // звичайні функції
    int a[n];
    Create(a, n, -20, 20, 0);
    Print(a, n, 0);
    cout << "SumNeg(a, n)         = " << SumNeg(a, n, 0) << endl << endl;

    // шаблони для int
    int b[n];
    Create<int>(b, n, -20, 20, 0);
    Print<int>(b, n, 0);
    cout << "SumNeg<int>(b, n)    = " << SumNeg<int>(b, n, 0) << endl << endl;

    // шаблони для double
    double c[n];
    Create<double>(c, n, -20, 20, 0);
    Print<double>(c, n, 0);
    cout << "SumNeg<double>(c, n) = " << SumNeg<double>(c, n, 0) << endl;

    return 0;
}
