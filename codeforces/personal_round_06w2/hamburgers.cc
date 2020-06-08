#include <iostream>
#include <vector>
#include <string>

#define ll long long


using namespace std;


struct Info {
    vector<int> r;
    vector<int> n;
    vector<int> p;
    ll ruble = 0LL;

    Info() : r(3), n(3), p(3) {}
};


bool CanMakeBurger(ll cur, const Info& ctx) {
    ll cost = 0LL;
    for (int i = 0; i < 3; ++i) {
        ll need = cur * ctx.r[i];
        if (need > ctx.n[i])
            cost += (need - ctx.n[i]) * ctx.p[i];
    }
    return cost <= ctx.ruble;
}


int main() {
    string recipe;
    cin >> recipe;

    Info ctx;
    for (auto& c : recipe) {
        if (c == 'B')
            ++ctx.r[0];
        if (c == 'S')
            ++ctx.r[1];
        if (c == 'C')
            ++ctx.r[2];
    }

    for (int i = 0; i < 3; ++i)
        cin >> ctx.n[i];
    for (int i = 0; i < 3; ++i)
        cin >> ctx.p[i];
    cin >> ctx.ruble;

    ll left = 0;
    ll right = (ctx.ruble + 100) * 2;
    ll result = -1;
    while (left <= right) {
        ll mid = (right - left) / 2 + left;
        if (CanMakeBurger(mid, ctx)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result << endl;
}
