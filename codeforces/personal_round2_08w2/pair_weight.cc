#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long


using namespace std;


void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    unordered_map<int, ll> acc;
    ll result = 0LL;
    ll cur = 0LL;
    for (int i = 0; i < n; i++) {
        int ai = a[i];
        cur += acc[ai];
        result += cur;
        acc[ai] += i+1;
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        Solve();
}
