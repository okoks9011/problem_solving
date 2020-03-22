#include <iostream>
#include <queue>


using namespace std;


int Solve() {
    int n, k;
    cin >> n >> k;

    priority_queue<int> pq;

    int mi;
    cin >> mi;
    for (int i = 0; i < n-1; ++i) {
        int mj;
        cin >> mj;
        pq.emplace(mj - mi);
        mi = mj;
    }

    for (int i = 0; i < k; ++i) {
        int cur = pq.top();
        if (cur <= 1)
            break;

        pq.pop();
        int half = cur / 2;
        pq.emplace(half);
        pq.emplace(half + cur % 2);
    }

    return pq.top();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        cout << "Case #" << i+1 << ": " << Solve() << endl;
}
