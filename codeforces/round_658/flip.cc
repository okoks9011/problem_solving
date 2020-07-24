#include <iostream>
#include <string>
#include <vector>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    string rev_a(a.rbegin(), a.rend());
    for (auto& c : rev_a)
        c = c == '0' ? '1' : '0';

    bool flipped = false;
    vector<int> result;
    int ai = n-1;
    int rev_ai = n-1;
    for (int i = n-1; i >= 0; --i) {
        if (!flipped) {
            if (a[ai] == b[i]) {
                --ai;
                continue;
            }
            if (rev_a[rev_ai] != b[i])
                result.emplace_back(1);
            flipped = true;
            --rev_ai;
            result.emplace_back(i+1);
        } else {
            if (rev_a[rev_ai] == b[i]) {
                --rev_ai;
                continue;
            }

            if (a[ai] != b[i])
                result.emplace_back(1);
            flipped = false;
            --ai;
            result.emplace_back(i+1);
        }
    }

    cout << result.size() << " ";
    for (auto& ri : result)
        cout << ri << " ";
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
