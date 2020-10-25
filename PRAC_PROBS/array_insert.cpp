#include <iostream>
using namespace std;

void insert(int *, int, int, int, int);

int main()
{
    int arr[10] = {10, 20, 30, 40, 50, 800};
    for (int it = 0; it < sizeof(arr) / sizeof(arr[0]); it++)
        cout << arr[it] << " ";
    cout << endl;
    insert(arr, 100, 1, 6, sizeof(arr) / sizeof(arr[0]));
    for (int it = 0; it < sizeof(arr) / sizeof(arr[0]); it++)
        cout << arr[it] << " ";
    cout << endl;
}

void insert(int *arr, int element, int pos, int n, int size) // n => capacity of the array
{
    if (n == size)
        return;

    // (6-1)+1 = 6 :=> complexity o(n)
    int it = n - 1;
    for (int ptr = 0; ptr < (n - pos) + 1; it--, ptr++)
        arr[it + 1] = arr[it];
    arr[it + 1] = element;
}
