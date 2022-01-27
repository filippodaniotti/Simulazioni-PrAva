
#include "online.h"

Online::Online(int q, float p, string o, string w):Acquisto(q,p,o){
	website = w;
}
		
ostream& Online::stampaOperator(ostream& os)const{
	os << qta << " " << prezzo <<  " " << oggetto;
	os << website;
	return os;
}
ostream& operator<<(ostream& os, const Online& o){
	return o.stampaOperator(os);
}

