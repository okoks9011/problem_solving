#include <iostream>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

bool Remove(priority_queue<ll>* pq_ptr, ll v) {
    auto& pq = *pq_ptr;
    if (pq.size() == 0) {
        return false;
    }
    auto e = pq.top();
    pq.pop();
    if (e < v) {
        return false;
    }

    ll r = e - v;
    if (r > 0) {
        pq.emplace(r);
    }
    return true;
}

bool Validate(ll x, ll y, const vector<int>& a) {
    priority_queue<ll> max_pq;
    for (auto& ai : a) {
        max_pq.emplace(ai);
    }

    bool odd_len = x % 2;
    ll first_block_size = y % 2 ? 3 : 2;
    if (odd_len) {
        if (!Remove(&max_pq, first_block_size*x)) {
            return false;
        }
    } else {
        if (!Remove(&max_pq, first_block_size*x/2)) {
            return false;
        }
        if (!Remove(&max_pq, first_block_size*x/2)) {
            return false;
        }
    }

    int blocks = y / 2 - 1;
    for (int i = 0; i < blocks; i++) {
        if (odd_len) {
            if (!Remove(&max_pq, 2*x)) {
                return false;
            }
        } else {
            if (!Remove(&max_pq, x)) {
                return false;
            }
            if (!Remove(&max_pq, x)) {
                return false;
            }
        }
    }
    return true;
}

void Solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for (auto& ai : a) {
        cin >> ai;
    }

    if (Validate(n, m, a) || Validate(m, n, a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        Solve();
    }
}
