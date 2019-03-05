#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int CalMaxArea(const vector<int>& a, int left, int right) {
    if (left == right)
        return a[left];
    int mid = left + (right - left) / 2;
    int result = max(CalMaxArea(a, left, mid), CalMaxArea(a, mid+1, right));

    int li = mid;
    int ri = mid+1;
    int cur_height = numeric_limits<int>::max();
    while (left <= li || ri <= right) {
        if (left <= li && ri <= right) {
            if (a[li] < a[ri]) {
                cur_height = min(cur_height, a[ri]);
                ++ri;
            } else {
                cur_height = min(cur_height, a[li]);
                --li;
            }
        } else if (left <= li) {
            cur_height = min(cur_height, a[li]);
            --li;
        } else {  // ri <= right
            cur_height = min(cur_height, a[ri]);
            ++ri;
        }
        result = max(result, (ri-li-1)*cur_height);
    }

    return result;
}

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    cout << CalMaxArea(a, 0, n-1) << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
