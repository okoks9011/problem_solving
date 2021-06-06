#include <iostream>
#include <vector>
#include <cassert>
#include <string>

#define ll long long


using namespace std;


void PrintResult(int base, int over) {
    string result;
    string target = "codeforces";
    for (int i = 0; i < target.size(); ++i) {
        if (i < over)
            result += string(base+1, target[i]);
        else
            result += string(base, target[i]);
    }
    cout << result << endl;
}

int main() {
    ll n;
    cin >> n;

    int base = 1;
    while (true) {
        ll result = 1LL;
        for (int i = 0; i < 10; ++i)
            result *= base;
        if (result >= n)
            break;
        ++base;
    }
    if (base == 1) {
        cout << "codeforces" << endl;
        return 0;
    }
    --base;
    for (int i = 1; i <= 10; ++i) {
        ll result = 1LL;
        for (int j = 0; j < 10; ++j) {
            if (j < i)
                result *= (base + 1);
            else
                result *= base;
        }
        if (result >= n) {
            PrintResult(base, i);
            return 0;
        }
    }
    assert(false);
}
