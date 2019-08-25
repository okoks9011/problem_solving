#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    long long total = 0;
    int neg_cnt = 0;
    int zero_cnt = 0;
    for (auto& ai : a) {
        if (ai > 0) {
            total += ai - 1;
        } else if (ai < 0) {
            total += -ai - 1;
            ++neg_cnt;
        } else {
            total += 1;
            ++zero_cnt;
        }
    }
    if (neg_cnt & 1 == 1 && zero_cnt == 0)
        total += 2;
    cout << total << endl;
}
