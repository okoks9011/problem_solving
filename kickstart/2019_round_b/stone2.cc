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

    int CalLose() const {
        return min(e, s*l);
    }

    bool operator<(const Stone& other) const {
        return this->CalLose() < other.CalLose();
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

    vector<Stone> target;
    int result = 0;
    for (auto& stone : stones) {
        if (stone.l)
            target.emplace_back(stone);
        else
            result += stone.e;
    }

    for (int i = target.size()-1; i >= 0; --i) {
        sort(target.begin(), target.end());
        auto cur = target.back();
        target.pop_back();

        cout << cur.e << ": " << cur.CalLose() << ", ";
        result += cur.e;
        for (auto& stone : target)
            stone.e -= stone.CalLose();
    }
    cout << endl;
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
