#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for (auto& p : a) {
        min_heap.emplace(p);
        if (min_heap.size() > m*k)
            min_heap.pop();
    }

    vector<pair<int, int>> picked;
    while (!min_heap.empty()) {
        picked.emplace_back(min_heap.top());
        min_heap.pop();
    }
    long long result = 0;
    for (auto& p : picked)
        result += p.first;
    cout << result << endl;

    sort(picked.begin(), picked.end(), [](pair<int, int>& a, pair<int, int>&b){
            return a.second < b.second;
        });

    for (int i = 1; i < k; ++i)
        cout << picked[m*i-1].second+1 << " ";
    cout << endl;
}
