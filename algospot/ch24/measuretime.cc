#include <iostream>
#include <vector>


using namespace std;


const int kValMax = 1000000;


struct FenwickTree {
    vector<int> tree;

    FenwickTree(int n) : tree(n+1) {}

    int acc(int pos) {
        ++pos;
        int result = 0;
        while (pos > 0) {
            result += tree[pos];
            pos &= (pos - 1);
        }
        return result;
    }

    void add(int pos, int val) {
        ++pos;
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};


void Solve() {
    int n;
    cin >> n;

    int result = 0;
    FenwickTree t(kValMax);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;

        int lte = t.acc(ai);
        result += i - lte;
        t.add(ai, 1);
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
