#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ProdDigit(const string& num) {
    int i = 0;
    while (i < num.size() && num[i] == '0')
        ++i;
    int result = 1;
    for (; i < num.size(); ++i)
        result *= num[i] - '0';
    return result;
}

int main() {
    string s;
    cin >> s;

    int result = ProdDigit(s);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0')
            continue;

        string tmp(s);
        --tmp[i];
        for (int j = i+1; j < s.size(); ++j)
            tmp[j] = '9';
        result = max(result, ProdDigit(tmp));
    }
    cout << result << endl;
}
