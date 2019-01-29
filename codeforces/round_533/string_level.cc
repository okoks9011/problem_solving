#include <iostream>
#include <string>

using namespace std;

int FindMaxLevel(string& s, int k, char c) {
    int x = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ++cnt;
        } else {
            cnt = 0;
        }
        if (cnt >= k) {
            ++x;
            cnt = 0;
        }
    }
    return x;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int max_level = 0;
    for (char c = 'a'; c <= 'z'; ++c)
        max_level = max(max_level, FindMaxLevel(s, k, c));

    cout << max_level << endl;
}
