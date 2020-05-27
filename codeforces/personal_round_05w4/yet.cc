#include <iostream>
#include <vector>


using namespace std;


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


long long count(long long t, const vector<int>& acc) {
    int l = acc.size();
    return (t / l) * acc.back() + acc[t%l];
}


void Solve() {
    int a, b, q;
    cin >> a >> b >> q;

    int g = gcd(a, b);
    int l = a * b / g;
    vector<int> acc(l);
    for (int i = 0; i < l; ++i) {
        if (i >= 1)
            acc[i] = acc[i-1];
        if ((i % a) % b != (i % b) % a)
            ++acc[i];
    }

    for (int i = 0; i < q; ++i) {
        long long li, ri;
        cin >> li >> ri;
        cout << count(ri, acc) - count(li-1, acc) << " ";
    }
    cout << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
