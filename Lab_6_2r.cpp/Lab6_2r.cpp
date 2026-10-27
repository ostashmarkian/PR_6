#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

// сума парних елементів масиву (рекурсивно)
int SumEven(int* a, const int size, int i)
{
    if (i < size) {
        if (a[i] % 2 == 0)
            return a[i] + SumEven(a, size, i + 1);
        else
            return SumEven(a, size, i + 1);
    }
    return 0;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 20;
    int a[n];

    Create(a, n, -20, 20, 0);
    Print(a, n, 0);

    cout << "sum of even = " << SumEven(a, n, 0) << endl;

    return 0;
}
