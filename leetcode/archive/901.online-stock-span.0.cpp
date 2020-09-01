#include <vector>
#include <utiltiy>

using namespace std;

class StockSpanner {
    vector<pair<int, int>> stack = vector<pair<int, int>>();
public:
    StockSpanner() {
    }

    int next(int price) {
        int cnt = 1;
        while (!stack.empty() && stack.back().first <= price) {
            cnt += stack.back().second;
            stack.pop_back();
        }
        stack.emplace_back(price, cnt);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
