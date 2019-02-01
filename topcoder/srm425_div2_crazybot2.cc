#include <vector>
#include <deque>
#include <utility>

#define x first
#define y second

using namespace std;

class CrazyBot {
  public:
    double CalProb(pair<int, int> cur, int n) {
        if (grid[cur.x][cur.y])
            return 0.0;
        if (n == 0)
            return 1.0;

        grid[cur.x][cur.y] = true;
        double result = 0.0;
        for (int i = 0; i < 4; ++i)
            result += prob[i] * CalProb({cur.x+v[i].x, cur.y+v[i].y}, n-1);

        grid[cur.x][cur.y] = false;
        return result;
    }

    double getProbability(int n, int east, int west, int south, int north) {
        prob[0] = east / 100.0;
        prob[1] = west / 100.0;
        prob[2] = south / 100.0;
        prob[3] = north / 100.0;
        pair<int, int> cur{50, 50};

        return CalProb(cur, n);
    }

  private:
    // E W S N
    vector<double> prob = vector<double>(4);
    vector<pair<int, int>> v = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<deque<bool>> grid = vector<deque<bool>>(100, deque<bool>(100));
};
