#include <iostream>
#include <thread>
#include <functional>
#include <string>
#include <mutex>

using namespace std;

int N = 20;

int main(int argc, char **argv)
{
	mutex mmm;

	function<void(string, int)> stampaStrana = [](string s, int n) {
		for (int i = 0; i < n; ++i)
		{
			cout << s;
		}
	};

	thread t1(stampaStrana, "tanti", N);
	thread t2(stampaStrana, "ionico", N);

	t1.join();
	t2.join();

	return 0;
}
