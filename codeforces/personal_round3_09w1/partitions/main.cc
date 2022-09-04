#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int find_odd(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int sum = 0;
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
    }

    bitset<200001> bs{1};
    for (auto& ai : a) {
        bs |= bs << ai;
    }

    if (sum % 2 == 0 && bs[sum/2]) {
        int odd_idx = find_odd(a);
        while (odd_idx == -1) {
            for (auto& ai : a) {
                ai /= 2;
            }
            odd_idx = find_odd(a);
        }
        cout << "1" << endl;
        cout << odd_idx+1 << endl;
    } else {
        cout << "0" << endl;
    }
}
