#include <queue>
#include <iostream>
#include <functional>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    int level = 0;
    priority_queue<int, vector<int>, greater<>> min_pq;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        min_pq.emplace(ai);
        while (!min_pq.empty() && min_pq.top() <= level)
            min_pq.pop();
        if (min_pq.size() > level)
            ++level;
        cout << level << " ";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
