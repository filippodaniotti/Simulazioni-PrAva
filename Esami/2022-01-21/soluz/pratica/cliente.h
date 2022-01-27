#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include <string>
#include <iostream>
#include <list>
using namespace std;
class Acquisto;
class Cliente{
	int idCliente;
	string nome;
	list<Acquisto*> acquisti;
	public: 
		Cliente();
		Cliente(int id, string n);
	
		friend ostream& operator<<(ostream& os, const Cliente& c);
		
};

#endif

