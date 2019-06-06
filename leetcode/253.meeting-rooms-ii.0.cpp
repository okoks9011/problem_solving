#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& meets) {
        vector<int> starts(meets.size());
        vector<int> ends(meets.size());
        for (int i = 0; i < meets.size(); ++i) {
            starts[i] = meets[i][0];
            ends[i] = meets[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int ei = 0;
        int result = 0;
        for (int si = 0; si < starts.size(); ++si) {
            if (ends[ei] > starts[si])
                ++result;
            else
                ++ei;
        }
        return result;
    }
};
