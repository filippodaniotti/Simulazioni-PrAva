#include <iostream>
#include <vector>
#include <algorithm> // std::transform

using namespace std;

void booleanizzazione(vector<int> &vect)
{
	transform(vect.begin(), vect.end(), vect.begin(), [](int el) {
		if ((el % 2) == 0)
			return 0;
		else
			return 1;
	});
}

int main(int argc, char **argv)
{
	vector<int> v;
	for (int i = 0; i < 15; i++)
		v.push_back(rand() % 100);

	for (auto el : v)
		cout << el << ", ";

	cout << endl;

	booleanizzazione(v);

	for (auto el : v)
		cout << el << ", ";
		
	cout << endl;

	return 0;
}
