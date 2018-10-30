#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::string;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << "NO" << endl;
        return 0;
    }

    char c = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] != c) {
            cout << "YES" << endl;
            cout << string{c, s[i]} << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
