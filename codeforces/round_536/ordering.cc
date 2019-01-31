#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Dish {
    int c = 0;
    int origin_idx = 0;
    int a = 0;

    bool operator<(const Dish& other) const {
        if (c == other.c)
            return origin_idx < other.origin_idx;
        return c < other.c;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Dish> d(n);
    for (int i = 0; i < n; ++i)
        d[i].origin_idx = i+1;

    for (auto& di : d)
        cin >> di.a;

    for (auto& di : d)
        cin >> di.c;

    sort(d.begin(), d.end());

    vector<int> conv(n+1);
    for (int i = 0; i < n; ++i)
        conv[d[i].origin_idx] = i;

    vector<pair<int, int>> customers(m);
    for (auto& p : customers)
        cin >> p.first >> p.second;

    int cheap = 0;
    for (auto& p : customers) {
        long long cost = 0;
        while (p.second != 0) {
            if (cheap == d.size()) {
                cost = 0;
                break;
            }
            int picked = conv[p.first];
            if (d[picked].a == 0)
                picked = cheap;

            int eat = min(d[picked].a, p.second);
            cost += 1LL * eat * d[picked].c;
            d[picked].a -= eat;
            p.second -= eat;

            while (cheap < d.size() && d[cheap].a == 0)
                ++cheap;
        }
        cout << cost << endl;
    }
}
