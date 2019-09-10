#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n % 2) {
        cout << "No" << endl;
        return 0;
    }

    int cur = 0;
    for (auto& si : s) {
        if (si == '(')
            ++cur;
        else if (si == ')')
            --cur;
        else
            assert(false);

        if (cur <= -2) {
            cout << "No" << endl;
            return 0;
        }
    }

    if (cur == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
