#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>

using namespace std;

bool IsValid(int i, int j, const vector<string>& map, int n, int m) {
    if (i < 0 || n <= i || j < 0 || m <= j)
        return false;
    if (map[i][j] == '#')
        return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> map(n);
    for (auto& row : map)
        cin >> row;

    set<pair<int, int>> cur{{0, 0}};
    bool converge = false;
    while (!cur.empty()) {
        set<pair<int, int>> next;
        for (auto& p : cur) {
            if (IsValid(p.first+1, p.second, map, n, m))
                next.emplace(p.first+1, p.second);
            if (IsValid(p.first, p.second+1, map, n, m))
                next.emplace(p.first, p.second+1);
        }

        if (next.size() == 1) {
            auto& p = *(next.begin());
            if (p.first == n-1 && p.second == m-1) {
                if (converge)
                    cout << "1" << endl;
                else
                    cout << "2" << endl;
                return 0;
            } else
                converge = true;
        }
        cur = next;
    }

    cout << "0" << endl;
}
