#include <iostream>
#include <queue>
#include <vector>
#include <functional>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    priority_queue<int> max_pq;
    for (auto& ai : a) {
        cin >> ai;
        max_pq.emplace(ai);
    }

    while (max_pq.size() >= 2) {
        if (max_pq.size() >= 3) {
            int p1 = max_pq.top();
            max_pq.pop();
            int p2 = max_pq.top();
            max_pq.pop();
            int p3 = max_pq.top();
            max_pq.pop();

            int dec = (p3/2) * 2;
            if (dec > 0) {
                p1 -= dec;
                if (p1 > 0)
                    max_pq.emplace(p1);
                p2 -= dec;
                if (p2 > 0)
                    max_pq.emplace(p2);
                p3 -= dec;
                if (p3 > 0)
                    max_pq.emplace(p3);
            }
        }

        int p1 = max_pq.top();
        max_pq.pop();
        int p2 = max_pq.top();
        max_pq.pop();

        if (p1-p2 > 0)
            max_pq.emplace(p1-p2);
    }

    if (max_pq.size() == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
