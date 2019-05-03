#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void Solve(int w) {
    vector<unsigned long long> result(7);

    cout << 224 << endl;
    unsigned long long ans;
    cin >> ans;

    result[6] = (ans >> 37) & 127;
    result[5] = (ans >> 44) & 127;
    result[4] = (ans >> 56) & 127;

    cout << 56 << endl;
    cin >> ans;

    ans -= result[6] << 9;
    ans -= result[5] << 11;
    ans -= result[4] << 14;

    result[3] = (ans >> 18) & 127;
    result[2] = (ans >> 28) & 127;
    result[1] = (ans >> 56) & 127;

    for (int i = 1; i <= 6; ++i)
        cout << result[i] << " ";
    cout << endl;

    int verdict;
    cin >> verdict;
    assert(verdict==1);
}

int main() {
    int t, w;
    cin >> t >> w;

    for (int i = 0; i < t; ++i)
        Solve(w);
}
