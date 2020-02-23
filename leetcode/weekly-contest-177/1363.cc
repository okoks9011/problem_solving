#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;


class Solution {
  public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());

        int sum = accumulate(digits.begin(), digits.end(), 0);
        if (sum % 3) {
            auto it = find_if(digits.begin(), digits.end(), [&](int v){ return sum % 3 == v % 3; });
            if (it != digits.end())
                digits.erase(it);
        }
        if (digits.empty())
            return "";

        sum = accumulate(digits.begin(), digits.end(), 0);
        if (sum % 3) {
            int t = 3 - (sum % 3);

            auto it1 = find_if(digits.begin(), digits.end(), [&](int v){ return t == v % 3; });
            if (it1 == digits.end())
                return "";
            digits.erase(it1);
            auto it2 = find_if(digits.begin(), digits.end(), [&](int v){ return t == v % 3; });
            if (it2 == digits.end())
                return "";
            digits.erase(it2);
        }
        if (digits.empty())
            return "";

        if (all_of(digits.begin(), digits.end(), [](int v){ return v == 0; }))
            return "0";

        string result;
        for (auto& di : digits)
            result += static_cast<char>('0'+di);
        return {result.rbegin(), result.rend()};
    }
};
