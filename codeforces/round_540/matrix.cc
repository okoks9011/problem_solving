#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;
    for (int i = 0; i < n*n; ++i) {
        int a;
        cin >> a;
        ++freq[a];
    }

    vector<vector<int>> candi(3);
    for (auto& p : freq) {
        while (p.second >= 4 && candi[0].size() < (n/2)*(n/2)) {
            p.second -= 4;
            candi[0].emplace_back(p.first);
        }
    }

    if (candi[0].size() != (n/2)*(n/2)) {
        cout << "NO" << endl;
        return 0;
    }

    if (n % 2) {
        for (auto& p : freq) {
            while (p.second >= 2 && candi[1].size() < n-1) {
                p.second -= 2;
                candi[1].emplace_back(p.first);
            }
        }

        if (candi[1].size() != n-1) {
            cout << "NO" << endl;
            return 0;
        }

        for (auto& p : freq) {
            while (p.second >= 1) {
                p.second -= 1;
                candi[2].emplace_back(p.first);
            }
        }

        if (candi[2].size() != 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            int cur = candi[0].back();
            candi[0].pop_back();
            result[i][j] = cur;
            result[n-1-i][j] = cur;
            result[i][n-1-j] = cur;
            result[n-1-i][n-1-j] = cur;
        }
    }

    if (n % 2) {
        for (int i = 0; i < n/2; ++i) {
            int cur = candi[1].back();
            candi[1].pop_back();
            result[i][n/2] = cur;
            result[n-1-i][n/2] = cur;

            cur = candi[1].back();
            candi[1].pop_back();
            result[n/2][i] = cur;
            result[n/2][n-1-i] = cur;
        }
        result[n/2][n/2] = candi[2].back();
    }

    cout << "YES" << endl;
    for (auto& row : result) {
        for (auto& aij : row)
            cout << aij << " ";
        cout << endl;
    }
}
