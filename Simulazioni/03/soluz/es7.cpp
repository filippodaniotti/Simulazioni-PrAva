#include <iostream>
using namespace std;

class B
{
public:
    int y;
};

class A
{
private:
    int i;
    B *bp;

public:
    // costruttore a un parametro
    A(int _n)
    {
        i = _n;
        bp = NULL;
    }
    // copy constructor
    A(const A &other)
    {
        cout << "copy" << endl;
        i = other.i;
        bp = new B();
        (*bp).y = other.bp->y;
    }
    // move construcotr
    A(A &&other)
    {
        cout << "move" << endl;
        i = other.i;
        bp = other.bp;
        other.bp = NULL;
    }
    // ridefinizione +
    A operator+(const A &_a) const
    {
        return A(_a.i + i);
    }
    // ridefinizione -
    A operator-(const A &_a) const
    {
        int n = _a.i - i;
        return A(n);
    }
    // ridefinizione ++pre
    A &operator++()
    {
        i++;
    }
    // ridefinizione post++
    A operator++(int)
    {
        A tmp(i);
        i++;
        return tmp;
    }
    // operatore = copia
    A &operator=(const A &other)
    {
        i = other.i;
        bp = new B();
        bp->y = other.bp->y;
        return *this;
    }
    // operatore = move
    A &operator=(A &&other)
    {
        i = other.i;
        bp = other.bp;
        other.bp = NULL;
        return *this;
    }
    // ridefinizione distruttoreH
    ~A()
    {
        delete bp;
        bp = NULL;
        cout << "A distrutto" << endl;
    }
};