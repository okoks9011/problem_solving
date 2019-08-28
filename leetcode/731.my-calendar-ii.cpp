#include <set>
#include <utility>

using namespace std;

class MyCalendarTwo {
  private:
    multiset<pair<int, int>> cal;
  public:
    MyCalendarTwo() {
    }

    bool checkOverlap(pair<int, int> t1, pair<int, int> t2) {
        return t1.first < t2.second && t2.first < t1.second;
    }

    bool book(int start, int end) {
        if (cal.size() <= 1) {
            cal.emplace(start, end);
            return true;
        }

        auto cur_it = cal.begin();
        auto next_it = cur_it;
        ++next_it;
        while (next_it != cal.end()) {
            if (cur_it->second > next_it->first) {
                if (cur_it->second <= next_it->second) {
                    if (checkOverlap({start, end}, {next_it->first, cur_it->second}))
                        return false;
                    cur_it = next_it;
                } else {
                    if (checkOverlap({start, end}, {next_it->first, next_it->second}))
                        return false;
                }
                ++next_it;
            } else {
                cur_it = next_it;
                ++next_it;
            }
        }
        cal.emplace(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
