#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::string;

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

bool isLowercase(char c) {
    return 'a' <= c && c <= 'z';
}

bool isUppercase(char c) {
    return 'A' <= c && c <= 'Z';
}

string AlterPassword(string s) {
    int l = 0;
    int u = 0;
    int d = 0;
    for (auto& c : s) {
        if (isDigit(c))
            ++d;
        else if (isLowercase(c))
            ++l;
        else if (isUppercase(c))
            ++u;
    }

    if (l && u && d)
        return s;

    if (l && u) {
        if (l > u) {
            for (int i = 0; i < s.size(); ++i) {
                if (isLowercase(s[i])) {
                    s[i] = '0';
                    break;
                }
            }
        } else {
            for (int i = 0; i < s.size(); ++i) {
                if (isUppercase(s[i])) {
                    s[i] = '0';
                    break;
                }
            }
        }
    } else if (u && d) {
        if (u > d) {
            for (int i = 0; i < s.size(); ++i) {
                if (isUppercase(s[i])) {
                    s[i] = 'a';
                    break;
                }
            }
        } else {
            for (int i = 0; i < s.size(); ++i) {
                if (isDigit(s[i])) {
                    s[i] = 'a';
                    break;
                }
            }
        }
    } else if (d && l) {
        if (d > l) {
            for (int i = 0; i < s.size(); ++i) {
                if (isDigit(s[i])) {
                    s[i] = 'A';
                    break;
                }
            }
        } else {
            for (int i = 0; i < s.size(); ++i) {
                if (isLowercase(s[i])) {
                    s[i] = 'A';
                    break;
                }
            }
        }
    } else if (l) {
        s[0] = 'A';
        s[1] = '0';
    } else if (u) {
        s[0] = '0';
        s[1] = 'a';
    } else if (d) {
        s[0] = 'a';
        s[1] = 'A';
    }

    return s;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        cout << AlterPassword(s) << endl;
    }
}
