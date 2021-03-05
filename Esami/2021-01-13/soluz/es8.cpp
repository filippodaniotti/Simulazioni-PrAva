#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, char** argv) {
	
	multimap<string, int> m;
	m.insert(pair<string, int> ("A", 3));
	m.insert(pair<string, int> ("A", 4));
	m.insert(pair<string, int> ("C", 3));
	m.insert(pair<string, int> ("W", 12));
	m.insert(pair<string, int> ("Fsad", 12));
	m.insert(pair<string, int> ("CCC", 13));
	m.insert(pair<string, int> ("A", 13));
	m.insert(pair<string, int> ("NN", 33));
	m.insert(pair<string, int> ("B", 3));
	m.insert(pair<string, int> ("A", 16));
	
	multimap<int, string> im;
	for (auto& p : m) {
		im.insert({p.second, p.first});
	}

	return 0;
}
