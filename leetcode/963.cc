#include <vector>
#include <limits>
#include <cmath>


using namespace std;


class Solution {
  private:
    vector<vector<int>> points;

  public:
    long long CalLengthSquare(int a, int b) {
        auto& pa = points[a];
        auto& pb = points[b];
        int x_diff = pa[0] - pb[0];
        int y_diff = pa[1] - pb[1];
        return 1LL * x_diff * x_diff + y_diff * y_diff;
    }

    bool CheckAngle(int a, int b, int c) {
        return CalLengthSquare(a, b) + CalLengthSquare(b, c) == CalLengthSquare(a, c);
    }

    bool IsRectangle(int a, int b, int c, int d) {
        return CheckAngle(a, b, c) && CheckAngle(b, c, d) && CheckAngle(c, d, a) && CheckAngle(d, a, b);
    }

    double CalSize(int a, int b, int c, int d) {
        return sqrt(CalLengthSquare(a, b)) * sqrt(CalLengthSquare(b, c));
    }

    double minAreaFreeRect(vector<vector<int>>& points) {
        this->points = points;
        double result = numeric_limits<double>::max();
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j)
                        continue;
                    for (int w = 0; w < n; ++w) {
                        if (w == i || w == j || w == k)
                            continue;

                        if (!IsRectangle(i, j, k, w))
                            continue;
                        result = min(result, CalSize(i, j, k, w));
                    }
                }
            }
        }

        if (result == numeric_limits<double>::max())
            return 0;
        else
            return result;
    }
};
