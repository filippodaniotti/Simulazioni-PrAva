#ifndef __ACQUISTO_H__
#define __ACQUISTO_H__

#include <iostream>
#include <string>
#include "cliente.h"
using namespace std;

class Acquisto{
	protected:
		int qta;
		float prezzo;
		string oggetto;
		Cliente* pC;
	public:
		Acquisto(int q, float p, string o);
		
		void aggiungiCliente(Cliente* p);
		virtual ostream& stampaOperator(ostream& os)const;
		friend ostream& operator<<(ostream& os, const Acquisto& a);
};

#endif


