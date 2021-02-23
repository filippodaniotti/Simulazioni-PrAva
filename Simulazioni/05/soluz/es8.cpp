#include <iostream>
#include <list>
using namespace std;

class Autobus;
class Autista
{
	string nome;
	list<Autobus *> bus;

public:
	Autista(string _n);
	void addAutobus(Autobus *a);
	void stampa();
	friend ostream &operator<<(ostream &os, const Autista &a);
};

class Autobus
{
	string targa;
	list<Autista *> autisti;

public:
	Autobus(const string &_t, Autista *_a);
	void addAutista(Autista *a);
	void stampa();
};

Autista::Autista(string _n)
{
	nome = _n;
}

void Autista::addAutobus(Autobus *a)
{
	bus.push_back(a);
}

void Autista::stampa()
{
	cout << "Ciao! sono l'autista " << nome << endl;
}

Autobus::Autobus(const string &_t, Autista *_a)
{
	targa = _t;
	autisti.push_back(_a);
}

void Autobus::addAutista(Autista *a)
{
	autisti.push_back(a);
}

ostream &operator<<(ostream &os, const Autista &a)
{
	return os << a.nome;
}

void Autobus::stampa()
{
	cout << "Ciao! sono l'autobus " << targa << endl;
	cout << ">>> i miei autisti sono: ";
	for (auto it = autisti.begin(); it != autisti.end(); ++it)
	{
		cout << **it << " ";
	}
}

int main(int argc, char **argv)
{

	Autista a1("Piero Cardin");
	Autobus il_5("313", &a1);

	a1.stampa();
	il_5.stampa();

	return 0;
}
