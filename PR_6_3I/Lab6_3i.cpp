#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ---------- звичайні функції ----------

// заповнення масиву випадковими числами з діапазону [Low, High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву у вигляді [1, 2, 3]
void Print(int* a, const int size)
{
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            cout << a[i];
        else
            cout << a[i] << ", ";
    }
    cout << "]" << endl;
}

// сума від'ємних елементів масиву
int SumNeg(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < 0)
            s += a[i];
    return s;
}

// ---------- шаблони функцій ----------

template <typename T>
void Create(T* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void Print(T* a, const int size)
{
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            cout << a[i];
        else
            cout << a[i] << ", ";
    }
    cout << "]" << endl;
}

template <typename T>
T SumNeg(T* a, const int size)
{
    T s = T();
    for (int i = 0; i < size; i++)
        if (a[i] < 0)
            s += a[i];
    return s;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;

    // звичайні функції
    int a[n];
    Create(a, n, -20, 20);
    Print(a, n);
    cout << "SumNeg(a, n)         = " << SumNeg(a, n) << endl << endl;

    // шаблони для int
    int b[n];
    Create<int>(b, n, -20, 20);
    Print<int>(b, n);
    cout << "SumNeg<int>(b, n)    = " << SumNeg<int>(b, n) << endl << endl;

    // шаблони для double
    double c[n];
    Create<double>(c, n, -20, 20);
    Print<double>(c, n);
    cout << "SumNeg<double>(c, n) = " << SumNeg<double>(c, n) << endl;

    return 0;
}
