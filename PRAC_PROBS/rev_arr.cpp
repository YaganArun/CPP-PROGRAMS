//Program to reverse a given array using function
//Yagan 19th Oct 2020

#include <iostream>
using namespace std;
void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (1)
    {
        if (start > end)
            break;

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++, end--;
    }
    for (int itr = 0; itr < size; itr++)
        cout << arr[itr] << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    reverseArray(arr, size);
    return 0;
}