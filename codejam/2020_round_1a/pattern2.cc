#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <utility>


using namespace std;


bool starts_with(string a, string b) {
    if (a.size() < b.size())
        return false;

    return b == string(a.begin(), a.begin()+b.size());
}


bool ends_with(string a, string b) {
    if (a.size() < b.size())
        return false;

    return b == string(a.end()-b.size(), a.end());
}


void Solve() {
    int n;
    cin >> n;

    vector<string> patterns(n);
    for (auto& pi : patterns)
        cin >> pi;

    string prefix;
    string suffix;
    string body;
    for (auto& pi : patterns) {
        auto sit = pi.find('*');
        assert(sit != string::npos);
        string cur_prefix = string(pi.begin(), pi.begin()+sit);

        auto eit = pi.rfind('*');
        assert(eit != string::npos);
        string cur_suffix = string(pi.begin()+eit+1, pi.end());

        if (prefix.size() < cur_prefix.size())
            swap(prefix, cur_prefix);
        if (!starts_with(prefix, cur_prefix)) {
            cout << "*";
            return;
        }

        if (suffix.size() < cur_suffix.size())
            swap(suffix, cur_suffix);
        if (!ends_with(suffix, cur_suffix)) {
            cout << "*";
            return;
        }

        string cur_body = string(pi.begin()+sit, pi.begin()+eit+1);
        for (auto& c : cur_body) {
            if (c != '*')
                body += c;
        }
    }

    string result = prefix + body + suffix;
    if (result.empty())
        cout << "*";
    else
        cout << result;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
