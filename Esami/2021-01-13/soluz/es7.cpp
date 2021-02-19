#include <iostream>
using namespace std;

int compute(int exp, int x) {
	if (exp < 0)
		throw "Esponente negativo";
	if (exp == 0)
		throw "Esponente 0";
	if (x < 0)
		throw "Base negativa";
	int result = x;
	for (int i = 1; i < exp; ++i) {
		result *= x;
	}
	return result;
}

int esponenteKu(int exp, int x) {
	int value;
	try {
		value = compute(exp, x);
	} catch (const char *msg) {
		cout << msg << endl;
		value = 0;
	}
	return 0;
}

int main(int argc, char** argv) {
	
	cout << esponenteKu(5,2);
	
	return 0;
}
