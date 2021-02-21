#include <iostream>
#include <list>
using namespace std;

typedef enum Tristezza {
    MALESSERE, SOFFERENZA, DEPRESSIONE
};

class Condimento;
class Piatto;
class Pasto;
class Mensa;

class Condimento
{
    int costo;
    string nome;
public:
    Condimento (int _c, string _n)
    {
        costo = _c;
        nome = _n;
    }
    friend ostream& operator << (ostream& os, const Condimento& c);
};

ostream& operator << (ostream& os, const Condimento& c) 
{
    os << c.costo << c.nome;
}

class Piatto
{
    string nome;
    Condimento* c;
public:
    Piatto (string _n, Condimento* _c = nullptr)
    {
        nome = _n;
        c = _c;
    }
    friend ostream& operator << (ostream& os, const Piatto& p);
};

ostream& operator << (ostream& os, const Piatto& p)
{
    os << p.nome;
    if (p.c != nullptr) {
        os << "condimento: " << *(p.c);
    }
    return os;
}

class Pasto
{
    Tristezza t;
    list<Piatto> primi;
    Piatto* secondo;
public:
    Pasto (Tristezza _t, string _n, Condimento* _c = nullptr)
    {
        Piatto _p(_n, _c);
        t = _t;
        primi.push_back(_p);
        secondo = nullptr;
    }
    friend ostream& operator << (ostream& os, const Pasto& p);
};

ostream& operator << (ostream& os, const Pasto& p)
{
    for (auto it = p.primi.begin(); it != p.primi.end(); ++it) {
        os << *it << " ";
    }
    if (p.secondo != nullptr) {
        os << "secondo: " << *(p.secondo);
    }
    return os;
}

class Mensa
{
    list<Pasto> pasti;
    list<Condimento> condimenti;
public:
    Mensa (Condimento _c)
    {
        condimenti.push_back(_c);
    }
};

int main() {

    Condimento c1(4, "sale");
    Pasto p(SOFFERENZA, "demotivazione ", &c1);
    cout << c1 << endl;
    cout << p << endl;

    return 0;
}