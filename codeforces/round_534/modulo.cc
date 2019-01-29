#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    int x = 0;
    int y = 1;
    while (true) {
        // up to 31 questions
        cout << "? " << x << " " << y << endl;
        cin >> s;
        if (s == "y") {
            x = y;
            y *= 2;
        } else if (s == "x") {
            break;
        } else {
            cout << "Answer should be x or y" << endl;
            return;
        }
    }

    int left = x + 1;
    int right = y;
    int a = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // up to 29 questions
        cout << "? " << x << " " << mid << endl;
        cin >> s;
        if (s == "y") {
            left = mid + 1;
        } else if (s == "x") {
            a = mid;
            right = mid - 1;
        } else {
            cout << "Answer should be x or y" << endl;
            return;
        }
    }
    cout << "! " << a << endl;
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "start") {
            solve();
        } else if (s == "mistake") {
            cout << "mistake!" << endl;
            return 0;
        } else {  // end or else
            return 0;
        }
    }
}
