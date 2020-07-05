#include <iostream>
#include <algorithm>


using namespace std;


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, r;
        cin >> n >> r;

        int k = min(n-1, r);
        long long result = 1LL * k * (k+1) / 2;
        if (n <= r)
            ++result;
        cout << result << endl;
    }
}
