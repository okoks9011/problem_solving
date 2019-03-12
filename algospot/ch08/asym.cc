#include <iostream>
#include <vector>

using namespace std;

const int kDiv = 1000000007;

int CalPlace(int i, vector<int>* dp_ptr) {
    if (i < 0)
        return 0;
    if (i == 0)
        return 1;

    auto& dp = *dp_ptr;
    auto& result = dp[i];
    if (result != -1)
        return result;

    result = (CalPlace(i-1, dp_ptr) + CalPlace(i-2, dp_ptr)) % kDiv;
    return result;
}

void Solve() {
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);
    int result = CalPlace(n, &dp);
    result += kDiv - CalPlace(n/2, &dp);
    result %= kDiv;

    if (n % 2 == 0) {
        result += kDiv - CalPlace(n/2-1, &dp);
        result %= kDiv;
    }

    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
