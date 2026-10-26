#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// заповнення масиву випадковими числами з діапазону [Low, High]
void Create(int* t, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        t[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
void Print(int* a, const int size)
{
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            cout << a[i];           // останній елемент — без коми
        else
            cout << a[i] << ", ";
    }
    cout << "]" << endl;
}

// чи задовольняє елемент критерію
bool Fits(const int x)
{
    return !(x < 0 || x % 2 != 0);
}

// кількість елементів, що задовольняють критерію
int Count(int* t, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (Fits(t[i]))
            k++;
    return k;
}

// сума елементів, що задовольняють критерію
int Sum(int* t, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (Fits(t[i]))
            s += t[i];
    return s;
}

// заміна нулями елементів, що задовольняють критерію
void Replace(int* t, const int size)
{
    for (int i = 0; i < size; i++)
        if (Fits(t[i]))
            t[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 25;
    int t[n];
    int Low = -5;
    int High = 12;

    Create(t, n, Low, High);
    Print(t, n);

    int count = Count(t, n);
    int sum = Sum(t, n);
    Replace(t, n);

    cout << "count = " << count << endl;
    cout << "sum   = " << sum << endl;
    Print(t, n);

    return 0;
}
