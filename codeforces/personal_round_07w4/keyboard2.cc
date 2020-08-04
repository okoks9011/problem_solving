#include <iostream>
#include <string>
#include <vector>


using namespace std;


void Solve() {
    string s;
    cin >> s;

    vector<char> used(26);
    used[s[0]-'a'] = true;
    string result = string(1, s[0]);
    int pos = 0;

    for (int i = 1; i < s.size(); ++i) {
        if (used[s[i]-'a']) {
            if (pos > 0 && result[pos-1] == s[i]) {
                --pos;
            } else if (pos+1 < result.size() && result[pos+1] == s[i]) {
                ++pos;
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            if (pos == 0) {
                result = s[i] + result;
            } else if (pos == result.size()-1) {
                result += s[i];
                ++pos;
            } else {
                cout << "NO" << endl;
                return;
            }
            used[s[i]-'a'] = true;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (used[i])
            continue;
        result += i + 'a';
    }
    cout << "YES" << endl;
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
