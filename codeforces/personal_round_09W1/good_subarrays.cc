#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    string a;
    cin >> a;

    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int acc = 0;
    long long result = 0LL;
    for (int i = 1; i <= n; ++i) {
        acc += a[i-1] - '0';
        int diff = acc - i;
        result += cnt[diff];
        ++cnt[diff];
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
