#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void positivizza(list<int>& l) {
    transform(l.begin(), l.end(), l.begin(),
        [l] (int n) mutable {
            return n > 0 ? n : 0;
        }
    );
}

int main() {

    list<int> l = {1,3,-6,2,-3,6,1,-3,5,-1,3,5,3};

    positivizza(l);

    for(auto& item : l) {
        cout << item << " ";
    }

    return 0;
}