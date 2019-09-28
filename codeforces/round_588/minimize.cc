#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (n == 1 && k == 1) {
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (k == 0)
            break;
        char t = i != 0 ? '0' : '1';
        if (s[i] != t) {
            s[i] = t;
            --k;
        }
    }
    cout << s << endl;
}
