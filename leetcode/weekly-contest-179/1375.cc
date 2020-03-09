#include <vector>


using namespace std;


class Solution {
  public:
    int numTimesAllBlue(vector<int>& light) {
        vector<char> status(light.size());
        int max_cont = 0;
        int result = 0;

        for (int i = 0; i < light.size(); ++i) {
            status[light[i]-1] = true;
            while (max_cont < status.size() && status[max_cont])
                ++max_cont;

            if (max_cont == i+1)
                ++result;
        }

        return result;
    }
};
