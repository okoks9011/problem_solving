#include <queue>
#include <cmath>


using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_pq;
        for (auto& s : stones)
            max_pq.emplace(s);
        while (max_pq.size() > 1) {
            int x = max_pq.top();
            max_pq.pop();
            int y = max_pq.top();
            max_pq.pop();
            if (x != y)
                max_pq.emplace(abs(x-y));
        }
        if (max_pq.empty())
            return 0;
        return max_pq.top();
    }
};
