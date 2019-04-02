#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto& vi : v)
        os << vi << " ";
    return os;
}

const int kNum = 26;

bool CompareVector(const vector<int>& v1,
                   const vector<int>& v2) {
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

bool FindCurInFreq(const vector<int>& cur, int cur_size,
                   const vector<vector<vector<int>>>& freq) {
    int n = freq.size();
    for (int i = 0; i < n-cur_size+1; ++i) {
        if (CompareVector(cur, freq[i][i+cur_size-1]))
            return true;
    }
    return false;
}

int Solve() {
    int n;
    cin >> n;

    string A, B;
    cin >> A >> B;

    vector<vector<vector<int>>> freq(n, vector<vector<int>>(n, vector<int>(kNum)));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (j > i)
                freq[i][j] = freq[i][j-1];
            ++freq[i][j][B[j]-'A'];
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> cur(kNum);
        for (int j = i; j < n; ++j) {
            ++cur[A[j]-'A'];
            if (FindCurInFreq(cur, j-i+1, freq))
                ++result;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
