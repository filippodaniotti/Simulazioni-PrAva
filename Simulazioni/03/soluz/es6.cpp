#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    list<char> l;
    string alfabeto = "qwertyuiopasdfghjklzxcvbnm";
    //		alfabeto = "bucefalo";
    for (int i = 0; i < 8; i++)
    {
        int rand_index = rand() % alfabeto.length();
        char c = alfabeto[rand_index];
        l.push_back(c);
    }
    //		for(int i = 0; i<8; i++){
    //			char c = alfabeto[i];
    //			l.push_back(c);
    //		}
    //
    cout << "[";
    for (auto car : l)
    {
        cout << car << " ";
    }
    cout << "]" << endl;

    bool am = all_of(l.begin(), l.end(), [](char c) {
        if (c >= 'a' && c <= 'm')
        {
            return true;
        }
        return false;
    });

    bool xyz = any_of(l.begin(), l.end(), [](char c) {
        if (c == 'x' || c == 'y' || c == 'z')
        {
            return true;
        }
        return false;
    });

    list<char> b;
    for (char c : "bucefalo")
    {
        b.push_back(c);
    }
    bool bucefalo = is_permutation(l.begin(), l.end(), b.begin());

    cout << "tutti nell'intervallo a-m? " << am << endl;
    cout << "almeno uno tra x y o z? " << xyz << endl;
    cout << "un bucefalo? " << bucefalo << endl;

    list<char>::iterator toBeRemoved;
    toBeRemoved = adjacent_find(l.begin(), l.end());
    while (toBeRemoved != l.end())
    {
        l.erase(toBeRemoved);
        toBeRemoved = adjacent_find(l.begin(), l.end());
    }

    cout << "eliminate le adiacenti: " << endl;
    cout << "[";
    for (auto car : l)
    {
        cout << car << " ";
    }
    cout << "]" << endl;
}