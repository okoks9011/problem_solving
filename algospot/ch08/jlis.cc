#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CalJoinedLISB(const vector<int>& a, const vector<int>& b,
                  int i, int j,
                  vector<vector<int>>* dpA_ptr, vector<vector<int>>* dpB_ptr);

int CalJoinedLISA(const vector<int>& a, const vector<int>& b,
                  int i, int j,
                  vector<vector<int>>* dpA_ptr, vector<vector<int>>* dpB_ptr) {
    if (i == a.size())
        return 0;

    auto& dpA = *dpA_ptr;
    auto& result = dpA[i][j];
    if (result != -1)
        return result;

    result = 1;
    for (int k = i+1; k < a.size(); ++k) {
        if (a[i] < a[k])
            result = max(result, 1+CalJoinedLISA(a, b, k, j, dpA_ptr, dpB_ptr));
    }
    for (int k = j; k < b.size(); ++k) {
        if (a[i] < b[k])
            result = max(result, 1+CalJoinedLISB(a, b, i+1, k, dpA_ptr, dpB_ptr));
    }
    return result;
}

int CalJoinedLISB(const vector<int>& a, const vector<int>& b,
                  int i, int j,
                  vector<vector<int>>* dpA_ptr, vector<vector<int>>* dpB_ptr) {
    if (j == b.size())
        return 0;

    auto& dpB = *dpB_ptr;
    auto& result = dpB[i][j];
    if (result != -1)
        return result;

    result = 1;
    for (int k = j+1; k < b.size(); ++k) {
        if (b[j] < b[k])
            result = max(result, 1+CalJoinedLISB(a, b, i, k, dpA_ptr, dpB_ptr));
    }
    for (int k = i; k < a.size(); ++k) {
        if (b[j] < a[k])
            result = max(result, 1+CalJoinedLISA(a, b, k, j+1, dpA_ptr, dpB_ptr));
    }
    return result;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> b(m);
    for (auto& bi : b)
        cin >> bi;

    vector<vector<int>> dpA(n+1, vector<int>(m+1, -1));
    vector<vector<int>> dpB(n+1, vector<int>(m+1, -1));
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result = max(result, CalJoinedLISA(a, b, i, j, &dpA, &dpB));
            result = max(result, CalJoinedLISB(a, b, i, j, &dpA, &dpB));
        }
    }
    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
