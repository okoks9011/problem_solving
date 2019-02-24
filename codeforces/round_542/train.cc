#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> candies(n);
    vector<int> min_dis(n, n);
    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        ++candies[ai];
        int cur_dis = (bi - ai + n) % n;
        min_dis[ai] = min(min_dis[ai], cur_dis);
    }

    vector<int> total(n, -1);
    for (int i = 0; i < n; ++i) {
        if (candies[i] == 0)
            continue;
        total[i] = (candies[i]-1) * n;
        total[i] += min_dis[i];
    }

    for (int i = 0; i < n; ++i) {
        int result = 0;
        for (int j = 0; j < n; ++j) {
            int cur = (i + j) % n;
            if (total[cur] == -1)
                continue;
            result = max(result, total[cur] + j);
        }
        cout << result << " ";
    }
    cout << endl;
}
