#include <iostream>
#include <string>


using namespace std;


int main() {
    string s;
    cin >> s;

    while (!s.empty() && s.back() == '0')
        s.pop_back();

    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n-1-i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
