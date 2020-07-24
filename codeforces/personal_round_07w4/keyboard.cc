#include <iostream>
#include <vector>
#include <set>
#include <string>


using namespace std;


string Fill(const string& ans) {
    vector<char> used(26);
    for (auto& c : ans)
        used[c-'a'] = true;

    string result(ans);
    for (int i = 0; i < 26; ++i) {
        if (used[i])
            continue;
        result += i + 'a';
    }
    return result;
}


void Solve() {
    string s;
    cin >> s;

    if (s.size() <= 2) {
        cout << "YES" << endl;
        cout << Fill(s) << endl;
        return;
    }

    vector<set<int>> adjs(26);
    for (int i = 0; i < s.size()-1; ++i) {
        char u = s[i] - 'a';
        char v = s[i+1] - 'a';
        adjs[u].emplace(v);
        adjs[v].emplace(u);
    }

    int end_cnt = 0;
    int end_idx = -1;
    for (int i = 0; i < 26; ++i) {
        if (adjs[i].size() == 2 || adjs[i].empty()) {
            continue;
        } else if (adjs[i].size() == 1) {
            ++end_cnt;
            end_idx = i;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if (end_cnt != 2) {
        cout << "NO" << endl;
        return;
    }

    int cur = end_idx;
    string result = string(1, cur + 'a');
    while (!adjs[cur].empty()) {
        int next = *adjs[cur].begin();
        adjs[next].erase(cur);
        result += next + 'a';
        cur = next;
    }
    cout << "YES" << endl;
    cout << Fill(result) << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
