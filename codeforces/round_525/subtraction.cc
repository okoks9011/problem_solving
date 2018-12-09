#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;

using std::set;

int main() {
    int n, k;
    cin >> n >> k;

    set<int> nums;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums.emplace(tmp);
    }

    int before = 0;
    auto it = nums.begin();
    for (int i = 0; i < k; ++i) {
        if (it != nums.end()) {
            cout << *it - before << endl;
            before = *it++;
        } else {
            cout << 0 << endl;
        }
    }
}
