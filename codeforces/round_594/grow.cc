#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;
    sort(a.begin(), a.end());

    long long total = accumulate(a.begin(), a.end(), 0);
    long long half = 0;
    for (int i = n/2; i < n; ++i)
        half += a[i];
    long long result = half * half + (total - half) * (total - half);
    cout << result << endl;
}
