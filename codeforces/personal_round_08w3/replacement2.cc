#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    s = 'a' + s + 'a';

    int sum = 0;
    int chunk = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '.')
            ++sum;
        if (s[i-1] == '.' && s[i] != '.')
            ++chunk;
    }

    for (int i = 0; i < m; ++i) {
        int xi;
        char ci;
        cin >> xi >> ci;

        if ((ci == '.' && s[xi] == '.') ||
            (ci != '.' && s[xi] != '.')) {
            cout << sum - chunk << endl;
            continue;
        }

        s[xi] = ci;
        if (ci == '.') {
            if (s[xi-1] == '.' && s[xi+1] == '.')
                --chunk;
            else if (s[xi-1] != '.' && s[xi+1] != '.')
                ++chunk;
            ++sum;
        } else {
            if (s[xi-1] == '.' && s[xi+1] == '.')
                ++chunk;
            else if (s[xi-1] != '.' && s[xi+1] != '.')
                --chunk;
            --sum;
        }
        cout << sum - chunk << endl;
    }
}
