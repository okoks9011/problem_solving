#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;


class Solution {
  public:
    vector<int> getFriendsWithLevel(const vector<vector<string>>& watchedVideos, const vector<vector<int>>& friends, int id, int level) {
        vector<int> cur;
        cur.emplace_back(id);
        unordered_set<int> visited;
        visited.emplace(id);

        for (int i = 0; i < level; ++i) {
            vector<int> buf;
            for (auto& cur_id : cur) {
                for (auto& f_id : friends[cur_id]) {
                    if (visited.find(f_id) != visited.end())
                        continue;
                    buf.emplace_back(f_id);
                    visited.emplace(f_id);
                }
            }
            cur = buf;
        }
        return cur;
    }

    vector<string> watchedVideosByFriends(const vector<vector<string>>& watchedVideos, const vector<vector<int>>& friends, int id, int level) {
        auto k_friends = getFriendsWithLevel(watchedVideos, friends, id, level);
        unordered_map<string, int> freq;
        for (auto& f_id : k_friends) {
            for (auto& video : watchedVideos[f_id])
                ++freq[video];
        }

        vector<pair<int, string>> reorder;
        for (auto& p : freq)
            reorder.emplace_back(p.second, p.first);
        sort(reorder.begin(), reorder.end());

        vector<string> result;
        for (auto& p : reorder)
            result.emplace_back(p.second);
        return result;
    }
};
