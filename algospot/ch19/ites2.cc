#include <iostream>
#include <deque>

using namespace std;

struct Seq {
    unsigned int ai = 1983;

    Seq& operator++() {
        ai = ai * 214013 + 2531011;
        return *this;
    }
    int operator*() {
        return ai % 10000 + 1;
    }
};

void Solve() {
    int k, n;
    cin >> k >> n;

    int acc = 0;
    int result = 0;
    deque<int> q;
    Seq s;
    for (int i = 0; i < n; ++i) {
        q.emplace_back(*s);
        acc += *s;
        ++s;

        while (!q.empty() && acc > k) {
            acc -= q.front();
            q.pop_front();
        }

        if (acc == k)
            ++result;
    }

    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
