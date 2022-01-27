#ifndef __NEGOZIO_H__
#define __NEGOZIO_H__

#include <iostream>
#include <string>
#include "acquisto.h"


class Negozio: public Acquisto{
	string nomeNegozio;
	public:
		Negozio(int q, float p, string o, string nome);
		ostream& stampaOperator(ostream& os)const;
		friend ostream& operator<<(ostream& os, const Negozio& n);
};

#endif

