#include <iostream>
#include <string>
#include <vector>


using namespace std;


bool Contain(int cur, const string& t, const string& p,
             const vector<int>& order) {
    int ti = 0;
    int pi = 0;
    while (ti < t.size() && pi < p.size()) {
        if (order[ti] > cur && t[ti] == p[pi])
            ++pi;
        ++ti;
    }
    return pi == p.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t, p;
    cin >> t >> p;

    vector<int> order(t.size());
    for (int i = 1; i <= t.size(); ++i) {
        int ai;
        cin >> ai;
        order[ai-1] = i;
    }

    int left = 0;
    int right = t.size();
    int result = -1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (Contain(mid, t, p, order)) {
            left = mid + 1;
            result = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << result << endl;
}
