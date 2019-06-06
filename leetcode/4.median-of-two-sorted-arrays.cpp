#include <vector>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j]) {
                result.emplace_back(A[i]);
                ++i;
            } else {
                result.emplace_back(B[j]);
                ++j;
            }
        }
        if (i < A.size())
            result.insert(result.end(), A.begin()+i, A.end());
        if (j < B.size())
            result.insert(result.end(), B.begin()+j, B.end());

        double median = 0;
        if (result.size() % 2) {
            median = result[result.size()/2];
        } else {
            int mid = result.size() / 2;
            median = (result[mid-1]+result[mid]) / 2.0;
        }
        return median;
    }
};
