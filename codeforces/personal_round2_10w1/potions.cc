#include <iostream>
#include <vector>
#include <queue>
#include <functional>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& ai : a)
        cin >> ai;

    long long health = 0;
    int cnt = 0;
    priority_queue<int, vector<int>, greater<>> min_pq;
    for (auto& ai : a) {
        if (ai >= 0) {
            health += ai;
            cnt++;
            continue;
        }

        if (health + ai >= 0) {
            health += ai;
            min_pq.emplace(ai);
            cnt++;
            continue;
        }

        if (min_pq.size() > 0 && min_pq.top() < ai) {
            int t = min_pq.top();
            min_pq.pop();
            health -= t;

            health += ai;
            min_pq.emplace(ai);
        }
    }
    cout << cnt << endl;
}
