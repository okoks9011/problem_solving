#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cassert>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_qa;
    priority_queue<int, vector<int>, greater<int>> min_qb;
    int max_q_sum = 0;
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a && b) {
            max_q.emplace(t);
            max_q_sum += t;
            if (max_q.size() > k) {
                max_q_sum -= max_q.top();
                max_q.pop();
            }
        } else if (a) {
            min_qa.emplace(t);
            if (min_qa.size() > k)
                min_qa.pop();
        } else if (b) {
            min_qb.emplace(t);
            if (min_qb.size() > k)
                min_qb.pop();
        }
    }

    if (min(min_qa.size(), min_qb.size()) + max_q.size() < k) {
        cout << -1 << endl;
        return 0;
    }

    int result = max_q_sum;
    for (int i = max_q.size(); i < k; ++i) {
        assert(!min_qa.empty() && !min_qb.empty());
        result += min_qa.top();
        min_qa.pop();
        result += min_qb.top();
        min_qb.pop();
    }

    int cur_result = result;
    for (int i = min(min_qa.size(), min_qb.size()); i > 0; --i) {
        cur_result -= max_q.top();
        max_q.pop();
        cur_result += min_qa.top();
        min_qa.pop();
        cur_result += min_qb.top();
        min_qb.pop();
        result = min(result, cur_result);
    }
    cout << result << endl;
}
