#include <vector>


using namespace std;


class Solution {
  public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        int push_i = 0;
        int pop_i = 0;

        while (pop_i < popped.size()) {
            if (stack.empty() || stack.back() != popped[pop_i]) {
                if (push_i >= pushed.size())
                    return false;
                stack.emplace_back(pushed[push_i++]);
            } else {
                stack.pop_back();
                ++pop_i;
            }
        }
        return true;
    }
};
