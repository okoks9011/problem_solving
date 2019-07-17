#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(k);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        --ai;
        ++cnt[ai];
    }

    int result = (n+1) / 2;
    for (int i = 0; i < k; ++i)
        result += cnt[i] / 2;
    cout << result << endl;
}
