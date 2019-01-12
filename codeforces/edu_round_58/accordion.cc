#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

using std::deque;

using std::string;

using std::count;

int main() {
    string s;
    cin >> s;

    deque<char> q(s.begin(), s.end());
    while (!q.empty() && q.front() != '[')
        q.pop_front();
    if (q.empty()) {
        cout << "-1" << endl;
        return 0;
    }
    q.pop_front();

    while (!q.empty() && q.front() != ':')
        q.pop_front();
    if (q.empty()) {
        cout << "-1" << endl;
        return 0;
    }
    q.pop_front();

    while (!q.empty() && q.back() != ']')
        q.pop_back();
    if (q.empty()) {
        cout << "-1" << endl;
        return 0;
    }
    q.pop_back();

    while (!q.empty() && q.back() != ':')
        q.pop_back();
    if (q.empty()) {
        cout << "-1" << endl;
        return 0;
    }
    q.pop_back();

    cout << count(q.begin(), q.end(), '|') + 4 << endl;
}
