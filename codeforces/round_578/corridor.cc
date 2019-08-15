#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    int q;
    cin >> q;

    long long cnt = gcd(n, m);
    long long inner_size = n / cnt;
    long long outer_size = m / cnt;
    for (int i = 0; i < q; ++i) {
        int sx, ex;
        long long sy, ey;
        cin >> sx >> sy >> ex >> ey;

        long long start = -1;
        if (sx == 1)
            start = (sy-1) / inner_size;
        else
            start = (sy-1) / outer_size;

        long long end = -1;
        if (ex == 1)
            end = (ey-1) / inner_size;
        else
            end = (ey-1) / outer_size;

        if (start == end)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
