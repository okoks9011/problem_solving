#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stone {
    int s = 0;
    int e = 0;
    int l = 0;

    Stone() = default;
    Stone(int is, int ie, int il) : s(is), e(ie), l(il) {}

    bool operator<(const Stone& other) const {
        if (e == other.e)
            return l < other.l;
        else
            return e < other.e;
    }
};

int Solve() {
    int n;
    cin >> n;

    vector<Stone> stones;
    for (int i = 0; i < n; ++i) {
        int si, ei, li;
        cin >> si >> ei >> li;
        stones.emplace_back(si, ei, li);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        sort(stones.begin(), stones.end());
        auto cur = stones.back();
        stones.pop_back();

        result += cur.e;
        for (auto& stone : stones)
            stone.e = max(stone.e-stone.l*cur.s, 0);
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
