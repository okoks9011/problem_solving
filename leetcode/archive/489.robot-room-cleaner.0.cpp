#include <vector>
#include <set>
#include <utility>

using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
  public:
    vector<pair<int, int>> ds;
    set<pair<int, int>> visited;

    Solution() {
        ds = vector<pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    }

    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void dfs(Robot& robot, int y, int x, int d) {
        visited.emplace(y, x);
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            int next_d = (d+i) % 4;
            int next_y = y + ds[next_d].first;
            int next_x = x + ds[next_d].second;

            if (visited.find({next_y, next_x}) == visited.end() && robot.move()) {
                dfs(robot, next_y, next_x, next_d);
                goBack(robot);
            }

            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};
