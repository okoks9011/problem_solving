#include <vector>
#include <cassert>


using namespace std;


class Solution {
public:
    int findEdge(const vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int edge = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[0] <= nums[mid]) {
                edge = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }
        return edge;
    }

    int binarySearch(const vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int edge = findEdge(nums);
        int r = binarySearch(nums, 0, edge, target);
        if (r != -1)
            return r;

        return binarySearch(nums, edge+1, nums.size()-1, target);
    }
};
