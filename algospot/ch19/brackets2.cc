#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void Solve() {
    string s;
    cin >> s;

    vector<char> stack;
    unordered_map<char, char> p_map{{')', '('}, {'}', '{'}, {']', '['}};
    vector<char> lp{'(', '{', '['};
    int i = 0;
    for (i = 0; i < s.size(); ++i) {
        if (find(lp.begin(), lp.end(), s[i]) != lp.end()) {
            stack.emplace_back(s[i]);
        } else if (p_map.find(s[i]) != p_map.end()) {
            if (!stack.empty() && stack.back() == p_map[s[i]])
                stack.pop_back();
            else
                break;
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
