#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string,string> namebirth;
    ifstream f("data.txt");

    string name;
    string birthdate;
    while(!f.eof())
    {
        getline(f,name);
        getline(f,birthdate);
        namebirth.insert(pair(name,birthdate));
    }

    f.close();

    string input;
    while(true)
    {
        cout << "Write '--stop' to end the loop" << endl;
        getline(cin, input);

        if(input == "--stop") break;

        auto it = namebirth.find(input);
        if(it == namebirth.end())
        {
            cout << "Name not found!" << endl;
        }
        else
        {
            cout << it->first << " : " << it->second << endl; 
        }
    }

    return 0;
}