#include <iostream>
#include <set>
using namespace std;

class Rimpianto;
template <class T>
class Cassetto;
template <class T>
ostream &operator<<(ostream &os, const Cassetto<T> &c);

template <class T>
class Cassetto
{
private:
	set<T> s;

public:
	Cassetto();

	void add(const T &t);
	friend ostream &operator<<<>(ostream &os, const Cassetto<T> &c);
};

template <class T>
Cassetto<T>::Cassetto()
{
	cout << "creato cassetto" << endl;
}

template <class T>
void Cassetto<T>::add(const T &t)
{
	s.insert(t);
}

template <class T>
ostream &operator<<(ostream &os, const Cassetto<T> &c)
{
	for (auto it = c.s.begin(); it != c.s.end(); ++it)
	{
		os << *it << " ";
	}
	return os;
}

class Rimpianto
{
	int dolore;

public:
	Rimpianto(int _d)
	{
		dolore = _d;
	}
	friend bool operator<(const Rimpianto &a, const Rimpianto &b);
	friend ostream &operator<<(ostream &os, const Rimpianto &r);
};

bool operator<(const Rimpianto &a, const Rimpianto &b)
{
	return a.dolore < b.dolore;
}
ostream &operator<<(ostream &os, const Rimpianto &r)
{
	return os << r.dolore;
}

int main(int argc, char **argv)
{

	Cassetto<Rimpianto> c;
	c.add(Rimpianto(6));
	c.add(5);
	c.add(4);
	c.add(3);

	cout << c << endl;

	return 0;
}
