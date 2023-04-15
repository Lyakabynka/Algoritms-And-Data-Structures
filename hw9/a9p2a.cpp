#include <iostream>
#include <list>
#include <algorithm>


using namespace std;

template<typename T>
void reverse(list<T>& l)
{
    auto left = l.begin();
    auto right = --l.end();
    for(int i = 0; i < l.size()/2; i++)
    {
        swap(*left, *right);
        left++;
        right--;
    }
}

int main()
{
    list<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    s.push_back(6);
    s.push_back(7);
    s.push_back(8);
    s.push_back(9);

    reverse(s);

    for(auto it : s)
    {
        cout << it << " ";
    }

    return 0;
}