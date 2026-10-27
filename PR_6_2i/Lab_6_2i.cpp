#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

// сума парних елементів масиву
int SumEven(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0)
            s += a[i];
    return s;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 20;
    int a[n];

    Create(a, n, -20, 20);
    Print(a, n);

    cout << "sum of even = " << SumEven(a, n) << endl;

    return 0;
}
