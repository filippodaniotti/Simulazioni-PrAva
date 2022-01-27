#ifndef __ONLINE_H__
#define __ONLINE_H__


#include <iostream>
#include <string>
#include "acquisto.h"
using namespace std;

class Online: public Acquisto{
	string website;
	public:
		Online(int q, float p, string o, string w);
		ostream& stampaOperator(ostream& os)const;
		friend ostream& operator<<(ostream& os, const Online& o);

};

#endif

