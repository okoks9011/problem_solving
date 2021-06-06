#include <iostream>
#include <string>


using namespace std;


bool Contains(const string& s, int t) {
    string sub_s = to_string(t);
    string::size_type start = 0;
    for (int i = 0; i < sub_s.size(); ++i) {
        auto it = s.find(sub_s[i], start);
        if (it == string::npos)
            return false;
        start = it + 1;
    }
    return true;
}


int main() {
    string s;
    cin >> s;

    for (int i = 0; i < 1000; i += 8) {
        if (Contains(s, i)) {
            cout << "YES" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
