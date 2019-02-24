#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int neg = 0;
    int zero = 0;
    int pos = 0;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp > 0)
            ++pos;
        else if (tmp < 0)
            ++neg;
        else
            ++zero;
    }

    if (pos >= (n+1)/2)
        cout << "1" << endl;
    else if (neg >= (n+1)/2)
        cout << "-1" << endl;
    else
        cout << "0" << endl;
}
