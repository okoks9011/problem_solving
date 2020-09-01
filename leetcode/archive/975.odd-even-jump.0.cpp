#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<int> odd_next(n);
        vector<int> even_next(n);

        map<int, int> idx;
        for (int i = n-1; i >= 0; --i) {
            auto larger = idx.lower_bound(A[i]);
            if (larger != idx.end()) {
                odd_next[i] = larger->second;
            } else {
                odd_next[i] = n;
            }

            auto smaller = idx.upper_bound(A[i]);
            if (smaller != idx.begin()) {
                --smaller;
                even_next[i] = smaller->second;
            } else {
                even_next[i] = n;
            }
            idx[A[i]] = i;
        }

        vector<char> odd_reach(n+1);
        vector<char> even_reach(n+1);
        odd_reach[n-1] = true;
        even_reach[n-1] = true;
        for (int i = n-2; i >= 0; --i) {
            odd_reach[i] = even_reach[odd_next[i]];
            even_reach[i] = odd_reach[even_next[i]];
        }

        return count(odd_reach.begin(), odd_reach.end(), true);
    }
};
