#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CanFillFridge(int k, const vector<int>& a, int h) {
    vector<int> target(a.begin(), a.begin()+k);
    sort(target.rbegin(), target.rend());

    for (int i = 0; i < target.size(); i += 2) {
        h -= target[i];
        if (h < 0)
            return false;
    }

    return true;
}

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    int left = 1;
    int right = n;
    int result = -1;
    while (left <= right) {
        int mid = left + (right-left) / 2;
        if (CanFillFridge(mid, a, h)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
}
