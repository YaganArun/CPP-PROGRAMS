#include <iostream>
#include <vector>
using namespace std;

struct result
{
    int position;
    bool flag;
};

struct result search(vector<int> vec, int pos, int data)
{
    if (vec[pos] == data)
    {
        struct result res;
        res.flag = true;
        res.position = pos;
        return res;
    }
    else if (pos == 0)
    {
        struct result res;
        res.flag = false;
        res.position = pos;
        return res;
    }
    else if (pos == 0 && vec[pos] == data)
    {
        struct result res;
        res.flag = true;
        res.position = pos;
        return res;
    }
    else
        return search(vec, pos - 1, data);
}

int main()
{
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    struct result res = search(vec, vec.size() - 1, 40);
    if (res.flag)
        cout << "ELEMENT FOUND AT POSITION : " << res.position;
    else
        cout << "NO SUCH ELEMENT EXIST !";
}