#include <iostream>
#include <vector>


using namespace std;


bool IsSplitPossible(int size, const vector<int>& m, int k) {
    int cnt = 0;
    for (auto& mi : m) {
        cnt += (mi - 1) / size;
        if (cnt > k)
            return false;
    }
    return true;
}


int Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> m(n);
    for (auto& mi : m)
        cin >> mi;
    for (int i = 0; i < n-1; ++i)
        m[i] = m[i+1] - m[i];
    m.pop_back();

    int left = 1;
    int right = 1000000000;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (IsSplitPossible(mid, m, k)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        cout << "Case #" << i+1 << ": " << Solve() << endl;
}
