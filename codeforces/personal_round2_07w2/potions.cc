#include <iostream>
#include <queue>
#include <functional>

#define ll long long


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    ll health = 0;
    int pos_cnt = 0;
    priority_queue<int, vector<int>, greater<>> min_pq;
    for (auto& ai : a) {
        if (ai >= 0) {
            pos_cnt++;
            health += ai;
            continue;
        }

        if (health + ai >= 0) {
            min_pq.emplace(ai);
            health += ai;
            continue;
        }
        if (min_pq.size() > 0 && min_pq.top() < ai) {
            health -= min_pq.top();
            min_pq.pop();
            min_pq.emplace(ai);
            health += ai;
        }
    }
    cout << pos_cnt + min_pq.size() << endl;
}
