#include <vector>
#include <utiltiy>

using namespace std;

class StockSpanner {
    vector<pair<int, int>> stack = vector<pair<int, int>>();
    int i = 0;
public:
    StockSpanner() {
    }

    int next(int price) {
        while (!stack.empty() && stack.back().second <= price)
            stack.pop_back();
        int left = stack.empty() ? -1 : stack.back().first;
        stack.emplace_back(i, price);

        int result = i - left;
        ++i;
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
