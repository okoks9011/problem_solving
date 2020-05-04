#include <iostream>
#include <string>


using namespace std;


void Solve() {
    string s;
    cin >> s;

    string full;
    for (auto& si : s) {
        int n = si - '0';
        full += string(n, '(');
        full += si;
        full += string(n, ')');
    }

    string result;
    for (auto& fi : full) {
        if (!result.empty() && result.back() == ')' && fi == '(')
            result.pop_back();
        else
            result += fi;
    }

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
