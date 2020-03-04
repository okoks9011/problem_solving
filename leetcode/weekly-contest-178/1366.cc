#include <vector>
#include <string>
#include <algorithm>
#include <cassert>


using namespace std;


class Solution {
  public:
    string rankTeams(vector<string>& votes) {
        assert(!votes.empty());
        int n = votes[0].size();
        vector<vector<int>> scores(26, vector<int>(n+1));
        for (int i = 0; i < 26; ++i)
            scores[i].back() = i;

        for (int i = 0; i < n; ++i) {
            for (auto& vote : votes) {
                int cur = 25 - (vote[i]-'A');
                ++scores[cur][i];
            }
        }
        sort(scores.rbegin(), scores.rend());

        string result;
        for (int i = 0; i < n; ++i) {
            int cur = 25 - scores[i].back();
            result += static_cast<char>(cur+'A');
        }
        return result;
    }
};
