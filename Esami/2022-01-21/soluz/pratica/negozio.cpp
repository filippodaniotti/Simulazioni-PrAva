#include "negozio.h"

Negozio::Negozio(int q, float p, string o, string nome):Acquisto(q,p,o){
	nomeNegozio = nome;
}
		
ostream& Negozio::stampaOperator(ostream& os)const{
	os << qta << " " << prezzo <<  " " << oggetto;
	os << nomeNegozio;
	return os;
}
ostream& operator<<(ostream& os, const Negozio& n){
	return n.stampaOperator(os);
}
