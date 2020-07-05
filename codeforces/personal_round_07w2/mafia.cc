#include <iostream>
#include <algorithm>

#define ll long long


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll sum = 0LL;
    int max_a = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        max_a = max(ai, max_a);
        sum += ai;
    }

    cout << max((sum + n - 2) / (n-1), static_cast<ll>(max_a)) << endl;
}
