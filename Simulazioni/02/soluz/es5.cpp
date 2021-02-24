#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    int len = 20;
    vector<int> v;
    for (int i = 0; i < len; ++i)
    {
        v.push_back(rand() % 100 - 50);
    }

    cout << "1 positivo -> " << any_of(v.begin(), v.end(), [](int n) {
        return n > 0;
    }) << endl;

    cout << "tutti positivo -> " << all_of(v.begin(), v.end(), [](int n) {
        return n > 0;
    }) << endl;

    cout << "nessuni positivo -> " << none_of(v.begin(), v.end(), [](int n) {
        return n > 0;
    }) << endl;

    vector<int>::iterator it = ++(++(++(v.begin())));
    cout << "1 positivo nei primi 3 -> " << any_of(v.begin(), it, [](int n) {
        return n > 0;
    }) << endl;

    return 0;
}
