#include <iostream>
#include <string>
#include <list>
using namespace std;
typedef int piede;

class Ciabatta
{
private:
	int taglia;
	string marca;
	list<piede*> piedi;

public:
	Ciabatta(int _t, string _m);
	Ciabatta(const Ciabatta& _c);
	Ciabatta(Ciabatta&& _c);
	~Ciabatta();
	void add(piede* _p);
	friend ostream& operator<<(ostream& os, const Ciabatta& c);
};

Ciabatta::Ciabatta(int _t, string _m)
{
	taglia = _t;
	marca = _m;
	cout << "Creata una ciabatta" << endl;
}

Ciabatta::Ciabatta(const Ciabatta& _c)
{
	taglia = _c.taglia;
	marca = _c.marca;
	piedi = _c.piedi;
}

Ciabatta::Ciabatta(Ciabatta&& _c)
{
	taglia = _c.taglia;
	marca = _c.marca;
	piedi = _c.piedi;

	_c.taglia = 0;
	_c.marca = '\0';
	_c.piedi.clear();
}

Ciabatta::~Ciabatta()
{
	cout << "Distrutta una ciabatta" << endl;
}

void Ciabatta::add(piede* _p)
{
	piedi.push_back(_p);
}

ostream& operator<<(ostream& os, const Ciabatta& c)
{
	return os << c.marca << " taglia " << c.taglia;
}

int main(int argc, char **argv)
{

	Ciabatta c(4, "alemagno");
	cout << c << endl;
	c.add(new piede(6));

	return 0;
}
