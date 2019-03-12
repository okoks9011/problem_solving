#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int CalMaxLeastBeauty(const vector<int>& v) {
    int m = (v.size()+1) / 2;
    int sum = accumulate(v.begin(), v.begin()+m-1, 0);
    int max_sum = 0;
    for (int i = m-1; i < v.size(); ++i) {
        sum += v[i];
        max_sum = max(max_sum, sum);
        sum -= v[i-m+1];
    }

    return max_sum;
}

int Solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        char tmp;
        cin >> tmp;
        v[i] = tmp - '0';
    }

    return CalMaxLeastBeauty(v);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
