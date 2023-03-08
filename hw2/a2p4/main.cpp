#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a;

    for(int i = 1; i<31; i++)
    {
        a.push_back(i);
    }

    a.push_back(5);

    reverse(a.begin(), a.end());

    for(auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << '\n';

    replace(a.begin(), a.end(), 5, 129);

    for(auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << ' ';
    }

    return 0;
}