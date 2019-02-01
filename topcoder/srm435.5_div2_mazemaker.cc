#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

struct Point {
    int x = 0;
    int y = 0;
    int level = 0;
    Point(int xi, int yi, int l) : x(xi), y(yi), level(l) {}
};

class MazeMaker {
  public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
        int max_level = 0;
        deque<Point> q{{startRow, startCol, 0}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop_front();
            if (cur.x < 0 || cur.x >= maze.size() || cur.y < 0 || cur.y >= maze[cur.x].size())
                continue;
            if (maze[cur.x][cur.y] == 'X')
                continue;

            maze[cur.x][cur.y] = 'X';
            max_level = cur.level;
            for (int i = 0; i < moveRow.size(); ++i)
                q.emplace_back(cur.x+moveRow[i], cur.y+moveCol[i], cur.level+1);
        }

        for (auto& row : maze) {
            if (row.find('.') != string::npos)
                return -1;
        }

        return max_level;
    }
};
