#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int min_j = 1;
    int max_j = m;
    while (min_j < max_j) {
        for (int i = 1; i <= n; ++i) {
            cout << i << " " << min_j << endl;
            cout << n+1-i << " " << max_j << endl;
        }
        ++min_j;
        --max_j;
    }
    if (min_j == max_j) {
        int min_i = 1;
        int max_i = n;
        while (min_i < max_i) {
            cout << min_i << " " << min_j << endl;
            cout << max_i << " " << min_j << endl;
            ++min_i;
            --max_i;
        }
        if (min_i == max_i)
            cout << min_i << " " << min_j << endl;
    }
}
