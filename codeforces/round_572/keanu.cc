#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cnt(2);
    for (auto& c : s)
        ++cnt[c%2];

    if (cnt[0] != cnt[1]) {
        cout << "1" << endl;
        cout << s << endl;
    } else {
        cout << "2" << endl;
        cout << s[0] << " " << s.substr(1) << endl;
    }
}
