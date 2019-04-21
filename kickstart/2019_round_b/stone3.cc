#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

mt19937 rng(17);

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

    int result = 0;
    for (int t = 0; t < 1000; ++t) {
        int cur_result = 0;
        vector<Stone> target(stones);
        shuffle(target.begin(), target.end(), rng);
        vector<Stone> saved(target);

        for (int i = target.size()-1; i >= 0; --i) {
            auto cur = target.back();
            target.pop_back();

            cur_result += cur.e;
            for (auto& stone : target)
                stone.e -= stone.CalLose();
        }
        if (cur_result > result) {
            result = max(result, cur_result);
            for (auto& si : saved)
                cout << si.e << ", ";
            cout << endl;
            vector<Stone> target(saved);
            for (int i = target.size()-1; i >= 0; --i) {
                auto cur = target.back();
                target.pop_back();

                cout << cur.e << ": " << cur.CalLose() << ", ";
                cur_result += cur.e;
                for (auto& stone : target)
                    stone.e -= stone.CalLose();
            }
            cout << endl;
        }
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
