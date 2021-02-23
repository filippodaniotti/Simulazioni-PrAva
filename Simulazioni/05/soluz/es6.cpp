#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex hip;
// mutex hop;

class Stampella
{
private:
	int n;
public:
	Stampella(int _n);
	void saltello(int x);
	void operator()();
};

Stampella::Stampella(int _n)
{
	n = _n;
	hip.lock();
}

void Stampella::saltello(int x)
{
	hip.lock();
	for (auto i = 0; i < x * n; ++i)
	{
		cout << "hip";
	}
	cout << endl;
}

void Stampella::operator()()
{
	// hop.lock();
	for (auto i = 0; i < n; ++i)
	{
		cout << "hop";
	}
	cout << endl;
	// hop.unlock();
	hip.unlock();
}

int main(int argc, char **argv)
{

	Stampella s1(5);
	Stampella s2(8);

	thread t1(s1);
	thread t2(Stampella::saltello, &s2, 2);

	t1.join();
	t2.join();

	return 0;
}
