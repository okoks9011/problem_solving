#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

void print_pq(priority_queue<pair<int, char>> max_pq) {
    while (!max_pq.empty()) {
        auto p = max_pq.top();
        max_pq.pop();
        cout << p.first << ": " << p.second << endl;
    }
}

class Solution {
  public:
    string reorganizeString(string s) {
        if (s.size() == 0)
            return "";

        unordered_map<char, int> cnt;
        for (auto& si : s)
            ++cnt[si];
        priority_queue<pair<int, char>> max_pq;
        for (auto& p : cnt)
            max_pq.emplace(p.second, p.first);

        auto p = max_pq.top();
        max_pq.pop();
        string result(1, p.second);
        if (p.first > 1)
            max_pq.emplace(p.first-1, p.second);
        while (!max_pq.empty()) {
            char last = result.back();
            auto p = max_pq.top();
            max_pq.pop();

            if (p.second != last) {
                result += p.second;
                --p.first;
                if (p.first)
                    max_pq.emplace(p);
            } else {
                if (max_pq.empty())
                    return "";
                auto p2 = max_pq.top();
                max_pq.pop();

                result += p2.second;
                --p2.first;
                if (p.first)
                    max_pq.emplace(p);
                if (p2.first)
                    max_pq.emplace(p2);
            }
        }
        return result;
    }
};
