#include <iostream>
#include <vector>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> bits(20);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;

        for (int j = 0; j < 20; ++j) {
            if (ai == 0)
                break;
            if (ai & 1)
                ++bits[j];
            ai >>= 1;
        }
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 19; j >=0; --j) {
            cur <<= 1;
            if (bits[j]) {
                cur += 1;
                --bits[j];
            }
        }
        result += 1LL * cur * cur;
    }

    cout << result << endl;
}
