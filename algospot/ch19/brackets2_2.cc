#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Solve() {
    string s;
    cin >> s;

    const string lp("({[");
    const string rp(")}]");
    vector<char> stack;
    int i;
    for (i = 0; i < s.size(); ++i) {
        if (lp.find(s[i]) != string::npos) {
            stack.emplace_back(s[i]);
        } else if (!stack.empty() && rp.find(s[i]) == lp.find(stack.back())) {
                stack.pop_back();
        } else {
            break;
        }
    }

    if (i == s.size() && stack.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
