#include <iostream>
#include <vector>
#include <ios>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> freq(n+1);
    vector<int> round(m+1);
    int next = 1;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        ++freq[t];
        ++round[freq[t]];

        if (round[next] == n) {
            cout << "1";
            ++next;
        } else {
            cout << "0";
        }
    }
    cout << endl;
}
