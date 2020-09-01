#include <vector>


using namespace std;


class Solution {
  public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        int pop_i = 0;

        for (auto& v : pushed) {
            stack.emplace_back(v);
            while (!stack.empty() && stack.back() == popped[pop_i]) {
                stack.pop_back();
                ++pop_i;
            }
        }
        return stack.empty();
    }
};
