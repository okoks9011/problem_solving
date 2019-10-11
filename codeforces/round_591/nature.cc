#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


long long CalContrib(const vector<int>& t,
                     int x, long long a, int y, long long b, int tickets) {
    long long common = a * b / gcd(a, b);
    int common_cnt = tickets / common;
    int x_cnt = (tickets / a) - common_cnt;
    int y_cnt = (tickets / b) - common_cnt;

    long long result = 0;
    int cur = 0;
    for (int i = 0; i < common_cnt; ++i)
        result += t[cur++] * (x+y);
    for (int i = 0; i < x_cnt; ++i)
        result += t[cur++] * x;
    for (int i = 0; i < y_cnt; ++i)
        result += t[cur++] * y;
    return result;
}


void Solve() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (auto& ti : t) {
        cin >> ti;
        ti /= 100;
    }

    int x, y;
    long long a, b;
    cin >> x >> a;
    cin >> y >> b;

    long long k;
    cin >> k;

    sort(t.rbegin(), t.rend());

    if (x < y) {
        swap(x, y);
        swap(a, b);
    }

    long long left = 1;
    long long right = n;
    int result = -1;
    while (left <= right) {
        long long mid = left + (right-left) / 2;
        if (CalContrib(t, x, a, y, b, mid) >= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
        Solve();
}
