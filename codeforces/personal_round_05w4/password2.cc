#include <iostream>
#include <vector>
#include <string>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> p(n);
    int begin = 1;
    int matched = 0;
    while (begin + matched < n) {
        if (s[begin+matched] == s[matched]) {
            ++matched;
            p[begin+matched-1] = matched;
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - p[matched-1];
                matched = p[matched-1];
            }
        }
    }

    string not_found = "Just a legend";
    if (p[n-1] == 0) {
        cout << not_found << endl;
        return 0;
    }

    for (int i = 1; i < n-1; ++i) {
        if (p[i] == p[n-1]) {
            cout << s.substr(0, p[n-1]) << endl;
            return 0;
        }
    }

    if (p[p[n-1]-1] == 0)
        cout << not_found << endl;
    else
        cout << s.substr(0, p[p[n-1]-1]) << endl;
}
