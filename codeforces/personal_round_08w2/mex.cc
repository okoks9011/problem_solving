#include <iostream>
#include <vector>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, x;
    cin >> q >> x;

    vector<int> cnt(x);
    int mex = 0;

    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        ++cnt[a%x];

        while (cnt[mex%x]) {
            --cnt[mex%x];
            ++mex;
        }
        cout << mex << endl;
    }
}
