#include <iostream>
#include <vector>
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

    int mk = m * k;
    nth_element(a.begin(), a.begin()+mk-1, a.end(), greater<pair<int, int>>());

    long long result = 0;
    for (int i = 0; i < mk; ++i)
        result += a[i].first;
    cout << result << endl;

    sort(a.begin(), a.begin()+mk, [](pair<int, int>& a, pair<int, int>&b){
            return a.second < b.second;
        });

    for (int i = 1; i < k; ++i)
        cout << a[m*i-1].second+1 << " ";
    cout << endl;
}
