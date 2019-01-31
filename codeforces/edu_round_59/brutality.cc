#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<char> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    int i = 0;
    long long result = 0;
    char prev = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != prev) {
            while (!min_heap.empty()) {
                result += min_heap.top();
                min_heap.pop();
            }
        }
        min_heap.push(a[i]);
        if (min_heap.size() > k)
            min_heap.pop();
        prev = s[i];
    }

    while (!min_heap.empty()) {
        result += min_heap.top();
        min_heap.pop();
    }
    cout << result << endl;
}
