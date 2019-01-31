#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (auto& si : s)
        cin >> si;

    int result = 0;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if (s[i][j] == 'X' &&
                s[i-1][j-1] == 'X' &&
                s[i-1][j+1] == 'X' &&
                s[i+1][j-1] == 'X' &&
                s[i+1][j+1] == 'X')
                ++result;
        }
    }
    cout << result << endl;
}
