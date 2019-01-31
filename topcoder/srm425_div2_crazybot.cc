#include <set>
#include <utility>

#define x first
#define y second

using namespace std;

class CrazyBot {
  public:
    double CalProb(pair<int, int> cur, int n, set<pair<int, int>>* history_ptr) {
        auto& history = *history_ptr;
        if (history.count(cur) != 0)
            return 0.0;
        if (n == 0)
            return 1.0;
        history.emplace(cur);

        double result = 0.0;
        result += ea * CalProb({cur.x+1, cur.y}, n-1, history_ptr);
        result += we * CalProb({cur.x-1, cur.y}, n-1, history_ptr);
        result += so * CalProb({cur.x, cur.y-1}, n-1, history_ptr);
        result += no * CalProb({cur.x, cur.y+1}, n-1, history_ptr);

        history.erase(cur);
        return result;
    }

    double getProbability(int n, int east, int west, int south, int north) {
        ea = east / 100.0;
        we = west / 100.0;
        so = south / 100.0;
        no = north / 100.0;

        set<pair<int, int>> history;
        pair<int, int> cur{0, 0};

        return CalProb(cur, n, &history);
    }

  private:
    double ea = 0;
    double we = 0;
    double so = 0;
    double no = 0;
};
