#include <vector>


class Solution {
public:
    vector<int> xorQueries(const vector<int>& arr, const vector<vector<int>>& queries) {
        vector<int> ac(arr.size()+1);
        for (int i = 0; i < arr.size(); ++i)
            ac[i+1] = ac[i] ^ arr[i];

        vector<int> result;
        for (auto& q : queries)
            result.emplace_back(ac[q[0]] ^ ac[q[1]+1]);
        return result;
    }
};
