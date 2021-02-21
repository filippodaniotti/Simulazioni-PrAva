#include <iostream>
#include <list>
using namespace std;

class Verdura
{
    int tristezza;

public:
    Verdura(int i)
    {
        tristezza = i;
    }
    friend ostream &operator<<(ostream &os, const Verdura &v);
};

ostream &operator<<(ostream &os, const Verdura &v)
{
    cout << v.tristezza;
}

class Minestrone
{
    list<Verdura *> v;

public:
    Minestrone();
    Minestrone(const Minestrone &other);
    Minestrone(Minestrone &&other);
    void add(Verdura *_v);
    friend ostream &operator<<(ostream &os, const Minestrone &m);
};

Minestrone::Minestrone()
{
    cout << "creato minestrone" << endl;
}

Minestrone::Minestrone(const Minestrone &other)
{
    v = other.v;
}

Minestrone::Minestrone(Minestrone &&other)
{
    for (auto it = other.v.begin(); it != other.v.end(); ++it)
    {
        v.push_back(*it);
        *it = nullptr;
    }
}

void Minestrone::add(Verdura *_v)
{
    v.push_back(_v);
}

ostream &operator<<(ostream &os, const Minestrone &m)
{
    os << "Il minestrone oggi ha tristezza ";
    for (auto it = m.v.begin(); it != m.v.end(); ++it)
    {
        if (*it != nullptr)
            os << **it;
        else
            os << "o";
    }
    return os;
}

int main()
{

    Verdura v1(5);
    Verdura v2(2);
    Verdura v3(9);
    cout << v1 << v2 << v3 << endl;

    Minestrone m;
    m.add(&v1);
    m.add(&v2);
    m.add(&v3);

    Minestrone m2(m);
    m2.add(&v2);
    m2.add(&v2);
    m2.add(&v2);
    cout << m << endl;
    cout << m2 << endl;

    Minestrone m3(std::move(m2));

    cout << m << endl;
    cout << m2 << endl;
    cout << m3 << endl;

    return 0;
}