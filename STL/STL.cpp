#include <bits/stdc++.h>
using namespace std;

void explainPair()
{

    pair<int, int> p1 = {1, 3};
    // prints 1 3
    cout << p1.first << " " << p1.second;

    //Nesting of pairs
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    // prints 1 4 3
    cout << p2.first << " " << p2.second.second << " " << p2.second.first;

    //array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    // Prints 5
    cout << arr[1].second;

    //use make_pair() to initilize
    pair<int, int> p3;
    p3 = make_pair(10, 111);
    //prints 10 111
    cout << p3.first << " " << p3.second;
}

void explainList()
{
    // ITERATORS :=> begin, end, rbegin, rend
}

int main()
{
    vector<int> v;
    v.push_back(100);
    cout << v.back();
    return 0;
}