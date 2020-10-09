#include <iostream>
#include <cassert>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int calMaxHeight(const vector<int>& row) {
        vector<int> stack;
        int result = 0;
        for (int i = 0; i < row.size(); ++i) {
            while (!stack.empty() && row[stack.back()] >= row[i]) {
                int j = stack.back();
                stack.pop_back();

                int left = stack.empty() ? -1 : stack.back();
                int area = row[j] * (i - left - 1);
                result = max(result, area);
            }
            stack.emplace_back(i);
        }
        return result;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;

        vector<int> row(m+1);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1')
                    ++row[j];
                else
                    row[j] = 0;
            }
            result = max(result, calMaxHeight(row));
        }
        return result;
    }
};
