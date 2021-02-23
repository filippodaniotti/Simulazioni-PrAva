#include <iostream>
using namespace std;

typedef enum {
	EPOC, GRUPPO, CANAGLIE
} TipoEPOC;

int main(int argc, char** argv) {
	
	TipoEPOC a = CANAGLIE;
	cout << a << endl;
	
	return 0;
}
