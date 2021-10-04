#include <iostream>
#include <vector>
#include <set>

#define ll long long


using namespace std;


void Solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (n == 1) {
        cout << "Yes" << endl;
        return;
    }

    set<int> candi{1};
    while (candi.size() > 0) {
        auto it = candi.begin();
        int cur = *it;

        ll next = 1LL*cur*a;
        if (next == n) {
            cout << "Yes" << endl;
            return;
        } else if (next < n) {
            candi.emplace(static_cast<int>(next));
        }

        next = 1LL*cur+b;
        if (next == n) {
            cout << "Yes" << endl;
            return;
        } else if (next < n) {
            candi.emplace(static_cast<int>(next));
        }

        candi.erase(it);
    }
    cout << "No" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
