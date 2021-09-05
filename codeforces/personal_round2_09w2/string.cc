#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<vector<char>> goal(20, vector<char>(20));
    for (int i = 0; i < n; i++) {
        int ai = a[i]-'a';
        int bi = b[i]-'a';
        if (ai > bi) {
            cout << -1 << endl;
            return;
        }
        if (ai < bi)
            goal[ai][bi] = true;
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (goal[i][j])
                cerr << "(" << static_cast<char>('a'+i) << ", " << static_cast<char>('a'+j) << ")" << endl;
        }
    }

    vector<vector<char>> adjs(20, vector<char>(20));
    vector<vector<char>> reach(20, vector<char>(20));
    for (int i = 0; i < 20; i++) {
        adjs[i][i] = true;
        reach[i][i] = true;
    }

    for (int len = 1; len < 20; len++) {
        for (int start = 0; start+len < 20; start++) {
            int end = start+len;
            if (!goal[start][end] || reach[start][end])
                continue;

            adjs[start][end] = true;
            for (int i = 0; i <= start; i++) {
                for (int j = end; j < 20; j++) {
                    if (reach[i][start] && reach[end][j])
                        reach[i][j] = true;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 20; i++) {
        result += count(adjs[i].begin(), adjs[i].end(), true);
        // To remove adjs[i][i], loop
        result--;
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
