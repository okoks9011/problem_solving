#include <vector>


using namespace std;


enum Color {
    kWhite,
    kGray,
    kBlack,
};


class Solution {
  public:
    bool TopologicalSort(int cur, vector<vector<int>>& adjs,
                         vector<int>* visited_ptr, vector<int>* result_ptr) {
        auto& visited = *visited_ptr;
        visited[cur] = kGray;

        for (auto& adj : adjs[n]) {
            if (visited[adj] == kGray)
                return false;
            if (visited[adj] == kBlack)
                continue;

            if (!TopologicalSort(adj, adjs, visited_ptr, result_ptr))
                return false;
        }
        result_ptr->emplace_back(cur);
        return true;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before) {
        int g_cnt = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] != -1)
                continue;
            group[i] = g_cnt;
            ++g_cnt;
        }

        vector<int> visited(n, kWhite);
        vector<int> ordred;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == kWhite)
                TopologicalSort(i, before, &visited, &ordered);
        }
    }
};
