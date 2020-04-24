#include <vector>
#include <algorithm>


using namespace std;


struct Elem {
    int v = 0;
    int cnt = 0;

    Elem(int vx, int cntx) : v(vx), cnt(cntx) {}
};


class MinStack {
private:
    vector<int> stack;
    vector<Elem> mins;
public:
    MinStack() {
    }

    void push(int x) {
        stack.emplace_back(x);
        int min_v = x;
        if (mins.empty()) {
            mins.emplace_back(x, 1);
        } else {
            auto& e = mins.back();
            if (e.v <= x)
                ++e.cnt;
            else
                mins.emplace_back(x, 1);
        }
    }

    void pop() {
        stack.pop_back();
        auto& e = mins.back();
        --e.cnt;
        if (!e.cnt)
            mins.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return mins.back().v;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
