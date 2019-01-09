#include <iostream>
#include <unordered_map>
#include <set>
#include <iterator>
#include <algorithm>
#include <utility>

using std::cin;
using std::cout;
using std::endl;

using std::unordered_map;

using std::set;

using std::inserter;

using std::set_intersection;

using std::pair;

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

    set<pair<int, int>> inter;
    set_intersection(candi1.begin(), candi1.end(),
                     candi2.begin(), candi2.end(),
                     inserter(inter, inter.end()));
    unordered_map<int, int> edges;
    for (auto& p : inter)
        edges.emplace(p);

    int cur = 1;
    for (int i = 0; i < edges.size(); ++i) {
        cout << cur << " ";
        cur = edges[cur];
    }
    cout << endl;
}
