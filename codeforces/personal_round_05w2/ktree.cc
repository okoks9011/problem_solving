// https://codeforces.com/problemset/problem/431/C
#include <iostream>
#include <vector>


using namespace std;


const int kMod = 1000000007;


int CalNumPath(int i, int z, int k, int d,
               vector<vector<int>>* dp_ptr) {
    if (i == 0)
        return z ? 0 : 1;
    if (i < 0)
        return 0;

    auto& dp = *dp_ptr;
    auto& result = dp[i][z];
    if (result != -1)
        return result;

    result = 0;
    for (int j = 1; j <= k; ++j) {
        if (z && j >= d)
            result += CalNumPath(i-j, 0, k, d, dp_ptr);
        else
            result += CalNumPath(i-j, z, k, d, dp_ptr);
        result %= kMod;
    }
    return result;
}


int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> dp(n+1, vector<int>(2, -1));

    cout << CalNumPath(n, 1, k, d, &dp) << endl;
}
