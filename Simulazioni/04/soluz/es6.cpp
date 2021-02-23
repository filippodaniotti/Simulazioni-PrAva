#include <iostream>
using namespace std;

class B;

class A
{
private:
	int n;

public:
	A(int _n)
	{
		n = _n;
	}
	friend bool operator<(const A &a, const B &b);
	friend bool operator<=(const A &a, const B &b);
};

class B
{
private:
	int n;

public:
	B(int _n)
	{
		n = _n;
	}
	friend bool operator<(const A &a, const B &b);
	friend bool operator<=(const A &a, const B &b);
};

bool operator<(const A &a, const B &b)
{
	return a.n < b.n;
}

bool operator<=(const A &a, const B &b)
{
	return a.n <= b.n;
}

bool operator<(const B &b, const A &a)
{
	return !(a <= b);
}

int main(int argc, char **argv)
{
	A a(5);
	B b(6);

	if (b < a)
		cout << "bea" << endl;
	else
		cout << "nope" << endl;

	return 0;
}
