#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    string s;
    cin >> s;

    int acc = 0;
    long long result = 0LL;
    unordered_map<int, int> acc_cnt;
    acc_cnt[0] = 1;
    for (auto& si : s) {
        if (si == '1')
            ++acc;
        auto it = acc_cnt.find(acc - k);
        if (it != acc_cnt.end())
            result += it->second;
        ++acc_cnt[acc];
    }
    cout << result << endl;
}
