#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> acc(n+1);
    for (int i = 1; i <= n; ++i)
        acc[i] = acc[i-1] + a[i];

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int li, ri;
        cin >> li >> ri;
        --li;
        cout << (acc[ri]-acc[li]) / 10 << endl;
    }
}
