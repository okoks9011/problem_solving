#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void Solve(int w) {
    assert(w >= 6);

    vector<int> result(7);
    for (int i = 1; i <= 6; ++i) {
        cout << i * 50 << endl;

        unsigned long long num;
        cin >> num;
        result[i] = static_cast<int>((num >> 50) & 127);
    }

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
