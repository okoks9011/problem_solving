#include <iostream>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    --l;
    int l_multi3 = l / 3;
    int l_multi3_1 = l_multi3;
    int l_multi3_2 = l_multi3;
    if (l % 3 == 2) {
        ++l_multi3_1;
        ++l_multi3_2;
    } else if (l % 3 == 1) {
        ++l_multi3_1;
    }

    int r_multi3 = r / 3;
    int r_multi3_1 = r_multi3;
    int r_multi3_2 = r_multi3;
    if (r % 3 == 2) {
        ++r_multi3_1;
        ++r_multi3_2;
    } else if (r % 3 == 1) {
        ++r_multi3_1;
    }

    int mod3_0 = r_multi3 - l_multi3;
    int mod3_1 = r_multi3_1 - l_multi3_1;
    int mod3_2 = r_multi3_2 - l_multi3_2;

    long long r0 = mod3_0;
    long long r1 = mod3_1;
    long long r2 = mod3_2;
    const int m = 1000000007;
    for (int i = 1; i < n; ++i) {
        long long next_r0 = (r0 * mod3_0) % m;
        next_r0 = (next_r0 + (r1 * mod3_2) % m) % m;
        next_r0 = (next_r0 + (r2 * mod3_1) % m) % m;
        long long next_r1 = (r0 * mod3_1) % m;
        next_r1 = (next_r1 + (r1 * mod3_0) % m) % m;
        next_r1 = (next_r1 + (r2 * mod3_2) % m) % m;
        long long next_r2 = (r0 * mod3_2) % m;
        next_r2 = (next_r2 + (r1 * mod3_1) % m) % m;
        next_r2 = (next_r2 + (r2 * mod3_0) % m) % m;

        r0 = next_r0;
        r1 = next_r1;
        r2 = next_r2;
    }

    cout << r0 << endl;;
}
