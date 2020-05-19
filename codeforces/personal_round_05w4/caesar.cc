#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


const int kMod = 100000000;


vector<vector<int>> GenSplit(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int i = 1; i <= k && i <= n; ++i)
        dp[i][1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int v = 1; v <= k && v < i; ++v) {
                dp[i][j] += dp[i-v][j-1];
                dp[i][j] %= kMod;
            }
        }
    }

    return dp;
}

int main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    if (n1 > n2) {
        swap(n1, n2);
        swap(k1, k2);
    }

    auto split1 = GenSplit(n1, k1);
    auto split2 = GenSplit(n2, k2);

    long long total = 0;
    for (int i = 1; i <= n1; ++i) {
        total += (1LL * split1[n1][i] * split2[n2][i-1]) % kMod;
        total += (2LL * split1[n1][i] * split2[n2][i]) % kMod;
        if (i + 1 <= n2)
            total += (1LL * split1[n1][i] * split2[n2][i+1]) % kMod;
        total %= kMod;
    }
    cout << total << endl;
}
