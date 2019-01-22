#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int v = 0;
    int h = 0;
    for (auto& c : s) {
        if (c == '0') {
            if (v % 2 == 0)
                cout << "1 1" << endl;
            else
                cout << "3 1" << endl;
            ++v;
        } else {
            if (h % 2 == 0)
                cout << "4 3" << endl;
            else
                cout << "4 1" << endl;
            ++h;
        }
    }
}
