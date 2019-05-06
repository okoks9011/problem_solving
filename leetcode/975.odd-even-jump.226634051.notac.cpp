#include <algorithm>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<char> even(n);
        vector<char> odd(n);
        even[n-1] = true;
        odd[n-1] = true;
        for (int i = n-2; i >= 0; --i) {
            int large = -1;
            for (int j = n-1; j > i; --j) {
                if (A[i] <= A[j] &&
                    (large == -1 || A[large] >= A[j]))
                    large = j;
            }
            if (large != -1)
                odd[i] = even[large];

            int small = -1;
            for (int j = n-1; j > i; --j) {
                if (A[i] >= A[j] &&
                    (small == -1 || A[small] <= A[j]))
                    small = j;
            }
            if (small != -1)
                even[i] = odd[small];
        }
        return count(odd.begin(), odd.end(), true);
    }
};
