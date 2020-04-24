#include <vector>
#include <algorithm>
#include <limits>


using namespace std;


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int FindFirstOne(BinaryMatrix& b, int row) {
        auto d = b.dimensions();
        int left = 0;
        int right = d[1]-1;
        int result = d[1];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int v = b.get(row, mid);
            if (v) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int leftMostColumnWithOne(BinaryMatrix& b) {
        auto d = b.dimensions();
        int result = d[1];
        for (int i = 0; i < d[0]; ++i) {
            if (result <= 0 || b.get(i, result-1) == 0)
                continue;
            result = min(result, FindFirstOne(b, i));
        }
        if (result == d[1])
            return -1;
        return result;
    }
};
