#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    //there is nothing to explain
	vector<string> vec;
	string s;
	while (true)
	{
		cin >> s;
		if (s == "END") break;

		vec.push_back(s);
	}

	if (vec.size() >= 5)
	{
		string temp = vec[4];
		vec[4] = vec[1];
		vec[1] = temp;
	}

	vec[vec.size() - 1] = "???";

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1)
		{
			cout << ",";
		}
	}
	cout << endl;

	for (auto it = vec.begin();;)
	{
		cout << *it;
		it++;
		if (it != vec.end())
			cout << ";";
		else
			break;
	}
	cout << endl;
	for (auto it = --vec.end();;)
	{
		cout << *it << " ";
		if (it == vec.begin())
			break;
		it--;
	}

	return 0;
}