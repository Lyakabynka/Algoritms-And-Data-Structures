#include <iostream>
#include <list>
#include <fstream>
using namespace std;
int main()
{
    list<int> a;
    list<int> b;

    int input;
    while(true)
    {
        cout << "Add the integer to the list (enter <0 to escape the loop): ";
        cin >> input;
        if(input <= 0) break;
        a.push_back(input);
    }

    //copying from a to b (reverse)
    for(auto it : a)
    {
        b.push_front(it);
    }

    for(auto it : a)
    {
        cout << it << ' ';
    }

    ofstream f;
    f.open("listB.txt");
    for(auto it : b)
    {
        f << it << " ";
    }
    f.close();

    cout << "\n";

    int firstElem = a.front();
    a.erase(a.begin());
    a.push_back(firstElem);

    firstElem = b.front();
    b.erase(b.begin());
    b.push_back(firstElem);

    //printing without last comma
    for(auto it = a.begin(); ;)
    {
        cout << *it;
        ++it;
        if(it != a.end())
        {
            cout << ',';
        }
        else
            break;
    }

    cout << "\n";
    //printinf without last comma in b
    for(auto it = b.begin(); ;)
    {
        cout << *it;
        ++it;
        if(it != b.end())
        {
            cout << ',';
        }
        else
            break;
    }

    cout << "\n";

    //mergin b to a
    a.merge(b);
    //sorting
    a.sort();

    //printing
    for(auto it : a)
    {
        cout << it << ' ';
    }

    return 0;
}