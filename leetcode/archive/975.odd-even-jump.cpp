#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<pair<int, int>> idx;
        for (int i = 0; i < n; ++i)
            idx.emplace_back(A[i], i);
        sort(idx.begin(), idx.end());

        vector<int> stack;
        vector<int> odd_next(n);
        for (int i = n-1; i >= 0; --i) {
            auto cur_idx = idx[i].second;
            while (!stack.empty() && stack.back() < cur_idx)
                stack.pop_back();
            odd_next[cur_idx] = stack.empty() ? n : stack.back();
            stack.emplace_back(cur_idx);
        }
        stack.clear();

        for (auto& elem : idx)
            elem.first = -elem.first;
        sort(idx.begin(), idx.end());
        vector<int> even_next(n);
        for (int i = n-1; i >= 0; --i) {
            auto cur_idx = idx[i].second;
            while (!stack.empty() && stack.back() < cur_idx)
                stack.pop_back();
            even_next[cur_idx] = stack.empty() ? n : stack.back();
            stack.emplace_back(cur_idx);
        }

        vector<char> odd_reach(n+1);
        vector<char> even_reach(n+1);
        odd_reach[n-1] = true;
        even_reach[n-1] = true;
        for (int i = n-2; i >= 0; --i) {
            odd_reach[i] = even_reach[odd_next[i]];
            even_reach[i] = odd_reach[even_next[i]];
        }

        return count(odd_reach.begin(), odd_reach.end(), true);
    }
};
