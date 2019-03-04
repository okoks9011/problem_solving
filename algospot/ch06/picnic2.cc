#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int CountSeq(deque<bool>* taken_ptr, const vector<deque<bool>>& f) {
    auto& taken = *taken_ptr;
    int first_candi = -1;
    auto it = find_if(taken.begin(), taken.end(), [](bool v){return !v;});
    if (it == taken.end())
        return 1;
    else
        first_candi = it - taken.begin();

    int result = 0;
    taken[first_candi] = true;
    for (int i = first_candi+1; i < taken.size(); ++i) {
        if (!taken[i] && (f[first_candi][i] || f[i][first_candi])) {
            taken[i] = true;
            result += CountSeq(taken_ptr, f);
            taken[i] = false;
        }
    }
    taken[first_candi] = false;
    return result;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<deque<bool>> f(n, deque<bool>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        f[a][b] = true;
        f[b][a] = true;
    }

    deque<bool> taken(n);
    cout << CountSeq(&taken, f) << endl;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i)
        Solve();
}
