#include <iostream>
using namespace std;

class A
{
    const int ci;
    const float cf;
    static int si;
    static float sf; 
public:
    A (int _ci, float _cf);
    static void print()
    {
        cout << si << sf << endl;
    }
    void out()
    {
        cout << ci << cf;
    }
};

A::A (int _ci, float _cf)
    : ci(_ci)
    , cf(_cf)
{
    cout << "inizializzati" << endl;
}

int A::si = 42;
float A::sf = 3.14;

int main() {

    A a(1, 1.0);
    a.out();
    a.print();

    return 0;
}