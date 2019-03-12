#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int CountValid(string* cur_ptr, int i, int n, const unordered_set<string>& f) {
    auto& cur = *cur_ptr;
    if (f.find(cur) != f.end())
        return 0;
    if (i == n)
        return 1;

    int result = 0;
    for (char c : {'R', 'B'}) {
        cur += c;
        result += CountValid(cur_ptr, i+1, n, f);
        cur.pop_back();
    }
    return result;
}

int Solve() {
    int n, p;
    cin >> n >> p;

    unordered_set<string> f;
    for (int i = 0; i < p; ++i) {
        string tmp;
        cin >> tmp;
        f.emplace(tmp);
    }

    string cur;
    return CountValid(&cur, 0, n, f);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int s = Solve();
        cout << "Case #" << i + 1 << ": " << s << endl;
    }
}
