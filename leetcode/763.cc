#include <vector>
#include <string>
#include <utility>
#include <algorithm>


using namespace std;


class Solution {
  public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i)
            last[s[i]-'a'] = i;
        for (int i = n-1; i >= 0; --i)
            first[s[i]-'a'] = i;

        vector<pair<int, int>> inter;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1)
                continue;
            inter.emplace_back(first[i], last[i]);
        }
        sort(inter.begin(), inter.end());

        auto cur = inter[0];
        vector<int> result;
        for (int i = 1; i < inter.size(); ++i) {
            if (cur.second < inter[i].first) {
                result.emplace_back(cur.second - cur.first + 1);
                cur = inter[i];
            } else {
                cur.second = max(cur.second, inter[i].second);
            }
        }
        result.emplace_back(cur.second - cur.first + 1);
        return result;
    }
};
