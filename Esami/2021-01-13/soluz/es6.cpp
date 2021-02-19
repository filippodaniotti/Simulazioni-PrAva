#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

class Persona
{
    string fn, ln;
    int age;
public:
    Persona (string _fn, string _ln, int _a);
    int getAge() const; // per velocità non c'avevo sbatti di ridefinire <
    friend ostream& operator << (ostream& os, const Persona& p);
};

int Persona::getAge() const
{
    return age;
}

ostream& operator << (ostream& os, const Persona& p)
{
    return os << p.fn << p.ln << p.age;
}

Persona::Persona (string _fn, string _ln, int _a) 
{
    fn = _fn;
    ln = _ln;
    age = _a;
}

list<Persona> createList (string _fn, string _ln, int _a)
{
    list<Persona> l;
    l.push_back(Persona(_fn, _ln, _a));
    l.push_back(Persona(_ln, _fn, _a * 3));
    return l;
}

Persona addPersona (string _fn, string _ln, int _a)
{
    return Persona(_fn, _ln, _a);
}

int main() {

    map<string, list<Persona>> m;
    m["a"] = createList("Mario", "Lin", 15);
    m["b"] = createList("Gero", "Lin", 12);
    m["c"] = createList("Furbo", "Lin", 5);

    for (auto it = m.begin(); it != m.end(); ++it) {
        for (auto lit = (it->second).begin(); lit != (it->second).end(); ++lit) {
            cout << *lit << endl;
        }
    }

    int age_lim = 30;
    for (auto it = m.begin(); it != m.end(); ++it) {
        (it->second).erase(
            remove_if((it->second).begin(), (it->second).end(), 
                [age_lim] (auto e) {
                    return e.getAge() < age_lim;
                }
            )
        );
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        for (auto lit = (it->second).begin(); lit != (it->second).end(); ++lit) {
            cout << *lit << endl;
        }
    }

    return 0;
}