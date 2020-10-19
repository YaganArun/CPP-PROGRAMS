//Simple usage of struct to find max min element in a given array

#include <iostream>
using namespace std;

struct Pair
{
    int min;
    int max;
};
typedef struct Pair Pair;

Pair getMaxMinPair(int *arr, int size)
{
    Pair pair;
    pair.max = arr[0];
    pair.min = arr[0];

    // TODO: Have to implement using merge sort

    for (int itr = 1; itr < size; itr++) //Complexity == > O(n)
    {
        if (arr[itr] > pair.max)
            pair.max = arr[itr];

        if (arr[itr] < pair.min)
            pair.min = arr[itr];
    }

    return pair;
}

int main()
{
    int arr[] = {10, 100, 29, 90, 88, 1, 876, 1};
    int size = sizeof(arr) / sizeof(int);
    Pair pair = getMaxMinPair(arr, size);
    cout << pair.max << " " << pair.min;
    return 0;
}