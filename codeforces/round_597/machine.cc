#include <iostream>
#include <string>

using namespace std;

const int kMod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    long long last_n = 0;
    long long last_u = 0;
    long long last_other = 1;
    for (auto& si : s) {
        if (si == 'm' || si == 'w') {
            cout << "0" << endl;
            return 0;
        }

        long long last_sum = last_n + last_u + last_other;
        last_sum %= kMod;
        long long cur_n = 0;
        long long cur_u = 0;
        long long cur_other = 0;
        if (si == 'n') {
            cur_n = last_sum;
            cur_other = last_n;
        } else if (si == 'u') {
            cur_u = last_sum;
            cur_other = last_u;
        } else {
            cur_other = last_sum;
        }

        last_n = cur_n;
        last_u = cur_u;
        last_other = cur_other;
    }

    cout << (last_n + last_u + last_other) % kMod << endl;
}
