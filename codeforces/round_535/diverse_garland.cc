#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    string c("RGB");
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i-1] == s[i]) {
            for (int j = 0; j < 3; ++j) {
                if (c[j] != s[i-1] &&
                    (i == n-1 || c[j] != s[i+1])) {
                    s[i] = c[j];
                    ++cnt;
                    break;
                }
            }
        }
    }

    cout << cnt << endl;
    cout << s << endl;
}
