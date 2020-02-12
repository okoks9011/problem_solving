#include <vector>
#include <utility>
#include <limits>
#include <cassert>
#include <algorithm>


using namespace std;


class Solution {
  public:
    void getNeighbors(int cur, int dist, const vector<vector<pair<int, int>>>& adjs, vector<char>* visited_ptr) {
        if (dist < 0)
            return;

        auto& visited = *visited_ptr;
        if (dist <= visited[cur])
            return;
        visited[cur] = dist;

        if (dist == 0)
            return;

        for (auto& adj : adjs[cur])
            getNeighbors(adj.first, dist-adj.second, adjs, visited_ptr);
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjs(n);
        for (auto& edge : edges) {
            int f = edge[0];
            int t = edge[1];
            int w = edge[2];

            adjs[f].emplace_back(t, w);
            adjs[t].emplace_back(f, w);
        }

        int min_neighbors = numeric_limits<int>::max();
        int min_id = -1;
        for (int i = 0; i < n; ++i) {
            vector<char> visited(n, -1);
            getNeighbors(i, distanceThreshold, adjs, &visited);
            int cur_neighbors = n - count(visited.begin(), visited.end(), -1);
            if (cur_neighbors <= min_neighbors) {
                min_id = i;
                min_neighbors = cur_neighbors;
            }
        }
        assert(min_id != -1);

        return min_id;
    }
};
