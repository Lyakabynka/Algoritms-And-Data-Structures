#include <iostream>
#include <deque>
#include <fstream>
using namespace std;
int main()
{
    deque<float> A;
    float input;
    while(true)
    {
        cin >> input;
        if(input == 0)
            break;

        if(input > 0)
            A.push_back(input);
        else
            A.push_front(input);
    }

    //printing
    for(auto it : A)
    {
        cout << it << " ";
    }
    cout << '\n';
    
    //gets the last negative iterator (its value)
    auto iterFirstPositive = A.begin();
    for(auto it = A.begin(); it != A.end(); it++)
    {
        if(*it > 0) 
        { 
            iterFirstPositive = it; 
            break;
        }
    }
    //inserting into the last negative index
    A.insert(iterFirstPositive, 0);

//printing
    for(auto it = A.begin(); ;)
    {
        cout << *it;
        ++it;
        if(it != A.end())
        {
            cout << ';';
        }
        else
            break;
    }
    
    return 0;
}