#include <algorithm>
#include <vector>
#include <cassert>


using namespace std;


const int kMod = 1000000007;

class Rec {
  public:
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    long long size = 0;

    Rec(int nx1, int ny1, int nx2, int ny2) : x1(nx1), y1(ny1), x2(nx2), y2(ny2) {
        if (x1 >= x2 || y1 >= y2) {
            size = 0LL;
        } else {
            size = (1LL * (x2 - x1) * (y2 - y1)) % kMod;
        }
    }

    Rec inter(Rec other) {
        return Rec(max(x1, other.x1),
                   max(y1, other.y1),
                   min(x2, other.x2),
                   min(y2, other.y2));
    }
};

class Solution {
  public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        assert(n > 0);
        auto r0 = rectangles[0];
        vector<vector<Rec>> rs{{Rec(r0[0], r0[1], r0[2], r0[3])}};

        for (int i = 1; i < n; ++i) {
            auto& t = rectangles[i];
            Rec cur_r(t[0], t[1], t[2], t[3]);
            rs.emplace_back(vector<Rec>());
            for (int j = rs.size()-1; j >= 1; --j) {
                for (auto& r : rs[j-1]) {
                    auto new_r = cur_r.inter(r);
                    if (new_r.size > 0)
                        rs[j].emplace_back(new_r);
                }
            }
            rs[0].emplace_back(cur_r);
        }

        long long result = 0LL;
        for (int i = 0; i < rs.size(); ++i) {
            for (int j = 0; j < rs[i].size(); ++j) {
                if (i % 2 == 0)
                    result += rs[i][j].size;
                else
                    result += (kMod - rs[i][j].size);
                result %= kMod;
            }
        }
        return static_cast<int>(result);
    }
};
