#include <map>
#include <iterator>


using namespace std;


class MyCalendar {
  private:
    map<int, int> inter;

  public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        if (inter.empty()) {
            inter[start] = end;
            return true;
        }

        auto it = inter.upper_bound(start);
        if (it != inter.begin()) {
            if (prev(it)->second >= start)
                return false;
        }
        if (it != inter.end()) {
            if (end >= it->first)
                return false;
        }
        inter[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
