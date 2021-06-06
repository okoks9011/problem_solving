#include <iostream>

#define ll long long


using namespace std;

const int kMod = 1000000007;

int main() {
    int n;
    cin >> n;

    ll start = 1;
    ll other = 0;
    for (int i = 0; i < n; ++i) {
        ll next_start = (other * 3LL) % kMod;
        ll next_other = (other * 2LL + start) % kMod;
        start = next_start;
        other = next_other;
    }
    cout << start << endl;
}
