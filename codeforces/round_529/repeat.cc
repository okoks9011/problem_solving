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

    int step = 1;
    for (int i = 0; i < n; i += step++) {
        cout << s[i];
    }
    cout << endl;
}
