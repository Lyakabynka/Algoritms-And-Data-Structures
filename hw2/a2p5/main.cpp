#include <iostream>
#include <set>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;
int main()
{
    srand(time(0));
    set<int> s;
    for(int i = 0; i < 6; i++)
    {
        s.insert(rand()%49+1);
    }

    // sort(s.begin(), s.end());

    for(auto it : s)
    {
        cout << it << " ";
    }

    return 0;
}