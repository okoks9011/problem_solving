#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::string;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = 0;
    for (i; i < s.size()-1; ++i) {
        if (s[i] > s[i+1])
            break;
    }

    s.erase(i, 1);
    cout << s << endl;
}
