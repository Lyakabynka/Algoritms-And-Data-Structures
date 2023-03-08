#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    //there is nothing to explain
	vector<string> vec;
	string s;
	while(true)
	{
		cin >> s;
		if (s == "END") break;

		vec.push_back(s);
	}

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	for (auto it = vec.begin();;)
	{
		cout << *it;
		it++;
		if (it != vec.end())
			cout << ",";
		else
			break;
	}


	return 0;
}