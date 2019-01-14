#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> pref_acc(n+1);
    vector<bool> pref_valid(n+1);
    vector<int> suf_acc(n+1);
    vector<bool> suf_valid(n+1);
    pref_acc[0] = suf_acc[0] = 0;
    pref_valid[0] = suf_valid[0] = true;
    for (int i = 1; i <= n; ++i) {
        pref_acc[i] = pref_acc[i-1] + (s[i-1] == '(' ? 1 : -1);
        pref_valid[i] = pref_valid[i-1] && (pref_acc[i] >= 0);
        suf_acc[i] = suf_acc[i-1] + (s[n-i] == '(' ? -1 : 1);
        suf_valid[i] = suf_valid[i-1] && (suf_acc[i] >= 0);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (!pref_valid[i] || !suf_valid[n-1-i])
            continue;
        if (s[i] == '(') {
            if (pref_acc[i]-1 == suf_acc[n-1-i])
                ++result;
        } else {
            if (pref_acc[i]+1 == suf_acc[n-1-i])
                ++result;
        }
    }

    cout << result << endl;
}
