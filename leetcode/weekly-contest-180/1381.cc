#include <vector>


using namespace std;


class CustomStack {
  private:
    int max = 0;
    vector<int> buf;

  public:
    CustomStack(int maxSize) {
        max = maxSize;
    }

    void push(int x) {
        if (buf.size() < max)
            buf.emplace_back(x);
    }

    int pop() {
        if (!buf.empty()) {
            int result = buf.back();
            buf.pop_back();
            return result;
        } else {
            return -1;
        }
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < buf.size(); ++i)
            buf[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
