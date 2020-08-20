#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool CanHold(int k, const vector<int>& s) {
    int t = s.size() - 1;
    for (int i = k-1; i >= 0; --i) {
        if (s[t] / 2 < s[i])
            return false;
        --t;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> s(n);
    for (auto& si : s)
        cin >> si;
    sort(s.begin(), s.end());

    int left = 0;
    int right = n / 2;
    int hold = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (CanHold(mid, s)) {
            left = mid + 1;
            hold = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << n - hold << endl;
}
