#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "cliente.h"
#include "negozio.h"
#include "online.h"
#include "acquisto.h"

#include <map>
#include <list>

Acquisto* initDato(int qualeIstanza, map<int,Cliente>& clienti){
	int qta = rand()%9 + 1;
	string dato;
	cin >> dato;
	int id = rand()%5 + 1;
	float prezzo = 1.0;
	if(qualeIstanza == 1){
		Acquisto* a = new Online(qta,prezzo,"ABC",dato);
		if(clienti.find(id)!=clienti.end()){
			a->aggiungiCliente(&clienti.find(id)->second);
		}else{
			throw "Id non valido!";
		}
		return a;
	}else{
		Acquisto* a= new Negozio(qta,prezzo,"ABC",dato);
		if(clienti.find(id)!=clienti.end()){
			a->aggiungiCliente(&clienti.find(id)->second);
		}else{
			throw "Id non valido!";
		}
		return a;
	}
}

int main(int argc, char** argv) {
	
	map<int,Cliente> clienti;
	clienti[1] = Cliente(1,"Marco");
	clienti[2] = Cliente(2,"Lucia");
	clienti[3] = Cliente(3,"Luca");
	
	//Acquisto* a = new Online(1,1.0,"ABC","E");
	
	list<Acquisto*> acquisti;
	for(int i=0;i<6;i++){
		try{
			acquisti.push_back(initDato(rand()%2,clienti));
		}catch(const char* msg){
			cout << msg << endl;
		}		
	}
	for(auto& t : clienti){
		cout << t.first << endl;
		cout << t.second << endl;
	}
	
	
	return 0;
}
