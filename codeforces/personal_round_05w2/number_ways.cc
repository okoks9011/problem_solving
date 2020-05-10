// https://codeforces.com/problemset/problem/466/C
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <functional>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto& ai : a)
        cin >> ai;

    long long sum = accumulate(a.begin(), a.end(), 0LL);

    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    long long target_sum = sum / 3;

    priority_queue<long long, vector<long long>, greater<>> min_pq;
    long long cur_sum = 0;
    for (int i = n-1; i >= 0; --i) {
        cur_sum += a[i];
        if (cur_sum == target_sum)
            min_pq.emplace(i-1);
    }

    long long result = 0;
    cur_sum = 0;
    for (int i = 0; i < n; ++i) {
        cur_sum += a[i];
        if (cur_sum != target_sum)
            continue;

        while (!min_pq.empty() && min_pq.top() <= i)
            min_pq.pop();
        result += min_pq.size();
    }

    cout << result << endl;
}
