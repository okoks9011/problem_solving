class Solution {
public:
    void dfs(int here, const vector<vector<int>>& stones, vector<char>* visited_ptr) {
        auto& visited = *visited_ptr;
        visited[here] = true;
        for (int there = 0; there < stones.size(); ++there) {
            if (visited[there])
                continue;
            if (stones[here][0] == stones[there][0] ||
                stones[here][1] == stones[there][1])
                dfs(there, stones, visited_ptr);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<char> visited(n);
        int comp = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, stones, &visited);
                ++comp;
            }
        }
        return n - comp;
    }
};
