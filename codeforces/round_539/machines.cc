#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int MinDiff(int ai, int aj) {
    int result = 0;
    for (int i = 2; i < ai; ++i) {
        if (ai % i == 0) {
            int new_ai = ai / i;
            int new_aj = aj * i;
            result = min(result, (new_ai+new_aj)-(ai+aj));
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    deque<bool> freq(101);
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        freq[ai] = true;
        result += ai;
    }

    vector<pair<int, pair<int, int>>> pre;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            int diff = MinDiff(i, j);
            if (diff != 0)
                pre.emplace_back(diff, make_pair(i, j));
        }
    }
    sort(pre.begin(), pre.end());

    for (auto& p : pre) {
        auto& a = p.second;
        if (freq[a.first] && freq[a.second]) {
            result += p.first;
            break;
        }
    }

    cout << result << endl;
}
