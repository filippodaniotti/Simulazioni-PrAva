#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Tesoro
{
private:
	int valore;

public:
	Tesoro();
	Tesoro(int v);

	friend ostream &operator<<(ostream &os, const Tesoro &t);
};

// 
Tesoro::Tesoro()
{
	valore = 0;
}

ostream &operator<<(ostream &os, const Tesoro &t)
{
	return os << " valore: " << t.valore;
}

Tesoro::Tesoro(int v)
{
	valore = v;
}

int main(int argc, char **argv)
{

	map<string, Tesoro> m;
	m["all'angolo dello sfizio"] = Tesoro(5);
	m["nella credenza della nonna"] = Tesoro(90);
	m["nella lettera del prof. oak"] = Tesoro(24);
	m["dietro il tuo orecchio sinistro"] = Tesoro(457);
	m["dentro il tuo cuore"] = Tesoro(135);

	for_each(m.begin(), m.end(), [] (pair<string, Tesoro> p) {
		cout << "Tesoro " << p.first << p.second << endl;
	});

	return 0;
}
