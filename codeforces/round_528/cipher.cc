#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    deque<char> buf;
    char tmp_c;
    while (cin >> tmp_c) {
        buf.emplace_back(tmp_c);
    }

    bool left = buf.size() % 2;
    string s;
    while (!buf.empty()) {
        if (left) {
            s += buf.front();
            buf.pop_front();
        } else {
            s += buf.back();
            buf.pop_back();
        }
        left = !left;
    }

    reverse(s.begin(), s.end());
    cout << s << endl;
}
