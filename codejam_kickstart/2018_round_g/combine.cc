#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

using std::vector;

using std::min;
using std::max;

using std::pair;
using std::make_pair;

vector<int> genSequence(int x1, int x2, int a, int b, int c, int m, int n) {
    vector<int> result;
    if (n >= 1)
        result.emplace_back(x1);
    if (n >= 2)
        result.emplace_back(x2);
    for (int i = 0; i < n-2; ++i) {
        int xi = static_cast<int>((1LL * a * x2 + 1LL * b * x1 + c) % m);
        result.emplace_back(xi);
        x1 = x2;
        x2 = xi;
    }
    return result;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
void printVector(const vector<T>& v_seq) {
    cout << "[ ";
    for (auto& vi : v_seq)
        cout << vi << " ";
    cout << "]" << endl;
}

long long greaterThanEqual(vector<pair<int, int>>& scores, int t) {
    long long result = 0;
    for (auto& score : scores) {
        int li = score.first;
        int ri = score.second;
        if (t < li)
            result += ri - li + 1;
        else if (li <= t && t <= ri)
            result += ri - t + 1;
    }
    return result;
}

int kthScore(vector<pair<int, int>>& scores, int k) {
    int left = 0;
    int right = 1000000000;
    int result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long rank = greaterThanEqual(scores, mid);
        if (rank >= k) {
            result = mid;
            left = mid + 1;
        } else {  // rank < k
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    for (int case_num = 1; case_num < t+1; ++case_num) {
        int n, q;
        cin >> n >> q;

        int x1, x2, a1, b1, c1, m1;
        cin >> x1 >> x2 >> a1 >> b1 >> c1 >> m1;
        auto x_seq = genSequence(x1, x2, a1, b1, c1, m1, n);

        int y1, y2, a2, b2, c2, m2;
        cin >> y1 >> y2 >> a2 >> b2 >> c2 >> m2;
        auto y_seq = genSequence(y1, y2, a2, b2, c2, m2, n);

        int z1, z2, a3, b3, c3, m3;
        cin >> z1 >> z2 >> a3 >> b3 >> c3 >> m3;
        auto z_seq = genSequence(z1, z2, a3, b3, c3, m3, q);

        vector<pair<int, int>> scores;
        for (int i = 0; i < n; ++i) {
            int li = min(x_seq[i], y_seq[i]) + 1;
            int ri = max(x_seq[i], y_seq[i]) + 1;
            scores.emplace_back(make_pair(li, ri));
        }

        vector<int> questions;
        long long result = 0;
        for (int i = 0; i < q; ++i) {
            int ki = z_seq[i] + 1;
            result += 1LL * (i + 1) * kthScore(scores, ki);
        }
        cout << "Case #" << case_num << ": " << result << endl;
    }
}
