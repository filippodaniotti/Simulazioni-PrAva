#include <iostream>
#include <algorithm>
#include <list>
#include <ctime>
#include <string>
using namespace std;

void print(list<string> &l)
{
    for (auto &i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}

list<string>::iterator getIt(list<string> &p, const int &n)
{
    list<string>::iterator it = p.begin();
    for (int i = 0; i < n; ++i)
    {
        ++it;
    }
    return it;
}

int main()
{

    srand(time(NULL));

    list<string> p;
    p.push_back("Jony");
    p.push_back("Gigi");
    p.push_back("Stasi");
    p.push_back("Cuatro");
    p.push_back("Dava");
    int len = p.size();
    print(p);

    for (int i = 0; i < 2; ++i)
        p.insert(getIt(p, rand() % len + 1), 1, "Paolo");
    for (int i = 0; i < 3; ++i)
        p.insert(getIt(p, rand() % len + 1), 1, "Giovanni");
    print(p);

    list<string>::iterator fin = p.begin();
    list<string>::iterator mid = p.begin();
    for (int i = 0; i < 7; ++i)
    {
        ++fin;
        if (i < 3)
            ++mid;
    }
    rotate(p.begin(), mid, fin);
    print(p);

    string s1 = "Paolo";
    string s2 = "Franco";
    replace(p.begin(), p.end(), s1, s2);
    print(p);

    /**
     * Il metodo remove della libreria algorithm in realtà non rimuove niente,
     * bensì prende gli elementi uguali (op. ==) al terzo argomento e li
     * sposta in fondo al vettore, e ritorna un iteratore che punta al primo
     * elemento rimosso.
     * Il lavoro di cancellare gli elementi viene fatto dal metodo erare() 
     * di std::list<>, che per l'appunto elimina dalla lista gli elementi
     * compresi tra i due iteratori passati; è per questo che noi inseriamo
     * remove() come primo parametro di p.erase().
     */
    p.erase(
        remove(p.begin(), getIt(p, 6), "Franco")),
        p.end();
    print(p);

    for_each(p.begin(), p.end(),
             [](string s) {
                 if (s.length() <= 5)
                     cout << s << " ";
             });

    return 0;
}