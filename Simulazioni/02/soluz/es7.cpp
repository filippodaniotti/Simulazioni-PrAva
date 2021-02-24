#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{

	bitset<64> b;
	istringstream("101000000010101010010110101101") >> b;
	//	b = bitset<64>("101000000010101010010110101101");
	cout << b << endl;
	b >>= 4;
	cout << b << endl;
	cout << b.to_ullong() << endl;
	b.reset(17);
	cout << b << endl;
	cout << b.flip() << endl;
	cout << ~b << endl;

	return 0;
}
