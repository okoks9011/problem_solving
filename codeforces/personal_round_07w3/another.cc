#include <iostream>
#include <vector>
#include <string>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    string s;
    cin >> s;

    int cur = 0;
    vector<int> zeros;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            ++cur;
        } else {
            zeros.emplace_back(cur);
            cur = 0;
        }
    }
    zeros.emplace_back(cur);

    long long result = 0;
    if (k == 0) {
        for (int i = 0; i < zeros.size(); ++i)
            result += 1LL * (zeros[i]+1) * zeros[i] / 2;
    } else {
        for (int i = k; i < zeros.size(); ++i)
            result += 1LL * (zeros[i-k]+1) * (zeros[i]+1);
    }
    cout << result << endl;
}
