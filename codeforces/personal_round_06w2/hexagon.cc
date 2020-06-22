#include <iostream>
#include <vector>


using namespace std;


int main() {
    vector<int> a(6);
    for (auto& ai : a)
        cin >> ai;

    int side = a[0] + a[1] + a[2];
    cout << side*side - a[0]*a[0] - a[2]*a[2] - a[4]*a[4] << endl;
}
