#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    const int d = 1000000;

    ++k;
    int total = 1 + k / d;
    if (k % d)
        ++total;
    ++total;

    cout << total << endl;

    cout << -1 << " ";
    for (int i = 0; i < k/d; ++i)
        cout << d << " ";
    if (k % d)
        cout << k % d << " ";
    cout << total-1 << endl;
}
