#include <vector>
#include <unordered_set>
#include <algorithm>


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

        for (auto& adj : adjs[cur]) {
            if (visited[adj] == kGray)
                return false;
            if (visited[adj] == kBlack)
                continue;

            if (!TopologicalSort(adj, adjs, visited_ptr, result_ptr))
                return false;
        }
        visited[cur] = kBlack;
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
        vector<int> item_order;
        for (int i = 0; i < n; ++i) {
            if (visited[i] != kWhite)
                continue;
            if (!TopologicalSort(i, before, &visited, &item_order))
                return {};
        }
        vector<int> priority(n);
        for (int i = 0; i < n; ++i)
            priority[item_order[i]] = i;
        vector<vector<int>> group_by(g_cnt);
        for (int i = 0; i < n; ++i)
            group_by[group[i]].emplace_back(i);
        for (int i = 0; i < g_cnt; ++i) {
            sort(group_by[i].begin(), group_by[i].end(),
                 [&](int v1, int v2) { return priority[v1] < priority[v2]; });
        }

        vector<unordered_set<int>> group_before_set(g_cnt);
        for (int i = 0; i < n; ++i) {
            for (auto& b : before[i]) {
                if (group[i] != group[b])
                    group_before_set[group[i]].emplace(group[b]);
            }
        }
        vector<vector<int>> group_before(g_cnt);
        for (int i = 0; i < g_cnt; ++i)
            group_before[i] = vector<int>(group_before_set[i].begin(), group_before_set[i].end());

        visited = vector<int>(g_cnt, kWhite);
        vector<int> group_order;
        for (int i = 0; i < g_cnt; ++i) {
            if (visited[i] != kWhite)
                continue;
            if (!TopologicalSort(i, group_before, &visited, &group_order))
                return {};
        }

        vector<int> result;
        for (int i = 0; i < group_order.size(); ++i) {
            auto& cur_group = group_by[group_order[i]];
            result.insert(result.end(), cur_group.begin(), cur_group.end());
        }
        return result;
    }
};
