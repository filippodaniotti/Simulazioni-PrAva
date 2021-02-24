#include <iostream>
#include <string>
using namespace std;

class Pinguino
{
private:
	int zampe;
	int age;
	string nome;

public:
	Pinguino(int _z, int _a, string _n);

	Pinguino operator+(const Pinguino &other) const;
	Pinguino &operator++();
	Pinguino operator++(int);
	bool operator<(const Pinguino &other);
	void operator()(const string &cibo);
};

Pinguino::Pinguino(int _z, int _a, string _n)
{
	zampe = _z;
	age = _a;
	nome = _n;
}

Pinguino Pinguino::operator+(const Pinguino &other) const
{
	return Pinguino(zampe + other.zampe, 0, nome);
}

Pinguino &Pinguino::operator++()
{
	++(this->zampe);
	return *this;
}

Pinguino Pinguino::operator++(int)
{
	Pinguino temp(*this);
	++zampe;
	return temp;
}

bool Pinguino::operator<(const Pinguino &other)
{
	return zampe < other.zampe;
}

void Pinguino::operator()(const string &cibo)
{
	cout << "Il pinguino " << nome << " ha mangiato " << cibo << endl;
}

int main(int argc, char **argv)
{

	Pinguino p1(2, 4, "Gilgamesh");
	Pinguino p2(2, 3, "Enkidu");

	Pinguino p3 = p1 + p2;

	cout << (bool)(p1 < p2) << endl;
	p2++;
	cout << (bool)(p1 < p2) << endl;

	p1("la focaccia");

	return 0;
}
