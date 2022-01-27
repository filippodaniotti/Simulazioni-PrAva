#include "acquisto.h"

Acquisto::Acquisto(int q, float p, string o){
	qta = q;
	prezzo = p;
	oggetto = o;
	pC = NULL;
}

ostream& Acquisto::stampaOperator(ostream& os)const{
	os << qta << " " << prezzo <<  " " << oggetto;
	return os;
}

void Acquisto::aggiungiCliente(Cliente* p){
	pC = p;
}

ostream& operator<<(ostream& os, const Acquisto& a){
	return a.stampaOperator(os);
}
