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
    for (auto& pi : patterns) {
        auto it = pi.find('*');
        assert(it != string::npos);
        string cur_prefix = string(pi.begin(), pi.begin()+it);
        string cur_suffix = string(pi.begin()+it+1, pi.end());

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
    }

    string result = prefix + suffix;
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
