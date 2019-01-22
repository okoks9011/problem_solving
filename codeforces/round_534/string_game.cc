#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int pop = 0;
    vector<char> buf;
    for (auto& c : s) {
        if (buf.empty() || buf.back() != c) {
            buf.emplace_back(c);
        } else {
            buf.pop_back();
            ++pop;
        }
    }

    if (pop % 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
