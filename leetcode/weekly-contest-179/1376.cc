#include <vector>
#include <cassert>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int calPathLength(int i, vector<int>* path_length_ptr,
                      const vector<int>& manager, const vector<int>& informTime) {
        auto& path_length = *path_length_ptr;
        if (path_length[i] != -1)
            return path_length[i];

        assert(manager[i] != -1);
        int parent_length = calPathLength(manager[i], path_length_ptr, manager, informTime);
        path_length[i] = parent_length + informTime[manager[i]];

        return path_length[i];
    }

    int numOfMinutes(int n, int headID, const vector<int>& manager, const vector<int>& informTime) {
        vector<int> path_length(n, -1);
        path_length[headID] = 0;

        for (int i = 0; i < n; ++i)
            calPathLength(i, &path_length, manager, informTime);

        return *max_element(path_length.begin(), path_length.end());
    }
};
