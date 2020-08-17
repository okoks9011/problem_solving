#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> DiffCnt(const vector<vector<int>>& cnt, int start, int stop) {
    vector<int> result(27);
    for (int i = 1; i <= 26; ++i)
        result[i] = cnt[stop][i] - cnt[start][i];
    return result;
}


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<vector<int>> cnt(n+1, vector<int>(27));
    for (int i = 0; i < n; ++i) {
        cnt[i+1] = cnt[i];
        cnt[i+1][a[i]] += 1;
    }

    int result = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            vector<int> first = DiffCnt(cnt, 0, i);
            vector<int> second = DiffCnt(cnt, i, j);
            vector<int> third = DiffCnt(cnt, j, n);
            for (int a = 1; a <= 26; ++a) {
                for (int b = 1; b <= 26; ++b) {
                    if (first[a] != third[a])
                        continue;
                    int cur_length = first[a] + second[b] + third[a];
                    result = max(result, cur_length);
                }
            }
        }
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
