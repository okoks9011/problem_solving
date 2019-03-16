#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k, n, s;
    cin >> m >> k >> n >> s;

    vector<int> a(m);
    for (auto& ai : a)
        cin >> ai;

    unordered_map<int, int> b;
    int total = 0;
    for (int i = 0; i < s; ++i) {
        int tmp;
        cin >> tmp;
        ++b[tmp];
        ++total;
    }

    int left = 0;
    int right = -1;
    int found = 0;
    unordered_map<int, int> cnt;
    vector<int> r_loc(m, m);
    while (right < m-1) {
        while (right < m-1 && found < total) {
            ++right;
            int ai = a[right];

            auto it = b.find(ai);
            if (it != b.end() && cnt[ai] < it->second)
                ++found;
            ++cnt[ai];
        }

        while (left <= right && found == total) {
            r_loc[left] = right;
            int ai = a[left];
            --cnt[ai];

            auto it = b.find(ai);
            if (it != b.end() && cnt[ai] < it->second)
                --found;
            ++left;
        }
    }

    vector<int> result;
    cnt.clear();
    for (int i = 0; i < m; ++i) {
        int j = max(r_loc[i], i+k-1);
        if (m <= j)
            continue;
        if (i/k + (m-1-j)/k < n-1)
            continue;

        int fst = min((i/k)*k, (n-1)*k);
        for (int c = 0; c+fst < i; ++c)
            result.emplace_back(c);

        for (int c = i; c <= j; ++c)
            ++cnt[a[c]];

        int sub = (j-i+1) - k;
        for (int c = i; c <= j && sub; ++c) {
            if (cnt[a[c]] > b[a[c]]) {
                --cnt[a[c]];
                --sub;
                result.emplace_back(c);
            }
        }

        cout << result.size() << endl;
        for (auto& r : result)
            cout << r+1 << " ";
        cout << endl;
        return 0;
    }

    cout << -1 << endl;
}
