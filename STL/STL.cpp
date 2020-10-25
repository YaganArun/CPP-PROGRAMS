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

void explainVector()
{

    // A empty vector
    vector<int> v; // {}

    v.push_back(1);    // {1}
    v.emplace_back(2); // {1, 2}

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    // Vector of size 5 with
    // everyone as 100
    vector<int> v(5, 100); // {100, 100, 100, 100, 100}

    // A vector of size 5
    // initialized with 0
    // might take garbage value,
    // dependent on the vector
    vector<int> v(5); // {0, 0, 0, 0, 0}

    vector<int> v1(5, 20); // {20, 20, 20, 20, 20}
    vector<int> v2(v1);    // {20, 20, 20, 20, 20}

    // Take the vector to be {10, 20, 30, 40}
    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << " "; // prints 20

    it = it + 2;
    cout << *(it) << " "; // prints 30

    vector<int>::iterator it = v.end();

    // vector<int>::iterator it = v.rend();

    // vector<int>::iterator it = v.rbegin();

    cout << v[0] << " " << v.at(0);

    cout << v.back() << " ";

    // Ways to print the vector

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    for (auto it : v)
    {
        cout << it << " ";
    }

    // {10, 20, 12, 23}
    v.erase(v.begin()); // {20 , 12 , 23}

    v.erase(v.begin() + 1); // {10 , 12 . 23}

    // {10, 20, 12, 23, 35}
    v.erase(v.begin() + 2, v.begin() + 4); // // {10, 20, 35} [start, end)

    // Insert function

    vector<int> v(2, 100);          // {100, 100}
    v.insert(v.begin(), 300);       // {300, 100, 100};
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);                       // {50, 50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    // {10, 20}
    cout << v.size(); // 2

    //{10, 20}
    v.pop_back(); // {10}

    // v1 -> {10, 20}
    // v2 -> {30, 40}
    v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}

    v.clear(); // erases the entire vector

    cout << v.empty();
}

void explainSet()
{
    set<int> st;
    st.insert(1);  // {1}
    st.emplace(2); // {1, 2}
    st.insert(2);  // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4}

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3);

    // {1, 2, 3, 4, 5}
    auto it = st.find(6);

    // {1, 4, 5}
    st.erase(5); // erases 5 // takes logarithmic time

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it); // it takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does.

    // This is the syntax
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);
}

int main()
{
}