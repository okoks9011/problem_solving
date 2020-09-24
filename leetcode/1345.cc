#include <vector>
#include <unordered_map>
#include <cassert>


using namespace std;


class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> portal;
        for (int i = 0; i < n; ++i)
            portal[arr[i]].emplace_back(i);

        vector<char> visited(n);
        vector<int> cur;
        visited[0] = true;
        cur.emplace_back(0);

        int level = 0;
        while (!cur.empty()) {
            vector<int> next;
            for (auto& p : cur) {
                if (p == n-1)
                    return level;

                for (auto& d : {-1, 1}) {
                    int np = p + d;
                    if (np < 0 || n <= np)
                        continue;
                    if (visited[np])
                        continue;
                    visited[np] = true;
                    next.emplace_back(np);
                }
                auto it = portal.find(arr[p]);
                if (it == portal.end())
                    continue;
                for (auto& np : it->second) {
                    if (np == p)
                        continue;
                    visited[np] = true;
                    next.emplace_back(np);
                }
                portal.erase(arr[p]);
            }
            cur = next;
            ++level;
        }
        assert(false);
    }
};
