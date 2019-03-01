#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool Place(vector<pair<int, int>> pos, vector<vector<int>>* result_ptr, priority_queue<pair<int, int>>* max_heap_ptr) {
    auto& max_heap = *max_heap_ptr;
    auto cur = max_heap.top();
    max_heap.pop();
    if (cur.first < pos.size())
        return false;

    auto& result = *result_ptr;
    for (auto& p : pos)
        result[p.first][p.second] = cur.second;

    cur.first -= pos.size();
    max_heap.push(cur);
    return true;
}

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;
    for (int i = 0; i < n*n; ++i) {
        int a;
        cin >> a;
        ++freq[a];
    }

    priority_queue<pair<int, int>> max_heap;
    for (auto& p : freq)
        max_heap.emplace(p.second, p.first);

    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            int rev_i = n-1-i;
            int rev_j = n-1-j;
            if (!Place({{i, j}, {rev_i, j}, {i, rev_j}, {rev_i, rev_j}}, &result, &max_heap)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (n % 2) {
        for (int i = 0; i < n/2; ++i) {
            int rev_i = n-1-i;
            if (!Place({{i, n/2}, {rev_i, n/2}}, &result, &max_heap) ||
                !Place({{n/2, i}, {n/2, rev_i}}, &result, &max_heap)) {
                cout << "NO" << endl;
                return 0;
            }

        }
        if (!Place({{n/2, n/2}}, &result, &max_heap)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (auto& row : result) {
        for (auto& aij : row)
            cout << aij << " ";
        cout << endl;
    }
}
