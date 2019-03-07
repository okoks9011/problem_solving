#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Matched(const string& pat, const string& target, int i, int j,
            vector<vector<int>>* dp_ptr) {
    if (pat.size() <= i && target.size() <= j)
        return 1;
    if (pat.size() <= i || (target.size() <= j && pat[i] != '*'))
        return 0;

    auto& dp = *dp_ptr;
    auto& result = dp[i][j];
    if (result != -1)
        return result;

    if (pat[i] == '*') {
        result = Matched(pat, target, i+1, j, dp_ptr);
        if (j < target.size())
            result |= Matched(pat, target, i, j+1, dp_ptr);
    } else if (pat[i] == target[j] || pat[i] == '?') {
        result = Matched(pat, target, i+1, j+1, dp_ptr);
    } else {
        result = 0;
    }
    return result;
}

void Solve() {
    string pat;
    cin >> pat;

    int n;
    cin >> n;

    vector<string> result;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        vector<vector<int>> dp(pat.size()+1, vector<int>(tmp.size()+1, -1));
        if (Matched(pat, tmp, 0, 0, &dp))
            result.emplace_back(tmp);
    }

    sort(result.begin(), result.end());
    for (auto& s : result)
        cout << s << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
