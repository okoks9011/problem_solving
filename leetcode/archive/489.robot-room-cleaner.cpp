#include <random>

using namespace std;

const int kNum = 1000000;
mt19937 rng(17);

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
    void cleanRoom(Robot& robot) {
        uniform_int_distribution<int> dist(0, 2);
        for (int i = 0; i < kNum; ++i) {
            robot.clean();
            int d = dist(rng);
            if (d == 1)
                robot.turnLeft();
            else if (d == 2)
                robot.turnRight();
            robot.move();
        }
    }
};
