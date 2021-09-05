#include <iostream>
#include <vector>
#include <numeric>

#define ll long long

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;
    vector<int> b(n);
    for (auto& bi : b)
        cin >> bi;

    vector<ll> product(n);
    for (int i = 0; i < n; i++)
        product[i] = 1LL * a[i] * b[i];

    ll max_diff = 0;
    for (int start_left = 0; start_left < n; start_left++) {
        int left = start_left;
        int right = start_left + 2;
        ll cur_diff = 0;
        for (;left >= 0 && right < n; left -= 1, right += 1) {
            cur_diff -= product[left] + product[right];
            cur_diff += 1LL * a[left] * b[right] + 1LL * a[right] * b[left];
            max_diff = max(max_diff, cur_diff);
        }
    }
    for (int start_left = 0; start_left < n; start_left++) {
        int left = start_left;
        int right = start_left + 1;
        ll cur_diff = 0;
        for (;left >= 0 && right < n; left -= 1, right += 1) {
            cur_diff -= product[left] + product[right];
            cur_diff += 1LL * a[left] * b[right] + 1LL * a[right] * b[left];
            max_diff = max(max_diff, cur_diff);
        }
    }
    ll result = accumulate(product.begin(), product.end(), 0LL) + max_diff;
    cout << result << endl;
}
