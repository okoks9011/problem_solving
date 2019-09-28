#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<int> a(4);
    for (auto& ai : a)
        cin >> ai;

    int sum = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < 4; ++i) {
        if (a[i]*2 == sum) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if ((a[i]+a[j])*2 == sum) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}
