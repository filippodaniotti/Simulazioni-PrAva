#include <iostream>
#include <map>
using namespace std;

void stampaOrdineDEC(map<string, int>& parcheggi) 
{
    // una multimap è ordinata in ordine decrescente
    // rispetto alla chiave
    multimap<int, string> _p;   
    for (auto it = parcheggi.begin(); it != parcheggi.end(); ++it) {
        _p.insert({it->second, it->first});
    }

    for (auto& p : _p) {
        cout << "Nome " << p.second << " posti " << p.first << endl;;
    }
}

int main() {

    map<string, int> parcheggi;
    parcheggi.insert({"FIERA", 200});
    parcheggi.insert({"FLAVIO", 250});
    parcheggi.insert({"FLUENTE", 200});

    stampaOrdineDEC(parcheggi);

    return 0;
}