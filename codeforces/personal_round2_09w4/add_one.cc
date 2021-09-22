#include <iostream>
#include <vector>


using namespace std;


const int kMaxM = 200010;
const int kMod = 1000000007;

int CalLength(int step, vector<int>* dp_ptr) {
    if (step <= 9)
        return 1;

    auto& dp = *dp_ptr;
    auto& result = dp[step];
    if (result != -1)
        return result;

    result = CalLength(step-10, dp_ptr) + CalLength(step-9, dp_ptr);
    result %= kMod;
    return result;
}

void Solve(vector<int>* dp_ptr) {
    int n, m;
    cin >> n >> m;

    int result = 0;
    while (n) {
        int cur = n % 10;
        result += CalLength(m+cur, dp_ptr);
        result %= kMod;

        n /= 10;
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> dp(kMaxM+1, -1);
    dp[0] = 1;
    for (int i = 0; i < t; i++)
        Solve(&dp);
}
