#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <map>
using namespace std;

class Alpaca
{
  private:
  	string nome;
  	int age;
  	string razza;
  public:	
	Alpaca (string _n, int _a, string _r) {
		nome = _n;
		age = _a;
		razza = _r;
	}
	friend ostream& operator << (ostream& os, const Alpaca& a);
};

class Allevatore
{
	int id;
  public:
  	Allevatore (int _id) {
  		id = _id;
	}
	friend bool operator < (const Allevatore& a, const Allevatore& b);
};

class Allevamento
{
  private:
  	list<Alpaca*> alpaca;
  public:
	void add (const Alpaca* _a) {
		alpaca.push_back(new Alpaca(*(_a)));
	}
};

ostream& operator << (ostream& os, const Alpaca& a) {
	return os << "ciao! sono " << a.nome << ", " << a.razza;
}

bool operator < (const Allevatore& a, const Allevatore& b) 
{
	return a.id < b.id;
}

int main(int argc, char** argv) {
	
	map<Allevatore, Allevamento> m;
	
	Allevatore a1(5);
	Allevatore a2(6);
	
	m.insert(pair<Allevatore, Allevamento> (a1, Allevamento()));
	m.insert(pair<Allevatore, Allevamento> (a2, Allevamento()));
	
	list<Alpaca> l;
	l.push_back(Alpaca("geronimo", 3, "lupetto"));
	l.push_back(Alpaca("zia", 4, "brunilde"));
	l.push_back(Alpaca("guantanamo", 2, "luogo geografico"));
	l.push_back(Alpaca("eta beta", 8, "paperopoli"));
	l.push_back(Alpaca("pipino", 6, "il  breve"));
	l.push_back(Alpaca("refurtiva", 4, "criminalità"));
	l.push_back(Alpaca("rubare", 3, "la droga"));
	
	
	int counter = 0; // non c'è modo di ottenere l'indice
	int iter = 0; 	 // di un elemento nella lista altrimenti
	for_each(m.begin(), m.end(), 
		[l, &counter, &iter] (pair<Allevatore, Allevamento> p) {
			for (auto it = l.begin(); it != l.end(); ++it) {
				if (iter == 0 && counter % 2 == 0) {
					p.second.add(&(*it));
				} else if (iter == 1 && counter % 2 == 1) {
					p.second.add(&(*it));
				}
			++counter;
			}
		++iter;
		}
	);
	
	return 0;
}
