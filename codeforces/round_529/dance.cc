#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 3) {
        cout << "1 2 3" << endl;
        return 0;
    }

    set<pair<int, int>> candi1;
    set<pair<int, int>> candi2;

    for (int i = 1; i <= n; ++i) {
        int p1, p2;
        cin >> p1 >> p2;

        candi1.emplace(i, p1);
        candi1.emplace(i, p2);

        candi2.emplace(p1, p2);
        candi2.emplace(p2, p1);
    }

    unordered_map<int, int> edges;
    for (auto& p : candi1) {
        if (candi2.count(p))
            edges.emplace(p);
    }

    int cur = 1;
    for (int i = 0; i < edges.size(); ++i) {
        cout << cur << " ";
        cur = edges[cur];
    }
    cout << endl;
}
