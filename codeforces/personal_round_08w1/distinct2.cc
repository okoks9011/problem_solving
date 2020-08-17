#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cassert>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<set<int>> cnt(26);
    for (int i = 0; i < s.size(); ++i)
        cnt[s[i]-'a'].emplace(i+1);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos;
            cin >> pos;
            char c;
            cin >> c;

            cnt[s[pos-1]-'a'].erase(pos);
            cnt[c-'a'].emplace(pos);
            s[pos-1] = c;
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;

            int result = 0;
            for (int j = 0; j < 26; ++j) {
                auto it = cnt[j].lower_bound(l);
                if (it == cnt[j].end())
                    continue;
                if (*it <= r)
                    ++result;
            }
            cout << result << endl;
        } else {
            assert(false);
        }
    }
}
