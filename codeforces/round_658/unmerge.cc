#include <iostream>
#include <vector>


using namespace std;


bool CanSplit(int i, int cur_size, int other_size, const vector<int>& p) {
    int n = p.size() / 2;
    cerr << "i: " << i << " cur_size: " << cur_size << " other_size: " << other_size << " p[i]: " << p[i] << endl;
    if (cur_size == n) {
        if (i == p.size() - 1)
            return true;
        return p[i] < p[i+1];
    }
    if (p[i] < p[i+1]) {
        if (CanSplit(i+1, other_size+1, cur_size, p))
            return true;
    }
    return CanSplit(i+1, cur_size+1, other_size, p);
}


void Solve() {
    int n;
    cin >> n;

    vector<int> p(2*n);
    for (auto& pi : p)
        cin >> pi;

    if (CanSplit(0, 1, 0, p))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
