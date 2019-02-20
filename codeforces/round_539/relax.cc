#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<unordered_map<int, int>> cnt(2);
    cnt[0][0] = 1;
    long long result = 0;
    int acc = 0;
    for (int i = 1; i <= n; ++i) {
        acc ^= a[i];
        result += cnt[i%2][acc];
        ++cnt[i%2][acc];
    }

    cout << result << endl;
}
