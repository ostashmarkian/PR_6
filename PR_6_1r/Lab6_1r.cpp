#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <iostream>
using namespace std;

// Заповнення масиву випадковими числами (рекурсивно)
void Create(int* a, const int size, const int Low, const int High, int i)
{
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

// Виведення у вигляді [1, 2, 3] (рекурсивно)
void Print(int* a, const int size, int i)
{
    if (i == 0)
        cout << "[";                     // на початку — відкрита дужка

    if (i == size - 1)
        cout << a[i] << "]" << endl;     // останній елемент — без коми
    else {
        cout << a[i] << ", ";
        Print(a, size, i + 1);
    }
}

// Критерій: всі, крім від'ємних або непарних
bool Fits(const int x)
{
    return !(x < 0 || x % 2 != 0);
}

// Кількість елементів, що задовольняють критерій (рекурсивно)
int Count(int* a, const int size, int i)
{
    if (i < size) {
        if (Fits(a[i]))
            return 1 + Count(a, size, i + 1);
        else
            return Count(a, size, i + 1);
    }
    return 0;
}

// Сума елементів, що задовольняють критерій (рекурсивно)
int Sum(int* a, const int size, int i)
{
    if (i < size) {
        if (Fits(a[i]))
            return a[i] + Sum(a, size, i + 1);
        else
            return Sum(a, size, i + 1);
    }
    return 0;
}

// Заміна нулями елементів, що задовольняють критерій (рекурсивно)
void Replace(int* a, const int size, int i)
{
    if (i < size) {
        if (Fits(a[i]))
            a[i] = 0;
        Replace(a, size, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));   // ОДИН раз, на початку main
    const int n = 25;
    int t[n];

    Create(t, n, -5, 12, 0);       // числа від -5 до 12 включно
    Print(t, n, 0);

    cout << "count = " << Count(t, n, 0) << endl;
    cout << "sum   = " << Sum(t, n, 0) << endl;

    Replace(t, n, 0);
    Print(t, n, 0);

    return 0;
}