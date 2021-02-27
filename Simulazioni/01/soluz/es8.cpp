#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <exception>

using namespace std;

int main(int argc, char **argv)
{
	unordered_map<int, int> um;
	for (int i = 0; i < 10; i++)
	{
		um.insert(pair<int, int>(i, i));
		um.insert(pair<int, int>(i, i));
	}

	//	for(pair<int, int> e : um){
	//		cout << "(" << e.first << ", " << e.second << ") - ";
	//	}

	auto result = [um]() {
		vector<int> v(um.size());
		list<int> l;
		set<int> s;
		for (pair<int, int> el : um)
		{
			int val = el.second;
			int key = el.first;

			try
			{
				vector<int>::iterator it = v.begin() + key;
				v.insert(it, val);
			}
			catch (...)
			{
				cout << "Vector too short!" << endl;
			}

			l.push_front(val);

			try
			{
				s.insert(val);
			}
			catch (...)
			{
				cout << "You tried to insert a double element in the 7!" << endl;
			}
		}
		return;
	};

	result();

	return 0;
}
