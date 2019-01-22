#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    auto pos = s.find('[');
    if (pos == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    s.erase(0, pos+1);

    pos = s.find(':');
    if (pos == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    s.erase(0, pos+1);

    reverse(s.begin(), s.end());

    pos = s.find(']');
    if (pos == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    s.erase(0, pos+1);

    pos = s.find(':');
    if (pos == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    s.erase(0, pos+1);

    cout << count(s.begin(), s.end(), '|') + 4 << endl;
}
