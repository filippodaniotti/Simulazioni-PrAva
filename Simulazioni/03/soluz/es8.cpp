#include <iostream>
#include <list>
using namespace std;

typedef enum Tipocomb
{
    BEN,
    GPL,
    ZUC
};
class Motore
{
private:
    Tipocomb brucio;
    int cilindri;

public:
    Motore(int ci, Tipocomb co)
    {
        brucio = co;
        cilindri = ci;
    }
};
class Auto
{
private:
    Motore motore; // sicuramente ne deve avere uno
    Motore scorta; // Potrebbe averlo come no
public:
    Auto(int ci, Tipocomb co) : motore(ci, co), scorta(0, GPL)
    {
        //			cout << "Creazione auto" << endl;
        //			motore = Motore(ci, co);
    }
    void addMotoreSecondario(int ci, Tipocomb co)
    {
        scorta = Motore(ci, co);
    }
};

int main(int argc, char **argv)
{

    list<Auto> la;
    la.push_back(Auto(2, ZUC));
    la.push_back(Auto(3, GPL));

    return 0;
}
