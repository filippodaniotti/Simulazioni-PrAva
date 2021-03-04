#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
using namespace std;

mutex mx;

void setPari(vector<int>* dato)
{
    mx.lock();
    transform(dato->begin(), dato->end(), dato->begin(), [] (int n) {
        return n % 2 == 0 ? 0 : n;
    });
    mx.unlock();
}

void setDispari(vector<int>* dato)
{  
    mx.lock();
    transform(dato->begin(), dato->end(), dato->begin(), [] (int n) {
        return n % 2 != 0 ? 1 : n;
    });
    mx.unlock();
}

int main() {

    vector<int> dato(10);
    generate(dato.begin(), dato.end(), [] () {
        return rand () % 11;
    });

    thread t1(setPari, &dato);
    thread t2(setDispari, &dato);

    t1.join();
    t2.join();

    return 0;
}