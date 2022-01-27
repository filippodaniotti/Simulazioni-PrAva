#include "cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
	idCliente = 0;
	nome = "";
}
Cliente::Cliente(int id, string n){
		
	idCliente = id;
	nome = n;
	
}

ostream& operator<<(ostream& os, const Cliente& c){
	return os << c.idCliente << " " << c.nome;
}
