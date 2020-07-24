#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    if (p > (n+1) / 2) {
        p = (n+1) - p;
        reverse(s.begin(), s.end());
    }
    p -= 1;

    vector<int> diff(n/2);
    for (int i = 0; i < diff.size(); ++i) {
        int d = abs(s[i] - s[n-1-i]);
        if (d > 13)
            d = 26 - d;
        diff[i] = d;
    }
    int left_span = 0;
    int right_span = 0;
    for (int i = 0; i < diff.size(); ++i) {
        if (diff[i] == 0)
            continue;
        left_span = max(left_span, p - i);
        right_span = max(right_span, i - p);
    }

    int result = 0;
    result += min(left_span, right_span) * 2;
    result += max(left_span, right_span);
    for (int i = 0; i < diff.size(); ++i)
        result += diff[i];
    cout << result << endl;
}
