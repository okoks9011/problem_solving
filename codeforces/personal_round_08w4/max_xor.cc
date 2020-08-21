#include <iostream>

#define ll long long


using namespace std;


int CountBit(ll x) {
    int result = 0;
    while (x) {
        ++result;
        x >>= 1;
    }
    return result;
}


int main() {
    ll a, b;
    cin >> a >> b;

    int len_a = CountBit(a);
    int len_b = CountBit(b);
    while (len_b > 0 && len_a == len_b) {
        ll first = 1LL << (len_b - 1);
        a ^= first;
        b ^= first;

        len_a = CountBit(a);
        len_b = CountBit(b);
    }

    ll result = 0;
    for (int i = 0; i < len_b; ++i) {
        result <<= 1;
        result += 1;
    }
    cout << result << endl;
}
