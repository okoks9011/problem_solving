#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int Solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        char tmp;
        cin >> tmp;
        v[i] = tmp - '0';
    }

    int m = (v.size()+1) / 2;
    int sum = accumulate(v.begin(), v.begin()+m-1, 0);
    int result = 0;
    for (int i = m-1; i < v.size(); ++i) {
        sum += v[i];
        result = max(result, sum);
        sum -= v[i-(m-1)];
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
