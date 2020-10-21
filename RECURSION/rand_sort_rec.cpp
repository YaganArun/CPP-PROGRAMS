//Sort based on recursion to understand recuraion

#include <iostream>
#include <vector>
using namespace std;

void ins_sort(vector<int> &vec, int temp)
{
    if (vec.size() == 0 || vec[vec.size() - 1] <= temp)
    {
        vec.push_back(temp);
        return;
    }
    int val = vec[vec.size() - 1];
    vec.pop_back();
    ins_sort(vec, temp);
    vec.push_back(val);
}

void sort(vector<int> &vec)
{
    if (vec.size() == 1)
        return;

    int val = vec[vec.size() - 1];
    vec.pop_back();
    sort(vec);
    ins_sort(vec, val);
}

int main()
{
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(2);
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
        cout << *itr << " ";
    sort(vec);
    cout << "\n";
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
        cout
            << *itr << " ";
    return 0;
}