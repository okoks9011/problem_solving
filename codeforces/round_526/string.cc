#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

using std::vector;

int main() {
    vector<int> v;
    char c;
    int a_cnt = 0;
    while (cin >> c) {
        if (c == 'a') {
            ++a_cnt;
        } else if (c == 'b' && a_cnt){
            v.emplace_back(a_cnt);
            a_cnt = 0;
        }
    }
    if (a_cnt)
        v.emplace_back(a_cnt);

    long long total = 0;
    const int kMod = 1000000007;
    for (auto& vi : v) {
        total += (total * vi) % kMod + vi;
    }
    total %= kMod;
    cout << total << endl;
}
