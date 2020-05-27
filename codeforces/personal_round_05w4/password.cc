#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (s.size() <= 2) {
        cout << "Just a legend" << endl;
        return 0;
    }

    string body(s.begin()+1, s.end()-1);
    vector<int> head_cnt(26);
    vector<int> tail_cnt(26);
    for (int i = s.size()-1; i >= 1; --i) {
        ++head_cnt[s[i]-'a'];
        ++tail_cnt[s[s.size()-i-1]-'a'];
        if (head_cnt != tail_cnt)
            continue;
        if (string(s.begin(), s.begin()+i) != string(s.end()-i, s.end()))
            continue;

        string t = string(s.begin(), s.begin()+i);
        auto it = body.find(t);
        if (it != string::npos) {
            cout << t << endl;
            return 0;
        }
    }

    cout << "Just a legend" << endl;
}
