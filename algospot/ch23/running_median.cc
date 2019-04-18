#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cassert>

using namespace std;

const int kMod = 20090711;

struct Seq {
    int a = 0;
    int b = 0;
    int cur = 1983;

    Seq(int ia, int ib) : a(ia), b(ib) {}

    int operator*() {
        return cur;
    }

    Seq& operator++() {
        cur = static_cast<int>((1LL*cur*a+b) % kMod);
        return *this;
    }
};

void Solve() {
    int n, a, b;
    cin >> n >> a >> b;

    Seq s = Seq(a, b);

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int ai = *s;
        ++s;
        if (max_heap.empty() || max_heap.top() >= ai)
            max_heap.emplace(ai);
        else
            min_heap.emplace(ai);

        if (min_heap.size() > max_heap.size()) {
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
        if (max_heap.size() - min_heap.size() >= 2) {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }
        assert(max_heap.size() == min_heap.size() ||
               max_heap.size() == min_heap.size()+1);

        result += max_heap.top();
        result %= kMod;
    }

    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
