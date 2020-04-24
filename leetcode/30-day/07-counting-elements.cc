#include <set>
#include <vector>


using namespace std;


class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> u;
        for (auto& a : arr)
            u.emplace(a);

        int result = 0;
        for (auto& a : arr) {
            if (u.find(a+1) != u.end())
                ++result;
        }
        return result;
    }
};
