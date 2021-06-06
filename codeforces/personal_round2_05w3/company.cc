#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> friends(n);
    for (auto& f : friends)
        cin >> f.first >> f.second;

    sort(friends.begin(), friends.end());
    int end = 0;
    long long result = 0LL;
    long long sum = 0LL;
    for (int start = 0; start < n; ++start) {
        while (end < n && friends[end].first - friends[start].first < d) {
            sum += friends[end].second;
            ++end;
        }
        result = max(result, sum);
        sum -= friends[start].second;
    }
    cout << result << endl;
}
