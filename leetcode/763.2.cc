#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
  public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        for (int i = 0; i < n; ++i)
            last[s[i]-'a'] = i;

        int part_end = -1;
        int part_start = 0;
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            part_end = max(part_end, last[s[i]-'a']);
            if (part_end == i) {
                result.emplace_back(part_end - part_start + 1);
                part_start = i + 1;
            }
        }
        return result;
    }
};
