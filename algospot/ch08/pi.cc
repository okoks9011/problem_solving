#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

const int kInf = 987654321;

using namespace std;

int CalSegLevel(const string& s, int start, int end) {
    auto m = s.substr(start, end-start);

    if (m == string(m.size(), m[0]))
        return 1;

    bool alter = true;
    for (int i = 2; i < m.size() && alter; ++i) {
        if (m[i%2] != m[i])
            alter = false;
    }
    if (alter)
        return 4;

    bool arith = true;
    for (int i = 1; i < m.size()-1 && arith; ++i) {
        if (m[i]-m[i-1] != m[i+1]-m[i])
            arith = false;
    }
    if (arith) {
        if (abs(m[0] - m[1]) == 1)
            return 2;
        else
            return 5;
    }

    return 10;
}

int CalMinLevel(const string& s, int i, vector<int>* dp_ptr) {
    if (i == s.size())
        return 0;

    auto& dp = *dp_ptr;
    auto& result = dp[i];
    if (result != -1)
        return result;

    result = kInf;
    for (int j = i+3; j <= i+5 && j <= s.size(); ++j)
        result = min(result, CalSegLevel(s, i, j)+CalMinLevel(s, j, dp_ptr));

    return result;
}

void Solve() {
    string s;
    cin >> s;

    vector<int> dp(s.size(), -1);
    cout << CalMinLevel(s, 0, &dp) << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
