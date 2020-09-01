#include <map>

using namespace std;

class MyCalendarTwo {
  private:
    map<int, int> time;
  public:
    MyCalendarTwo() {
    }
    bool checkValid() {
        int cur = 0;
        for (auto& p : time) {
            cur += p.second;
            if (cur >= 3)
                return false;
        }
        return true;
    }
    bool book(int start, int end) {
        ++time[start];
        --time[end];
        if (!checkValid()) {
            --time[start];
            ++time[end];
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
