#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>


using namespace std;


class Solution {
  public:
    string reorganizeString(string s) {
        vector<int> cnt(26);
        for (auto& c : s)
            ++cnt[c-'a'];

        vector<pair<int, int>> order;
        for (int i = 0; i < 26; ++i)
            order.emplace_back(cnt[i], i);
        sort(order.begin(), order.end(), greater<>());

        int n = s.size();
        int half = (n + 1) / 2;
        if (order[0].first > half)
            return "";

        string freq;
        for (int i = 0; i < 26; ++i) {
            auto& c = order[i];
            freq += string(c.first, c.second + 'a');
        }

        string result;
        for (int i = 0; i < half; ++i) {
            result += freq[i];
            if (half + i < n)
                result += freq[half+i];
        }
        return result;
    }
};
