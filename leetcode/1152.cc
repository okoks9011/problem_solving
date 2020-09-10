#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <utility>
#include <cassert>
#include <algorithm>


using namespace std;


struct Seq {
    string x;
    string y;
    string z;

    Seq(string nx, string ny, string nz) : x(nx), y(ny), z(nz) {}
    Seq() = default;

    bool operator<(const Seq& other) const {
        if (x == other.x) {
            if (y == other.y)
                return z < other.z;
            return y < other.y;
        }
        return x < other.x;
    }
};


class Solution {
  public:
    set<Seq> getUserSeqs(const vector<pair<int, string>>& record) {
        int n = record.size();
        set<Seq> result;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = j+1; k < n; ++k)
                    result.emplace(record[i].second, record[j].second, record[k].second);
            }
        }
        return result;
    }

    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        assert(username.size() == timestamp.size());
        assert(timestamp.size() == website.size());
        int n = username.size();

        unordered_map<string, vector<pair<int, string>>> user_record;
        for (int i = 0; i < n; ++i)
            user_record[username[i]].emplace_back(timestamp[i], website[i]);

        for (auto& p : user_record)
            sort(p.second.begin(), p.second.end());

        map<Seq, int> cnt;
        for (auto& p : user_record) {
            auto user_seqs = getUserSeqs(p.second);
            for (auto& s : user_seqs)
                ++cnt[s];
        }

        int max_cnt = 0;
        Seq result;
        for (auto& p : cnt) {
            if (max_cnt < p.second) {
                result = p.first;
                max_cnt = p.second;
            } else if (max_cnt == p.second) {
                result = min(result, p.first);
            }
        }
        return {result.x, result.y, result.z};
    }
};
