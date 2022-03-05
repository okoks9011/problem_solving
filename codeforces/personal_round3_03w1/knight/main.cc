#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> candi;
    for (int i = 1; i <= n; i++)
        candi.emplace(i);

    vector<int> beat(n+1);
    for (int i = 0; i < m; i++) {
        int li, ri, xi;
        cin >> li >> ri >> xi;

        auto end_it = candi.upper_bound(ri);
        auto it = candi.lower_bound(li);
        while (it != candi.end() && it != end_it) {
            auto prev = it;
            it++;

            if (*prev != xi) {
                beat[*prev] = xi;
                candi.erase(prev);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << beat[i] << " ";
    cout << endl;
}
